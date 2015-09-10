#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_
#include <QObject>
class Settings: public QObject {
Q_OBJECT
public:
    Settings();
    virtual ~Settings();
Q_INVOKABLE
    QString getValueFor(const QString &objectName, const QString &defaultValue);
Q_INVOKABLE
    void saveValueFor(const QString &objectName, const QString &inputValue);

private:

	static const QString AUTHOR; // for creating settings
	static const QString APPNAME; // for creating settings
};
#endif
