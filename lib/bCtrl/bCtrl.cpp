/**
 * @file bCtrl.cpp
 * @author Dlerk
 * @brief bCrtl的实现文档
 * @version 0.1
 * @date 2022-04-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "bCtrl.h"

#include <Blinker.h>
#include <string.h>

bCtrl::bCtrl(char auth[], char ssid[], char pswd[]) {
    strcpy(_auth, auth);
    strcpy(_ssid, ssid);
    strcpy(_pswd, pswd);

    // 初始化Blinker
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);
    speed.attach(speed_callback);  //速度组件
    car1.attach(car1_callback);    //前进组件
    car2.attach(car2_callback);    //后退组件
    car3.attach(car3_callback);    //左转组件
    car4.attach(car4_callback);    //右转组件

    Serial.println(" bCtrl is initialized ");
}

bCtrl::~bCtrl() {
    Serial.println("bCtrl is deleted");
}

void bCtrl::dataRead(const String& data) {
    BLINKER_LOG("Blinker readString: ", data);
}

int bCtrl::speed_callback(int32_t value) {
    return (100 + value * 30);
}

void bCtrl::car1_callback(const String& state) {
    if (state == "press") {
        // 前行
    } else if (state == "pressup") {
    }
}

void bCtrl::car2_callback(const String& state) {
    if (state == "press") {
        // 后退
    } else if (state == "pressup") {
    }
}

void bCtrl::car3_callback(const String& state) {
    if (state == "press") {
        // 左转
    } else if (state == "pressup") {
    }
}

void bCtrl::car4_callback(const String& state) {
    if (state == "press") {
        // 右转
    } else if (state == "pressup") {
    }
}
