#include <math.h>
#include <vector>
#include "objects.h"
#include "mathEngine\Vector2.h"

object::object() {
    position = mtn::Vector2(0.0, 0.0);
    velocity = mtn::Vector2(0.0, 0.0);
    acceleration = mtn::Vector2(0.0, 0.0);
    //force = mtn::Vector2(0.0, 0.0);
    
    mass = 1.0;
}
object::object(mtn::Vector2 pos, mtn::Vector2 vel, mtn::Vector2 acc, mtn::Vector2 frc, float m) {
    position = pos;
    velocity = vel;
    acceleration = acc;
    //force = frc;
    
    mass = m;
}
object::object(const object& obj) {
    position = obj.position;
    velocity = obj.velocity;
    acceleration = obj.acceleration;
    //force = obj.force;
    
    mass = obj.mass;
}
object::~object() {}

void object::changePosition(mtn::Vector2 pos) {
    position = pos;
}
void object::changeVelocity(mtn::Vector2 vel) {
    velocity = vel;
}
void object::changeAcceleration(mtn::Vector2 acc) {
    acceleration = acc;
}

void object::update() {
    velocity += acceleration;
    position += velocity;
}
object& object::operator = (const object& obj) {    
    position = obj.position;
    velocity = obj.velocity;
    acceleration = obj.acceleration;
    
    mass = obj.mass;
    
    return * this;
}

/*###############################################################################*/

square::square() : object() {
    length = 1;
}
square::square(float l, mtn::Vector2 pos, mtn::Vector2 vel, mtn::Vector2 acc, mtn::Vector2 frc, float m) : object(pos, vel, acc, frc, m) {
    length = l;
}
square::square(float l, object& obj) : object(obj) {
    length = l;
}
square::square(const square& v) : object(v) {
    length = v.length;
}
square::~square() {}

square& square::operator = (const square& v) {
    length = v.length;
    
    return * this;
}
bool square::isOnPoint(mtn::Vector2 point) {
    if (point.x >= this->min.x && point.x <= this->max.x && point.y >= this->min.y && point.y <= this->max.y) {
        return true;
    }
    return false;
}

bool square::collide(square& sqr) {
    if (this->isOnPoint(corners[0][0]) || this->isOnPoint(corners[0][1]) || this->isOnPoint(corners[1][0]) || this->isOnPoint(corners[1][1])) {
        return true;
    }
    return false;
}
bool square::collide(rectangle& rect) {
    if (this->isOnPoint(rect.corners[0][0]) || this->isOnPoint(rect.corners[0][1]) || this->isOnPoint(rect.corners[1][0]) || this->isOnPoint(rect.corners[1][1])) {
        return true;
    }
    return false;
}
bool square::collide(circle& cir) {
    mtn::Vector2 circleDist(abs(cir.position.x - this->position.x), abs(cir.position.y - this->position.y));

    if (circleDist.x > (this->length / 2 + cir.radius)) { return false;}
    if (circleDist.y > (this->length / 2 + cir.radius)) { return false;}

    if (circleDist.x <= (this->length / 2)) { return true;}
    if (circleDist.y <= (this->length / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - this->length / 2), 2) + pow((float)(circleDist.y - this->length / 2), 2);

    return (cornerDistanceSq <= pow(cir.radius, 2));
}

/*###############################################################################*/

rectangle::rectangle() : object() {
    height = 2.0;
    width = 4.0;
}
rectangle::rectangle(float h, float w, mtn::Vector2 pos, mtn::Vector2 vel, mtn::Vector2 acc, mtn::Vector2 frc, float m) : object(pos, vel, acc, frc, m) {
    height = h;
    width = w;
}
rectangle::rectangle(float h, float w, object& obj) : object(obj) {
    height = h;
    width = w;
}
rectangle::rectangle(const rectangle& v) : object(v) {
    height = v.height;
    width = v.width;
}
rectangle::~rectangle() {}

rectangle& rectangle::operator = (const rectangle& v) {
    height = v.height;
    width = v.width;
    
    return * this;
}
bool rectangle::isOnPoint(mtn::Vector2 point) {
    if (point.x >= this->min.x && point.x <= this->max.x && point.y >= this->min.y && point.y <= this->max.y) {
        return true;
    }
    return false;
}

bool rectangle::collide(rectangle& rect) {
    if (this->isOnPoint(rect.corners[0][0]) || this->isOnPoint(rect.corners[0][1]) || this->isOnPoint(rect.corners[1][0]) || this->isOnPoint(rect.corners[1][1])) {
        return true;
    }
    return false;
}
bool rectangle::collide(square& sqr) {
    if (this->isOnPoint(sqr.corners[0][0]) || this->isOnPoint(sqr.corners[0][1]) || this->isOnPoint(sqr.corners[1][0]) || this->isOnPoint(sqr.corners[1][1])) {
        return true;
    }
    return false;
}
bool rectangle::collide(circle& cir) {
    mtn::Vector2 circleDist(abs(cir.position.x - this->position.x), abs(cir.position.y - this->position.y));

    if (circleDist.x > (this->width / 2 + cir.radius)) { return false;}
    if (circleDist.y > (this->height / 2 + cir.radius)) { return false;}

    if (circleDist.x <= (this->width / 2)) { return true;}
    if (circleDist.y <= (this->height / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - this->width / 2), 2) + pow((float)(circleDist.y - this->height / 2), 2);

    return (cornerDistanceSq <= pow(cir.radius, 2));
}

/*###############################################################################*/

circle::circle() : object() {
    radius = 1;
}
circle::circle(float r, mtn::Vector2 pos, mtn::Vector2 vel, mtn::Vector2 acc, mtn::Vector2 frc, float m) : object(pos, vel, acc, frc, m) {
    radius = r;
}
circle::circle(float r, object& obj) : object(obj) {
    radius = r;
}
circle::circle(const circle& v) : object(v) {
    radius = v.radius;
}
circle::~circle() {}

circle& circle::operator = (const circle& v) {
    radius = v.radius;
    
    return * this;
}
bool circle::isOnPoint(mtn::Vector2 point) {
    if (point.x >= this->min.x && point.x <= this->max.x && point.y >= this->min.y && point.y <= this->max.y) {
        return true;
    }
    return false;
}

bool circle::collide(circle& circ) { // Works
    //return ((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc)) < r*r;
    return ((this->position.x - circ.position.x)*(this->position.x - circ.position.x) + (this->position.y - circ.position.y)*(this->position.y - circ.position.y)) < (this->radius + circ.radius)*(this->radius + circ.radius);
}
bool circle::collide(square& sqr) {
    mtn::Vector2 circleDist(abs(sqr.position.x - this->position.x), abs(sqr.position.y - this->position.y));

    if (circleDist.x > (sqr.length / 2 + this->radius)) { return false;}
    if (circleDist.y > (sqr.length / 2 + this->radius)) { return false;}

    if (circleDist.x <= (sqr.length / 2)) { return true;}
    if (circleDist.y <= (sqr.length / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - sqr.length / 2), 2) + pow((float)(circleDist.y - sqr.length / 2), 2);

    return (cornerDistanceSq <= pow(this->radius, 2));
}
bool circle::collide(rectangle& rect) {
    mtn::Vector2 circleDist(abs(rect.position.x - this->position.x), abs(rect.position.y - this->position.y));

    if (circleDist.x > (rect.width / 2 + this->radius)) { return false;}
    if (circleDist.y > (rect.height / 2 + this->radius)) { return false;}

    if (circleDist.x <= (rect.width / 2)) { return true;}
    if (circleDist.y <= (rect.height / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - rect.width / 2), 2) + pow((float)(circleDist.y - rect.height / 2), 2);

    return (cornerDistanceSq <= pow(this->radius, 2));
}


//line detecting where they go for skipover problem

//possibly take in length from shape to fix collisions