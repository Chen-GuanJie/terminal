#ifndef SERIALDATA_H
#define SERIALDATA_H

#include "servo.h"

typedef struct moto_para_t{
    uint8_t id;
    uint16_t tx_angle=500;
    uint16_t tx_time=500;
    uint16_t rx_angle=500;
    uint16_t rx_time=500;
    uint16_t mid_angle=500;

} moto_para;

class serialdata
{
public:
    serialdata(uint16_t num);
    ~serialdata();
    void set_tx_angle(uint16_t tx_angle,uint8_t num);
    void set_tx_time(uint16_t tx_time,uint8_t num);
    uint16_t get_rx_angle(uint8_t num);
    uint16_t get_rx_time(uint8_t num);
    uint16_t* get_all_angle();
    uint16_t* get_all_time();
    void moveServos(uint8_t* retval);
    void moveOne(uint8_t* retval,uint8_t id,uint16_t tx_angle);
    void moveOne(uint8_t* retval,uint8_t id,uint16_t tx_angle,uint16_t tx_time);
    void decode_msg();
    void enable_send();
    void set_sendTime(uint16_t time);
    bool able_to_send;
    uint8_t moto_num=18;
    void update_para(uint16_t* input_angle,uint16_t* input_time);
    void update_para(double* input_angle,double* input_time);
    moto_para *mp;
    void set_b(double bx,int id);
    void set_mid_angle(uint16_t* mids);
    double* b;
    double* magnify;
    double t=1;
    uint8_t *group;
    uint8_t *enable;
    void runactiongroup(uint8_t* LobotTxBuf,uint8_t numOfAction, uint16_t Times);
    void stopactiongroup(uint8_t* LobotTxBuf);
private:
    LobotServo *lobot;
    uint16_t send_time=500;
    uint8_t* rx_data;

};

#endif // SERIALDATA_H
