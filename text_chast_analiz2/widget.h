#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QTextEdit;
class QLineSeries;
class QChart;
class QChartView;
class QLabel;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    int alphabet[33] = {0};
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QTextEdit   *textEdit;
    QPushButton *insertTextObjectButton;
    QPushButton *insertFileObjectButton;
    QLineSeries *series;
    QChart      *chart;
    QChartView  *chartView;
    QLabel * lblStatLabel;

private slots:
    void insertTextObject();
    void insertFileObject();
    void insertStatLabel();

private:
    void insertSeries();
    void addTextDB();
    void addFileDB();

};
#endif // WIDGET_H
