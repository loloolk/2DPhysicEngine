#include <string>
#include <chrono>
#include "time.h"
#include "objects.cpp"


int main() {
    /*
    //side length, position
    square s1(2, mtn::Vector2(0.0, 0.0));

    //side length, position
    rectangle s2(2, 2, mtn::Vector2(3.0, 0.0)); //1, 2

    //rad, position
    circle s3(1, mtn::Vector2(7.0, 0.0)); //1, 2
    circle s4(1, mtn::Vector2(10.0, 0.0)); //1, 2
    circle s5(1, mtn::Vector2(13.0, 0.0)); //1, 2
    circle s6(1, mtn::Vector2(15.0, 0.0)); //1, 2
    circle s7(1, mtn::Vector2(18.0, 0.0)); //1, 2
    circle s8(1, mtn::Vector2(21.0, 0.0)); //1, 2
    circle s9(1, mtn::Vector2(24.0, 0.0)); //1, 2
    circle s10(1, mtn::Vector2(27.0, 0.0)); //1, 2
    circle s11(1, mtn::Vector2(30.0, 0.0)); //1, 2
    circle s12(1, mtn::Vector2(33.0, 0.0)); //1, 2
    circle s33(1, mtn::Vector2(36.0, 0.0)); //1, 2
    circle s14(1, mtn::Vector2(39.0, 0.0)); //1, 2
    circle s26(1, mtn::Vector2(42.0, 0.0)); //1, 2
    circle s16(1, mtn::Vector2(45.0, 0.0)); //1, 2
    circle s17(1, mtn::Vector2(48.0, 0.0)); //1, 2
    circle s18(1, mtn::Vector2(51.0, 0.0)); //1, 2
    circle s20(1, mtn::Vector2(54.0, 0.0)); //1, 2
    circle s21(1, mtn::Vector2(57.0, 0.0)); //1, 2
    circle s22(1, mtn::Vector2(60.0, 0.0)); //1, 2
    circle s23(1, mtn::Vector2(63.0, 0.0)); //1, 2 */

    circle c1(1, mtn::Vector2(-5000.0, 0.0));
    circle c2(1, mtn::Vector2(0.0, 0.0));
    square s1(2, mtn::Vector2(0.1, 0.0));

    //s1.velocity = mtn::Vector2();
    //s2.velocity = mtn::Vector2();

    //s3.acceleration = mtn::Vector2(5.0, -3.0);

    for (int i = 0; i < 10; i++) {
        update();
    }
}

//momentum = mass * velocitys