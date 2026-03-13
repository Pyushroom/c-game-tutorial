#include "Spaceship.hpp"
#include "game.hpp"
#include "raylib.h"

int main() {
    Color grey = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    int offset = 50;
    const int W = 800;
    const int H = 600;

    InitWindow(W + offset, H + 2 * offset, "raylib tutorial");
    InitAudioDevice();

    Font font = LoadFontEx("assets/Font/monogram.ttf", 64, 0, 0);
    Texture2D image = LoadTexture("assets/Graphics/spaceship.png");

    SetTargetFPS(60);

    game game;

    while (!WindowShouldClose()) {
        UpdateMusicStream(game.backgroundMusic);

        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10, 10, 830, 680}, 0.18f, 20, yellow);
        DrawLineEx({15, H - 10}, {W - 15, H - 10}, 3, yellow);

        game.Draw(font);

        if (game.state == GameState::PLAYING) {
            DrawTextEx(font, "Level 1", {W - 100, H - 2}, 32, 2, yellow);

            for (int i = 0; i < game.lives; i++) {
                DrawTextureV(image, {15 + i * (image.width + 10), H - 2}, WHITE);
            }

            DrawTextEx(font, TextFormat("Score: %d", game.score), {15, 15}, 32, 2, yellow);
        }

        EndDrawing();
    }

    UnloadTexture(image);
    UnloadFont(font);
    CloseWindow();
    CloseAudioDevice();
    return 0;
}
