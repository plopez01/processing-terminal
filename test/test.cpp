#include "color.h"
#include "environment.h"

#include <iostream>

using namespace std;


void setup() {
    size(10, 5);
}

void draw() {
    cout << frameCount << endl;
    background(frameCount % 256, 255, 255);
}

int main() {

    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;

    run(setup, draw);
}