#include "Spiritual_rowdy.hpp"

Spiritual_rowdy::Spiritual_rowdy(int format, int height,int width,void* data){
    img.format = format;
    img.height = height;
    img.width = width;
    img.data = data;
    img.mipmaps = 1;
    
    sprite = LoadTextureFromImage(img); //in the ctor because ctor initialises as last
    pos= {
        (float)50.0,    //defining position X
        (float)50.0     //defining position Y
    };
    rectangle={pos.x,pos.y,(float)sprite.width,(float)sprite.height};

};
