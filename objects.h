#include "mathEngine\Vector2.cpp"
#include "mathEngine\line.cpp"
#include <iostream>
#include <vector>
#include <math.h>

class object;
class square;
class rectangle;
class circle;
class hitbox;

class object {
    public:
        mtn::Vector2 position;
        mtn::Vector2 velocity;
        mtn::Vector2 acceleration;

        mtn::Vector2 corners[2][2];
        mtn::Vector2 min = corners[1][0];
        mtn::Vector2 max = corners[0][1];
        mtn::line vertex[4];
        
        std::string type;

        float mass;
        float theta = RadToDegrees(atan2(position.y, position.x));

        object();
        object(mtn::Vector2 pos, mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float mass = 1.0);
        object(const object& obj);
        ~object();

        //come back here

        void changePosition(mtn::Vector2 pos);
        void changeVelocity(mtn::Vector2 vel);
        void changeAcceleration(mtn::Vector2 acc);
        void applyForce(mtn::Vector2 force);

        object& operator = (const object& v);
        bool operator == (const object& v);

        bool collide(object& obj);

        void update();

        bool isOnPoint(mtn::Vector2 point);

        //mtn::Vector2 collided(object& obj);
};

class square : public object {
    public:
        float length;
        
        square();
        square(float l, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float mass = 1.0);
        square(float l, object& obj);
        square(const square& v);
        ~square();
        
        square& operator = (const square& v);
};

class rectangle : public object {
    public:
        float height;
        float width;

        //hitbox hb;

        rectangle();
        rectangle(float h, float w, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float mass = 1.0);
        rectangle(float h, float w, object& obj);
        rectangle(const rectangle& v);
        ~rectangle();

        rectangle& operator = (const rectangle& v);
};

class circle : public object {
    public:
        float radius;

        //hitbox hb;
        
        circle();
        circle(float radius, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float m = 1.0);
        circle(float radius, object& obj);
        circle(const circle& v);
        ~circle();

        circle& operator = (const circle& v);
};

