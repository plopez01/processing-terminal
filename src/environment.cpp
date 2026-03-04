#include <cstdlib>
#include <iostream>
#include <ostream>
#include <unistd.h>

using namespace std;

namespace pterm {

    int width = 32;
    int height = 32;

    int _frameRate = 60;
    int frameCount = 0;

    char* framebuffer = nullptr;

    void size(int width, int height) {
        pterm::width = width;
        pterm::height = height;

        if (framebuffer != nullptr) free(framebuffer);

        framebuffer = (char*) malloc(width * height * sizeof(char));

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                framebuffer[y * width + x] = ' ';
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
                    cout << framebuffer[y * width + x];
                }
                cout << '\n';
            }
            cout.flush();
            
            usleep(1e6 / _frameRate);
            frameCount++;
        }
    }
}