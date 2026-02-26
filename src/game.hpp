#pragma once
#include "Spaceship.hpp"

class game {
  private:
    Spaceship spaceship;
    void deleteOffScreenLasers();

  public:
    game(/* args */);
    ~game();
    void Draw();
    void Update();
    void HandleInput();
};
