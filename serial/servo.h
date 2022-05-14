#ifndef SERVO_H
#define SERVO_H
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
#define FRAME_HEADER 0x55             //帧头
#define CMD_SERVO_MOVE 0x03           //舵机移动指令
#define CMD_ACTION_GROUP_RUN 0x06     //运行动作组指令
#define CMD_ACTION_GROUP_STOP 0x07    //停止动作组指令
#define CMD_ACTION_GROUP_SPEED 0x0B   //设置动作组运行速度
#define CMD_GET_BATTERY_VOLTAGE 0x0F  //获取电池电压指令
typedef struct _lobot_servo_ {  //舵机ID,舵机目标位置
    uint8_t ID;
    uint16_t Position;
} LobotServo;

void moveServo(uint8_t* LobotTxBuf,uint8_t servoID, uint16_t Position, uint16_t Time);
void moveServosByArray(uint8_t* LobotTxBuf,LobotServo servos[], uint8_t Num, uint16_t Time);

#endif // SETTINGSDIALOG_H
