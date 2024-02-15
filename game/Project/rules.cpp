#include "rules.h"
#include "game.h";

void rules()
{
    Vector2 mousePosition = GetMousePosition();
    Rectangle toGame = { GetScreenWidth() / 2 + 300, GetScreenHeight() / 2 + 350, 300, 100 };
    SetExitKey(KEY_ESCAPE);

    while (!WindowShouldClose())
    {
        BeginDrawing();
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
        ClearBackground(RED);
        DrawRectangle(toGame.x, toGame.y, toGame.width, toGame.height, CheckCollisionPointRec(mousePosition, toGame) ? ORANGE : GRAY);
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePosition, toGame))
            game();

    }
    EndDrawing();
}