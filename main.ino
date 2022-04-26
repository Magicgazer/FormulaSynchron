/**
 * 
 * @file main.ino
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#define BLINKER_WIFI
#include <SR04.h>
#include <bCtrl.h>

#define buzzerPin = 1 ;

const int ledPin = 13 ;

SR04* uls = new SR04(9,8) ;

//bCtrl Ctl = bCtrl( "\0" , "\0" , "\0" ) ;

void setup()
{
    
    Serial.begin(9600) ;    
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