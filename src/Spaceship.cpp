#include "Spaceship.hpp"

Spaceship::Spaceship() {
    image = LoadTexture("assets/Graphics/spaceship.png");
    position.x = GetScreenWidth() / 2 - image.width / 2;
    position.y = GetScreenHeight() - image.height - 120;
    lastFireTime = 0.0;
    speed = 5;
    laserSound = LoadSound("assets/Sounds/laser.ogg");
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
    UnloadSound(laserSound);
}

void Spaceship::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft() {
    if (position.x > 15)
        position.x -= speed;
}

void Spaceship::MoveRight() {
    if (position.x < GetScreenWidth() - image.width - 15)
        position.x += speed;
}

void Spaceship::FireLaser() {
    if (GetTime() - lastFireTime >= 0.35) { // fire rate limit: 0.5 seconds
        lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y}, -6));
        lastFireTime = GetTime();
        PlaySound(laserSound);
    }
}

Rectangle Spaceship::getRect() const {
    return {position.x, position.y, float(image.width), float(image.height)};
}

void Spaceship::Reset() {
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height - 120;
    lasers.clear(); // Clear all existing lasers when resetting
}
