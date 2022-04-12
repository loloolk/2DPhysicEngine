#include "objects.cpp"

std::vector<std::array<object*, 2>> colliding;

bool doesCollide(object& obj1, object& obj2) { //Broken
    if (obj1.type == "square") {
        if (obj2.type == "square") {
            return collide((square&)obj1, (square&)obj2);
        }
        else if (obj2.type == "rectangle") {
            return collide((square&)obj1, (rectangle&)obj2);
        }
        else if (obj2.type == "circle") {
            return collide((square&)obj1, (circle&)obj2);
        }
    }
    else if (obj1.type == "rectangle") {
        if (obj2.type == "square") {
            return collide((rectangle&)obj1, (square&)obj2);
        }
        else if (obj2.type == "rectangle") {
            return collide((rectangle&)obj1, (rectangle&)obj2);
        }
        else if (obj2.type == "circle") {
            return collide((rectangle&)obj1, (circle&)obj2);
        }
    }
    else if (obj1.type == "circle") {
        if (obj2.type == "square") {
            return collide((circle&)obj1, (square&)obj2);
        }
        else if (obj2.type == "rectangle") {
            return collide((circle&)obj1, (rectangle&)obj2);
        }
        else if (obj2.type == "circle") {
            return collide((circle&)obj1, (circle&)obj2);
        }
    }
    return false;
}

mtn::Vector2 findClosestObject(mtn::Vector2& v) {
    mtn::Vector2 closest;
    float closestDist = 999999999;
    for (int i = 0; i < objects.size(); i++) {
        float dist = sqrt(pow(objects[i]->position.x - v.x, 2) + pow(objects[i]->position.y - v.y, 2));
        if (dist < closestDist && dist != 0) {
            closestDist = dist;
            closest = objects[i]->position;
        }
    }

    return closest;
}

void checkCollisions(object& obj) {
    mtn::Vector2 closest = findClosestObject(obj.position);
    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->position == closest && !(objects[i] == &obj) && doesCollide(obj, *objects[i])) {
            colliding.push_back({&obj, objects[i]});
        }
    }
}

void collisionLogic(object& obj1, object& obj2) {
   return; 
}

void update() {
    //Start: Print out all object's locations
    /*for (int i = 0; i < objects.size(); i++) {
        std::cout << "Object " << i + 1 << ": " << objects[i]->position << std::endl;
    }
    */

    //Start: Check for collisions
    for (int i = 0; i < objects.size(); i++) {
        objects[i]->update();

        checkCollisions(*objects[i]);
    }
    
    //End: Check for collisions
    for (int i = 0; i < colliding.size(); i++) {
        //std::cout << "Collision with " << colliding[i][0]->position << " and " << colliding[i][1]->position << std::endl; 
    }
    

    colliding.clear();
}

//line detecting where they go for skipover problem
//finalVel.x = (obj1.momentum.x + obj2.momentum.x) / obj1.mass + obj2.mass