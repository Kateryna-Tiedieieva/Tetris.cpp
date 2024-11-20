#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0; //tracks update time for game

bool EventTriggered(double interval) //check if the specific interval of time has passed
{
    double currentTime = GetTime(); 
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(500, 620, "raylib Tetris"); //main window
    SetTargetFPS(60); //speed

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game(); //create an istance of game class

    while (WindowShouldClose() == false) 
    {
        game.HandleInput(); //handle user input
        if (EventTriggered(0.2))
        {
            game.MoveBlockDown();
        } //move block down if the specific interval has passed

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", { 365, 15 }, 38, 2, WHITE);
        DrawTextEx(font, "Next", { 370, 175 }, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", { 320, 450 }, 38, 2, WHITE);
        }
        DrawRectangleRounded({ 320, 55, 170, 60 }, 0.3, 6, lightBlue); //score background

        char scoreText[10];
        sprintf_s(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); //format the score as string and measure its size

        DrawTextEx(font, scoreText, { 320 + (170 - textSize.x) / 2, 65 }, 38, 2, WHITE); //draw the score text centered within the rectangle
        DrawRectangleRounded({ 320, 215, 170, 180 }, 0.3, 6, lightBlue); //next block background
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}