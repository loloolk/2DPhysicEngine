#include <iostream>
#include "objects.cpp"


int main() {
    mtn::Vector2 def = mtn::Vector2(0.0, 5.0);

    //side length, position
    square s1(1.0, def);

    //height, width-, position
    square s2(1.0, mtn::Vector2(-5.0, 0.0));
    //circle s2(1.0, def);

    s1.velocity = mtn::Vector2(-1.0, -1.0);
    //s2.velocity = mtn::Vector2(2.0, 0.0);

    for (int i = 0; i < 10; i++) {
        std::cout << "s1: (" << s1.position.x << ", " << s1.position.y << "), s2: (" << s2.position.x << ", " << s2.position.y << ")" << std::endl;
        s1.update();
        s2.update();
        if (collide(s1, s2)) {
            std::cout << "collision" << std::endl;
            //accurate collision
            if ((s1.velocity.x == 0 || s1.velocity.y == 0) && (s2.velocity.x == 0 || s2.velocity.y == 0)) {
                std::cout << "easy collision" << std::endl;
                mtn::Vector2 spare = s1.position;
                s1.position = s2.position;
                s2.position = spare;
            }
        }
    }
}


