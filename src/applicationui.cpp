#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <QTimer>
#include <QList>
#include <bb/PackageInfo>
#include <bb/cascades/DropDown>
#include <bb/cascades/Option>

#include <bb/system/InvokeRequest>
#include <bb/cascades/Invocation>
#include <bb/system/SystemDialog>
#include <bb/system/SystemToast>
#include <bb/system/SystemProgressToast>
#include <bb/system/SystemProgressDialog>

#include <bb/pim/account/AccountService>
#include <bb/pim/account/Account>
#include <bb/pim/account/Provider>
#include <bb/pim/message/MessageSearchFilter>
#include <bb/pim/message/MessageService>
#include <bb/pim/message/MessageBuilder>
#include <bb/pim/message/ConversationBuilder>
#include <bb/pim/message/Attachment>
#include <bb/pim/contacts/ContactService.hpp>
#include <bb/pim/contacts/ContactListFilters>
#include <bb/pim/contacts/Contact>
#include <bb/pim/contacts/ContactSearchFilters>

using namespace bb::pim::account;
using namespace bb::pim::message;
using namespace bb::cascades;
using namespace bb::system;

using bb::pim::contacts::ContactService;
using bb::pim::contacts::ContactListFilters;
using bb::pim::contacts::Contact;
using bb::pim::contacts::ContactSearchFilters;
using bb::PackageInfo;

const QString ApplicationUI::AUTHOR = "Nemory Development Studios";
const QString ApplicationUI::APPNAME = "SMS Flooder";

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
     QObject(app)
	, m_messageService(new bb::pim::message::MessageService(this))
{
	invokeManager = new InvokeManager();
	repeatedTimes = 0;
	maxTimes = 0;

	accounts = AccountService().accounts(Service::Messages);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timedout()));

	connect(
				m_messageService,
				SIGNAL(messageAdded(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey)),
				SLOT(onMessageAdded(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey))
			);

	connect(
				m_messageService,
				SIGNAL(messageUpdated(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey, bb::pim::message::MessageUpdate)),
				SLOT(onMessageUpdated(bb::pim::account::AccountKey, bb::pim::message::ConversationKey, bb::pim::message::MessageKey, bb::pim::message::MessageUpdate))
			);

    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
    qml->setContextProperty("_app", this);

    PackageInfo packageInfo;
	QDeclarativePropertyMap* map = new QDeclarativePropertyMap(this);
	map->setProperty("version", packageInfo.version());
	qml->setContextProperty("_packageInfo", map);

    AbstractPane *root = qml->createRootObject<AbstractPane>();
    app->setScene(root);
}

void ApplicationUI::onMessageAdded(bb::pim::account::AccountKey accountId, bb::pim::message::ConversationKey conversationId, bb::pim::message::MessageKey messageId)
{
	if(getSetting("autoDelete", "") == "true" || getSetting("autoDelete", "") == "")
	{
		Message message = m_messageService->message(accountId, messageId);
		Conversation conversation = m_messageService->conversation(accountId, conversationId);

		if(message.isSent() && (message.transmissionStatus() == MessageTransmissionStatus::Sent || message.transmissionStatus() == MessageTransmissionStatus::FailedToSent))
		{
			QString savedMessage = getSetting("message", "");
			QString sentMessage = message.body(MessageBody::PlainText).plainText();

			if(savedMessage.length() > 0 && savedMessage == sentMessage)
			{
				MessageService().remove(accountId, messageId);
				MessageService().remove(accountId, conversationId);
			}
		}
	}
}

void ApplicationUI::onMessageUpdated(bb::pim::account::AccountKey accountId, bb::pim::message::ConversationKey conversationId, bb::pim::message::MessageKey messageId, bb::pim::message::MessageUpdate data)
{
	if(getSetting("autoDelete", "") == "true" || getSetting("autoDelete", "") == "")
	{
		Message message = m_messageService->message(accountId, messageId);
		Conversation conversation = m_messageService->conversation(accountId, conversationId);

		if(message.isSent() && (message.transmissionStatus() == MessageTransmissionStatus::Sent || message.transmissionStatus() == MessageTransmissionStatus::FailedToSent))
		{
			QString savedMessage = getSetting("message", "");
			QString sentMessage = message.body(MessageBody::PlainText).plainText();

			if(savedMessage.length() > 0 && savedMessage == sentMessage)
			{
				MessageService().remove(accountId, messageId);
				MessageService().remove(accountId, conversationId);
			}
		}
	}
}

QString ApplicationUI::getSetting(const QString &objectName, const QString &defaultValue)
{
	QSettings settings(AUTHOR, APPNAME);;

	if (settings.value(objectName).isNull()
			|| settings.value(objectName) == "") {
		return defaultValue;
	}

	return settings.value(objectName).toString();
}

void ApplicationUI::setSetting(const QString &objectName, const QString &inputValue)
{
	QSettings settings(AUTHOR, APPNAME);
	settings.setValue(objectName, QVariant(inputValue));
}

void ApplicationUI::invokeEmail(QString email, QString subject, QString body) {
	InvokeRequest request;
	request.setTarget("sys.pim.uib.email.hybridcomposer");
	request.setAction("bb.action.SENDEMAIL");
	request.setUri(
			"mailto:" + email + "?subject=" + subject.replace(" ", "%20")
					+ "&body=" + body.replace(" ", "%20"));
	invokeManager->invoke(request);
}

void ApplicationUI::invokeBBWorld(QString appurl) {
	InvokeRequest request;
	request.setMimeType("application/x-bb-appworld");
	request.setAction("bb.action.OPEN");
	request.setUri(appurl);
	invokeManager->invoke(request);
}

void ApplicationUI::invokeBrowser(QString url) {
	InvokeRequest request;
	request.setTarget("sys.browser");
	request.setAction("bb.action.OPEN");
	request.setUri(url);
	invokeManager->invoke(request);
}

void ApplicationUI::showToast(QString text)
{
	SystemToast *toast = new SystemToast(this);
	toast->setBody(text);
	toast->setPosition(SystemUiPosition::MiddleCenter);
	toast->show();
}

void ApplicationUI::showDialog(const QString &title, const QString &text)
{
	SystemDialog *dialog = new SystemDialog(this);
	dialog->setTitle(title);
	dialog->setBody(text);
	dialog->setEmoticonsEnabled(true);
	dialog->show();
}

QString ApplicationUI::getContactPhoneNumber(int id)
{
	bb::pim::contacts::Contact contact = ContactService().contactDetails(id);

	if(contact.phoneNumbers().length() > 0)
	{
		return contact.phoneNumbers().first().value();
	}
	else
	{
		return "This contact has no phone number";
	}
}

QString ApplicationUI::getContactEmail(int id)
{
	bb::pim::contacts::Contact contact = ContactService().contactDetails(id);

	if(contact.emails().length() > 0)
	{
		return contact.emails().first().value();
	}
	else
	{
		return "This contact has no email";
	}
}

bool ApplicationUI::contains(QString text, QString find)
{
	if(find == "" || find == " " || find == "  " || text == "" || text == " " || text == "  ")
	{
		return false;
	}

	bool result;

	if(getSetting("caseSensitive", "false") == "true")
	{
		result = text.contains(find, Qt::CaseSensitive);
	}
	else if(getSetting("caseSensitive", "false") == "false")
	{
		result = text.contains(find, Qt::CaseInsensitive);
	}

	return result;
}

void ApplicationUI::populateEmails(QObject* dropDownObject)
{
    DropDown* dropDown = qobject_cast<DropDown*>(dropDownObject);

    foreach (Account account, accounts)
    {
    	if(account.displayName().isEmpty() || contains(account.displayName(), "Google Talk"))
    	{
    		continue;
    	}

        const QString name = account.displayName();

        Option::Builder option = Option::create().text(tr("%1 (%2)").arg(name, account.provider().name()))
                                                 .value(QVariant::fromValue(account.id()))
                                                 .selected(false);
        QUrl url("asset:///images/email.png");
        option.imageSource(url);

        dropDown->add(option);
    }
}

void ApplicationUI::timedout()
{
	repeatedTimes++;

	sendSMS(getSetting("recipientNumber", "222"), getSetting("message", "SMS Flood"));

	if(repeatedTimes >= maxTimes)
	{
		stopFlooding();
	}
}

void ApplicationUI::startFlooding(int interval, int times)
{
	stopFlooding();
	maxTimes = times;
    timer->start(interval);
}

void ApplicationUI::stopFlooding()
{
	repeatedTimes = 0;
	maxTimes = 0;
    timer->stop();
    emit done();
}

void ApplicationUI::sendEmail(int recipientEmailID, QString recipientEmailAddress, QString recipientEmailSubject, QString messageText, QString lastRecordedAudioPath, bool autoReply)
{
	const MessageContact recipient = MessageContact(-1, MessageContact::To, QString(), recipientEmailAddress);
	const QByteArray bodyData = messageText.replace("\n", "<br />").toUtf8();

	AccountKey accountkey(recipientEmailID);

	MessageBuilder *builder = MessageBuilder::create(accountkey);

	if(autoReply)
	{
		if(getSetting("attachRecordedAudios", "false") == "true")
		{
			Attachment attachment("audio/m4a", "Recorded Audio", QUrl::fromLocalFile(lastRecordedAudioPath));
			builder->addAttachment(attachment);
		}
	}

	builder->subject(recipientEmailSubject);
	builder->removeAllRecipients();
	builder->addRecipient(recipient);

	builder->body(MessageBody::Html, bodyData);

	m_messageService->send(accountkey, *builder);

	showToast("Email Trigger was sent successfully");
}

void ApplicationUI::sendSMS(QString recipientNumber, QString messageText)
{
	QStringList phoneNumbers;
	phoneNumbers << recipientNumber;

	bb::pim::account::AccountService accountService;
	bb::pim::message::MessageService messageService;

	QList<Account> accountListy = accountService.accounts(bb::pim::account::Service::Messages,"sms-mms");

	bb::pim::account::AccountKey smsAccountId = 0;
	if(!accountListy.isEmpty()) {
		smsAccountId = accountListy.first().id();
		qDebug() << "SMS-MMS account ID:" << smsAccountId;
	}
	else {
		showToast("Could not find SMS account");
		return;
	}

	QList<bb::pim::message::MessageContact> participants;
	foreach(const QString &phoneNumber, phoneNumbers) {
		bb::pim::message::MessageContact recipient = bb::pim::message::MessageContact(
			-1, bb::pim::message::MessageContact::To,
			phoneNumber, phoneNumber);
		participants.append(recipient);
	}

	bb::pim::message::ConversationBuilder *conversationBuilder =
		bb::pim::message::ConversationBuilder::create();
	conversationBuilder->accountId(smsAccountId);
	conversationBuilder->participants(participants);

	bb::pim::message::Conversation conversation = *conversationBuilder;
	bb::pim::message::ConversationKey conversationId = messageService.save(smsAccountId, conversation);

	bb::pim::message::MessageBuilder *builder =
		bb::pim::message::MessageBuilder::create(smsAccountId);
	builder->conversationId(conversationId);

	//builder->addAttachment(bb::pim::message::Attachment("text/plain", "", messageText.toUtf8()));

	QByteArray bodyData = messageText.toUtf8();

	builder->body(MessageBody::PlainText, bodyData);

	foreach(const bb::pim::message::MessageContact recipient, participants) {
		builder->addRecipient(recipient);
	}

	bb::pim::message::Message message = *builder;

	messageService.send(smsAccountId, message);

	delete builder;
	delete conversationBuilder;

	emit sent(repeatedTimes);
}
