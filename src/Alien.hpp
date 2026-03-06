#pragma once
#include "raylib.h"

class Alien {
  private:
  public:
    static Texture2D alienImages[3];
    static void UnloadImages();
    int type;
    Vector2 position;
    Alien(int type, Vector2 position);
    ~Alien();
    void Update(int direction);
    void Draw();
    int getType();
    Rectangle getRect() const;
};
