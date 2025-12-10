#ifndef PLAYER_CHARACTER_HPP
#define PLAYER_CHARACTER_HPP
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/evilMonster.h"
#include "raylib.h"
#include "raymath.h"
#include "ScreenDimensions.hpp"

class Player_Character{
    
    public:
    Player_Character(int format, int height,int width,void* data, float rotation, ScreenDimensions screendimensions);
    void draw();
    
    Texture2D getsprite(){return sprite;}
    Vector2 getpos(){return pos;}
    void setposX(float value){pos.x = value;}
    void setposY(float value){pos.y = value;}
    float getrotation(){return rotation;}
    void setrotation(float value){rotation = value;}

    Rectangle getrectangle(){return rectangle;}
    
    private:
    Image img;
    Texture2D sprite;
    Rectangle rectangle{};
    Vector2 pos{};
    float rotation;
    
};
#endif 