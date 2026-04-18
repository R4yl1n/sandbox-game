#ifndef SCREENDIMENSIONS_HPP
#define SCREENDIMENSIONS_HPP

#include "header_files/backgroundImage.h"
#include "raylib.h"
#include "raymath.h"

struct ScreenDimensions {
    int width;
    int height;

    ScreenDimensions(int w, int h)
        : width(w), height(h) {}
};

#endif