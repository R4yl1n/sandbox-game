#ifndef SPIRITUAL_ROWDY_HPP
#define SPIRITUAL_ROWDY_HPP
#include "raylib.h"
#include "raymath.h"
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/spiritualrowdy.h"
#include "Randomgen.hpp"

#include <iostream>

class Spiritual_rowdy{
    public:
        Spiritual_rowdy(int format, int height,int width,void* data);
        void draw(){
            if (alive){
            DrawTexture(sprite, pos.x, pos.y, WHITE);
            }
        }
        void kill(){alive=false;}
        bool isalive(){return alive;}

        Texture2D getsprite(){return sprite;}
        Vector2 getpos(){return pos;}
        Rectangle getrectangle(){return rectangle;}

    private:
        Image img;
        Texture2D sprite;
        Rectangle rectangle{};
        Vector2 pos{};
        bool alive=true;

};
#endif