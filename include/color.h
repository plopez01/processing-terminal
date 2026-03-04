#pragma once

namespace pterm {
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

    extern char _brush;
    extern color _fill;
    extern color _stroke;

    void brush(char c);

    void background(color rgba);
    void background(unsigned char gray);
    void background(unsigned char r, unsigned char g, unsigned char b);

    void fill(color rgba);
    void fill(unsigned char gray);
    void fill(unsigned char r, unsigned char g, unsigned char b);


    void stroke(color rgba);
    void stroke(unsigned char gray);
    void stroke(unsigned char r, unsigned char g, unsigned char b);
}

