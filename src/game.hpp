#pragma once
#include "Alien.hpp"
#include "MisteryShip.hpp"
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
    constexpr static double alienLaserShootInterval = 0.35;
    double timeLastAlienShot;
    MisteryShip misteryShip;
    double misteryShipInterval;
    double timeLastSpawnMistery;
    void checkCollisions();

  public:
    game(/* args */);
    ~game();
    void Draw();
    void Update();
    void HandleInput();
};
