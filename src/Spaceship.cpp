#include "Spaceship.hpp"

Spaceship::Spaceship() {
    image = LoadTexture("assets/Graphics/spaceship.png");
    position.x = GetScreenWidth() / 2 - image.width / 2;
    position.y = GetScreenHeight() - image.height - 20;
    lastFireTime = 0.0;
    speed = 5;
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
}

void Spaceship::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft() {
    if (position.x > 0)
        position.x -= speed;
}

void Spaceship::MoveRight() {
    if (position.x < GetScreenWidth() - image.width)
        position.x += speed;
}

void Spaceship::FireLaser() {
    if (GetTime() - lastFireTime >= 0.35) { // fire rate limit: 0.5 seconds
        lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y}, -6));
        lastFireTime = GetTime();
    }
}
