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

#ifndef SR04_H
#define SR04_H
#include "Arduino.h"

class SR04 {
private:
    int trigPin;
    int echoPin;

public:
    SR04(int trigPin, int echoPin);  //初始化SR04
    ~SR04();                         //析构函数，删除SR04类并释放内存

    float getDistance();  //将传感器返回值计算成实际距离（cm）
};

#endif
