#include "environment.h"
#include "color.h"


namespace pterm {
    void point(int x, int y) {
        framebuffer[y * width + x] = colored_char{_brush, _stroke};
    }


    void rect(int x, int y, int w, int h) {
        for (int j = y; j < y + h; j++) {
            for (int i = x; i < x + w; i++) {
                framebuffer[j * width + i] = colored_char{_brush, _fill};
            }
        }
    }
}