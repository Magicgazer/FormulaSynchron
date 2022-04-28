/**
 * @file L293D.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "L293D.h"

#include <AFMotor.h>

L293D::L293D() {
    direction = true;
    tolSpeed_ = 0;
    setDirection();
    set_tolSpeed();
    correctSpeed();
}

L293D::L293D(const short Lfront,
             const short Rfront,
             const short Lrear,
             const short Rrear) {
    Lfront_ = AF_DCMotor(Lfront);
    Rfront_ = AF_DCMotor(Rfront);
    Lfront_ = AF_DCMotor(Rfront);
    Rrear_ = AF_DCMotor(Lrear);
    direction = true;
    tolSpeed_ = 0;
    setDirection();
    set_tolSpeed();
    correctSpeed();
}

void L293D::upSpeed(const short variable) {
    for (short i = 1; i <= variable && tolSpeed_ <= 255; i++) {
        tolSpeed_++;
        set_tolSpeed();
    }
    correctSpeed();
}

void L293D::downSpeed(const short variable) {
    for (short i = 1; i <= variable && tolSpeed_ >= 0; i++) {
        tolSpeed_--;
        set_tolSpeed();
    }
    correctSpeed();
}

void L293D::setSpeed(const short speed) {
    if (speed < 0)
        return;
    if (tolSpeed_ > speed) {
        while (tolSpeed_ > speed && tolSpeed_) {
            tolSpeed_--;
            set_tolSpeed();
        }
    } else {
        while (tolSpeed_ < speed) {
            tolSpeed_++;
            set_tolSpeed();
        }
    }
    correctSpeed();
}

void L293D::stop() {
    tolSpeed_ = 0;
    set_tolSpeed();
    correctSpeed();
}

void L293D::brake() {
    return;
}

void L293D::straight() {
    setDirection();
    if (leftSpeed_ < tolSpeed_) {
        while (leftSpeed_ < tolSpeed_) {
            leftSpeed_++;
            set_leftSpeed();
        }
    } else if (rightSpeed_ < tolSpeed_) {
        while (rightSpeed_ < tolSpeed_) {
            rightSpeed_++;
            set_rightSpeed;
        }
    }
    correctSpeed();
}

void L293D::turnLeft() {
    straight();
    leftSpeed_ = tolSpeed_ / 2;
    set_leftSpeed();
}

void L293D::turnRight() {
    straight();
    rightSpeed_ = tolSpeed_ / 2;
    set_leftSpeed();
}

void L293D::turnRound() {
    const short temp = tolSpeed_;
    setSpeed(0);
    if (direction) {
        Lfront_.run(BACKWARD);
        Rfront_.run(FORWARD);
        Lrear_.run(BACKWARD);
        Rrear_.run(FORWARD);
    } else {
        Lfront_.run(FORWARD);
        Rfront_.run(BACKWARD);
        Lrear_.run(FORWARD);
        Rrear_.run(BACKWARD);
    }
    setSpeed(temp);
}

void L293D::reverse() {
    if(direction){
        direction = false;
        setDirection();
    }
    else{
        direction = true;
        setDirection();
    }
}