#include "mainwindow.h"
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QString password;
    password=generatePassword(lenght);
    qDebug() << password;
    fflush(stdout);
    createMenus();

    passwordLabel = new QLabel("Generated passwords will appear here.", this);
    passwordLabel->setAlignment(Qt::AlignCenter);

    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(passwordLabel);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    // Alalaitateksti
    infoLabel = new QLabel("2024 MNokka", this);
    infoLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(infoLabel);

    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
}


void MainWindow::resizeEvent(QResizeEvent *event)
{

    int newFontSize = event->size().height() / 20; // Säädä jakajaa tarpeen mukaan
    QFont font = infoLabel->font();
    font.setPointSize(newFontSize);
    passwordLabel->setFont(font);

    QMainWindow::resizeEvent(event);
}


MainWindow::~MainWindow() {
}

void MainWindow::createMenus()
{
    aboutMenu = menuBar()->addMenu(tr("&New password"));
    aboutAct = new QAction(tr("&Generate"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::generate);
    aboutMenu->addAction(aboutAct);

    aboutMenu = menuBar()->addMenu(tr("&Password lenght"));
    aboutAct = new QAction(tr("&Set"), this);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::setPasswordLength);
    aboutMenu->addAction(aboutAct);


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::Clockgenerate);
    timer->start(5000); // 10 000 ms = 10 sekuntia
}


void MainWindow::Clockgenerate(void)
{
    QString autopassword;
    passwordlen = QString::number(lenght);
    autopassword=generatePassword(lenght);
    qDebug() << "AUTOGEN " << autopassword;
    passwordLabel->setText("Generated password, lenght = " + passwordlen + "\n\n" + autopassword);
}


void MainWindow::generate()
{
    QString password;
    password=generatePassword(lenght);
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(password);

    QMessageBox::about(this, tr("Generated password"),
                       tr("\n") +password +("\n\nCopied to clipboard!"));
}


QString MainWindow::generatePassword(int lenght)
{

    QString characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZÅÄÖ"
                         "abcdefghijklmnopqrstuvwxyzåäö"
                         "0123456789"
                         "!@#$%^&*()_+-=[]{}|;:,.<>?";
    QString password;

    for (int i = 0; i < lenght; ++i)
    {
        int index = QRandomGenerator::global()->bounded(characters.size());
        password.append(characters.at(index));
    }
    return password;
}

void MainWindow::OkButtonClicked(void) {
    lenght= spinBox->value();
    //QString password = generatePassword(lenght);
    qDebug() << "Lenght" << lenght;
    dialog->accept();
}

void MainWindow::setPasswordLength(void) {
    dialog=new QDialog(this);
    dialog->setWindowTitle("Set length");

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    spinBox = new QSpinBox(dialog);
    spinBox->setRange(4, 64);
    spinBox->setValue(lenght);
    layout->addWidget(spinBox);

    QPushButton *okButton = new QPushButton("OK", dialog);
    layout->addWidget(okButton);

    dialog->setLayout(layout);

    connect(okButton, &QPushButton::clicked, this, &MainWindow::OkButtonClicked);
    dialog->exec();
}
