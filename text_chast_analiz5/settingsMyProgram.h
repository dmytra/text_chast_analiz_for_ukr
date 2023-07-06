#pragma once

#include <QWidget>
#include <QSettings>

class settingsMyProgram : public QWidget {
Q_OBJECT

private:
    QSettings  m_settings;
    int        m_nCounter;

public:
    settingsMyProgram(QWidget* pwgt = 0);
    virtual ~settingsMyProgram();

    void writeSettings();
    void readSettings ();

};
