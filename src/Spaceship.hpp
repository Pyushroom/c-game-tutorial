#pragma once
#include "laser.hpp"
#include "raylib.h"
#include <vector>

class Spaceship {

  public:
    Spaceship();
    ~Spaceship();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();
    std::vector<Laser> lasers; // holding all laser objects fired by the spaceship

  private:
    Texture2D image;
    Vector2 position;
    int speed;
    double lastFireTime;
};
