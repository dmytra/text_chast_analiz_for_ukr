#include <QtWidgets>
#include "settingsMyProgram.h"
#include <QDebug>

settingsMyProgram::settingsMyProgram(QWidget* pwgt/*=0*/)
    : QWidget(pwgt) 
    , m_settings("BHV","settingsMyProgram")
{
    readSettings();
}

/*virtual*/settingsMyProgram::~settingsMyProgram()
{
    writeSettings();
}

void settingsMyProgram::readSettings()
{
    m_settings.beginGroup("/Settings");
    int     nWidth     = m_settings.value("/width", width()).toInt();
    int     nHeight    = m_settings.value("/height", height()).toInt();
    m_nCounter = m_settings.value("/counter", 1).toInt();
    QString str = QString().setNum(m_nCounter++);
    resize(nWidth, nHeight);
    qDebug() << "read"<<  m_nCounter << width() << height();
    m_settings.endGroup();
}

void settingsMyProgram::writeSettings()
{
    m_settings.beginGroup("/Settings");
    m_settings.setValue("/counter", m_nCounter);
    qDebug() << "write" << m_nCounter << width() << height();
    m_settings.setValue("/width", width());
    m_settings.setValue("/height", height());
    m_settings.endGroup();
}
