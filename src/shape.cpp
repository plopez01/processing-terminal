#include "environment.h"
#include "color.h"


namespace pterm {
    void point(int x, int y) {
        if  (_stroke) {
            framebuffer[y * width + x] = colored_char{_strokeBrush, _strokeColor};
        }
    }


    void rect(int x, int y, int w, int h) {
        for (int j = y; j < y + h; j++) {
            for (int i = x; i < x + w; i++) {
                // If edge
                if (_stroke && (i == x || i == x + w - 1 || j == y || j == y + h - 1)) {
                    framebuffer[j * width + i] = colored_char{_strokeBrush, _strokeColor};
                }
                else if (_fill) {
                    framebuffer[j * width + i] = colored_char{_fillBrush, _fillColor};
                }
            }
        }
    }
}