#pragma once

#include "color.h"

namespace pterm {
    extern int width;
    extern int height;

    extern int frameCount;

    extern colored_char* framebuffer;
    void _writeFramebuffer(int x, int y, colored_char c);

    void size(int width, int height);
    void frameRate(int fps);

    void run(void (*setup)(), void (*draw)());
}
