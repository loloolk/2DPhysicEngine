#include <string>
#include <chrono>
#include "time.h"
#include "objects.cpp"

int main() {
    auto begin1 = std::chrono::high_resolution_clock::now();
    circle c1(1, mtn::Vector2(-50000.0, 0.0), mtn::Vector2(5.0, 0.0));
    circle c2(1, mtn::Vector2(0.0, 0.0));
    square s1(2, mtn::Vector2(0.1, 0.0));

    //s1.velocity = mtn::Vector2();
    //s2.velocity = mtn::Vector2();

    //s3.acceleration = mtn::Vector2(5.0, -3.0);

    for (int i = 0; i < 10000; i++) {
        update();
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << c1.position;
    std::cout << "first section: " << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1).count() << " miliseconds" << std::endl;
}