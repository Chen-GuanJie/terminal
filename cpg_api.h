#pragma once
#include <iostream>

typedef struct retval_t{
    double* t;
    double*angle;
    int t_size;
    int angle_size;
}retval;
class cpg_api
{
public:
	cpg_api();
	~cpg_api();
    static retval_t run(const double dv[], double tspan);
	bool test();
};
