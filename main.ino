/**
 * @file main.ino
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
 * @file main.ino
 * @author Dlerk
 * @brief 
 * @version 1.0
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define BLINKER_WIFI
#include <SR04.h>
#include <string>
using std::string ;

#define buzzerPin = 1 ;

string str = "AAADDDDFFFG"  ;

const int ledPin = 13 ;

const char* SSID = "" ;
const char* PSWD = "" ;

SR04* uls = new SR04(9,8) ;

void setup()
{
    
    Serial.begin(9600) ;    //初始化串口比特率
    pinMode( ledPin, OUTPUT ) ;

}

void loop()
{
    
    //Serial.println( "*****DEBUG*****" ) ;

    float distance = uls->getDistance() ;

    Serial.print( "Distance is : " ) ;
    Serial.print( distance ) ;
    Serial.print( " cm\n" ) ;

    delay(1000) ;

}