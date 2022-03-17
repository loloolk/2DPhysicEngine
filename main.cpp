#include <iostream>
#include <string>
#include "objects.cpp"


int main() {
    //side length, position
    square s3(2, mtn::Vector2(-1.0, 0.0));

    //side length, position
    rectangle s1(2, 2, mtn::Vector2(1.0, 0.0)); //1, 2

    //rad, position
    circle s2(1, mtn::Vector2(3.0, 0.0)); //1, 2

    //s1.velocity = mtn::Vector2();
    //s2.velocity = mtn::Vector2();

    //s3.acceleration = mtn::Vector2(5.0, -3.0);

    std::cout << findClosestObject(s1.position) << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "s1: " << s1.position << ", s2: " << s2.position << ", s3: " << s3.position << std::endl;
        update();
    }
}

//only switch momentum if same mass

//FIX CORNERS