#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : portList)
        qDebug() <<"the port name:"<< port.portName();



    //扫描可用串口，，添加到字符数组中
//    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
//        QSerialPort serial;
//        serial.setPort(info);
//        if(serial.open(QIODevice::ReadWrite)){
//            ui->searchCombo->addItem(serial.portName());

//            serial.close();
//        }
//    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

