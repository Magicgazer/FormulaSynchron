/**
 * @file bCtrl.h
 * @author Dlerk
 * @brief Blinker控制模块
 * @version 1.0
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Blinker.h>
#include <String.h>
#define BLINKER_WIFI

class bCtrl
{
private:
    string* auth = "***" ;   //双引号里把*换成blinker.app上的key
    char ssid[10] = "\0\0\0\0\0\0\0\0\0" ;  //链接Wi-Fi或手机热点名称
    char pswd[10] = "\0\0\0\0\0\0\0\0\0" ;  //Wi-Fi密码

    // 创建Blinker模块对象
    BlinkerNumber Dist("dist") ;        //距离
    BlinkerButton Car1("btn-up");       //前进
    BlinkerButton Car2("btn-down");     //后退
    BlinkerButton Car3("btn-left");     //左转
    BlinkerButton Car4("btn-right");    //右转
    BlinkerSlider Speed("speed") ;      //速度
    
public:
    bCtrl( char SSID[] , char PSWD[] ) ;
    ~bCtrl() ;

};

