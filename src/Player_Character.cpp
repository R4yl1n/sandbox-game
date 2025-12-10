#include "Player_Character.hpp"

Player_Character::Player_Character(int format, int height,int width,void* data, float Rotation, ScreenDimensions screendimensions){ //initiation of main character
    img.format = format;
    img.height = height;
    img.width = width;
    img.data = data;
    img.mipmaps = 1;
    
    sprite = LoadTextureFromImage(img); //in the ctor because ctor initialises as last
    pos={
        (float)screendimensions.width / 2 - (float)sprite.width / 2, //defining position X
        (float)screendimensions.height / 2 - (float)sprite.height / 2 //defining position Y
    };
    rectangle={
        pos.x - sprite.width / 2.0f,
        pos.y - sprite.height / 2.0f,
        (float)sprite.width,
        (float)sprite.height
    };
    rotation = Rotation;
};

void Player_Character::draw(){
    DrawTexturePro(
    sprite,
    Rectangle{0, 0, (float)sprite.width, (float)sprite.height},
    Rectangle{pos.x, pos.y, (float)sprite.width, (float)sprite.height},
    Vector2{(float)sprite.width/2, (float)sprite.height/2}, 
    rotation,
    WHITE
    );
};