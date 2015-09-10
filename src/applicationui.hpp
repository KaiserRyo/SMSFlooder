/*
 * Copyright (c) 2011-2013 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <QtCore/QtCore>
#include <QTimer>
#include <bb/system/InvokeManager>
#include <bb/pim/account/Account>
#include <bb/pim/message/MessageService>
#include <bb/system/SystemProgressToast>
#include <bb/system/SystemProgressDialog>

using bb::system::InvokeManager;
using bb::pim::account::Account;
using bb::system::SystemProgressToast;

namespace bb
{
    namespace cascades
    {
        class Application;
    }
}

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }

    static const QString AUTHOR;
	static const QString APPNAME;

    Q_INVOKABLE void startFlooding(int interval, int times);
    Q_INVOKABLE void stopFlooding();

    Q_INVOKABLE void populateEmails(QObject* dropDownObject);
	Q_INVOKABLE bool contains(QString text, QString find);

    Q_INVOKABLE void invokeEmail(QString email, QString subject, QString body);
	Q_INVOKABLE void invokeBBWorld(QString appurl);
	Q_INVOKABLE void invokeBrowser(QString url);

    Q_INVOKABLE QString getContactPhoneNumber(int id);
	Q_INVOKABLE QString getContactEmail(int id);

    Q_INVOKABLE void showToast(QString text);
	Q_INVOKABLE void showDialog(const QString &title, const QString &text);
	Q_INVOKABLE QString getSetting(const QString &objectName, const QString &defaultValue);
	Q_INVOKABLE void setSetting(const QString &objectName, const QString &inputValue);

	Q_INVOKABLE void sendSMS(QString recipientNumber, QString message);
	Q_INVOKABLE void sendEmail(int recipientEmailID, QString recipientEmailAddress, QString recipientEmailSubject, QString messageText, QString lastRecordedAudioPath, bool autoReply);

private slots:

	void timedout();

	void onMessageAdded(bb::pim::account::AccountKey accountId, bb::pim::message::ConversationKey conversationId, bb::pim::message::MessageKey messageId);
	void onMessageUpdated(bb::pim::account::AccountKey accountId, bb::pim::message::ConversationKey conversationId, bb::pim::message::MessageKey messageId, bb::pim::message::MessageUpdate data);

signals:
	void sent(int repeatedTimes);
	void done();

private:

	bb::pim::message::MessageService* m_messageService;
    QList<Account> accounts;
    QTimer* timer;
    int maxTimes;
    int repeatedTimes;
    InvokeManager* invokeManager;

};

#endif /* ApplicationUI_HPP_ */
