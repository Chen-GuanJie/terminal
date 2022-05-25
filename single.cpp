#include "ui_single.h"
#include "mainwindow.h"
#include "single.h"

single::single(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::single)
{
    ui->setupUi(this);
    ui->sdoubleSpinBox->setFocusPolicy(Qt::StrongFocus);
    ui->sdoubleSpinBox->setFocus();
    ui->sdoubleSpinBox->installEventFilter(this);
    ui->singlelineEdit->setFocusPolicy(Qt::StrongFocus);
    ui->singlelineEdit->setFocus();
    ui->singlelineEdit->installEventFilter(this);
    ui->doubleSpinBox_2->setFocusPolicy(Qt::StrongFocus);
    ui->doubleSpinBox_2->setFocus();
    ui->doubleSpinBox_2->installEventFilter(this);
    ui->sdoubleSpinBox->setFocusPolicy(Qt::StrongFocus);
    ui->sdoubleSpinBox->setFocus();
    ui->sdoubleSpinBox->installEventFilter(this);


}

single::~single()
{
    delete ui;
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
    ui->horizontalSlider->setValue(sd->mp[id-1].mid_angle);
    ui->singlelineEdit->setText(QString::number( sd->mp[id-1].mid_angle));
    ui->customplot->set_data_source(&(this->sdata->mp[id-1].tx_angle));
}


void single::on_singleButto_setd_clicked()
{
    sdata->set_b(ui->sdoubleSpinBox->value(),id-1);
    QString q="参数d：";
    q.append(QString::number(ui->sdoubleSpinBox->value()));
    ui->label_2->setText(q);
}

void single::on_singlebuttuon_clicked()
{
    QString t=ui->singlelineEdit->text();
        if(sdata->able_to_send){
            sdata->able_to_send=false;
            uint8_t *tosend =new uint8_t[10];
            sdata->moveOne(tosend,(uint8_t)id,(uint16_t)t.toInt());
            serial->write((const char*)tosend,10);
            //delete [] tosend;
        }
}
int  single::eventhandler(QEvent *event){
    if(event->type()==QEvent::KeyPress){
        QKeyEvent *k=static_cast<QKeyEvent*>(event);
        if(k->key()==Qt::Key_Return){
            return 1;
        }
    }
    return 0;
}


bool single::eventFilter(QObject *target,QEvent *event){
    if(target==ui->sdoubleSpinBox){
        switch (eventhandler(event)) {
            case 1:
                on_singleButto_setd_clicked();
                break;
        default:
            break;
        }
    }else if(target==ui->singlelineEdit){
        switch (eventhandler(event)) {
            case 1:
                on_singlebuttuon_clicked();
            break;
    default:
            break;
        }
    }else if(target==ui->sdoubleSpinBox){
        switch (eventhandler(event)) {
            case 1:
                on_singlebuttuon_clicked();
            break;
    default:
            break;
        }
    }else if(target==ui->doubleSpinBox_2){
        switch (eventhandler(event)) {
            case 1:
                on_singlebuttuon_clicked();
            break;
    default:
            break;
        }

    }
    return QWidget::eventFilter(target,event);
}


void single::on_horizontalSlider_valueChanged(int value)
{
    sdata->set_tx_angle((uint16_t)value,id-1);
    ui->singlelineEdit->setText( QString::number(value, 10));
    if(sdata->able_to_send){
        sdata->able_to_send=false;
        uint8_t *tosend =new uint8_t[10];
        sdata->moveOne(tosend,(uint8_t)id,(uint16_t)value);
        serial->write((const char*)tosend,10);
        //delete [] tosend;
    }
}

void single::on_horizontalSlider_2_valueChanged(int value)
{
    for (int i=0;i<sdata->moto_num;i++){
        if(sdata->group[id-1]==sdata->group[i]){
            sdata->magnify[i]=(double)value/100;
        }
    }
    ui->doubleSpinBox_2->setValue(sdata->magnify[id-1]);
    ui->doubleSpinBox_2->repaint();
}

void single::on_pushButton_clicked()
{
    if(sdata->able_to_send){
        sdata->able_to_send=false;
        sdata->set_tx_angle(sdata->mp[id-1].mid_angle,id);
        uint8_t *tosend =new uint8_t[10];
        sdata->moveOne(tosend,(uint8_t)id,(uint16_t)sdata->mp[id-1].mid_angle,500);
        serial->write((const char*)tosend,10);
        //delete [] tosend;
    }
}

void single::on_checkBox_enable_stateChanged(int arg1)
{
    if(arg1 == 2)
    {
        sdata->enable[id-1]=1;
    }
    else if(arg1 == 0)
    {
        sdata->enable[id-1]=0;
    }

}
void  single::reset_check(Qt::CheckState cs){
    ui->checkBox_enable->setCheckState(cs);
}
