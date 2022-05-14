// dllmain.cpp : 定义 DLL 应用程序的入口点。

#include "cpg_api.h"
#include "matlab/CPG2C.h"
cpg_api::cpg_api()
{
}

cpg_api::~cpg_api()
{
}

retval_t cpg_api::run(const double dv[], double tspan )
{
	coder::array<double, 2U> angle;
	coder::array<double, 1U> t;
	std::cout << "ssssss" << std::endl;

	CPG2C(dv, tspan, t, angle);
    retval_t rt;

    rt.t=new double[(size_t)t.size()];
    rt.angle=new double[(size_t)angle.size()];
    //memcpy(time, t.data(),(size_t) t.size());
    //memcpy(anglet, angle.data(),(size_t) angle.size());
    int i = 0;
	for (auto it = t.begin(); it != t.end(); it++, i++) {
        rt.t[i] = *it;
    }
    rt.t_size=i;
    i = 0;
	for (auto it = angle.begin(); it != angle.end(); it++, i++) {
        rt.angle[i] = *it;
		//std::cout << time[i] << " ";
    }
    rt.angle_size=i;
	std::cout << "sdfsdf" << std::endl;
    return  rt;
}


