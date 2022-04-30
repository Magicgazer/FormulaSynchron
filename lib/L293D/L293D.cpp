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

namespace motor{
    short leftSpeed_ = 0;   // 左侧速度
    short rightSpeed_ = 0;  // 右侧速度
    short tolSpeed_ = 0;    // 总速度
    bool direction = true;     // 方向 true = 正向
    AF_DCMotor Lfront_(1);
    AF_DCMotor Rfront_(2);
    AF_DCMotor Lrear_(3);
    AF_DCMotor Rrear_(4);
    void correctSpeed() {
        leftSpeed_ = tolSpeed_;
        rightSpeed_ = tolSpeed_;
    }
    void setDirection() {
        if (direction) {
            Lfront_.run(FORWARD);
            Rfront_.run(FORWARD);
            Lrear_.run(FORWARD);
            Rrear_.run(FORWARD);
        } else {
            Lfront_.run(BACKWARD);
            Rfront_.run(BACKWARD);
            Lrear_.run(BACKWARD);
            Rrear_.run(BACKWARD);
        }
    }
    void setTolSpeed() {
        Lfront_.setSpeed(tolSpeed_);
        Rfront_.setSpeed(tolSpeed_);
        Lrear_.setSpeed(tolSpeed_);
        Rrear_.setSpeed(tolSpeed_);
    }
    void setLeftSpeed() {
        Lfront_.setSpeed(leftSpeed_);
        Lrear_.setSpeed(leftSpeed_);
    }
    void setRightSpeed() {
        Rfront_.setSpeed(rightSpeed_);
        Rrear_.setSpeed(rightSpeed_);
    }
}

void L293D(const short Lfront,
           const short Rfront,
           const short Lrear,
           const short Rrear) {
    motor::Lfront_ = AF_DCMotor(Lfront);
    motor::Rfront_ = AF_DCMotor(Rfront);
    motor::Lfront_ = AF_DCMotor(Rfront);
    motor::Rrear_ = AF_DCMotor(Lrear);
    motor::direction = true;
    motor::tolSpeed_ = 0;
    motor::setDirection();
    motor::setTolSpeed();
    motor::correctSpeed();
}

void upSpeed(const short variable) {
    for (short i = 1; i <= variable && motor::tolSpeed_ <= 255; i++) {
        motor::tolSpeed_++;
        motor::setTolSpeed();
    }
    motor::correctSpeed();
}

void downSpeed(const short variable) {
    for (short i = 1; i <= variable && motor::tolSpeed_ >= 0; i++) {
        motor::tolSpeed_--;
        motor::setTolSpeed();
    }
    motor::correctSpeed();
}

void setSpeed(const short speed) {
    if (speed < 0)
        return;
    if (motor::tolSpeed_ > speed) {
        while (motor::tolSpeed_ > speed && motor::tolSpeed_) {
            motor::tolSpeed_--;
            motor::setTolSpeed();
        }
    } else {
        while (motor::tolSpeed_ < speed) {
            motor::tolSpeed_++;
            motor::setTolSpeed();
        }
    }
    motor::correctSpeed();
}

void carStop() {
    motor::tolSpeed_ = 0;
    motor::setTolSpeed();
    motor::correctSpeed();
}

void brake() {
    return;
}

void straight() {
    motor::direction = true;
    motor::setDirection();
    if (motor::leftSpeed_ < motor::tolSpeed_) {
        while (motor::leftSpeed_ < motor::tolSpeed_) {
            motor::leftSpeed_++;
            motor::setLeftSpeed();
        }
    } else if (motor::rightSpeed_ < motor::tolSpeed_) {
        while (motor::rightSpeed_ < motor::tolSpeed_) {
            motor::rightSpeed_++;
            motor::setRightSpeed;
        }
    }
    motor::correctSpeed();
}

void turnLeft() {
    straight();
    motor::leftSpeed_ = motor::tolSpeed_ / 2;
    motor::setLeftSpeed();
}

void turnRight() {
    straight();
    motor::rightSpeed_ = motor::tolSpeed_ / 2;
    motor::setLeftSpeed();
}

void turnRound() {
    const short temp = motor::tolSpeed_;
    setSpeed(0);
    if (motor::direction) {
        motor::Lfront_.run(BACKWARD);
        motor::Rfront_.run(FORWARD);
        motor::Lrear_.run(BACKWARD);
        motor::Rrear_.run(FORWARD);
    } else {
        motor::Lfront_.run(FORWARD);
        motor::Rfront_.run(BACKWARD);
        motor::Lrear_.run(FORWARD);
        motor::Rrear_.run(BACKWARD);
    }
    setSpeed(temp);
}

void backup() {
    motor::direction = false;
    motor::setDirection();
}