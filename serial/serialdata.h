#ifndef SERIALDATA_H
#define SERIALDATA_H

#include "servo.h"

typedef struct moto_para_t{
    uint8_t id;
    uint16_t tx_angle;
    uint16_t tx_time;
    uint16_t rx_angle;
    uint16_t rx_time;
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
    void decode_msg();
    void enable_send();
    void set_sendTime(uint16_t time);
    bool able_to_send;
    uint8_t moto_num;
    moto_para *mp;

private:
    LobotServo *lobot;
    uint16_t send_time;
    uint8_t* rx_data;
};

#endif // SERIALDATA_H
