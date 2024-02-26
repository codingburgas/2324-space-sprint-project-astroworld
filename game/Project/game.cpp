#include "game.h"
#include "rules.h"
#include "gameLost.h"
#include "questions.h"
#include "gameWon.h"

#define ROCKS 450
bool answer;

//Declare collected parts
int collectedParts = 0;

// Structure for spacecraft parts
struct SpacecraftPart {
    Model obj;
    Texture2D texture;
    Vector3 position;
    float scale;
    bool visible;
};

float Vector3Distance(Vector3 v1, Vector3 v2)
{
    return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
}

// Check collision between player and spacecraft part
bool CheckCollisionPlayerPart(Vector3 playerPos, Vector3 partPos, float partScale)
{
    // Adjust bounding box for the spacecraft parts
    Vector3 partSize = { 10.0f * partScale, 10.0f * partScale, 10.0f * partScale };

    // Calculate half extents for player and part bounding boxes
    Vector3 playerHalfExtents = { 0.5f, 0.5f, 0.5f };
    Vector3 partHalfExtents = { partSize.x * 0.5f, partSize.y * 0.5f, partSize.z * 0.5f };

    // Calculate the distance between player and part
    Vector3 distVec = { playerPos.x - partPos.x, playerPos.y - partPos.y, playerPos.z - partPos.z };
    Vector3 minDist = { fabs(distVec.x), fabs(distVec.y), fabs(distVec.z) };

    // Check if the distance is less than the sum of the half extents
    if (minDist.x <= (playerHalfExtents.x + partHalfExtents.x) &&
        minDist.y <= (playerHalfExtents.y + partHalfExtents.y) &&
        minDist.z <= (playerHalfExtents.z + partHalfExtents.z))
    {
        // Collision detected
        return true;
    }

    // No collision
    return false;
}

void game()
{
    // Screen's size
    const int screenWidth = 1920;
    const int screenHeight = 975;

    // Game's background
    Texture2D bgPhoto = LoadTexture("../images/bgPhoto.png");

    // Timer's parameters
    int minutes = 3;
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
    firstPart.position = { 102.5f, 2.0f, 9.8f }; // Initial coordinates
    firstPart.scale = 0.05f;
    firstPart.visible = true; // Ensure it's visible initially
    parts.push_back(firstPart);

    SpacecraftPart secondPart;
    secondPart.obj = LoadModel("../images/spacecraft/objects/secondPart.obj");
    secondPart.texture = LoadTexture("../images/spacecraft/secondPart.png");
    secondPart.position = { -120.0f, 1.0f, -60.7f };
    secondPart.scale = 0.05f;
    secondPart.visible = true; // Ensure it's visible initially
    parts.push_back(secondPart);

    SpacecraftPart thirdPart;
    thirdPart.obj = LoadModel("../images/spacecraft/objects/thirdPart.obj");
    thirdPart.texture = LoadTexture("../images/spacecraft/thirdPart.png");
    thirdPart.position = { -70.0f, 1.0f, 80.9f };
    thirdPart.scale = 0.05f;
    thirdPart.visible = true; // Ensure it's visible initially
    parts.push_back(thirdPart);

    SpacecraftPart fourthPart;
    fourthPart.obj = LoadModel("../images/spacecraft/objects/fourthPart.obj");
    fourthPart.texture = LoadTexture("../images/spacecraft/fourthPart.png");
    fourthPart.position = { 10.6f, 2.0f, -100.4f };
    fourthPart.scale = 0.05f;
    fourthPart.visible = true; // Ensure it's visible initially
    parts.push_back(fourthPart);

    SpacecraftPart fifthPart;
    fifthPart.obj = LoadModel("../images/spacecraft/objects/fifthPart.obj");
    fifthPart.texture = LoadTexture("../images/spacecraft/fifthPart.png");
    fifthPart.position = { 90.0f, 1.0f, 80.0f };
    fifthPart.scale = 0.05f;
    fifthPart.visible = true; // Ensure it's visible initially
    parts.push_back(fifthPart);

    SpacecraftPart sixthPart;
    sixthPart.obj = LoadModel("../images/spacecraft/objects/sixthPart.obj");
    sixthPart.texture = LoadTexture("../images/spacecraft/sixthPart.png");
    sixthPart.position = { 95.6f, 1.0f, -120.0f };
    sixthPart.scale = 0.05f;
    sixthPart.visible = true; // Ensure it's visible initially
    parts.push_back(sixthPart);


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
        rockPositions[i] = { (float)GetRandomValue(-149,149), heights[i] / 2.0f, (float)GetRandomValue(-100, 100) };
    }
    DisableCursor();
    SetTargetFPS(240);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera, cameraMode);

        BeginDrawing();

        // Display timer
       

        ClearBackground(RAYWHITE);

        //Draw background photo
        DrawTexture(bgPhoto, 0, 0, WHITE);

        BeginMode3D(camera);

        // Draw ground
        DrawPlane({ 0.0f, 0.0f, 0.0f }, { 300.0f, 300.0f }, { 192, 96, 0, 250 });

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

        for (auto& part : parts)
        {
            if (part.visible)
            {
                // Calculate the distance between player and part
                float distance = Vector3Distance(camera.position, part.position);

                // Define a threshold for collision
                float collisionThreshold = 2.0f; // Adjust as needed

                // Check if the distance is less than the collision threshold
                if (distance < collisionThreshold)
                {
                    // Collision occurred, make the part disappear
                    EndMode3D();
                    questions();
                    if (answer) 
                    {
                        part.visible = false; //Parts disappear
                        collectedParts++;
                    }
                    else 
                    {
                        part.visible = true; //Parts don't disappear
                    }
                    if (collectedParts == 6)
                    {
                        EndMode3D();
                        collectedParts = 0;
                        gameWon(); //End game
                        
                    }
                }
            }
        }

        elapsedTime += GetFrameTime();

        if (elapsedTime >= updateInterval) {
            // Decrement the timer
            if (seconds == 0) {
                if (minutes == 0)
                {
                    EndMode3D();
                    collectedParts = 0;
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

        EndMode3D();
        // Draw timer
        DrawText(TextFormat("%02d:%02d", minutes, seconds), 930, 40, 50, RED);

        //Draw the amount of collected parts
        DrawText(TextFormat("%01d", collectedParts), 1700, 40, 50, WHITE);
        DrawText("/6", 1730, 40, 50, WHITE);

        EndDrawing();
    }

    SetExitKey(KEY_ESCAPE);
    EnableCursor();
}
