#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include "/Users/raylin/Documents/GitHub/sandboxGame/header_files/backgroundImage.h"
#include "raylib.h"
#include "raymath.h"

class Background{

    public:
        Background(int format, int height,int width,void* data);
        void draw();
        Image getimage(){return img;};


    private: 
        Image img;

};
#endif