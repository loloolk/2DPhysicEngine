#include "objects.h"
#include <vector>
#include <array>
#include <chrono>
#include <typeinfo>

std::vector<object*> objects;

object::object() {
    position = mtn::Vector2(0.0, 0.0);
    velocity = mtn::Vector2(0.0, 0.0);
    acceleration = mtn::Vector2(0.0, 0.0);

    mass = 1.0;
    theta = RadToDegrees(atan2(position.y, position.x));
    momentum = mtn::Vector2(mass * velocity.x, mass * velocity.y);
}
object::object(mtn::Vector2 pos, mtn::Vector2 vel = mtn::Vector2(0.0, 0.0), mtn::Vector2 acc = mtn::Vector2(0.0, 0.0), float m = 1.0) {
    position = pos;
    velocity = vel;
    acceleration = acc;

    mass = m;
    theta = RadToDegrees(atan2(position.y, position.x));
    momentum = mtn::Vector2(mass * velocity.x, mass * velocity.y);
}
object::object(const object& obj) {
    position = obj.position;
    velocity = obj.velocity;
    acceleration = obj.acceleration;
    
    mass = obj.mass;
    theta = RadToDegrees(atan2(position.y, position.x));
    momentum = mtn::Vector2(mass * velocity.x, mass * velocity.y);
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

object& object::operator = (const object& obj) {    
    position = obj.position;
    velocity = obj.velocity;
    acceleration = obj.acceleration;
    
    mass = obj.mass;
    
    return * this;
}
bool object::operator == (const object& obj) {
    return (position == obj.position && velocity == obj.velocity && acceleration == obj.acceleration && mass == obj.mass);
}

void object::update() {
    velocity += acceleration;
    position += velocity;

    momentum = mtn::Vector2(mass * velocity.x, mass * velocity.y);
    theta = RadToDegrees(atan2(position.y, position.x));
}

bool object::isOnPoint(mtn::Vector2 point) {
    if (point.x >= this->min.x && point.x <= this->max.x && point.y >= this->min.y && point.y <= this->max.y) {
        return true;
    }
    return false;
}

/*###############################################################################*/

square::square() : object() {
    length = 1;

    corners[0][0] = mtn::Vector2(this->position.x - length / 2, this->position.y + length / 2);
    corners[0][1] = mtn::Vector2(this->position.x + length / 2, this->position.y + length / 2);
    corners[1][0] = mtn::Vector2(this->position.x - length / 2, this->position.y - length / 2);
    corners[1][1] = mtn::Vector2(this->position.x + length / 2, this->position.y - length / 2);

    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);

    type = "square";

    objects.push_back(this);
}
square::square(float l, mtn::Vector2 pos, mtn::Vector2 vel, mtn::Vector2 acc, mtn::Vector2 frc, float m) : object(pos, vel, acc, m) {
    length = l;

    corners[0][0] = mtn::Vector2(this->position.x - length / 2, this->position.y + length / 2);
    corners[0][1] = mtn::Vector2(this->position.x + length / 2, this->position.y + length / 2);
    corners[1][0] = mtn::Vector2(this->position.x - length / 2, this->position.y - length / 2);
    corners[1][1] = mtn::Vector2(this->position.x + length / 2, this->position.y - length / 2);

    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "square";

    objects.push_back(this);
}
square::square(float l, object& obj) : object(obj) {
    length = l;
    
    corners[0][0] = mtn::Vector2(this->position.x - length / 2, this->position.y + length / 2);
    corners[0][1] = mtn::Vector2(this->position.x + length / 2, this->position.y + length / 2);
    corners[1][0] = mtn::Vector2(this->position.x - length / 2, this->position.y - length / 2);
    corners[1][1] = mtn::Vector2(this->position.x + length / 2, this->position.y - length / 2);

    max = corners[0][1];
    min = corners[1][0];
    
    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "square";

    objects.push_back(this);
}
square::square(const square& v) : object(v) {
    length = v.length;
    
    corners[0][0] = mtn::Vector2(this->position.x - length / 2, this->position.y + length / 2);
    corners[0][1] = mtn::Vector2(this->position.x + length / 2, this->position.y + length / 2);
    corners[1][0] = mtn::Vector2(this->position.x - length / 2, this->position.y - length / 2);
    corners[1][1] = mtn::Vector2(this->position.x + length / 2, this->position.y - length / 2);

    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "square";

    objects.push_back(this);
}
square::~square() {}

square& square::operator = (const square& v) {
    length = v.length;
    
    return * this;
}

/*###############################################################################*/

rectangle::rectangle() : object() {
    height = 2.0;
    width = 4.0;

    corners[0][0] = mtn::Vector2(this->position.x - width / 2, this->position.y + height / 2);
    corners[0][1] = mtn::Vector2(this->position.x + width / 2, this->position.y + height / 2);
    corners[1][0] = mtn::Vector2(this->position.x - width / 2, this->position.y - height / 2);
    corners[1][1] = mtn::Vector2(this->position.x + width / 2, this->position.y - height / 2);

    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "rectangle";
    
    objects.push_back(this);
}
rectangle::rectangle(float h, float w, mtn::Vector2 pos, mtn::Vector2 vel, mtn::Vector2 acc, mtn::Vector2 frc, float m) : object(pos, vel, acc, m) {
    height = h;
    width = w;
    
    corners[0][0] = mtn::Vector2(this->position.x - width / 2, this->position.y + height / 2);
    corners[0][1] = mtn::Vector2(this->position.x + width / 2, this->position.y + height / 2);
    corners[1][0] = mtn::Vector2(this->position.x - width / 2, this->position.y - height / 2);
    corners[1][1] = mtn::Vector2(this->position.x + width / 2, this->position.y - height / 2);
    
    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "rectangle";

    objects.push_back(this);
}
rectangle::rectangle(float h, float w, object& obj) : object(obj) {
    height = h;
    width = w;
    
    corners[0][0] = mtn::Vector2(this->position.x - width / 2, this->position.y + height / 2);
    corners[0][1] = mtn::Vector2(this->position.x + width / 2, this->position.y + height / 2);
    corners[1][0] = mtn::Vector2(this->position.x - width / 2, this->position.y - height / 2);
    corners[1][1] = mtn::Vector2(this->position.x + width / 2, this->position.y - height / 2);
    
    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "rectangle";

    objects.push_back(this);
}
rectangle::rectangle(const rectangle& v) : object(v) {
    height = v.height;
    width = v.width;
    
    corners[0][0] = mtn::Vector2(this->position.x - width / 2, this->position.y + height / 2);
    corners[0][1] = mtn::Vector2(this->position.x + width / 2, this->position.y + height / 2);
    corners[1][0] = mtn::Vector2(this->position.x - width / 2, this->position.y - height / 2);
    corners[1][1] = mtn::Vector2(this->position.x + width / 2, this->position.y - height / 2);
    
    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "rectangle";

    objects.push_back(this);
}
rectangle::~rectangle() {}

rectangle& rectangle::operator = (const rectangle& v) {
    height = v.height;
    width = v.width;
    
    return * this;
}

/*###############################################################################*/

circle::circle() : object() {
    radius = 1;
    
    corners[0][0] = mtn::Vector2(this->position.x + radius * cos(135), this->position.y + radius * sin(135));
    corners[0][1] = mtn::Vector2(this->position.x + radius * cos(45), this->position.y + radius * sin(45));
    corners[1][0] = mtn::Vector2(this->position.x + radius * cos(225), this->position.y + radius * sin(225));
    corners[1][1] = mtn::Vector2(this->position.x + radius * cos(315), this->position.y + radius * sin(315));
    
    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "circle";

    objects.push_back(this);
}
circle::circle(float r, mtn::Vector2 pos, mtn::Vector2 vel, mtn::Vector2 acc, mtn::Vector2 frc, float m) : object(pos, vel, acc, m) {
    radius = r;
    
    corners[0][0] = mtn::Vector2(this->position.x + radius * cos(135), this->position.y + radius * sin(135));
    corners[0][1] = mtn::Vector2(this->position.x + radius * cos(45), this->position.y + radius * sin(45));
    corners[1][0] = mtn::Vector2(this->position.x + radius * cos(225), this->position.y + radius * sin(225));
    corners[1][1] = mtn::Vector2(this->position.x + radius * cos(315), this->position.y + radius * sin(315));
    
    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "circle";

    objects.push_back(this);
}
circle::circle(float r, object& obj) : object(obj) {
    radius = r;
    
    corners[0][0] = mtn::Vector2(this->position.x + radius * cos(135), this->position.y + radius * sin(135));
    corners[0][1] = mtn::Vector2(this->position.x + radius * cos(45), this->position.y + radius * sin(45));
    corners[1][0] = mtn::Vector2(this->position.x + radius * cos(225), this->position.y + radius * sin(225));
    corners[1][1] = mtn::Vector2(this->position.x + radius * cos(315), this->position.y + radius * sin(315));
    
    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "circle";

    objects.push_back(this);
}
circle::circle(const circle& v) : object(v) {
    radius = v.radius;
    
    corners[0][0] = mtn::Vector2(this->position.x + radius * cos(135), this->position.y + radius * sin(135));
    corners[0][1] = mtn::Vector2(this->position.x + radius * cos(45), this->position.y + radius * sin(45));
    corners[1][0] = mtn::Vector2(this->position.x + radius * cos(225), this->position.y + radius * sin(225));
    corners[1][1] = mtn::Vector2(this->position.x + radius * cos(315), this->position.y + radius * sin(315));
    
    max = corners[0][1];
    min = corners[1][0];

    vertex[0] = mtn::line(corners[0][0], corners[0][1]);
    vertex[1] = mtn::line(corners[0][0], corners[1][0]);
    vertex[2] = mtn::line(corners[0][1], corners[1][1]);
    vertex[3] = mtn::line(corners[1][0], corners[1][1]);
    
    type = "circle";

    objects.push_back(this);
}
circle::~circle() {}

circle& circle::operator = (const circle& v) {
    radius = v.radius;
    
    return * this;
}

/*###############################################################################*/


bool collide(square& sqr, square& sqr2) {
    if (sqr.isOnPoint(sqr2.corners[0][0]) || sqr.isOnPoint(sqr2.corners[0][1]) || sqr.isOnPoint(sqr2.corners[1][0]) || sqr.isOnPoint(sqr2.corners[1][1])) {
        return true;
    }
    return false;
}
bool collide(square& sqr, rectangle& rect) { //Works (?)
    if (sqr.isOnPoint(rect.corners[0][0]) || sqr.isOnPoint(rect.corners[0][1]) || sqr.isOnPoint(rect.corners[1][0]) || sqr.isOnPoint(rect.corners[1][1])) {
        return true;
    }
    return false;
}
bool collide(square& sqr, circle& cir) { //Works
    mtn::Vector2 circleDist(abs(cir.position.x - sqr.position.x), abs(cir.position.y - sqr.position.y));

    if (circleDist.x > (sqr.length / 2 + cir.radius)) { return false;}
    if (circleDist.y > (sqr.length / 2 + cir.radius)) { return false;}

    if (circleDist.x <= (sqr.length / 2)) { return true;}
    if (circleDist.y <= (sqr.length / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - sqr.length / 2), 2) + pow((float)(circleDist.y - sqr.length / 2), 2);

    return (cornerDistanceSq <= pow(cir.radius, 2));
}

bool collide(rectangle& rect, rectangle& rect2) { //Works
    if (rect2.isOnPoint(rect.corners[0][0]) || rect2.isOnPoint(rect.corners[0][1]) || rect2.isOnPoint(rect.corners[1][0]) || rect2.isOnPoint(rect.corners[1][1])) {
        return true;
    }
    return false;
}
bool collide(rectangle& rect, square& sqr) { //Works (?)
    if (rect.isOnPoint(sqr.corners[0][0]) || rect.isOnPoint(sqr.corners[0][1]) || rect.isOnPoint(sqr.corners[1][0]) || rect.isOnPoint(sqr.corners[1][1])) {
        return true;
    }
    return false;
}
bool collide(rectangle& rect, circle& cir) { //Works
    mtn::Vector2 circleDist(abs(cir.position.x - rect.position.x), abs(cir.position.y - rect.position.y));

    if (circleDist.x > (rect.width / 2 + cir.radius)) { return false;}
    if (circleDist.y > (rect.height / 2 + cir.radius)) { return false;}

    if (circleDist.x <= (rect.width / 2)) { return true;}
    if (circleDist.y <= (rect.height / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - rect.width / 2), 2) + pow((float)(circleDist.y - rect.height / 2), 2);

    return (cornerDistanceSq <= pow(cir.radius, 2));
}


bool collide(circle& circ, circle& circ2) { // Works
    //return ((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc)) < r*r;
    return ((circ2.position.x - circ.position.x)*(circ2.position.x - circ.position.x) + (circ2.position.y - circ.position.y)*(circ2.position.y - circ.position.y)) < (circ2.radius + circ.radius)*(circ2.radius + circ.radius);
}
bool collide(circle& circ, square& sqr) { //Works
    mtn::Vector2 circleDist(abs(sqr.position.x - circ.position.x), abs(sqr.position.y - circ.position.y));

    if (circleDist.x > (sqr.length / 2 + circ.radius)) { return false;}
    if (circleDist.y > (sqr.length / 2 + circ.radius)) { return false;}

    if (circleDist.x <= (sqr.length / 2)) { return true;}
    if (circleDist.y <= (sqr.length / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - sqr.length / 2), 2) + pow((float)(circleDist.y - sqr.length / 2), 2);

    return (cornerDistanceSq <= pow(circ.radius, 2));
}
bool collide(circle& circ, rectangle& rect) { //Works
    mtn::Vector2 circleDist(abs(rect.position.x - circ.position.x), abs(rect.position.y - circ.position.y));

    if (circleDist.x > (rect.width / 2 + circ.radius)) { return false;}
    if (circleDist.y > (rect.height / 2 + circ.radius)) { return false;}

    if (circleDist.x <= (rect.width / 2)) { return true;}
    if (circleDist.y <= (rect.height / 2)) { return true;}

    float cornerDistanceSq = pow((float)(circleDist.x - rect.width / 2), 2) + pow((float)(circleDist.y - rect.height / 2), 2);

    return (cornerDistanceSq <= pow(circ.radius, 2));
}

/*###############################################################################*/