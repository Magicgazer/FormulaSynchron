#include "L293D.h"

#include <AFMotor.h>

L293D::L293D() {
    direction = true;
    tol_speed_ = 0;
    set_tol();
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
    tol_speed_ = 0;
    set_tol();
}

void L293D::upSpeed(const short variable) {
    for (short i = 1; i <= variable; i++) {
        tol_speed_++;
        set_tol_speed();
    }
}

void L293D::downSpeed(const short variable) {
    for (short i = 1; i <= variable; i++) {
        tol_speed_--;
        set_tol_speed();
    }
}

void L293D::setSpeed(const short speed) {
    if (tol_speed_ > speed) {
        for (; tol_speed_ > speed; tol_speed_--) {
            set_tol_speed();
        }
    } else {
        for (; tol_speed_ < speed; tol_speed_++) {
            set_tol_speed();
        }
    }
}
