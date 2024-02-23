#include "game.h"
#include "gameLost.h"
#include "rules.h"

#include <vector>

#define ROCKS 200

// Structure for spacecraft parts
struct SpacecraftPart {
    Model obj;
    Texture2D texture;
    Vector3 position;
    float scale;
    bool visible;
};

bool CheckCollisionPlayerPart(Vector3 playerPos, Vector3 partPos, float partScale)
{

    Vector3 partSize = { 10.0f * partScale, 10.0f * partScale, 10.0f * partScale };


    Vector3 playerHalfExtents = { 0.5f, 0.5f, 0.5f };
    Vector3 partHalfExtents = { partSize.x * 0.5f, partSize.y * 0.5f, partSize.z * 0.5f };


    Vector3 distVec = { playerPos.x - partPos.x, playerPos.y - partPos.y, playerPos.z - partPos.z };
    Vector3 minDist = { fabs(distVec.x), fabs(distVec.y), fabs(distVec.z) };


    if (minDist.x <= (playerHalfExtents.x + partHalfExtents.x) &&
        minDist.y <= (playerHalfExtents.y + partHalfExtents.y) &&
        minDist.z <= (playerHalfExtents.z + partHalfExtents.z))
    {

        return true;
    }


    return false;
}

void game()
{
    // Screen's size
    const int screenWidth = 1920;
    const int screenHeight = 975;


    Texture2D bgPhoto = LoadTexture("../images/bgPhoto.png");

    // Timer's parameters
    int minutes = 5;
    int seconds = 0;

    // Update timer every second
    float elapsedTime = 0.0f;
    float updateInterval = 1.0f;

    // Objects
    float heights[ROCKS] = { 0 };
    Vector3 rockPositions[ROCKS] = { 0 };

    // Spacecraft parts
    vector<SpacecraftPart> parts;

    // Load spacecraft parts
    SpacecraftPart firstPart;
    firstPart.obj = LoadModel("../images/spacecraft/objects/firstPart.obj");
    firstPart.texture = LoadTexture("../images/spacecraft/firstPart.png");
    firstPart.position = { 102.5f,2.0f,9.8f };
    firstPart.scale = 0.05f;
    firstPart.visible = true;
    parts.push_back(firstPart);

    // Load other spacecraft parts similarly

    // Variables for the camera
    Camera camera = { 0 };
    camera.position = { 0.0f, 2.0f, 4.0f };
    camera.target = { 0.0f, 2.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    int cameraMode = CAMERA_FIRST_PERSON;

    // Defines rocks' positions
    for (int i = 0; i < ROCKS; i++)
    {
        heights[i] = (float)GetRandomValue(0.9, 1.0);
        rockPositions[i] = { (float)GetRandomValue(-110,110), heights[i] / 2.0f, (float)GetRandomValue(-100, 100) };
    }
    DisableCursor();
    SetTargetFPS(240);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, cameraMode);

        BeginDrawing();

        // Display timer
        elapsedTime += GetFrameTime();

        if (elapsedTime >= updateInterval) {
            // Decrement the timer
            if (seconds == 0) {
                if (minutes == 0)
                {
                    gameLost();
                }
                minutes--;
                seconds = 59;

            }
            else {
                seconds--;
            }

            elapsedTime = 0.0f; // Reset elapsed time
        }

        ClearBackground(RAYWHITE);

        DrawTexture(bgPhoto, 0, 0, WHITE);

        // Draw timer
        DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

        BeginMode3D(camera);

        // Draw ground
        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 250.0f, 250.0f }, { 192, 96, 0, 250 });

        // Draw rocks
        for (int i = 0; i < ROCKS; i++)
        {
            DrawCube(rockPositions[i], 1.5f, { 0.9f }, 1.5f, { 138, 69, 0, 250 });
        }

        // Draw spacecraft parts
        for (auto& part : parts)
        {
            if (part.visible)
            {
                DrawModel(part.obj, part.position, part.scale, WHITE);
                
            }
        }

        // Check collision between player and each spacecraft part
        for (auto& part : parts)
        {
            if (part.visible && CheckCollisionPlayerPart(camera.position, part.position, part.scale))
            {
                // Collision occurred, handle it here
                // For example, make the collided part disappear
                rules();
                part.visible = false;
            }
        }

        EndMode3D();

        EndDrawing();
    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();
}
