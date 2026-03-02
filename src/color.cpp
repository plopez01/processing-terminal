#include "environment.h"
#include <iostream>
#include "color.h"

using namespace std;

char _brush = '@';

void brush(char c) {
    _brush = c;
}

void _setForegroundTrueColor(int r, int g, int b) {
    cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "m";
}

void background(color rgba) {
    background(rgba.r, rgba.g, rgba.b, rgba.a);
}

void background(unsigned char gray) {
    background(gray, gray, gray);
}

void background(unsigned char r, unsigned char g, unsigned char b) {
    background(r, g, b, 255);
}

void background(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    _setForegroundTrueColor(r, g, b);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            framebuffer[y * width + x] = _brush;
        }
    }
}