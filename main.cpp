#include <iostream>
#include "objects.cpp"


int main() {
    mtn::Vector2 def = mtn::Vector2(-1.0, 0.0);

    //side length, position
    circle s1(1, def);

    //rad, position
    rectangle s2(2, 4, mtn::Vector2(2.0, 0.0));

    //s1.velocity = mtn::Vector2();
    //s2.velocity = mtn::Vector2();


    for (int i = 0; i < 10; i++) {
        std::cout << "s1: (" << s1.position.x << ", " << s1.position.y << "), s2: (" << s2.position.x << ", " << s2.position.y << ")" << std::endl;
        s1.update();
        s2.update();
        if (s1.collide(s2)) {
            std::cout << "collision" << std::endl;
            //accurate collision
            /*if ((s1.velocity.x == 0 || s1.velocity.y == 0) && (s2.velocity.x == 0 || s2.velocity.y == 0)) {
                std::cout << "easy collision" << std::endl;
                mtn::Vector2 spare = s1.position;
                s1.position = s2.position;
                s2.position = spare;
            }*/
        }
    }
}