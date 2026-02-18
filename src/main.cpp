#include "raylib.h"

int main() {
    const int W = 800;
    const int H = 600;

    InitWindow(W, H, "My 2D Game (raylib)");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Hello raylib!", 280, 280, 20, DARKGRAY);
        DrawCircle(400, 300, 40, SKYBLUE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
