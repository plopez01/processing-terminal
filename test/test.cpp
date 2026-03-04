#include "color.h"
#include "environment.h"
#include "shape.h"

#include <iostream>

using namespace pterm;

void setup() {
    size(140, 40);
}

void draw() {
    std::cout << frameCount << std::endl;
    fill(255, 0, 0);
    rect(10, 10, 8, 5);

    stroke(0, 255, 0);
    point(20, 10);

    fill(0, 0, 255);
    rect(20, 20, 6, 3);
}

int main() {

    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;

    run(setup, draw);
}