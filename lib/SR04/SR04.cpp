/**
 * @file SR04.h
 * @author Dlerk
 * @brief 
 * @version 1.0
 * @date 2022-04-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Arduino.h"
#include "SR04.h"

void SR04::SR04 ( int tP , int eP ) 
{
    pinMode(trigPin, OUTPUT) ;
    pinMode(echoPin, INPUT) ;
    trigPin = tP ;
    echoPin = eP ;
}

float SR04::getDistance ()
{
    digitalWrite( trigPin, LOW ) ;
    delayMicroseconds(2) ;
    digitalWrite( trigPin, HIGH ) ;
    delayMicroseconds(10) ;
    digitalWrite( trigPin, LOW ) ;
    float distance = pulseln( echoPin, HIGH ) / 58.0 ;
    return distance ;
}

SR04::~SR04()
{
    Serial.println( "SR04 is deleted" ) ;
}