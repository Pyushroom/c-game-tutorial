#pragma once
#include "raylib.h"

class MisteryShip {
  public:
    MisteryShip();
    ~MisteryShip();

    void Update();
    void Draw();
    void Spawn();
    bool alive;
    Rectangle getRect() const;

  private:
    Vector2 position;
    Texture2D image;
    int speed;
};
