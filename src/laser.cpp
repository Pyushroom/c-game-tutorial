#include "laser.hpp"
#include <iostream>

Laser::Laser(Vector2 position, int speed) {
    this->position = position;
    this->speed = speed;
    IsOffScreen = false;
}

Laser::~Laser() {}

void Laser::Draw() {
    if (!IsOffScreen) {
        DrawRectangle(position.x, position.y, 4, 15, YELLOW);
    }
}

void Laser::Update() {
    position.y += speed;
    if (!IsOffScreen && (position.y < 0 || position.y > GetScreenHeight())) {
        IsOffScreen = true;
        // std::cout << "Laser went off screen!" << std::endl;
    }
}

Rectangle Laser::getRect() const {
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 4;
    rect.height = 15;
    return rect;
}
