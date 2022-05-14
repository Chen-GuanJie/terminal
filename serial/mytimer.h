#ifndef MYTIMER_H
#define MYTIMER_H
#include "serialdata.h"
#include "qcustomplot.h"
#include "qobject.h"

#define _MYTIMER_H

#include <QObject>

class myTimer : public QObject
{
    Q_OBJECT

public:
    myTimer(QObject* parent = NULL,serialdata *sd=NULL,QCustomPlot* cp=NULL);
    ~myTimer();
    void  handleTimeout();  //超时处理函数
    void reset_time(unsigned int time);

    virtual void timerEvent( QTimerEvent *event);
private:
    int m_nTimerID;
    void *time_callback;
    serialdata* sdata;
    QCustomPlot *customplot;
};


#endif // MYTIMER_H
