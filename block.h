#pragma once
#include <vector> //library for dynamic arrays
#include <map> //library for key-value pairs
#include "position.h"
#include "colors.h"

class Block
{
public:
    Block(); //constructor
    void Draw(int offsetX, int offsetY); //draw with specified offsets
    void Move(int rows, int columns); //move by specified number of rows and columns
    std::vector<Position> GetCellPositions(); //get position of cells that make a block
    void Rotate();
    void UndoRotation();
    int id; //unique identifier of the block
    std::map<int, std::vector<Position>> cells; //map of cell positions for different rotation states

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};

