#include "environment.h"
#include "color.h"

namespace pterm {

    char _brush = '@';
    color _fill = {.r = 255, .g = 255, .b = 255};
    color _stroke = {.r = 255, .g = 255, .b = 255};

    void brush(char c) {
        _brush = c;
    }

    void background(color rgba) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                framebuffer[y * width + x] = colored_char{_brush, rgba};
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


    void stroke(color rgba) {
        _stroke = rgba;
    }

    void stroke(unsigned char gray) {
        stroke(color{.r = gray, .g = gray, .b = gray});
    }

    void stroke(unsigned char r, unsigned char g, unsigned char b) {
        stroke(color{.r = r, .g = g, .b = b});
    }

}