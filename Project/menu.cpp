#include "menu.h"
#include "textures.h"
void mainMenu()
{
    Textures* texture = new Textures();
    const int screenWidth = 1920;
    const int screenHeight = 975;
    InitWindow(screenWidth, screenHeight, "ASTROWORLD");
    bool exitGame = WindowShouldClose();
    Texture2D menuBG = LoadTexture("../images/mainMenuBg.png");
    const Rectangle startButton = { (screenWidth / 2) - 500, (screenHeight / 2) - 50, 270, 90 };
    const Rectangle rulesButton = { (screenWidth / 2) + 300, (screenHeight / 2) - 50, 270, 90 };
    const Rectangle exitButton = { (screenWidth / 2) - 65, (screenHeight / 2) + 380, 270, 90 };

    while (!exitGame)
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        Vector2 mousePosition = GetMousePosition();
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, startButton);
        DrawTexture(menuBG, 0, 0, WHITE);
        DrawRectangleRec(startButton, (isMouseOverButtonStart ? ORANGE : GRAY));
        DrawText("Start", screenWidth / 2 - 440, screenHeight / 2 - 25, 50, BLACK);
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            
        }

        bool isMouseOverButtonRules = CheckCollisionPointRec(mousePosition, rulesButton);

        DrawRectangleRec(rulesButton, (isMouseOverButtonRules ? ORANGE : GRAY));
        DrawText("Rules", screenWidth / 2 + 360, screenHeight / 2 - 25, 50, BLACK);
        if (isMouseOverButtonRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            
        }

        bool isMouseOverButtonExit = CheckCollisionPointRec(mousePosition, exitButton);

        DrawRectangleRec(exitButton, (isMouseOverButtonExit ? ORANGE : GRAY));
        DrawText("Exit", screenWidth / 2 + 25, screenHeight / 2 + 400, 50, BLACK);
        if (isMouseOverButtonExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            exitGame = true;
        }

        EndDrawing();

    }
    CloseWindow();
}