#pragma once
#include "Alien.hpp"
#include "MisteryShip.hpp"
#include "Obstacle.hpp"
#include "Spaceship.hpp"

enum class GameState { MENU, PLAYING, GAME_OVER };

class game {
  private:
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
    void GameOver();
    void Reset();
    void InitGame();
    void checkForHighScore();
    void saveHighScore(int newHighScore);
    int loadHighScore();
    Sound explosionSound;

  public:
    game();
    ~game();

    void Draw(Font font);
    void Update();
    void HandleInput();
    void DrawMenu(Font font);
    void HandleMenuInput();

    bool running;
    bool paused;
    int lives;
    Spaceship spaceship;
    int score;
    int highScore;
    Music backgroundMusic;
    GameState state;
};
