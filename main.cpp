#include <iostream>
#include <string>
#include "objects.cpp"


int main() {

    //side length, position
    rectangle s1(2, 2, mtn::Vector2(1.0, 0.0)); //1, 2

    //rad, position
    rectangle s2(2, 2, mtn::Vector2(3.0, 0.0)); //1, 2

    //s1.velocity = mtn::Vector2();
    //s2.velocity = mtn::Vector2();

    std::cout << findClosestObject(s1.position) << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << "s1: " << s1.position << ", s2: " << s2.position << std::endl;
        update();
        /*if (s1.collide(s2) || s2.collide(s1)) {
            std::cout << "collision" << std::endl;
            //accurate collision
            if ((s1.velocity.x == 0 || s1.velocity.y == 0) && (s2.velocity.x == 0 || s2.velocity.y == 0)) {
                std::cout << "easy collision" << std::endl;
                mtn::Vector2 spare = s1.position;
                s1.position = s2.position;
                s2.position = spare;
            }
        }*/
    }
}

//only switch momentum if same mass

//FIX CORNERS