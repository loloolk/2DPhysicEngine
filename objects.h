#include "mathEngine\Vector2.cpp"
#include <vector>

class object {
    public:
        mtn::Vector2 position;
        mtn::Vector2 velocity;
        mtn::Vector2 acceleration;
        //mtn::Vector2 force;

        float mass;

        float size;
        float rW;

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

        mtn::Vector2 min = mtn::Vector2(this->position.x - this->length / 2, this->position.y - this->length / 2);
        mtn::Vector2 max = mtn::Vector2(this->position.x + this->length / 2, this->position.y + this->length / 2);
        
        square();
        square(float l, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float mass = 1.0);
        square(float l, object& obj);
        square(const square& v);
        ~square();
        
        bool isOnPoint(mtn::Vector2 point);
        
        square& operator = (const square& v);

        //void update();
};

class rectangle : public object {
    public:
        float height = 1.0;
        float width = 2.0;

        mtn::Vector2 min = mtn::Vector2(this->position.x - this->width / 2, this->position.y - this->height / 2);
        mtn::Vector2 max = mtn::Vector2(this->position.x + this->width / 2, this->position.y + this->height / 2);

        rectangle();
        rectangle(float h, float w, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float mass = 1.0);
        rectangle(float h, float w, object& obj);
        rectangle(const rectangle& v);
        ~rectangle();
        
        bool isOnPoint(mtn::Vector2 point);

        rectangle& operator = (const rectangle& v);

        //void update();
};

class circle : public object {
    public:
        float radius;

        mtn::Vector2 min = mtn::Vector2(this->position.x - this->radius, this->position.y - this->radius);
        mtn::Vector2 max = mtn::Vector2(this->position.x + this->radius, this->position.y + this->radius);
        
        circle();
        circle(float radius, mtn::Vector2 pos = mtn::Vector2(), mtn::Vector2 vel = mtn::Vector2(), mtn::Vector2 acc = mtn::Vector2(), mtn::Vector2 frc = mtn::Vector2(), float m = 1.0);
        circle(float radius, object& obj);
        circle(const circle& v);
        ~circle();
        
        bool isOnPoint(mtn::Vector2 point);

        circle& operator = (const circle& v);

        //void update();
};

