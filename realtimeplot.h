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
    void set_data_source(uint16_t* source);
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
    uint16_t* source;
    int* source_num;
    uint16_t last_data;
};

#endif // REALTIMEPLOT_H
