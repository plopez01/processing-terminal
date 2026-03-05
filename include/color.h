#pragma once

namespace pterm {

    // color components are always 0-255
    typedef union {
        int color;

        struct {
            unsigned char a;
            unsigned char r;
            unsigned char g;
            unsigned char b;
        };
    } color;

    typedef struct {
        char character;
        color foreColor;
    } colored_char;

    enum ColorMode {
        RGB,
        HSB
    };


    extern char _brush;
    extern color _fill;
    extern color _stroke;

    void brush(char c);

    color new_color(float r, float g, float b);
    color new_color(float gray);

    void background(color rgba);
    void background(float gray);
    void background(float r, float g, float b);

    void fill(color rgba);
    void fill(float gray);
    void fill(float r, float g, float b);


    void stroke(color rgba);
    void stroke(float gray);
    void stroke(float r, float g, float b);

    void colorMode(ColorMode mode);
    void colorMode(ColorMode mode, float max);
    void colorMode(ColorMode mode, float max1, float max2, float max3);

    color hsv2rgb(color hsvColor);
}

