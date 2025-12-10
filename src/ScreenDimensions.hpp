#ifndef SCREENDIMENSIONS_HPP
#define SCREENDIMENSIONS_HPP
struct ScreenDimensions {
    int width;
    int height;

    ScreenDimensions(int w, int h)
        : width(w), height(h) {}
};

#endif