/****************************************************************************
**
** Copyright (C) 2012 Denis Shienkov <denis.shienkov@gmail.com>
** Copyright (C) 2012 Laszlo Papp <lpapp@kde.org>
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialPort module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "console.h"
#include "settingsdialog.h"

#include <QMessageBox>
#include <QLabel>
#include <QtSerialPort/QSerialPort>
#include "serial/serialdata.h"
//! [0]
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//! [0]
    ui->setupUi(this);
//    console = new Console;
 //   console->setEnabled(false);
   // setCentralWidget(console);
//! [1]
    serial = new QSerialPort(this);
//! [1]
    settings = new SettingsDialog;
    cpg = new cpg_api();
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionQuit->setEnabled(true);
    ui->actionConfigure->setEnabled(true);

    status = new QLabel;
    ui->statusBar->addWidget(status);

    initActionsConnections();

    sd=new serialdata(18);

    timer=new myTimer(NULL,sd);
     ui->single_1->set_serial_port(serial,1,sd);
     ui->single_2->set_serial_port(serial,2,sd);
     ui->single_3->set_serial_port(serial,3,sd);
     ui->single_4->set_serial_port(serial,4,sd);
     ui->single_5->set_serial_port(serial,5,sd);
     ui->single_6->set_serial_port(serial,6,sd);
     ui->single_7->set_serial_port(serial,7,sd);
     ui->single_8->set_serial_port(serial,8,sd);
     ui->single_9->set_serial_port(serial,9,sd);
     ui->single_10->set_serial_port(serial,10,sd);
     ui->single_11->set_serial_port(serial,11,sd);
     ui->single_12->set_serial_port(serial,12,sd);
     ui->single_13->set_serial_port(serial,13,sd);
     ui->single_14->set_serial_port(serial,14,sd);
     ui->single_15->set_serial_port(serial,15,sd);
     ui->single_16->set_serial_port(serial,16,sd);
     ui->single_17->set_serial_port(serial,17,sd);
     ui->single_18->set_serial_port(serial,18,sd);
     QStringList strList;
     strList<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8";
    ui->comboBoxx_1->addItems(strList);
    ui->comboBoxx_2->addItems(strList);
    ui->comboBoxx_3->addItems(strList);
    ui->comboBoxx_4->addItems(strList);
    ui->comboBoxx_5->addItems(strList);
    ui->comboBoxx_6->addItems(strList);
    ui->comboBoxx_7->addItems(strList);
    ui->comboBoxx_8->addItems(strList);
    ui->comboBoxx_9->addItems(strList);
    ui->comboBoxx_10->addItems(strList);
    ui->comboBoxx_11->addItems(strList);
    ui->comboBoxx_12->addItems(strList);
    ui->comboBoxx_13->addItems(strList);
    ui->comboBoxx_14->addItems(strList);
    ui->comboBoxx_15->addItems(strList);
    ui->comboBoxx_16->addItems(strList);
    ui->comboBoxx_17->addItems(strList);
    ui->comboBoxx_18->addItems(strList);

    ui->comboBoxx_1->setCurrentIndex(0);
    ui->comboBoxx_2->setCurrentIndex(0);
    ui->comboBoxx_3->setCurrentIndex(0);
    ui->comboBoxx_4->setCurrentIndex(0);
    ui->comboBoxx_5->setCurrentIndex(0);
    ui->comboBoxx_6->setCurrentIndex(0);

    ui->comboBoxx_7->setCurrentIndex(1);
    ui->comboBoxx_8->setCurrentIndex(1);
    ui->comboBoxx_9->setCurrentIndex(1);
    ui->comboBoxx_10->setCurrentIndex(1);
    ui->comboBoxx_11->setCurrentIndex(2);
    ui->comboBoxx_12->setCurrentIndex(2);
    ui->comboBoxx_13->setCurrentIndex(2);
    ui->comboBoxx_14->setCurrentIndex(2);
    ui->comboBoxx_15->setCurrentIndex(3);
    ui->comboBoxx_16->setCurrentIndex(3);
    ui->comboBoxx_17->setCurrentIndex(3);
    ui->comboBoxx_18->setCurrentIndex(3);
on_pushButton_7_clicked();
    connect(serial, static_cast<void (QSerialPort::*)(QSerialPort::SerialPortError)>(&QSerialPort::error),
            this, &MainWindow::handleError);

//! [2]
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//! [2]
    //connect(console, &Console::getData, this, &MainWindow::writeData);
//! [3]
}
//! [3]

MainWindow::~MainWindow()
{
    delete settings;
    delete ui;
}

//! [4]
void MainWindow::openSerialPort()
{
    SettingsDialog::Settings p = settings->settings();
    serial->setPortName(p.name);
    serial->setBaudRate(p.baudRate);
    serial->setDataBits(p.dataBits);
    serial->setParity(p.parity);
    serial->setStopBits(p.stopBits);
    serial->setFlowControl(p.flowControl);
    if (serial->open(QIODevice::ReadWrite)) {
        //console->setEnabled(true);
  //      console->setLocalEchoEnabled(p.localEchoEnabled);
        ui->actionConnect->setEnabled(false);
        ui->actionDisconnect->setEnabled(true);
        ui->actionConfigure->setEnabled(false);
        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                          .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}
//! [4]

//! [5]
void MainWindow::closeSerialPort()
{
    if (serial->isOpen())
        serial->close();
  //  console->setEnabled(false);
    ui->actionConnect->setEnabled(true);
    ui->actionDisconnect->setEnabled(false);
    ui->actionConfigure->setEnabled(true);
    showStatusMessage(tr("Disconnected"));
}
//! [5]

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

//! [6]
void MainWindow::writeData(const QByteArray &data)
{
    serial->write(data);
}
//! [6]

//! [7]
void MainWindow::readData()
{
    QByteArray data = serial->readAll();
    ui->textBrowser->setText(data);
 //   console->putData(data);
}
//! [7]

//! [8]
void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), serial->errorString());
        closeSerialPort();
    }
}
//! [8]

void MainWindow::initActionsConnections()
{
    connect(ui->actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(ui->actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
    connect(ui->actionConfigure, &QAction::triggered, settings, &SettingsDialog::show);
  //  connect(ui->actionClear, &QAction::triggered, console, &Console::clear);
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
    connect(ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::showStatusMessage(const QString &message)
{
    status->setText(message);
}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
    if(sd->able_to_send){
        sd->able_to_send=false;
        uint8_t *tosend =new uint8_t[7+3*sd->moto_num];
        for (int i=0;i<sd->moto_num;i++){
            sd->set_tx_angle(sd->mp[i].mid_angle,(uint8_t)i);
        }
        sd->set_sendTime(500);
        sd->moveServos(tosend);
        serial->write((const char*)tosend,7+3*sd->moto_num);
        //delete []tosend;
    }
}
#include "cpg_api.h"
void MainWindow::on_pushButton_5_clicked()
{
    //const double dv[18]=sd->b;
    cpg_send = new uint8_t[7+3*sd->moto_num];
    cpg->run(sd->b,sd->t);
    cpgTimer = new QTimer();
    connect(this->cpgTimer, SIGNAL(timeout()), this, SLOT(cpgtimerSlot()));
    cpgTimer->start(cpg_pird);
}

void MainWindow::cpgtimerSlot(){
    switch(cpg->step(cpg_pird)){
        case 0:
            break;
        case 1:
            /*for (int i=0;i<sd->moto_num;i++){
                sd->set_tx_angle((uint16_t)round(sd->mp[i+1].mid_angle+cpg_data_ptr[i]*1000/360),(uint8_t)i+1);
            }
            for (int i=0;i<sd->moto_num;i++){
                std::cout<<cpg_data_ptr[i]<<' ';
            }
            std::cout<<std::endl;*/

            sd->update_para(cpg->step_data,cpg->step_time_data);
            sd->moveServos(cpg_send);
            serial->write((const char*)cpg_send,7+3*sd->moto_num);
            break;
        case 2:
            cpgTimer->stop();
            delete [] cpg_send;
            break;
    }
}

void MainWindow::on_pushButton_pressed(){

}

void MainWindow::on_pushButton_3_clicked()
{
    cpgTimer->stop();
    delete [] cpg_send;
}

void MainWindow::on_pushButton_7_clicked()
{
    sd->group[0] = ui->comboBoxx_1->currentIndex();//获得索引
    sd->group[1] = ui->comboBoxx_2->currentIndex();//获得索引
    sd->group[2] = ui->comboBoxx_3->currentIndex();//获得索引
    sd->group[3] = ui->comboBoxx_4->currentIndex();//获得索引
    sd->group[4] = ui->comboBoxx_5->currentIndex();//获得索引
    sd->group[5] = ui->comboBoxx_6->currentIndex();//获得索引
    sd->group[6] = ui->comboBoxx_7->currentIndex();//获得索引
    sd->group[7] = ui->comboBoxx_8->currentIndex();//获得索引
    sd->group[8] = ui->comboBoxx_9->currentIndex();//获得索引
    sd->group[9] = ui->comboBoxx_10->currentIndex();//获得索引
    sd->group[10] = ui->comboBoxx_11->currentIndex();//获得索引
    sd->group[11] = ui->comboBoxx_12->currentIndex();//获得索引
    sd->group[12] = ui->comboBoxx_13->currentIndex();//获得索引
    sd->group[13] = ui->comboBoxx_14->currentIndex();//获得索引
    sd->group[14] = ui->comboBoxx_15->currentIndex();//获得索引
    sd->group[15] = ui->comboBoxx_16->currentIndex();//获得索引
    sd->group[16] = ui->comboBoxx_17->currentIndex();//获得索引
    sd->group[17] = ui->comboBoxx_18->currentIndex();//获得索引
}

void MainWindow::on_pushButton_t_clicked()
{
    QString s="周期:";
    sd->t=ui->lineEdit_3->text().toDouble();
    ui->label->setText(s.append(QString::number(sd->t)));

}

void MainWindow::on_pushButton_2_clicked(bool checked)
{
    Qt::CheckState cs=Qt::Checked;

        if(checked)
        {
            for (int i=0;i<sd->moto_num;i++) {
                sd->enable[i]=1;
            }

        }
        else
        {   cs=Qt::Unchecked;
            for (int i=0;i<sd->moto_num;i++) {
                sd->enable[i]=1;
            }
        }
        ui->single_1->reset_check(cs);
        ui->single_2->reset_check(cs);
        ui->single_3->reset_check(cs);
        ui->single_4->reset_check(cs);
        ui->single_5->reset_check(cs);
        ui->single_6->reset_check(cs);
        ui->single_7->reset_check(cs);
        ui->single_8->reset_check(cs);
        ui->single_9->reset_check(cs);
        ui->single_10->reset_check(cs);
        ui->single_11->reset_check(cs);
        ui->single_12->reset_check(cs);
        ui->single_13->reset_check(cs);
        ui->single_14->reset_check(cs);
        ui->single_15->reset_check(cs);
        ui->single_16->reset_check(cs);
        ui->single_17->reset_check(cs);
        ui->single_18->reset_check(cs);


}

void MainWindow::on_cpushButton_9_clicked()
{
    QString t= ui->clineEdit_6->text();
    try {
        sd->set_sendTime((uint16_t)t.toInt());
    } catch (_exception) {
        return;
    }
    QString a="设置为：";
    a.append(t);
    ui->clineEdit_6->setText(a);
}

void MainWindow::on_cpushButton_8_clicked()
{
    QString t= ui->clineEdit_5->text();
    try {
        cpg_pird=(uint16_t)t.toInt();
    } catch (_exception) {
        QString a="err";
        return;
    }
    QString a="设置为：";
    a.append(t);
    ui->clineEdit_5->setText(a);
}

void MainWindow::on_cpushButton_settime_clicked()
{
    QString t= ui->clineEdit_4->text();
    try {
        timer->reset_time((uint16_t)t.toInt());
    } catch (_exception) {
        QString a="err";
        return;
    }
    QString a="设置为：";
    a.append(t);
    ui->clineEdit_4->setText(a);

}

void MainWindow::on_pushButton_dz_clicked()
{
    if(sd->able_to_send){
        sd->able_to_send=false;
        uint8_t *tosend =new uint8_t[7];
        sd->runactiongroup(tosend,ui->spinBox_dz3->value(),ui->spinBox_dz->value());
        serial->write((const char*)tosend,7);
        delete []tosend;
    }
}

void MainWindow::on_pushButton_dz2_clicked()
{

}

void MainWindow::on_pushButton_dz3_clicked()
{
    if(sd->able_to_send){
        sd->able_to_send=false;
        uint8_t *tosend =new uint8_t[4];
        sd->stopactiongroup(tosend);
        serial->write((const char*)tosend,4);
        delete []tosend;
    }
}
