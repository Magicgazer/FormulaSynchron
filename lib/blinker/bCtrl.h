/**
 * @file bCtrl.h
 * @author Dlerk
 * @brief Blinker控制模块
 * @version 1.0
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Blinker.h>
#define BLINKER_WIFI

class bCtrl
{
    private:
        char _auth[10] = "\0" ;   //双引号里把*换成blinker.app上的key
        char _ssid[10] = "\0" ;  //链接Wi-Fi或手机热点名称
        char _pswd[10] = "\0" ;  //Wi-Fi密码

        
        
    public:
        // 创建Blinker模块对象
        BlinkerNumber dist=BlinkerNumber("dist") ;        //距离
        BlinkerButton car1=BlinkerButton("btn-up");       //前进
        BlinkerButton car2=BlinkerButton("btn-down");     //后退
        BlinkerButton car3=BlinkerButton("btn-left");     //左转
        BlinkerButton car4=BlinkerButton("btn-right");    //右转
        BlinkerSlider speed=BlinkerSlider("speed") ;      //速度

        //bCtrl() {} ;


        
        bCtrl( char auth[] , char ssid[] , char pswd[] ) ;
        ~bCtrl() ;
        int speed_callback(int32_t value) ;
        void car1_callback(const String & state) ;
        void car2_callback(const String & state) ;
        void car3_callback(const String & state) ;
        void car4_callback(const String & state) ;
        void dataRead(const String & data) ;

        

};

