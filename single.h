#ifndef SINGLE_H
#define SINGLE_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include "serial/serialdata.h"
#include "serial/mytimer.h"
QT_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui {
class single;
}
QT_END_NAMESPACE
class single : public QWidget
{
    Q_OBJECT

public:
    explicit single(QWidget *parent = nullptr);
    ~single();
    void set_serial_port(QSerialPort *s,uint8_t id,serialdata* sd);
    void  reset_check(Qt::CheckState cs);
protected:
    bool eventFilter(QObject *target,QEvent *event);
private slots:


    int  eventhandler(QEvent *event);
    void on_singleButto_setd_clicked();

    void on_singlebuttuon_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_clicked();


    void on_checkBox_enable_stateChanged(int arg1);

private:
    Ui::single *ui;
    QSerialPort *serial;
    bool checkBox_state;
    uint8_t id;
    serialdata* sdata;
    myTimer* tmr;
};


#endif // SINGLE_H
