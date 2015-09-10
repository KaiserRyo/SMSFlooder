#include "Settings.hpp"
#include <QSettings>

const QString Settings::AUTHOR = "Nemory Development Studios";
const QString Settings::APPNAME = "SMS Flooder";

Settings::Settings()
{

}

QString Settings::getValueFor(const QString &objectName, const QString &defaultValue)
{
    QSettings settings(AUTHOR, APPNAME);
    // If no value has been saved, return the default value.
    if (settings.value(objectName).isNull())
    {
        return defaultValue;
    }

    // Otherwise, return the value stored in the settings object.
    return settings.value(objectName).toString();
}
void Settings::saveValueFor(const QString &objectName, const QString &inputValue)
{
    // A new value is saved to the application settings object.
    QSettings settings(AUTHOR, APPNAME);
    settings.setValue(objectName, QVariant(inputValue));
}
Settings::~Settings()
{

}
