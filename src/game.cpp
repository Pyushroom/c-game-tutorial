#include "game.hpp"
#include <iostream>

game::game() {}

game::~game() {}

void game::Update() {
    for (auto& laser : spaceship.lasers) {
        laser.Update();
    }

    deleteOffScreenLasers();
}

void game::Draw() {
    spaceship.Draw();

    for (auto& laser : spaceship.lasers) {
        laser.Draw();
    }
}

void game::HandleInput() {
    if (IsKeyDown(KEY_LEFT)) {
        spaceship.MoveLeft();
    } else if (IsKeyDown(KEY_RIGHT)) {
        spaceship.MoveRight();
    } else if (IsKeyPressed(KEY_SPACE)) {
        spaceship.FireLaser();
    }
}

void game::deleteOffScreenLasers() {
    for (auto it = spaceship.lasers.begin(); it != spaceship.lasers.end();) {
        if (it->IsOffScreen) {
            // std::cout << "Deleted off-screen laser!" << std::endl;
            it = spaceship.lasers.erase(it);
        } else {
            ++it;
        }
    }
}