#ifndef REALTIMEPLOT_H
#define REALTIMEPLOT_H

#include <QWidget>
#include "qcustomplot.h"
#include "axistag.h"

namespace Ui {
class realtimeplot;
}

class realtimeplot : public QWidget
{
    Q_OBJECT

public:
    explicit realtimeplot(QWidget *parent = nullptr);
    ~realtimeplot();
private slots:
  void timerSlot();

private:
    Ui::realtimeplot *ui;
    QCustomPlot *mPlot;
    QPointer<QCPGraph> mGraph1;
    QPointer<QCPGraph> mGraph2;
    AxisTag *mTag1;
    AxisTag *mTag2;
    QTimer mDataTimer;

};

#endif // REALTIMEPLOT_H
