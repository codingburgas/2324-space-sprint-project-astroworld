#include "rules.h"
#include "game.h";

void story() {
    SetExitKey(KEY_ESCAPE);
    // Add texture for astroPhoto
    Texture2D astroPhoto = LoadTexture("../images/astronaut.png");

    while (!WindowShouldClose())
    {
        // Get mouse position
        Vector2 mousePosition = GetMousePosition();
        // Start drawing, draw textures, and clear background
        BeginDrawing();
        DrawTexture(astroPhoto, 160, 260, RAYWHITE);
        ClearBackground({ 0, 1, 41, 255 });
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(820, 60, 850, 850, { 0, 91, 241, 255 });

        // Draw text for story
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

        // Stop drawing
        EndDrawing();
    }
}
void controls() {
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        // Get mouse position, start drawing, and clear background
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();
        ClearBackground({ 0, 1, 41, 255 });

        // Draw text for controls
        DrawText("press ESC to go back", 75, 915, 20, RAYWHITE);
        DrawRectangleLines(530, 200, 800, 500, { 0, 91, 241, 255 });
        DrawText("W - move forward", 680, 255, 50, WHITE);
        DrawText("A - move to the left", 680, 365, 50, WHITE);
        DrawText("S - move backwards", 680, 475, 50, WHITE);
        DrawText("D - move to the right", 680, 585, 50, WHITE);

        // Stop drawing
        EndDrawing();
    }
}
void rules()
{
    // Load textures
    Texture2D alien = LoadTexture("../images/alien.png");
    Texture2D constellation = LoadTexture("../images/constellation.png");
    Texture2D star = LoadTexture("../images/star.png");

    // Add storyButton and controlsButton
    const Rectangle storyButton = { (GetScreenWidth() / 2) - 110, (GetScreenHeight() / 2) - 120, 270, 100 };
    const Rectangle controlsButton = { (GetScreenWidth() / 2) - 110, (GetScreenHeight() / 2) - (-15), 270, 100 };
    SetExitKey(KEY_ESCAPE);
    while (!WindowShouldClose())
    {
        // Get mouse position
        Vector2 mousePosition = GetMousePosition();
        BeginDrawing();

        // Clear the background and draw textures
        ClearBackground({ 0, 1, 41, 255 });
        DrawTexture(alien, 110, 400, RAYWHITE);
        DrawTexture(constellation, 1360, 250, RAYWHITE);
        DrawTexture(star, 640, 50, RAYWHITE);

        // Check if mouse is over the button
        bool isMouseOverStoryButton = CheckCollisionPointRec(mousePosition, storyButton);
        // Add colors for if mouse is over the button
        DrawRectangleRec(storyButton, (isMouseOverStoryButton ? SKYBLUE : BLUE));
        DrawText("Story", GetScreenWidth() / 2 - 45, GetScreenHeight() / 2 - 97, 50, WHITE);

        // Get sent to story() after clicking the story button
        if (isMouseOverStoryButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            story();
        }

        // Check if mouse is over the button
        bool isMouseOverControls = CheckCollisionPointRec(mousePosition, controlsButton);
        // Add colors for if mouse is over the button
        DrawRectangleRec(controlsButton, (isMouseOverControls ? GREEN : LIME));
        DrawText("Controls", GetScreenWidth() / 2 - 80, (GetScreenHeight() / 2) - (-40), 50, WHITE);

        // Get sent to controls() after clicking the controls button
        if (isMouseOverControls && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            controls();
        }
        EndDrawing();
    }
}