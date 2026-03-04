#include "environment.h"
#include <iostream>
#include "color.h"

using namespace std;

namespace pterm {

    char _brush = '@';
    color _fill = {.r = 255, .g = 255, .b = 255};

    void brush(char c) {
        _brush = c;
    }

    void _setForegroundTrueColor(color c) {
        cout << "\x1b[38;2;" << (int)c.r << ";" << (int)c.g << ";" << (int)c.b << "m";
    }

    void background(color rgba) {
        _setForegroundTrueColor(rgba);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                framebuffer[y * width + x] = _brush;
            }
        }
    }

    void background(unsigned char gray) {
        background(color{.r = gray, .g = gray, .b = gray});
    }

    void background(unsigned char r, unsigned char g, unsigned char b) {
        background(color{.r = r, .g = g, .b = b});
    }


    void fill(color rgba) {
        _fill = rgba;
    }

    void fill(unsigned char gray) {
        fill(color{.r = gray, .g = gray, .b = gray});
    }

    void fill(unsigned char r, unsigned char g, unsigned char b) {
        fill(color{.r = r, .g = g, .b = b});
    }

}