#include "servo.h"
#define GET_LOW_BYTE(A) ((uint8_t)(A))
//宏函数 获得A的低八位
#define GET_HIGH_BYTE(A) ((uint8_t)((A) >> 8))
//宏函数 获得A的高八位

/*********************************************************************************
 * Function:  moveServo
 * Description： 控制单个舵机转动
 * Parameters:   sevoID:舵机ID，Position:目标位置,Time:转动时间
                    舵机ID取值:0<=舵机ID<=31,Time取值: Time > 0
 * Return:       无返回
 * Others:
 **********************************************************************************/
void moveServo(uint8_t* LobotTxBuf,uint8_t servoID, uint16_t Position, uint16_t Time)
{
    if(Time<=0){
        Time=1;
    }
    if (servoID > 31 || !(Time > 0)) {  //舵机ID不能打于31,可根据对应控制板修改
        return;
    }
    LobotTxBuf[0] = LobotTxBuf[1] = FRAME_HEADER;    //填充帧头
    LobotTxBuf[2] = 8;
    LobotTxBuf[3] = CMD_SERVO_MOVE;           //数据长度=要控制舵机数*3+5，此处=1*3+5//填充舵机移动指令
    LobotTxBuf[4] = 1;                        //要控制的舵机个数
    LobotTxBuf[5] = GET_LOW_BYTE(Time);       //取得时间的低八位
    LobotTxBuf[6] = GET_HIGH_BYTE(Time);      //取得时间的高八位
    LobotTxBuf[7] = servoID;                  //舵机ID
    LobotTxBuf[8] = GET_LOW_BYTE(Position);   //取得目标位置的低八位
    LobotTxBuf[9] = GET_HIGH_BYTE(Position);  //取得目标位置的高八位
    LobotTxBuf[10]=0x00;
}

/*********************************************************************************
 * Function:  moveServosByArray
 * Description： 控制多个舵机转动
 * Parameters:   servos[]:舵机结体数组，Num:舵机个数,Time:转动时间
                    0 < Num <= 32,Time > 0
 * Return:       无返回
 * Others:
 **********************************************************************************/
void moveServosByArray(uint8_t* LobotTxBuf,LobotServo servos[], uint8_t Num, uint16_t Time)
{
    uint8_t index = 7;
    uint8_t i = 0;
    LobotTxBuf =new uint8_t[7+3*Num];
    if (Num < 1 || Num > 32 || !(Time > 0)) {
        return;                                          //舵机数不能为零和大与32，时间不能为零
    }
    LobotTxBuf[0] = LobotTxBuf[1] = FRAME_HEADER;      //填充帧头
    LobotTxBuf[2] = Num * 3 + 5;                       //数据长度 = 要控制舵机数*3+5
    LobotTxBuf[3] = CMD_SERVO_MOVE;                    //填充舵机移动指令
    LobotTxBuf[4] = Num;                               //要控制的舵机个数
    LobotTxBuf[5] = GET_LOW_BYTE(Time);                //取得时间的低八位
    LobotTxBuf[6] = GET_HIGH_BYTE(Time);               //取得时间的高八位

    for (i = 0; i < Num; i++) {                        //循环填充舵机ID和对应目标位置
        LobotTxBuf[index++] = servos[i].ID;              //填充舵机ID
        LobotTxBuf[index++] = GET_LOW_BYTE(servos[i].Position); //填充目标位置低八位
        LobotTxBuf[index++] = GET_HIGH_BYTE(servos[i].Position);//填充目标位置高八位
    }

}




