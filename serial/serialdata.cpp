#include "serialdata.h"
serialdata::serialdata(uint16_t num)
{
    mp=new moto_para[num];
    lobot=new LobotServo[num];
    for (uint8_t i=0;i<num;i++){
        lobot->ID=i+1;
    }
    moto_num=num;
}
serialdata::~serialdata(){

}
void serialdata::set_tx_angle(uint16_t tx_angle,uint8_t num){
    if(num>0&&num<moto_num){
        mp[num-1].tx_angle=tx_angle;
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

void serialdata::enable_send(){
    able_to_send=true;
}
void serialdata::set_sendTime(uint16_t time){
    send_time=time;
}


