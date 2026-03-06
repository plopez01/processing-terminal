#include <random>

std::random_device dev;
std::mt19937 rng(dev());

float random(float high) {
    std::uniform_real_distribution<> dist(0.0, high); 
    return dist(dev);
}

float random(float low, float high) {
    std::uniform_real_distribution<> dist(low, high); 
    return dist(dev);
}