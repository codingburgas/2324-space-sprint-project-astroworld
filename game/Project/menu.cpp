#include "menu.h"
#include "game.h"
#include "rules.h"
void mainMenu()
{
    const int screenWidth = 1920;
    const int screenHeight = 975;
    InitWindow(screenWidth, screenHeight, "ASTROWORLD");
    bool exitGame = WindowShouldClose();
    Texture2D menuBG = LoadTexture("../images/mainMenuBg.png");
    const Rectangle startButton = { (screenWidth / 2) + 340, (screenHeight / 2) - 15, 270, 90 };
    const Rectangle rulesButton = { (screenWidth / 2) + 340, (screenHeight / 2) + 140, 270, 90 };
    const Rectangle exitButton = { (screenWidth / 2) + 340, (screenHeight / 2) + 295, 270, 90 };

    while (!exitGame)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 mousePosition = GetMousePosition();
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, startButton);
        DrawTexture(menuBG, 0, 0, WHITE);
        DrawRectangleRec(startButton, (isMouseOverButtonStart ? PURPLE : GRAY));
        DrawText("Start", screenWidth / 2 + 400, screenHeight / 2 + 5, 50, WHITE);
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            game();
        }

        bool isMouseOverButtonRules = CheckCollisionPointRec(mousePosition, rulesButton);

        DrawRectangleRec(rulesButton, (isMouseOverButtonRules ? PURPLE : GRAY));
        DrawText("Rules", screenWidth / 2 + 400, screenHeight / 2 + 157, 50, WHITE);
        if (isMouseOverButtonRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            rules();
        }

        bool isMouseOverButtonExit = CheckCollisionPointRec(mousePosition, exitButton);

        DrawRectangleRec(exitButton, (isMouseOverButtonExit ? PURPLE : GRAY));
        DrawText("Exit", screenWidth / 2 + 425, screenHeight / 2 + 315, 50, WHITE);
        if (isMouseOverButtonExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            exitGame = true;
        }

        EndDrawing();

    }
    CloseWindow();
}