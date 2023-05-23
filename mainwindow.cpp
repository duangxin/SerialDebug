#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    //扫描可用串口，，添加到字符数组中
//    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
//        QSerialPort serial;
//        serial.setPort(info);
//        if(serial.open(QIODevice::ReadWrite)){
//            ui->searchCombo->addItem(serial.portName());

//            serial.close();
//        }
//    }
    ui->searchCombo->addItem("/dev/pts/3");
    ui->searchCombo->addItem("/dev/pts/4");


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ctrlSerialButton_clicked()
{
    //文本显示“打开串口”，进行打开操作
    if(ui->ctrlSerialButton->text() == "打开串口"){
        if(ui->searchCombo->currentText() == ""){   //没搜索到串口
            ui->stateLabel->setText("无可用串口");
            return;
        }
        m_serial = new QSerialPort;
        m_serial->setPortName(ui->searchCombo->currentText());//设置端口
        m_serial->open(QIODevice::ReadWrite);//以读写权限打开
        m_serial->setBaudRate(ui->baudCombo->currentText().toInt()); //设置波特率
        //校验位
        switch(ui->checkCombo->currentIndex()){
        case 0:
            m_serial->setParity(QSerialPort::NoParity);
            break;
        case 1:
            m_serial->setParity(QSerialPort::OddParity);
            break;
        case 2:
            m_serial->setParity(QSerialPort::EvenParity);
            break;
        default:
            break;
        }
        //数据位
        switch(ui->dataCombo->currentText().toInt()){
        case 5:
            m_serial->setDataBits(QSerialPort::Data5);
            break;
        case 6:
            m_serial->setDataBits(QSerialPort::Data6);
            break;
        case 7:
            m_serial->setDataBits(QSerialPort::Data7);
            break;
        case 8:
            m_serial->setDataBits(QSerialPort::Data8);
            break;
        default:
            break;
        }
        //停止位
        switch(ui->stopCombo->currentIndex()){
        case 0:
            m_serial->setStopBits(QSerialPort::OneStop);
            break;
        case 1:
            m_serial->setStopBits(QSerialPort::OneAndHalfStop);
            break;
        case 2:
            m_serial->setStopBits(QSerialPort::TwoStop);
            break;
        default:
            break;
        }

        ui->searchCombo->setEnabled(false);
        ui->baudCombo->setEnabled(false);
        ui->checkCombo->setEnabled(false);
        ui->dataCombo->setEnabled(false);
        ui->stopCombo->setEnabled(false);
        ui->ctrlSerialButton->setText("关闭串口");
        ui->stateLabel->setText("串口已打开");

        //接收数据
    }else{//关闭串口
        if(m_serial->isOpen())
            m_serial->close();

        ui->searchCombo->setEnabled(true);
        ui->baudCombo->setEnabled(true);
        ui->checkCombo->setEnabled(true);
        ui->dataCombo->setEnabled(true);
        ui->stopCombo->setEnabled(true);
        ui->ctrlSerialButton->setText("打开串口");
        ui->stateLabel->setText("串口已关闭");
    }
}

