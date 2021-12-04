#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QByteArray myarray;
//    myarray.resize(3);
//    myarray[0] = 0xf4;
//    myarray[1] = 0x4;
//    myarray[2] = 0xff;
//    char *str = myarray.data();
//    for(int i = 0; i < 3;i++){
//        qDebug() << "myarray" << i << ": " << uint16_t(*(str+i));
//    }

    QByteArray array = "FF0100000001FFFE";//source code
    QString chstr;
    bool bStatus = false;
    uint8_t mych[8];
    for(int i = 0; i < array.size()/2;i++){
        chstr = QString(array.mid(i*2,2));
        mych[i] = chstr.toUInt(&bStatus,16);
        qDebug() << "mych" << i << "): " << mych[i];
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
