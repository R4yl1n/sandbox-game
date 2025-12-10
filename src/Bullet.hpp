#ifndef BULLET_HPP
#define BULLET_HPP

#include "raylib.h"

struct Bullet {
    Vector2 pos;
    Vector2 vel;
    bool active;

    //Bullet(Vector2 p, Vector2 v)
    //: pos(p), vel(v) {}
};

#endif