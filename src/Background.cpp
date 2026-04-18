#include "Background.hpp"

Background::Background(int format, int height,int width,void* data){
    img.height = height;
    img.format = format;
    img.width = width;
    img.data = data;
    img.mipmaps = 1;    
};
