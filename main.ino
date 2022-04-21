/**
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
#include <Blinker.h>
#include <SR04.h>
#include <AFMotor.h>

#define buzzerPin = 1;
#define ledPin    = 13;

const char* SSID = "";
const char* PSWD = "";

// 初始化电动机对象
AF_DCMotor Lfront(1);
AF_DCMotor Rfront(2);
AF_DCMotor Lrear(3);
AF_DCMotor Rrear(4);

void setup() {
    // put your setup code here, to run once:
}

void loop() {
    // put your main code here, to run repeatedly:
}