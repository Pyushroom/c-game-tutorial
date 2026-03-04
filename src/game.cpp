#include "game.hpp"
#include <iostream>

game::game() {
    obstacles = createObstacles();
}

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

    for (auto& obstacle : obstacles) {
        obstacle.Draw();
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

std::vector<Obstacle> game::createObstacles() {
    int obstacleWidth = Obstacle::grid[0].size() * 3; // each block is 3 pixel wide
    // Implementation for creating obstacles

    float gap = (GetScreenWidth() - (4 * obstacleWidth)) / 5; // Calculate gap between obstacles

    for (int i = 0; i < 4; i++) {
        float offsetX = (i + 1) * gap + i * obstacleWidth; // Calculate x position for each obstacle
        obstacles.push_back(Obstacle(
            {offsetX, float(GetScreenHeight() - 100)})); // Create obstacle at calculated position
    }
    return obstacles;
}
