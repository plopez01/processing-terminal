#pragma once

typedef union {
    int color;

    struct {
        unsigned char a;
        unsigned char r;
        unsigned char g;
        unsigned char b;
    };
} color;

void brush(char c);

void background(color rgba);
void background(unsigned char gray);
void background(unsigned char r, unsigned char g, unsigned char b);
void background(unsigned char r, unsigned char g, unsigned char b, unsigned char a);