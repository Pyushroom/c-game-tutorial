#include "Spaceship.hpp"
#include "game.hpp"
#include "raylib.h"

int main() {
    Color grey = {29, 29, 27, 255};
    const int W = 800;
    const int H = 600;

    InitWindow(W, H, "raylib tutorial");
    SetTargetFPS(60);

    game game;

    while (!WindowShouldClose()) {

        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(grey);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
