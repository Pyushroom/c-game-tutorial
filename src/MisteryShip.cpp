#include "MisteryShip.hpp"

MisteryShip::MisteryShip() {
    image = LoadTexture("assets/Graphics/mystery.png");
    alive = false;
}

MisteryShip::~MisteryShip() {
    UnloadTexture(image);
}

void MisteryShip::Update() {
    if (alive) {
        position.x += speed;
        if (position.x > GetScreenWidth() - image.width - 15 || position.x < 15) {
            alive = false; // Deactivate if it goes off-screen
        }
    }
}

void MisteryShip::Draw() {
    if (alive) {
        DrawTextureV(image, position, WHITE);
    }
}

void MisteryShip::Spawn() {
    position.y = 90;
    int side = GetRandomValue(0, 1);

    if (side == 0) {
        position.x = -image.width; // Spawn from the left
        speed = 3;                 // Move right
    } else {
        position.x = GetScreenWidth() - image.width - 15; // Spawn from the right
        speed = -3;                                       // Move left
    }
    alive = true;
}

Rectangle MisteryShip::getRect() const {
    if (alive) {
        return {position.x, position.y, float(image.width), float(image.height)};
    } else {
        return {position.x, position.y, 0, 0}; // Return an empty rectangle if not alive
    }
}
