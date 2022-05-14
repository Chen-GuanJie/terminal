#include "ui_single.h"
#include "mainwindow.h"
#include "single.h"

single::single(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::single)
{
    ui->setupUi(this);
}

single::~single()
{
    delete ui;
}

void single::on_pushButton_clicked()
{

}

void single::on_horizontalSlider_sliderMoved(int position)
{
    const QString data = QString::number(position, 10);
    ui->singlelineEdit->setText(data);
    if(sdata->able_to_send){
        sdata->able_to_send=false;
        uint8_t *tosend =new uint8_t[10];
        sdata->moveOne(tosend,(uint8_t)id,(uint16_t)position);
        serial->write((const char*)tosend,10);

    }
}
void single::set_serial_port(QSerialPort *s,uint8_t id,serialdata* sd){
    serial=s;
    this->id=id;
    sdata=sd;
    QString str1 = "ID: ";
    QString str2=QString::number(id, 10);
    QString str3 = "输入值:";
    str1.append(str2);
    str1.append(str3);
    ui->label->setText(str1);

    //ui->customplot->set_data_source(&this->sdata->mp[id].tx_angle,);
    //ui->customplot->graph();
    //ui->customplot ->xAxis ->setLabel( "时间/ms");
    //ui->customplot ->yAxis ->setLabel( "角度/1000");
    //ui->customplot ->replot();
    //tmr=new myTimer(NULL,NULL,ui->customplot);
    //tmr->reset_time(20);
}
