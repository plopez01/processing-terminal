#include "color.h"

#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

namespace pterm {

    int width = 32;
    int height = 32;

    int _frameRate = 60;
    int frameCount = 0;

    colored_char* framebuffer = nullptr;

    void size(int width, int height) {
        pterm::width = width;
        pterm::height = height;

        if (framebuffer != nullptr) free(framebuffer);

        framebuffer = (colored_char*) malloc(width * height * sizeof(colored_char));

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                framebuffer[y * width + x] = colored_char{' ', color{.r = 255, .g = 255, .b = 255}};
            }
        }
    }

    void frameRate(int fps) {
        _frameRate = fps;
    }

    void run(void (*setup)(), void (*draw)()) {
        setup();

        while (1) {
            cout << "\x1b[2J"; // Clear screen
            cout << "\x1b[H"; // Move cursor to home (0, 0)

            draw();
            
            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    colored_char pixel = framebuffer[y * width + x];
                    cout << "\x1b[38;2;" << (int)pixel.foreColor.r << ";" << (int)pixel.foreColor.g << ";" << (int)pixel.foreColor.b << "m";
                    cout << pixel.character;
                }
                cout << '\n';
            }
            cout.flush();
            
            usleep(1e6 / _frameRate);
            frameCount++;
        }
    }
}