#ifndef MYTIMER_H
#define MYTIMER_H
#include <qcustomplot.h>

#include "qobject.h"

#define _MYTIMER_H

#include <QObject>

class plotTimer : public QObject
{
    Q_OBJECT

public:
    plotTimer(QObject* parent = NULL,    QCustomPlot *customplot=NULL);
    ~plotTimer();
    void  handleTimeout();  //超时处理函数
    virtual void timerEvent( QTimerEvent *event);
    void reset_time(unsigned int time);
private:
    int m_nTimerID;
    QCustomPlot *customplot;
};


#endif // MYTIMER_H
