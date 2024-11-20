#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Game::~Game()
{}

Block Game::GetRandomBlock()
{
    if (blocks.empty()) //if no blocks are left get all blocks again
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size(); //generate random index
    Block block = blocks[randomIndex]; //get block at random index
    blocks.erase(blocks.begin() + randomIndex); //remove the block from the vector
    return block; //return the random block
}

std::vector<Block> Game::GetAllBlocks()
{
    return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() }; //return a vector of all block shapes
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11, 11); //draw current block with an offset
    switch (nextBlock.id) //draw next block based on its id
    {
    case 3:
        nextBlock.Draw(255, 290);
        break;
    case 4:
        nextBlock.Draw(255, 280);
        break;
    default:
        nextBlock.Draw(270, 270);
        break;
    }
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0) //if the game is over and any key is pressed, reset the game
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed) //handle different key presses
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock.Move(0, -1); //move left by 1 column
        if (IsBlockOutside() || BlockFits() == false) //if block is outside or doesn't fit move it back
        {
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if (!gameOver)
    {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!gameOver)
    {
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false) //if block is outside or doesn't fit move it back and lock
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions(); //get pocisions of block cells
    for (Position item : tiles) //check each cell position
    {
        if (grid.IsCellOutside(item.row, item.column)) //if any cell is outside return true
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    if (!gameOver)
    {
        currentBlock.Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.UndoRotation();
        }
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles) //set on the grid all cell positions
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock; //set next block as current block
    if (BlockFits() == false) //if block doesn't fit set game over state
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows(); //clear full rows
    if (rowsCleared > 0) //if any rows were cleared update the score
    {
        UpdateScore(rowsCleared, 0);
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.column) == false) //if any cell is not empty return false
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}
