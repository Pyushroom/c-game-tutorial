#include "game.hpp"
#include <iostream>

game::game() {
    obstacles = createObstacles();
    aliens = createAliens();
    alienDirection = 1;
    timeLastAlienShot = 0.0;
    timeLastSpawnMistery = GetTime();
    misteryShipInterval = static_cast<double>(GetRandomValue(10, 20));
}

game::~game() {
    Alien::UnloadImages();
}

void game::Update() {
    double currentTime = GetTime();
    if (currentTime - timeLastSpawnMistery > misteryShipInterval) {
        misteryShip.Spawn();
        timeLastSpawnMistery = currentTime;
        misteryShipInterval =
            static_cast<double>(GetRandomValue(10, 20)); // Randomize next spawn interval
    }

    for (auto& laser : spaceship.lasers) {
        laser.Update();
    }

    MoveAliens();
    AlienShoot();

    for (auto& laser : alienLasers) {
        laser.Update();
    }

    deleteOffScreenLasers();
    misteryShip.Update();

    checkCollisions();
}
void game::Draw() {
    spaceship.Draw();

    for (auto& laser : spaceship.lasers) {
        laser.Draw();
    }

    for (auto& obstacle : obstacles) {
        obstacle.Draw();
    }

    for (auto& alien : aliens) {
        alien.Draw();
    }

    for (auto& laser : alienLasers) {
        laser.Draw();
    }

    misteryShip.Draw();
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

    for (auto it = alienLasers.begin(); it != alienLasers.end();) {
        if (it->IsOffScreen) {
            // std::cout << "Deleted off-screen laser!" << std::endl;
            it = alienLasers.erase(it);
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

std::vector<Alien> game::createAliens() {

    std::vector<Alien> aliens;
    for (int row = 0; row < 5; row++) {
        for (int column = 0; column < 11; column++) {

            int alienType;
            if (row == 0) {
                alienType = 3;
            } else if (row == 1 || row == 2) {
                alienType = 2;
            } else {
                alienType = 1;
            }
            float x = 75 + column * 55;
            float y = 110 + row * 55;
            aliens.push_back(Alien(alienType, {x, y}));
        }
    }
    return aliens;
}

void game::MoveAliens() {
    for (auto& alien : aliens) {
        if (alien.position.x + alien.alienImages[alien.type - 1].width > GetScreenWidth()) {
            alienDirection = -1; // Change direction to left
            MoveDownAliens(4);

        } else if (alien.position.x < 0) {
            alienDirection = 1; // Change direction to right
            MoveDownAliens(4);
        }
        alien.Update(alienDirection);
    }
}

void game::MoveDownAliens(int distance) {

    for (auto& alien : aliens) {
        alien.position.y += distance;
    }
}

void game::AlienShoot() {
    double currentTime = GetTime();
    if (currentTime - timeLastAlienShot >= alienLaserShootInterval && !aliens.empty()) {
        int randomAlienIndex = GetRandomValue(0, aliens.size() - 1);
        Alien& alien = aliens[randomAlienIndex];
        alienLasers.push_back(Laser({alien.position.x + alien.alienImages[alien.type - 1].width / 2,
                                     alien.position.y + alien.alienImages[alien.type - 1].height},
                                    6));
        timeLastAlienShot = GetTime(); // Update the time of the last shot
    }
}

void game::checkCollisions() {
    for (auto& laser : spaceship.lasers) {
        if (laser.IsOffScreen) {
            continue;
        }

        auto alienIt = aliens.begin();
        while (alienIt != aliens.end()) {
            if (CheckCollisionRecs(alienIt->getRect(), laser.getRect())) {
                alienIt = aliens.erase(alienIt);
                laser.IsOffScreen = true;
                break;
            } else {
                ++alienIt;
            }
        }

        if (laser.IsOffScreen) {
            continue;
        }

        for (auto& obstacle : obstacles) {
            auto blockIt = obstacle.blocks.begin();
            while (blockIt != obstacle.blocks.end()) {
                if (CheckCollisionRecs(blockIt->getRect(), laser.getRect())) {
                    blockIt = obstacle.blocks.erase(blockIt);
                    laser.IsOffScreen = true;
                    break;
                } else {
                    ++blockIt;
                }
            }

            if (laser.IsOffScreen) {
                break;
            }
        }

        if (CheckCollisionRecs(misteryShip.getRect(), laser.getRect())) {
            misteryShip.alive = false;
            laser.IsOffScreen = true;
        }
    }

    // alien lasers
    for (auto& laser : alienLasers) {
        if (laser.IsOffScreen) {
            continue;
        }

        if (CheckCollisionRecs(laser.getRect(), spaceship.getRect())) {
            // Handle spaceship hit (e.g., reduce lives, end game, etc.)
            std::cout << "Spaceship hit!" << std::endl;
            laser.IsOffScreen = true; // Mark laser for removal
        }

        for (auto& obstacle : obstacles) {
            auto blockIt = obstacle.blocks.begin();
            while (blockIt != obstacle.blocks.end()) {
                if (CheckCollisionRecs(blockIt->getRect(), laser.getRect())) {
                    blockIt = obstacle.blocks.erase(blockIt);
                    laser.IsOffScreen = true;
                    break;
                } else {
                    ++blockIt;
                }
            }

            if (laser.IsOffScreen) {
                break;
            }
        }
    }

    // alien collisions with obstacles
    for (auto& alien : aliens) {
        for (auto& obstacle : obstacles) {
            auto blockIt = obstacle.blocks.begin();
            while (blockIt != obstacle.blocks.end()) {
                if (CheckCollisionRecs(blockIt->getRect(), alien.getRect())) {
                    blockIt = obstacle.blocks.erase(blockIt);
                    break;
                } else {
                    ++blockIt;
                }
            }
        }

        if (CheckCollisionRecs(alien.getRect(), spaceship.getRect())) {
            std::cout << "Spaceship hit by alien!" << std::endl;
        }
    }
}