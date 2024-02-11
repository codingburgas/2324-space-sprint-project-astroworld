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
        DrawText("There were times when people decided to get better,", 190, 165, 50, WHITE);
        DrawText("to change themselves to a better reality and a ", 190, 215, 50, WHITE);
        DrawText("different lifestyle, so that's why they all gathered  ", 190, 265, 50, WHITE);
        DrawText("all the trash on the planet together and put them on", 190, 315, 50, WHITE);
        DrawText("a big recycling ship. But the big ship crashed on an ", 190, 365, 50, WHITE);
        DrawText("ice berg and all the garbage went floating in the ocean.", 190, 415, 50, WHITE);
        DrawText("Your task is to gather all the left overs of the trash ", 190, 465, 50, WHITE);
        DrawText("by completing chemistry and biology problems and ", 190, 515, 50, WHITE);
        DrawText("questions. Good luck saving the whole planet ECO pirate.", 190, 565, 50, WHITE);
        DrawText("*hint*", 190, 665, 50, WHITE);
        DrawText("You should be very careful when choosing the right", 190, 765, 50, WHITE);
        DrawText("answer because you have 3 lifes only.", 190, 825, 50, WHITE);
        ClearBackground(RED);
        DrawRectangle(toGame.x, toGame.y, toGame.width, toGame.height, CheckCollisionPointRec(mousePosition, toGame) ? ORANGE : GRAY);
        EndDrawing();
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePosition, toGame))
            game();

    }
    EndDrawing();
}