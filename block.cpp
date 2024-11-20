#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();
    for (Position item : tiles) //loop through each cell position and draw the cell
    {
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}
// get the positions of the cells that make up the block
std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];// get the positions of the cells in the current rotation state
    std::vector<Position> movedTiles;
    for (Position item : tiles)  // Calculate the new positions based on the offsets
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size()) // reset rotation state if it exceeds the number of states
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--; // decrement the rotation state
    if (rotationState == -1) //set rotation state to the last state if it goes below 0
    {
        rotationState = cells.size() - 1;
    }
}
