#include "color.h"
#include "environment.h"
#include "shape.h"

#include <iostream>

using namespace pterm;

void setup() {
    size(80, 40);
}

void draw() {
    std::cout << frameCount << std::endl;
    colorMode(HSB);

    fillBrush('O');
    strokeBrush('#');
    stroke(frameCount % 255, 255, 255);
    rect(10, 10, 15, 5);
}

int main() {

    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;

    run(setup, draw);
}