#include <QApplication>
#include <QMainWindow>
#include <QFile>
#include <QTextStream>

#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(QCoreApplication::applicationDirPath() + "/../../darktheme.css");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream ts(&file);
        a.setStyleSheet(ts.readAll());
    } else {
        qWarning("Tyylitiedoston lataaminen epäonnistui.");
    }



    MainWindow w;
    w.resize(250, 150);
    //QLabel *infoLabel = new QLabel(&w);
    //infoLabel->setText("2024 Mika Nokka");
    //QFont font("Arial", 8);
    //infoLabel->setFont(font);
    //infoLabel->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    //infoLabel->setGeometry(0, w.height() - 30, w.width(), 30);
    w.show();
    return a.exec();
}
