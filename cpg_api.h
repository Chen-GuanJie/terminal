#pragma once
#include <iostream>
#include "matlab/CPG2C.h"


class cpg_api
{
public:
    cpg_api();
	~cpg_api();
    void run(const double dv[], double tspan);
	bool test();
    double* step_data;
    double* step_time_data;
    int step(int time);
private:
    coder::array<double, 2U> angle;
    coder::array<double, 1U> t;
    double time_now=0;
    int index=0;
    int data_size;
};
