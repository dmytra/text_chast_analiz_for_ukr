#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtWidgets>
#include <QDebug>

QT_USE_NAMESPACE

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
        //QLabel * lblTextObject = new QLabel("insert text to FILD:");
        insertTextObjectButton = new QPushButton(tr("insert text to FILD and get STAT"));
        //QLabel * lblFileObject = new QLabel("for STAT text file:");
        insertFileObjectButton = new QPushButton(tr("Open text file for STAT:"));

        QLabel * lbl = new QLabel("<b>ЧАСТОТНИЙ АНАЛИЗ</b> (тільки українські букви)!");
        QHBoxLayout *bottomLayoutL1 = new QHBoxLayout;
        QHBoxLayout *bottomLayoutL2 = new QHBoxLayout;
        //bottomLayoutL1->addWidget(lblTextObject);
        bottomLayoutL2->addWidget(insertTextObjectButton);
        //bottomLayoutL1->addWidget(lblFileObject);
        bottomLayoutL2->addWidget(insertFileObjectButton);

        textEdit = new QTextEdit;        
        QVBoxLayout *mainLayout = new QVBoxLayout;

        mainLayout->addWidget(lbl);
        mainLayout->addLayout(bottomLayoutL1);
        mainLayout->addLayout(bottomLayoutL2);

        mainLayout->addWidget(textEdit);

        connect(insertTextObjectButton, SIGNAL(clicked()),
                this, SLOT(insertTextObject()));

        connect(insertFileObjectButton, SIGNAL(clicked()),
                this, SLOT(insertFileObject()));

        insertSeries();
        mainLayout->addWidget(chartView);

        lblStatLabel = new QLabel("...");
        mainLayout->addWidget(lblStatLabel);

        setLayout(mainLayout);
}

void Widget::addFileDB()
{
        // #include <QFileDialog>

        QString fileName = QFileDialog::getOpenFileName(this, "Open File", "/", "Text Files (*.txt);;All Files (*.*)");
        if (!fileName.isEmpty()) {
            // do something with the selected file
        }

        QFile file(fileName);
        file.open(QIODevice::ReadOnly | QIODevice::Text);

        for(int i= 0; i < 33; i++) alphabet[i] = 0;

        if(file.exists())
        {
            int i= 1;
            textEdit->clear();
            textEdit->setPlainText("");
            while (!file.atEnd()) {
                QString line = file.readLine();
                textEdit->insertPlainText(line);

                if (line != "\n")
                {
                    for (int j = 0; j < line.size(); j++ ) {
                        switch (line[j].unicode())
                        {
                        case    0x0410:     //'А':
                            alphabet[0]++;
                            break;
                        case 	0x0411:     //'Б':
                            alphabet[1]++;
                            break;
                        case    0x0412:     //'В':
                            alphabet[2]++;
                            break;
                        case    0x0413:     //'Г':
                            alphabet[3]++;
                            break;
                        case    0x0490:     //'Ґ':
                            alphabet[4]++;
                            break;
                        case    0x0414:     //'Д':
                            alphabet[5]++;
                            break;
                        case    0x0415:     //'Е':
                            alphabet[6]++;
                            break;
                            //                case    0x0401:     //'Ё':
                            //                    alphabet[6]++;
                            //                    break;
                        case    0x0404:     //'Є':
                            alphabet[7]++;
                            break;
                        case    0x0416:     //'Ж':
                            alphabet[8]++;
                            break;
                        case    0x0417:     //'З':
                            alphabet[9]++;
                            break;
                        case    0x0418:     //'И':
                            alphabet[10]++;
                            break;
                        case    0x0406:     //'І':
                            alphabet[11]++;;
                            break;
                        case    0x0407:     //'Ї':
                            alphabet[12]++;
                            break;
                        case    0x0419:     //'Й':
                            alphabet[13]++;
                            break;
                        case    0x041A:     //'К':
                            alphabet[14]++;
                            break;
                        case    0x041B:     //'Л':
                            alphabet[15]++;
                            break;
                        case    0x041C:     //'М':
                            alphabet[16]++;
                            break;
                        case    0x041D:     //'Н':
                            alphabet[17]++;
                            break;
                        case    0x041E:     //'О':
                            alphabet[18]++;
                            break;
                        case    0x041F:     //'П':
                            alphabet[19]++;
                            break;
                        case    0x0420:     //'Р':
                            alphabet[20]++;
                            break;
                        case    0x0421:     //'С':
                            alphabet[21]++;
                            break;
                        case    0x0422:     //'Т':
                            alphabet[22]++;
                            break;
                        case    0x0423:     //'У':
                            alphabet[23]++;
                            break;
                        case    0x0424:     //'Ф':
                            alphabet[24]++;
                            break;
                        case    0x0425:     //'Х':
                            alphabet[25]++;
                            break;
                        case    0x0426:     //'Ц':
                            alphabet[26]++;
                            break;
                        case    0x0427:     //'Ч':
                            alphabet[27]++;
                            break;
                        case    0x0428:     //'Ш':
                            alphabet[28]++;
                            break;
                        case    0x0429:     //'Щ':
                            alphabet[29]++;
                            break;
                            //                case    0x042A:     //'Ъ':
                            //                    alphabet[27]++;
                            //                    break;
                            //                case    0x042B:     //'Ы':
                            //                    alphabet[28]++;
                            //                    break;
                        case    0x042C:     //'Ь':
                            alphabet[30]++;
                            break;
                            //                case    0x042D:     //'Э':
                            //                    alphabet[30]++;
                            //                    break;
                        case    0x042E:     //'Ю':
                            alphabet[31]++;
                            break;
                        case    0x042F:     //'Я':
                            alphabet[32]++;
                            break;
                            //                case    0x040E:     //'Ў':
                            //                    alphabet[17]++;
                            //                    break;
                            //                case    0x040B:    //'Ћ':
                            //                    alphabet[17]++;
                            //                    break;

                        default:
                            break;
                        }
                    }
                    i++;
                }
            }
        }
        file.close();
}

void Widget::addTextDB()
{
        for(int i= 0; i < 33; i++) alphabet[i] = 0;

        QString line = textEdit->toPlainText();
        line = line.toUpper();
        qDebug() << line;

    for (int j = 0; j < line.size(); j++ ) {
            qDebug() << line[j].unicode();
        switch (line[j].unicode())
        {
        case    0x0410:     //'А':
            alphabet[0]++;
            break;
        case 	0x0411:     //'Б':
            alphabet[1]++;
            break;
        case    0x0412:     //'В':
            alphabet[2]++;
            break;
        case    0x0413:     //'Г':
            alphabet[3]++;
            break;
        case    0x0490:     //'Ґ':
            alphabet[4]++;
            break;
        case    0x0414:     //'Д':
            alphabet[5]++;
            break;
        case    0x0415:     //'Е':
            alphabet[6]++;
            break;
            //                case    0x0401:     //'Ё':
            //                    alphabet[6]++;
            //                    break;
        case    0x0404:     //'Є':
            alphabet[7]++;
            break;
        case    0x0416:     //'Ж':
            alphabet[8]++;
            break;
        case    0x0417:     //'З':
            alphabet[9]++;
            break;
        case    0x0418:     //'И':
            alphabet[10]++;
            break;
        case    0x0406:     //'І':
            alphabet[11]++;;
            break;
        case    0x0407:     //'Ї':
            alphabet[12]++;
            break;
        case    0x0419:     //'Й':
            alphabet[13]++;
            break;
        case    0x041A:     //'К':
            alphabet[14]++;
            break;
        case    0x041B:     //'Л':
            alphabet[15]++;
            break;
        case    0x041C:     //'М':
            alphabet[16]++;
            break;
        case    0x041D:     //'Н':
            alphabet[17]++;
            break;
        case    0x041E:     //'О':
            alphabet[18]++;
            break;
        case    0x041F:     //'П':
            alphabet[19]++;
            break;
        case    0x0420:     //'Р':
            alphabet[20]++;
            break;
        case    0x0421:     //'С':
            alphabet[21]++;
            break;
        case    0x0422:     //'Т':
            alphabet[22]++;
            break;
        case    0x0423:     //'У':
            alphabet[23]++;
            break;
        case    0x0424:     //'Ф':
            alphabet[24]++;
            break;
        case    0x0425:     //'Х':
            alphabet[25]++;
            break;
        case    0x0426:     //'Ц':
            alphabet[26]++;
            break;
        case    0x0427:     //'Ч':
            alphabet[27]++;
            break;
        case    0x0428:     //'Ш':
            alphabet[28]++;
            break;
        case    0x0429:     //'Щ':
            alphabet[29]++;
            break;
            //                case    0x042A:     //'Ъ':
            //                    alphabet[27]++;
            //                    break;
            //                case    0x042B:     //'Ы':
            //                    alphabet[28]++;
            //                    break;
        case    0x042C:     //'Ь':
            alphabet[30]++;
            break;
            //                case    0x042D:     //'Э':
            //                    alphabet[30]++;
            //                    break;
        case    0x042E:     //'Ю':
            alphabet[31]++;
            break;
        case    0x042F:     //'Я':
            alphabet[32]++;
            break;
            //                case    0x040E:     //'Ў':
            //                    alphabet[17]++;
            //                    break;
            //                case    0x040B:    //'Ћ':
            //                    alphabet[17]++;
            //                    break;

        default:
            break;
        }
    }
}

void Widget::insertTextObject()
{
        addTextDB();
        chart->removeSeries(series); // https://stackoverflow.com/questions/39171173/qt-qcharts-add-and-remove-series
        series->clear();
        //textEdit
        for(int i=0; i<32; i++) {
            series->append(i, alphabet[i]);
        }
        chart->createDefaultAxes();
        chart->addSeries(series);
        insertStatLabel();
}

void Widget::insertFileObject()
{
        addFileDB();
        chart->removeSeries(series); // https://stackoverflow.com/questions/39171173/qt-qcharts-add-and-remove-series
        series->clear();
        //textEdit
        for(int i=0; i<32; i++) {
        series->append(i, alphabet[i]);
        }
        chart->createDefaultAxes();
        chart->addSeries(series);
        insertStatLabel();
}

void Widget::insertSeries()
{
        series = new QLineSeries();
        //    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
        chart = new QChart();
        chart->legend()->hide();
        series->append(0, 10);
        series->append(0, 0);
        series->append(32, 0);
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("0-32 відповідає : А Б В Г Ґ Д Е Є Ж З И І Ї Й К Л М Н О П Р С Т У Ф Х Ц Ч Ш Щ ь Ю Я");

        chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
}

void Widget::insertStatLabel()
{
        QString strStatLabel = "А\tБ\tВ\tГ\tҐ\tД\tЕ\tЄ\tЖ\tЗ\tИ\tІ\tЇ\tЙ\tК\tЛ\tМ\tН\tО\tП\tР\tС\tТ\tУ\tФ\tХ\tЦ\tЧ\tШ\tЩ\tь\tЮ\tЯ\n";
        for(int i=0; i < 32; i++) strStatLabel += QString::number(alphabet[i]) + "\t";
                               lblStatLabel->setText(strStatLabel);
        lblStatLabel->setStyleSheet( "font-size: 9pt;");
}

Widget::~Widget()
{
}

