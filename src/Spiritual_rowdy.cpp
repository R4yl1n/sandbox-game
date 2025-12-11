#include "Spiritual_rowdy.hpp"

Spiritual_rowdy::Spiritual_rowdy(int format, int height,int width,void* data){
    img.format = format;
    img.height = height;
    img.width = width;
    img.data = data;
    img.mipmaps = 1;
    
    int x = Randomgen::getRandomInt(0,850);
    int y = Randomgen::getRandomInt(0,450);
    pos= {
        (float)x,    //defining position X
        (float)y     //defining position Y
    };
    
    sprite = LoadTextureFromImage(img); //in the ctor because ctor initialises as last
    rectangle={pos.x,pos.y,(float)sprite.width,(float)sprite.height};

};
