#include "rules.h"
#include "game.h";

void story() {
    SetExitKey(KEY_ESCAPE);
    Texture2D astroPhoto = LoadTexture("../images/astronaut.png");
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        DrawTexture(astroPhoto, 160, 260, RAYWHITE);
        ClearBackground({ 0, 1, 41, 255 });
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(820, 60, 850, 850, { 0, 91, 241, 255 });
        
        DrawText("Hi, I'm an astronaut from the ", 880, 80, 50, WHITE);
        DrawText("planet Earth, but on my last ", 880, 140, 50, WHITE);
        DrawText("expedition, my spacecraft ", 900, 200, 50, WHITE);
        DrawText("exploded and now its parts ", 900, 260, 50, WHITE);
        DrawText("are scattered across the ", 900, 320, 50, WHITE);
        DrawText("planet Mars. Your mission is ", 880, 380, 50, WHITE);
        DrawText("to help me put them together ", 880, 440, 50, WHITE);
        DrawText("so I can go back to my loved ", 880, 500, 50, WHITE);
        DrawText("ones and complete my expedition. ", 835, 560, 50, WHITE);
        DrawText("However, I have a certain ", 880, 620, 50, WHITE);
        DrawText("amount of time before I run ", 880, 680, 50, WHITE);
        DrawText("out of oxygen, my clock is ", 880, 740, 50, WHITE);
        DrawText("already tickingso be as fast ", 880, 800, 50, WHITE);
        DrawText("as you can! ", 1080, 860, 50, WHITE);
       
        EndDrawing();
    }
}
void controls() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground(RED);
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(530, 200, 800, 500, ORANGE);
        DrawFPS(75, 50);
        DrawText("W - move forward", 700, 255, 50, WHITE);
        DrawText("A - move to the left", 700, 365, 50, WHITE);
        DrawText("S - move backwards", 700, 475, 50, WHITE);
        DrawText("D - move to the right", 700, 585, 50, WHITE);
        EndDrawing();
    }
}
void rules()
{
    const Rectangle storyButton = { (GetScreenWidth() / 2) - 110, (GetScreenHeight() / 2) - 240, 270, 100 };
    const Rectangle controlsButton = { (GetScreenWidth() / 2) - 110, (GetScreenHeight() / 2) - 70, 270, 100 };
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        bool isMouseOverStoryButton = CheckCollisionPointRec(mousePosition, storyButton);
        DrawRectangleRec(storyButton, (isMouseOverStoryButton ? SKYBLUE : BLUE));
        DrawText("Story", GetScreenWidth() / 2 - 55, GetScreenHeight() / 2 - 215, 50, BLACK);

        if (isMouseOverStoryButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            story();
        }

        bool isMouseOverControls = CheckCollisionPointRec(mousePosition, controlsButton);
        DrawRectangleRec(controlsButton, (isMouseOverControls ? GREEN : LIME));
        DrawText("Controls", GetScreenWidth() / 2 - 90, (GetScreenHeight() / 2) - 45, 50, BLACK);

        if (isMouseOverControls && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            controls();
        }
        EndDrawing();
    }
}