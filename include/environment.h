#pragma once

namespace pterm {
    extern int width;
    extern int height;

    extern int frameCount;

    extern char* framebuffer;

    void size(int width, int height);
    void frameRate(int fps);

    void run(void (*setup)(), void (*draw)());
}
