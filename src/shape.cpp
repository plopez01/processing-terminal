#include "environment.h"
#include "color.h"
#include <iostream>


namespace pterm {
    void rect(int x, int y, int w, int h) {
        _setForegroundTrueColor(_fill);

        for (int j = y; j < y + h; j++) {
            for (int i = x; i < x + w; i++) {
                framebuffer[j * width + i] = _brush;
            }
        }
    }
}