#include "environment.h"
#include "color.h"


namespace pterm {
    void point(int x, int y) {
        if  (_stroke) {
            _writeFramebuffer(x, y, colored_char{_strokeBrush, _strokeColor});
        }
    }


    void rect(int x, int y, int w, int h) {
        for (int j = y; j < y + h; j++) {
            for (int i = x; i < x + w; i++) {
                // If edge
                if (_stroke && (i == x || i == x + w - 1 || j == y || j == y + h - 1)) {
                    _writeFramebuffer(i, j, colored_char{_strokeBrush, _strokeColor});
                }
                else if (_fill) {
                    _writeFramebuffer(i, j, colored_char{_fillBrush, _fillColor});
                }
            }
        }
    }

    void ellipse(int x, int y, int w, int h) {
        for (int j = y - h/2.0; j < y + h/2.0; j++) {
            for (int i = x - w/2.0; i < x + w/2.0; i++) {
                float dist = ((i - x)*(i - x)) / ((float)(w/2.0)*(w/2.0)) + ((j - y)*(j - y)) / ((float)(h/2.0)*(h/2.0));

                // If edge
                if (_stroke && dist < 1 && dist > 0.9) {
                    _writeFramebuffer(i, j, colored_char{_strokeBrush, _strokeColor});
                }
                else if (_fill && dist < 1) {
                    _writeFramebuffer(i, j, colored_char{_fillBrush, _fillColor});
                }
            }
        }
    }
}