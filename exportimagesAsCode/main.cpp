#include "raylib.h"
#include <string>

int main(){
    std::string name_of_png="spiritualrowdy.png";
    std::string path = "/Users/raylin/Documents/GitHub/sandboxGame/assets/sprites/";
    auto file = path + name_of_png;
    Image img = LoadImage(file.c_str());
    path = "header_files/";
    file = path + name_of_png;
    ExportImageAsCode(img, file.c_str());
    UnloadImage(img);


}

//make build_img
//bin gets into /bin/build_img_osx