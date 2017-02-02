#pragma once

#include <vector>

#include "SFML/Graphics.hpp"

#include "cell.h"

class Maze {
  public:
    Maze();
    void Initialize();

    void Update(sf::Vector2i _PlayerPosition);

    bool OkayMove(int _X, int _Y);

    int GetGridWidth();
    int GetGridHeight();
    float GetCellSize();

    sf::RectangleShape Draw(int _X, int _Y);

  private:
    void RescaleCells(int _Rows, int _Columns);

    std::vector<std::vector<Cell> > mGrid;

    float mCellSize;
};
