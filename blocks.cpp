#include "block.h"
#include "position.h"

class LBlock : public Block //class lblock inherits from class block
{
public:
    LBlock()
    {
        id = 1; //unique id
        cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
        cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) }; //positions for each rotation state
        Move(0, 3); //initial move to position the block correctly
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;
        cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
        Move(0, 3);
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;
        cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
        cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
        cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
        cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
        Move(-1, 3);
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
        Move(0, 4);
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;
        cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
        cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
        cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
        Move(0, 3);
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;
        cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
        Move(0, 3);
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;
        cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
        cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
        cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
        cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
        Move(0, 3);
    }
};
