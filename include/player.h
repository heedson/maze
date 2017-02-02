#pragma once

#include "SFML/Graphics.hpp"

class Player {
  public:
    Player();
    void Initialize(float _CellSize);

    void SetPosition(sf::Vector2i _NewPosition);
    void UpdatePosition(sf::Vector2i _Movement);
    sf::Vector2i GetPosition();

    sf::CircleShape Draw();

  private:
    sf::CircleShape mObject;

    float mCellSize;
    sf::Vector2i mPosition;
};
