#pragma once

#include "SFML/Graphics.hpp"

#include "helper.h"

class Cell {
  public:
    Cell(sf::Vector2i _Coord, bool _Solid);
    Cell(int _X, int _Y, bool _Solid);

    void Resize(float _NewSize);
    void SetColor(float _Brightness);
    void Recolor(sf::Color _NewColor);

    bool Solid();
    void IsSolid(bool _Solid);

    sf::RectangleShape Draw();

  private:
    sf::RectangleShape mCell;

    sf::Vector2i mPosition;
    sf::Color mColor;


    float mSize;
    int mPlayerDistance;
    bool mIsSolid;
};
