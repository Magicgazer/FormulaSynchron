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
    short left_speed_;   // 左侧速度
    short right_speed_;  // 右侧速度
    short tol_speed_;    // 总速度
    bool direction;      // 方向 true = 正向
    AF_DCMotor Lfront_;
    AF_DCMotor Rfront_;
    AF_DCMotor Lrear_;
    AF_DCMotor Rrear_;
    // 速度修正
    void correct() {
        left_speed_ = tol_speed_;
        right_speed_ = tol_speed_;
    }
    // 更改总速度
    void set_tol_speed() {
        Lfront_.setSpeed(tol_speed_);
        Rfront_.setSpeed(tol_speed_);
        Lrear_.setSpeed(tol_speed_);
        Rrear_.setSpeed(tol_speed_);
    }
    // 更改左侧速度
    void set_left_speed() {
        Lfront_.setSpeed(left_speed_);
        Lrear_.setSpeed(left_speed_);
    }
    // 更改右侧速度
    void set_right_speed() {
        Rfront_.setSpeed(right_speed_);
        Rrear_.setSpeed(right_speed_);
    }

public:
    L293D();
    /**
     * @brief Construct a new L293D object
     *
     * @param Lfront 左前轮电机端口号
     * @param Rfront 右前轮电机端口号
     * @param Lrear 左后轮电机端口号
     * @param Rrear 右后轮电机端口号
     */
    L293D(const short Lfront,
          const short Rfront,
          const short Lrear,
          const short Rrear);
    /**
     * @brief 提高指定量速度
     *
     * @param variable 变化量
     */
    void upSpeed(const short variable);
    /**
     * @brief 减少指定量速度
     *
     * @param variable 变化量
     */
    void downSpeed(const short variable);
    /**
     * @brief 重新设定速度
     *
     * @param tol_speed 需设定的速度值
     */
    void setSpeed(const short tol_speed);
    // 熄火
    void stop();
    /**
     * @brief 刹车
     * @deprecated 太难写了
     */
    void brake();
    // 左转
    void turnLeft();
    // 右转
    void turnRight();
    // 原地掉头
    void turnRound();
    // 挂倒挡
    void reverse();
};

#endif