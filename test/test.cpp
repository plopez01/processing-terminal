#include "color.h"
#include "environment.h"
#include "shape.h"
#include "math.h"

#include <iostream>

using namespace pterm;

void setup() {
    size(80, 40);
}

void draw() {
    std::cout << frameCount << std::endl;
    colorMode(HSB, 255, 255, 255);

    stroke(255, 255, 255);
    fill(frameCount % 255, 255, 255);
    ellipse(10, 10, 20, 10);

}

int main() {

    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;

    run(setup, draw);
}