#include "raylib.h"

int main(void)
{

    InitWindow(GetScreenWidth(), GetScreenHeight(), "Astro World");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("We are ASTROWORLD!", 500, 500, 20, BLACK);
        EndDrawing();

    }




    CloseWindow();
}