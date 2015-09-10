#include <bb/cascades/Application>
#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"
#include "Settings.hpp"
#include <bb/cascades/Pickers/ContactPicker>
#include <Qt/qdeclarativedebug.h>
#include <bb/pim/message/MessageUpdate>

using namespace bb::cascades;
using namespace bb::cascades::pickers;

QString getValue(QString value)
{
    Settings settings;
    return settings.getValueFor(value, "");
}

Q_DECLARE_METATYPE(bb::pim::message::MessageUpdate);

Q_DECL_EXPORT int main(int argc, char **argv)
{
	QString colortheme = getValue("colortheme");

	qDebug() << "THEME: " + colortheme;

	if(colortheme != "")
	{
		qputenv("CASCADES_THEME", colortheme.toUtf8());
	}

	qRegisterMetaType<bb::pim::message::MessageUpdate>();
	qmlRegisterType<ContactPicker>("bb.cascades.pickers", 1, 0, "ContactPicker");

    Application app(argc, argv);
    new ApplicationUI(&app);
    return Application::exec();
}
