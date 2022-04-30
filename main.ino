/**
 *
 * @file main.ino
 * @author your name (you@domain.com)
 * @brief
 * @version 1.0
 * @date 2022-04-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#define BLINKER_WIFI
#include <Blinker.h>
#include <L293D.h>
#include <SR04.h>
#include <bCtrl.h>

#define _int64 long long

/* ----- 初始化端口  ----- */
#define buzzerPin 1
#define ledPin    13

/* ----- 初始化SR04 ----- */

SR04* uls = new SR04(9, 8);

/* ----- 初始化Blinker账户密码 ----- */

char* auth = "";  // 双引号里把*换成blinker.app上的key
char* ssid = "";  // 链接Wi-Fi或手机热点名称
char* pswd = "";  // Wi-Fi密码

/* ----- 其他初始化 ----- */

int car_speed = 114;  // 车速初始化

void setup()
{
    /* ----- 初始化串口 ----- */

    Serial.begin(9600);    
    pinMode( ledPin , OUTPUT );
    pinMode( buzzerPin , OUTPUT );
    /*
        预留的电机串口空位
    */

    /* ----- 初始化Blinker ----- */

    Blinker.begin(auth, ssid, pswd);  // WIFI设置
    Blinker.attachData(dataRead);     //提示
    speed.attach(sudu_callback);      //速度组件
    car1.attach(car1_callback);       //前进组件
    car2.attach(car2_callback);       //后退组件
    car3.attach(car3_callback);       //左转组件
    car4.attach(car4_callback);       //右转组件

    /* ----- 初始化L293D ----- */

    void L293D(_Lfront, _Rfront, _Lrear, _Rrear);

    Serial.print("The car setups correctly\n");
}

_int64 loop_cnt = 1;

void loop()
{
    // 输出循环计数
    Serial.print("loop counter: ");
    Serial.print(loop_cnt++);
    Serial.print('\n');

    // Serial.println( "*****DEBUG*****" ) ;

    float _distance = uls->getDistance() ;

    if (isnan(_distance))
    {
        BLINKER_LOG("回音测距传感器错误!");
        Serial.print("回音测距传感器错误!\n");
    }
    else {
        dis_read = _distance;  // 将传感器探测到的距离数据传递给Blinker
    }


    car_speed = speed_callback() ;

    // 距离过进自动报警
    if( _distance < 30.00 )
        digitalWrite( buzzerPin , HIGH ) ;
    else
        digitalWrite( buzzerPin , LOW ) ;

