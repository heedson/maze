#include "player.h"

Player::Player() {
}

void Player::Initialize(float _CellSize) {
    mCellSize = _CellSize;

    mObject.setRadius((mCellSize * 0.5f) * 0.75f);
    // Maths to keep the player lined up with the centre of the cells.
    mObject.setOrigin(sf::Vector2f(-(mCellSize * 0.5f) * 0.25f, -(mCellSize * 0.5f) * 0.25f));
    mObject.setFillColor(sf::Color(20, 200, 20));

    mPosition = sf::Vector2i(0, 0);
    mObject.setPosition(sf::Vector2f(mPosition.x, mPosition.y) * mCellSize);
}

void Player::SetPosition(sf::Vector2i _NewPosition) {
    mPosition = _NewPosition;
    mObject.setPosition(sf::Vector2f(mPosition.x, mPosition.y) * mCellSize);
}

void Player::UpdatePosition(sf::Vector2i _Movement) {
    mPosition += _Movement;
    mObject.setPosition(sf::Vector2f(mPosition.x, mPosition.y) * mCellSize);
}

sf::Vector2i Player::GetPosition() {
    return mPosition;
}

sf::CircleShape Player::Draw() {
    return mObject;
}