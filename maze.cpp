#include "maze.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

Maze::Maze() {
}

void Maze::Initialize() {
    std::string line;
    std::ifstream inputMaze("input.txt");

    if (inputMaze.is_open()) {
        int row = 0;
        int column;

        int longestRow = 0;

        while (getline(inputMaze, line)) {
            std::vector<Cell> cells;
            
            std::replace(line.begin(), line.end(), ' ', '_');
            
            std::istringstream iss(line);
            char cellString;

            column = 0;

            while(iss >> cellString) {
                switch (cellString) {
                case '#':
                    cells.push_back(Cell(sf::Vector2i(column, row), true));
                    break;
                case 'X':
                    cells.push_back(Cell(sf::Vector2i(column, row), false));
                    cells[column].Recolor(sf::Color(20, 150, 20));
                    break;
                default:
                    cells.push_back(Cell(sf::Vector2i(column, row), false));
                }

                column++;
            }

            row++;

            mGrid.push_back(cells);
        }

        RescaleCells(row, column);
        
        inputMaze.close();
    }
    else {
        std::cout << "Unable to open file";
    }
}

void Maze::RescaleCells(int _Rows, int _Columns) {
    if (_Rows > _Columns) {
        mCellSize = WindowSize / _Rows;
    }
    else {
        mCellSize = WindowSize / _Columns;
    }
    
    for (int i = 0; i < _Rows; i++) {
        for (int j = 0; j < _Columns; j++) {
            mGrid[i][j].Resize(mCellSize);
        }
    }
}

void Maze::Update(sf::Vector2i _PlayerPosition) {
    for (int i = -5; i < 6; i++) {
        if (_PlayerPosition.y + i < 0 || _PlayerPosition.y + i >= GetGridHeight())
        {
            continue;
        }

        for (int j = -5; j < 6; j++) {
            if (_PlayerPosition.x + j < 0 || _PlayerPosition.x + j >= GetGridWidth())
            {
                continue;
            }

            mGrid[_PlayerPosition.y + i][_PlayerPosition.x + j].SetColor(1.0f / (abs(i) + abs(j) + 1.0f));
        }
    }
}

bool Maze::OkayMove(int _X, int _Y) {
    return !mGrid[_Y][_X].Solid();
}

int Maze::GetGridWidth() {
    return mGrid[0].size();
}

int Maze::GetGridHeight() {
    return mGrid.size();
}

float Maze::GetCellSize() {
    return mCellSize;
}

sf::RectangleShape Maze::Draw(int _X, int _Y) {
    return mGrid[_Y][_X].Draw();
}
