#pragma once

#include "SFML/Window/Keyboard.hpp"

#include "maze.h"
#include "player.h"

class Game {
    public:
    Game(sf::RenderWindow *_Window);

    void Update(float _dTime);
    void Render();

  private:
    void MovePlayer(float _dTime);

    sf::RenderWindow *mWindow;

    Maze mMaze;
    Player mPlayer;

    float mTimeSinceLastMove;
};
