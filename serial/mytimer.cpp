#include "mytimer.h"
#include<QDebug>
#include <QTimerEvent>

#define TIMER_TIMEOUT	100

myTimer::myTimer(QObject *parent,serialdata* sd,QCustomPlot* cp)
    :QObject(parent)
{
    m_nTimerID = this->startTimer(TIMER_TIMEOUT);
    sdata=sd;
    customplot=cp;
}

myTimer::~myTimer()
{

}

void myTimer::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
        if(customplot!=NULL){
        customplot->replot();
}else if(sdata!=NULL){        sdata->enable_send();}
    }
}

void myTimer::handleTimeout()
{
    qDebug()<<"Enter timeout processing function\n";
    killTimer(m_nTimerID);
}
void myTimer::reset_time(unsigned int time){
    this->killTimer(m_nTimerID);
    m_nTimerID=this->startTimer(time);
}
