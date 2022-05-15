#include "serialdata.h"
#include "math.h"

serialdata::serialdata(uint16_t num)
{
    mp=new moto_para[num];
    lobot=new LobotServo[num];
    b=new double[num];
    magnify=new double[num];
    group=new uint8_t[num];
    enable=new uint8_t[num];
    for (uint8_t i=0;i<num;i++){
        lobot[i].ID=i+1;
        mp[i].id=i+1;
        b[i]=1;
        magnify[i]=1;
        group[i]=1;
        enable[i]=1;
    }
    moto_num=num;
    uint16_t mid[18]={805,685,500,535,480,535,590,350,535,225,400,280,120,520,265,805,490,345};
    this->set_mid_angle(mid);
}
serialdata::~serialdata(){
    delete []  mp;
   delete []lobot;
    delete []b;
    delete []magnify;
}
void serialdata::set_tx_angle(uint16_t tx_angle,uint8_t num){
    if(num>=0&&num<moto_num){
        mp[num].tx_angle=tx_angle;
        lobot[num].Position=tx_angle;
    }
}
void serialdata::set_tx_time(uint16_t tx_time,uint8_t num){
    if(num>0&&num<moto_num){
        mp[num-1].tx_time=tx_time;
    }
}
uint16_t serialdata::get_rx_angle(uint8_t num){
    if(num>0&&num<moto_num){
        return mp[num].rx_angle;
    }
    return  0;
}
uint16_t serialdata::get_rx_time(uint8_t num){
    if(num>0&&num<moto_num){
        return mp[num].rx_time;
    }
    return 0;
}
uint16_t* serialdata::get_all_angle(){
    uint16_t* angle=new uint16_t[this->moto_num];
    for (uint8_t i=0;i<moto_num;i++){
        angle[i]=mp[i].rx_angle;
    }
    return angle;
}
uint16_t* serialdata::get_all_time(){
    uint16_t* time=new uint16_t[this->moto_num];
    for (uint8_t i=0;i<moto_num;i++){
        time[i]=mp[i].rx_time;
    }
    return time;
}

void serialdata::moveServos(uint8_t* retval){
        moveServosByArray(retval,lobot,moto_num,send_time);
}
void serialdata::moveOne(uint8_t* retval,uint8_t id,uint16_t tx_angle){
        mp[id-1].tx_angle=tx_angle;
        moveServo(retval,id,tx_angle,this->send_time);
}
void serialdata::moveOne(uint8_t* retval,uint8_t id,uint16_t tx_angle,uint16_t tx_time){
        mp[id-1].tx_angle=tx_angle;
        moveServo(retval,id,tx_angle,tx_time);
}

void serialdata::enable_send(){
    able_to_send=true;
}
void serialdata::set_sendTime(uint16_t time){
    send_time=time;
}
void serialdata::update_para(uint16_t* input_angle,uint16_t* input_time)
{
    for (int i=0;i<18;i++)
    {
        mp[i].tx_angle=input_angle[i];
        mp[i].tx_time=input_time[i];
        lobot->Position=input_angle[i];
    }
}
#include <iostream>
void serialdata::update_para(double* input_angle,double* input_time)
{

    for (int i=0;i<18;i++)
    {
        if(enable[i]){
            mp[i].tx_angle=mp[i].mid_angle+(uint16_t)round(magnify[i]*input_angle[i]);
            mp[i].tx_time=(uint16_t)round(*input_time);
            lobot[i].Position=mp[i].tx_angle;
            set_sendTime(mp[i].tx_time);
        }
        //std::cout<<lobot[i].Position<<' ';
    }//std::cout<<std::endl;
    //std::cout<<mp[0].tx_time<<std::endl;

}
void serialdata::set_mid_angle(uint16_t* mids){
    for(int i=0;i<18;i++){
        mp[i].mid_angle=mids[i];
    }
}

void serialdata::set_b(double bx,int id){
    b[id]=bx;
}
void serialdata::runactiongroup(uint8_t* LobotTxBuf,uint8_t numOfAction, uint16_t Times){
    runActionGroup(LobotTxBuf,numOfAction,Times);
}
void serialdata::stopactiongroup(uint8_t* LobotTxBuf){
    stopActionGroup(LobotTxBuf);
}
