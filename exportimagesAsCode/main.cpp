#include "raylib.h"

int main(){
    auto file = "/Users/raylin/Documents/GitHub/sandboxGame/assets/sprites/Pixel.png";
    Image img = LoadImage(file);
    ExportImageAsCode(img, "header_files/evilMonster.h");
    UnloadImage(img);


}

//make build_img
//bin gets into /bin/build_img_osx