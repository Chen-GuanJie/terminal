// dllmain.cpp : 定义 DLL 应用程序的入口点。

#include "cpg_api.h"
cpg_api::cpg_api()
{
    step_data=new double(18);
    step_time_data=new double(1);
}

cpg_api::~cpg_api()
{
}

void cpg_api::run(const double dv[], double tspan )
{
    //coder::array<double, 2U> angle;
    //coder::array<double, 1U> t;
    CPG2C(dv, tspan, t,angle);
    time_now=0;
    index=0;
    data_size=*t.size();
    /*int i = 0;
    for (auto it = t.begin(); it != t.end(); it++, i++) {

    }
    i = 0;
	for (auto it = angle.begin(); it != angle.end(); it++, i++) {
        std::cout << *it << " ";
    }*/
}
int cpg_api::step(int time){
    time_now+=time;
    auto it_t=t.begin();
    auto it_angle=angle.begin();
    int old=index;
    while (time_now>(double)*(it_t+index+1)*1000)
    {
        index=index+1;//index 当前时间
    }
    if(old!=index)
    {
        if(data_size>index)
        {
            for(int i=0;i<18;i++)
            {
                step_data[i]=1000*(double)*(it_angle+i*data_size+index+1)/360;//next angle
                //std::cout<<step_data[i]<<' ';
            }
            //std::cout<<std::endl;
            *step_time_data=((double)*(it_t+index+1)-(double)*(it_t+index))*1000;//time err ms
            //std::cout<<*step_time_data<<' ';
        }else{
            return 2;
        }
        return 1;
    }
    return  0;
}


