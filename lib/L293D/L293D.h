/**
 * @file L293D.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-04-20
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _L293D_H_
#define _L293D_H_

#include <Arduino.h>
#include <stdio.h>

#include "AFMotor.h"

class L293D {
private:
    short left_speed_;
    short right_speed_;
    short tol_speed_;
    bool direction;
    AF_DCMotor Lfront_;
    AF_DCMotor Rfront_;
    AF_DCMotor Lrear_;
    AF_DCMotor Rrear_;
    void set_tol() {
        left_speed_ = tol_speed_;
        right_speed_ = tol_speed_;
    }
    void set_tol_speed(){
        Lfront_.setSpeed(tol_speed_);
        Rfront_.setSpeed(tol_speed_);
        Lrear_.setSpeed(tol_speed_);
        Rrear_.setSpeed(tol_speed_);
    }
    void set_left_speed(){
        Lfront_.setSpeed(left_speed_);
        Lrear_.setSpeed(left_speed_);
    }
    void set_right_speed(){
        Rfront_.setSpeed(right_speed_);
        Rrear_.setSpeed(right_speed_);
    }

public:
    L293D();
    L293D(const short Lfront,
          const short Rfront,
          const short Lrear,
          const short Rrear);
    void upSpeed(const short variable);
    void downSpeed(const short variable);
    void setSpeed(const short tol_speed);
    void stop();       //熄火
    void turnLeft();   //左转
    void turnRight();  //右转
    void turnRound();  //原地掉头
    void reverse();    //挂倒挡
};

#endif