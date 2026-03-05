#include "environment.h"
#include "color.h"

namespace pterm {

    bool _fill = true;
    char _fillBrush = '@';
    color _fillColor = {.r = 255, .g = 255, .b = 255};
    
    bool _stroke = true;
    char _strokeBrush = '@';
    color _strokeColor = {.r = 255, .g = 255, .b = 255};

    float rangeR = 255;
    float rangeG = 255;
    float rangeB = 255;

    ColorMode _colorMode = RGB;

    void fillBrush(char c) {
        _fillBrush = c;
    }

    void strokeBrush(char c) {
        _strokeBrush = c;
    }

    color new_color(float r, float g, float b) {
        return color{
            .r = (unsigned char)(r / rangeR * 255),
            .g = (unsigned char)(g / rangeG * 255),
            .b = (unsigned char)(b / rangeB * 255)
        };
    }

    color new_color(float gray) {
        return new_color(gray, gray, gray);
    }

    void background(color rgba) {
        if (_colorMode == HSB) rgba = hsv2rgb(rgba);

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                framebuffer[y * width + x] = colored_char{_fillBrush, rgba};
            }
        }
    }

    void background(float gray) {
        background(new_color(gray));
    }

    void background(float r, float g, float b) {
        background(new_color(r, g, b));
    }


    void fill(color rgba) {
        if (_colorMode == HSB) rgba = hsv2rgb(rgba);
        _fillColor = rgba;
    }

    void fill(float gray) {
        fill(new_color(gray));
    }

    void fill(float r, float g, float b) {
        fill(new_color(r, g, b));
    }

    void noFill() {
        _fill = false;
    }


    void stroke(color rgba) {
        if (_colorMode == HSB) rgba = hsv2rgb(rgba);
        _strokeColor = rgba;
        _stroke = true;
    }

    void stroke(float gray) {
        stroke(new_color(gray));
    }

    void stroke(float r, float g, float b) {
        stroke(new_color(r, g, b));
    }

    void noStroke() {
        _stroke = false;
    }

    void colorMode(ColorMode mode) {
        _colorMode = mode;
    }

    void colorMode(ColorMode mode, float max) {
        _colorMode = mode;
        rangeR = max;
        rangeG = max;
        rangeB = max;
    }
    void colorMode(ColorMode mode, float max1, float max2, float max3) {
        _colorMode = mode;
        rangeR = max1;
        rangeG = max2;
        rangeB = max3;
    }


    // Adapted from https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
    color hsv2rgb(color hsvColor)
    {
        double h = hsvColor.r / 255.0 * 360.0;
        double s = hsvColor.g / 255.0;
        double v = hsvColor.b / 255.0;

        double hh, p, q, t, ff;
        long i;

        double r, g, b;
    

        if(s <= 0.0) {
            return {.r = (unsigned char)(v*255.0), 
                    .g = (unsigned char)(v*255.0), 
                    .b = (unsigned char)(v*255.0)};
        }
        
        hh = h;
        if(hh >= 360.0) hh = 0.0;
        hh /= 60.0;
        i = (long)hh;
        ff = hh - i;
        p = v * (1.0 - s);
        q = v * (1.0 - (s * ff));
        t = v * (1.0 - (s * (1.0 - ff)));

        switch(i) {
        case 0:
            r = v;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = v;
            b = p;
            break;
        case 2:
            r = p;
            g = v;
            b = t;
            break;

        case 3:
            r = p;
            g = q;
            b = v;
            break;
        case 4:
            r = t;
            g = p;
            b = v;
            break;
        case 5:
        default:
            r = v;
            g = p;
            b = q;
            break;
        }

        return {
            .r = (unsigned char)(r * 255.0),
            .g = (unsigned char)(g * 255.0),
            .b = (unsigned char)(b * 255.0)
        };     
    }

}