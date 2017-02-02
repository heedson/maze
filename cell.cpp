#include "cell.h"

Cell::Cell(sf::Vector2i _Coord, bool _Solid) {
    mPosition = _Coord;
    IsSolid(_Solid);
    SetColor(0.0f);
}

void Cell::Resize(float _NewSize) {
    mCell.setSize(sf::Vector2f(_NewSize, _NewSize));
    mCell.setPosition(sf::Vector2f(mPosition.x * _NewSize, mPosition.y * _NewSize));
}

void Cell::SetColor(float _Brightness) {
    mCell.setFillColor(sf::Color(mColor.r * _Brightness, mColor.g * _Brightness, mColor.b * _Brightness));
}

void Cell::Recolor(sf::Color _NewColor) {
    mColor = _NewColor;
}

bool Cell::Solid() {
    return mIsSolid;
}

void Cell::IsSolid(bool _Solid) {
    mIsSolid = _Solid;

    if (mIsSolid) {
        Recolor(sf::Color(20, 20, 150));
    } 
    else {
        Recolor(sf::Color(200, 200, 200));
    }
}

sf::RectangleShape Cell::Draw() {
    return mCell;
}
