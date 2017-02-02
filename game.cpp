#include "game.h"

#include <cstdlib>
#include <ctime>

Game::Game(sf::RenderWindow *_Window) {
    mWindow = _Window;

    srand((int) time(0));

    mMaze.Initialize();
    mPlayer.Initialize(mMaze.GetCellSize());

    while(!mMaze.OkayMove(mPlayer.GetPosition().x, mPlayer.GetPosition().y)) {
        mPlayer.SetPosition(sf::Vector2i((rand() % mMaze.GetGridWidth()), (rand() % mMaze.GetGridHeight())));
    }

    mTimeSinceLastMove = 0.0f;
}

void Game::Update(float _dTime) {
    MovePlayer(_dTime);

    mMaze.Update(mPlayer.GetPosition());
}

void Game::MovePlayer(float _dTime) {
    mTimeSinceLastMove += _dTime;

    if (mTimeSinceLastMove < 0.2f) {
        return;
    }

    int playerX = mPlayer.GetPosition().x;
    int playerY = mPlayer.GetPosition().y;

    if((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || 
    sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) &&
    playerY > 0) {
        if (mMaze.OkayMove(playerX, playerY - 1)) {
            playerY--;
            mTimeSinceLastMove = 0.0f;
        }
    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::A) || 
    sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) &&
    playerX > 0) {
        if (mMaze.OkayMove(playerX - 1, playerY)) {
            playerX--;
            mTimeSinceLastMove = 0.0f;
        }
    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::S) || 
    sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) &&
    playerY < mMaze.GetGridHeight() - 1) {
        if (mMaze.OkayMove(playerX, playerY + 1)) {
            playerY++;
            mTimeSinceLastMove = 0.0f;
        }
    }
    else if((sf::Keyboard::isKeyPressed(sf::Keyboard::D) || 
    sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) &&
    playerX < mMaze.GetGridWidth() - 1) {
        if (mMaze.OkayMove(playerX + 1, playerY)) {
            playerX++;
            mTimeSinceLastMove = 0.0f;
        }
    }

    mPlayer.SetPosition(sf::Vector2i(playerX, playerY));
}

void Game::Render() {
    mWindow->clear();

    for (int i = 0; i < mMaze.GetGridWidth(); i++) {
        for (int j = 0; j < mMaze.GetGridHeight(); j++) {
            mWindow->draw(mMaze.Draw(i, j));
        }
    }

    mWindow->draw(mPlayer.Draw());

    mWindow->display();
}
