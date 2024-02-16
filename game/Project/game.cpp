#include "game.h"

#define ROCKS 200
#define PARTS 6
void game()
{
    Texture2D bgPhoto = LoadTexture("../images/bgPhoto.png");
    Texture2D firstPart = LoadTexture ("../images/spacecraft/firstPart.png");
    Texture2D secondPart = LoadTexture ("../images/spacecraft/secondPart.png");
    Texture2D thirdPart = LoadTexture ("../images/spacecraft/thirdPart.png");
    Texture2D fourthPart = LoadTexture ("../images/spacecraft/fourthPart.png");
    Texture2D fifthPart = LoadTexture ("../images/spacecraft/fifthPart.png");
    Texture2D sixthPart = LoadTexture ("../images/spacecraft/sixthPart.png");

    const int screenWidth = 1920;
    const int screenHeight = 975;
    Camera camera = { 0 };
    camera.position = { 0.0f, 2.0f, 4.0f };    
    camera.target = { 0.0f, 2.0f, 0.0f };      
    camera.up = { 0.0f, 1.0f, 0.0f };          
    camera.fovy = 60.0f;                       
    camera.projection = CAMERA_PERSPECTIVE;   

    int cameraMode = CAMERA_FIRST_PERSON;
    
    float heights[ROCKS] = { 0 };
    Vector3 rockPositions[ROCKS] = { 0 };
    Vector3 partsPositions[PARTS] = { 0 };
 
    for (int i = 0; i < ROCKS; i++)
    {
        heights[i] = (float)GetRandomValue(0.9, 1.0);
        rockPositions[i] = { (float)GetRandomValue(-110,110), heights[i] / 2.0f, (float)GetRandomValue(-100, 100) };
    }
 
    DisableCursor();                  
    SetTargetFPS(165);                 
    while (!WindowShouldClose())      
    {

        UpdateCamera(&camera, cameraMode);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(bgPhoto, 0, 0, WHITE);

        DrawTexture(firstPart, 10, 10, WHITE);
        DrawTexture(secondPart, 20, 20, WHITE);
        DrawTexture(thirdPart, 30, 30, WHITE);
        DrawTexture(fourthPart, 40, 40, WHITE);
        DrawTexture(fifthPart, 50, 50, WHITE);
        DrawTexture(sixthPart, 60, 60, WHITE);

        BeginMode3D(camera);

        DrawPlane( { 0.0f, 0.0f, 0.0f },{ 250.0f, 250.0f }, { 192, 96, 0, 250});
        for (int i = 0; i < ROCKS; i++)
        {
            DrawCube(rockPositions[i], 1.5f, { 0.9f }, 1.5f, { 138, 69, 0, 250});
        }
        
        EndMode3D();

        EndDrawing();
    }
 
   
    SetExitKey(KEY_ESCAPE);
    EnableCursor();
}
