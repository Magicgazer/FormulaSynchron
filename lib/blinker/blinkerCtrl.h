/**
 * @file blinkerCtrl.h
 * @author Dlerk_
 * @brief blinker方法的库文档
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Blinker.h>
#include <L293D.h>
#define BLINKER_WIFI

// 创建Blinker模块对象
    BlinkerNumber dis=BlinkerNumber("dis") ;        //距离
    BlinkerButton car1=BlinkerButton("btn-up");       //前进
    BlinkerButton car2=BlinkerButton("btn-down");     //后退
    BlinkerButton car3=BlinkerButton("btn-left");     //左转
    BlinkerButton car4=BlinkerButton("btn-right");    //右转
    BlinkerSlider speed=BlinkerSlider("speed") ;      //速度

/**
 * @brief 从APP获取小车速度
 * 
 * @param value 从滑块读取的小车速度值
 * @return int 从App读取并转换后的速度值
 */
int speed_callback(int32_t value) ;

/**
 * @brief 自动减速刹车
 * 
 * @param distance 测距传感器读到的距离
 */
void autoBrake ( double distance ， const int globalspeed  ) ;

/**
 * @brief 小车控制函数以及报错函数
 * 
 * @param state  从APP上读取的按键状态
 */
void car1_callback(const String & state) ;  // 前进
void car2_callback(const String & state) ;  // 后退
void car3_callback(const String & state) ;  // 左转
void car4_callback(const String & state) ;  // 右转
void dataRead(const String & data) ;    // 未绑定的组件被触发时报错



/* ----- 下面为函数的具体实现 ----- */

void bCtrl::dataRead(const String & data)
{
    BLINKER_LOG( "Blinker readString: " , data ) ;
}

int bCtrl::speed_callback(int32_t value)
{
    return (100+value*30) ;
}

void bCtrl::car1_callback(const String & state)
{
    if( state == "press" )
    {
        straight() ;    // 前行
    }
    else if( state == "pressup" )
    {
        car_stop() ;
    }
}

void bCtrl::car2_callback(const String & state)
{
    if( state == "press" )
    {
        reverse() ;    // 后退
    }
    else if( state == "pressup" )
    {
        car_stop() ;
    }
}

void bCtrl::car3_callback(const String & state)
{
    if( state == "press" )
    {
        turnLeft() ;  // 左转
    }
    else if( state == "pressup" )
    {
        car_stop() ;
    }
}

void bCtrl::car4_callback(const String & state)
{
    if( state == "press" )
    {
        turnRight() ;   // 右转
    }
    else if( state == "pressup" )
    {
        car_stop() ;
    }
}

void autoBrake ( double distance , const int globalspeed ) ;
{

    if ( distance < 30 )
    {
        downSpeed( 100 ) ;   // 距离 < 30cm 时自动减速到100
    }
    else
    {
        upSpeed( globalspeed ) ;   // 正常距离范围时，恢复到全局速度
    }
    
}


