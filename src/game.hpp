#pragma once
#include "Alien.hpp"
#include "Obstacle.hpp"
#include "Spaceship.hpp"

class game {
  private:
    Spaceship spaceship;
    void deleteOffScreenLasers();
    std::vector<Obstacle> obstacles;
    std::vector<Obstacle> createObstacles();
    std::vector<Alien> aliens;
    std::vector<Alien> createAliens();
    void MoveAliens();
    int alienDirection;
    void MoveDownAliens(int distance);
    std::vector<Laser> alienLasers;
    void AlienShoot();
    constexpr static float alienLaserShootInterval = 0.35; // Time interval between alien shots
    float timeLastAlienShot; // Time when the last alien shot was fired

  public:
    game(/* args */);
    ~game();
    void Draw();
    void Update();
    void HandleInput();
};
