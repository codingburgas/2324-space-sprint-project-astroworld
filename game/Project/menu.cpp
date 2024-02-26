#include "menu.h"
#include "game.h"
#include "rules.h"
#include "questions.h"
void mainMenu()
{
    // Declare screen size variables
    const int screenWidth = 1920;
    const int screenHeight = 975;
    // Open new window
    InitWindow(screenWidth, screenHeight, "ASTROWORLD");
    // Set boolean variable used for exiting the game
    bool exitGame = WindowShouldClose();

    // Load textures and create buttons using Rectangle
    Texture2D menuBG = LoadTexture("../images/mainMenuBg.png");
    const Rectangle startButton = { (screenWidth / 2) + 340, (screenHeight / 2) - 15, 270, 90 };
    const Rectangle rulesButton = { (screenWidth / 2) + 340, (screenHeight / 2) + 140, 270, 90 };
    const Rectangle exitButton = { (screenWidth / 2) + 340, (screenHeight / 2) + 295, 270, 90 };

    while (!exitGame)
    {
        // Start drawing and clear background
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Get mouse position
        Vector2 mousePosition = GetMousePosition();
        // Check if mouse is hovering the specific button
        bool isMouseOverButtonStart = CheckCollisionPointRec(mousePosition, startButton);
        DrawTexture(menuBG, 0, 0, WHITE);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(startButton, (isMouseOverButtonStart ? PURPLE : GRAY));
        DrawText("Start", screenWidth / 2 + 400, screenHeight / 2 + 5, 50, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonStart && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            game();
        }

        // Check if mouse is hovering the specific button
        bool isMouseOverButtonRules = CheckCollisionPointRec(mousePosition, rulesButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(rulesButton, (isMouseOverButtonRules ? PURPLE : GRAY));
        DrawText("Rules", screenWidth / 2 + 400, screenHeight / 2 + 157, 50, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonRules && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            rules();
        }

        // Check if mouse is hovering the specific button
        bool isMouseOverButtonExit = CheckCollisionPointRec(mousePosition, exitButton);
        // Set new colors for hovering the button and draw text
        DrawRectangleRec(exitButton, (isMouseOverButtonExit ? PURPLE : GRAY));
        DrawText("Exit", screenWidth / 2 + 425, screenHeight / 2 + 315, 50, WHITE);
        // Handle click with the mouse over button
        if (isMouseOverButtonExit && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            exitGame = true;
        }

        // End the drawing
        EndDrawing();

    }
    // Close the window
    CloseWindow();
}