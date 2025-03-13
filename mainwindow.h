#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QString>
#include <QRandomGenerator>
#include <QChar>
#include <QDebug>
#include <QtWidgets>
#include <QMenuBar>
#include <QMenu>
#include <QClipboard>
#include <QLabel>
#include <QFont>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMenu *aboutMenu;
    QAction *aboutAct;
    void createMenus();
    QString generatePassword(int);
    void setPasswordLength(void);
    void OkButtonClicked(void);
    void Clockgenerate(void);
    void resizeEvent(QResizeEvent *event) override;  // Lisää tämä rivi
    int lenght=12;
    QSpinBox *spinBox;
    QDialog *dialog;
    QPushButton *okButton;
    QTimer *timer;
    QLabel *passwordLabel;
    QLabel *passwordLabel2;
    QString passwordlen;
    QLabel *infoLabel;

private slots:
    void generate();

};
#endif // MAINWINDOW_H
