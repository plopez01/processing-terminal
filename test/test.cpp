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
    rect(10, 10, 10, 5);
}

int main() {

    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;

    run(setup, draw);
}