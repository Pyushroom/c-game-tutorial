#include "Alien.hpp"

Texture2D Alien::alienImages[3] = {};

void Alien::UnloadImages() {
    for (int i = 0; i < 3; i++) {
        UnloadTexture(alienImages[i]);
    }
}

Alien::Alien(int type, Vector2 position) {
    this->type = type;
    this->position = position;

    if (alienImages[type - 1].id == 0) {
        switch (type) {
        case 1:
            alienImages[0] = LoadTexture("assets/Graphics/alien_1.png");
            break;
        case 2:
            alienImages[1] = LoadTexture("assets/Graphics/alien_2.png");
            break;
        case 3:
            alienImages[2] = LoadTexture("assets/Graphics/alien_3.png");
            break;

        default:
            alienImages[0] = LoadTexture("assets/Graphics/alien_1.png");
            break;
        }
    }
}

Alien::~Alien() {}

void Alien::Update(int direction) {
    position.x += direction; // Move alien horizontally based on direction
}

void Alien::Draw() {
    DrawTexture(alienImages[type - 1], position.x, position.y, WHITE);
}

int Alien::getType() {
    return this->type;
}

Rectangle Alien::getRect() const {
    return {position.x, position.y, float(alienImages[type - 1].width),
            float(alienImages[type - 1].height)};
}
