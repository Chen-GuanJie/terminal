#include "plottimer.h"
#include<QDebug>
#include <QTimerEvent>

#define TIMER_TIMEOUT	(5*100)

plotTimer::plotTimer(QObject *parent,QCustomPlot *cp)
    :QObject(parent)
{
    m_nTimerID = this->startTimer(TIMER_TIMEOUT);
    customplot=cp;
}

plotTimer::~plotTimer()
{

}

void plotTimer::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_nTimerID){
        customplot->replot();
    }
}

void plotTimer::handleTimeout()
{
    qDebug()<<"Enter timeout processing function\n";
    killTimer(m_nTimerID);
}
void plotTimer::reset_time(unsigned int time){
    this->killTimer(m_nTimerID);
    m_nTimerID=this->startTimer(time);
}
