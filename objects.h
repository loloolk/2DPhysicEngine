#include "mathEngine\Vector2.cpp"
#include <vector>
#include <math.h>

class object;
class square;
class rectangle;
class circle;

class object {
    public:
        mtn::Vector2 position;
        mtn::Vector2 velocity;
        mtn::Vector2 acceleration;
        
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

        void update();

        object& operator = (const object& v);
};

class square : public object {
    public:
        float length = 1.0;

        mtn::Vector2 corners[2][2] = {
            {mtn::Vector2(this->position.x - length / 2, this->position.y + length / 2), 
                mtn::Vector2(this->position.x + length / 2, this->position.y + length / 2)},
            {mtn::Vector2(this->position.x - length / 2, this->position.y - length / 2),
                mtn::Vector2(this->position.x + length / 2, this->position.y - length / 2)}
        };
        mtn::Vector2 min = corners[1][0];
        mtn::Vector2 max = corners[0][1];
        
        square();
        square(float l, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float mass = 1.0);
        square(float l, object& obj);
        square(const square& v);
        ~square();
        
        bool isOnPoint(mtn::Vector2 point);
        
        square& operator = (const square& v);

        bool collide(square& sqr);
        bool collide(rectangle& rect);
        bool collide(circle& circ);

        //void update();
};

class rectangle : public object {
    public:
        float height = 1.0;
        float width = 2.0;

        mtn::Vector2 corners[2][2] = {
            {mtn::Vector2(this->position.x - width / 2, this->position.y + height / 2), 
                mtn::Vector2(this->position.x + width / 2, this->position.y + height / 2)},
            {mtn::Vector2(this->position.x - width / 2, this->position.y - height / 2),
                mtn::Vector2(this->position.x + width / 2, this->position.y - height / 2)}
        };
        mtn::Vector2 min = corners[0][1];
        mtn::Vector2 max = corners[1][0];

        rectangle();
        rectangle(float h, float w, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float mass = 1.0);
        rectangle(float h, float w, object& obj);
        rectangle(const rectangle& v);
        ~rectangle();
        
        bool isOnPoint(mtn::Vector2 point);

        rectangle& operator = (const rectangle& v);

        bool collide(rectangle& rect);
        bool collide(circle& circ);
        bool collide(square& sqr);
        //void update();
};

class circle : public object {
    public:
        float radius;

        mtn::Vector2 corners[2][2] = {
            {mtn::Vector2(this->position.x + radius * cos(135), this->position.y + radius * sin(135)), 
                mtn::Vector2(this->position.x + radius * cos(45), this->position.y + radius * sin(45))},
            {mtn::Vector2(this->position.x + radius * cos(225), this->position.y + radius * sin(225)),
                mtn::Vector2(this->position.x + radius * cos(315), this->position.y + radius * sin(315))}
        };
        mtn::Vector2 min = corners[0][1];
        mtn::Vector2 max = corners[1][0];
        
        circle();
        circle(float radius, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float m = 1.0);
        circle(float radius, object& obj);
        circle(const circle& v);
        ~circle();
        
        bool isOnPoint(mtn::Vector2 point);

        circle& operator = (const circle& v);

        bool collide(circle& circ);
        bool collide(square& sqr);
        bool collide(rectangle& rect);

        //void update();
};

