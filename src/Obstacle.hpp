#pragma once
#include "Block.hpp"
#include <vector>

class Obstacle {
  private:
  public:
    Obstacle(Vector2 position);
    ~Obstacle();
    void Draw();
    Vector2 position;
    std::vector<Block> blocks;
    static std::vector<std::vector<int>> grid;
};