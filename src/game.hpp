#pragma once
#include "Obstacle.hpp"
#include "Spaceship.hpp"

class game {
  private:
    Spaceship spaceship;
    void deleteOffScreenLasers();
    std::vector<Obstacle> obstacles;
    std::vector<Obstacle> createObstacles();

  public:
    game(/* args */);
    ~game();
    void Draw();
    void Update();
    void HandleInput();
};
