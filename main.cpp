#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
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
