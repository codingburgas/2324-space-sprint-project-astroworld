#include "rules.h"
#include "game.h";

void story() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground(RED);
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(180, 160, 1500, 750, ORANGE);
        DrawFPS(75, 50);
        DrawText("Hi, I'm an astronaut from the planet Earth , but on my", 190, 165, 50, WHITE);
        DrawText("last expedition my spacecraft exploded and now its parts", 190, 215, 50, WHITE);
        DrawText("are scattered across the planet Mars. Your mission", 190, 265, 50, WHITE);
        DrawText("is to help me put them together so I can go back to my", 190, 315, 50, WHITE);
        DrawText("loved ones and complete my expedition. However, I ", 190, 365, 50, WHITE);
        DrawText("have a certain amount of time before I run out of ", 190, 415, 50, WHITE);
        DrawText("oxygen, my clock is already ticking so be as fast as ", 190, 465, 50, WHITE);
        DrawText("you can!", 190, 515, 50, WHITE);
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