#include "game.h"
#define MAX_COLUMNS 20
void game()
{
    const int screenWidth = 1920;
    const int screenHeight = 975;
    Camera camera = { 0 };
    camera.position = { 0.0f, 2.0f, 4.0f };    
    camera.target = { 0.0f, 2.0f, 0.0f };      
    camera.up = { 0.0f, 1.0f, 0.0f };          
    camera.fovy = 60.0f;                       
    camera.projection = CAMERA_PERSPECTIVE;    
 
    int cameraMode = CAMERA_FIRST_PERSON;
 
 
    float heights[MAX_COLUMNS] = { 0 };
    Vector3 Pebblepositions[MAX_COLUMNS] = { 0 };

 
    for (int i = 0; i < MAX_COLUMNS; i++)
    {
        heights[i] = (float)GetRandomValue(0.9, 1.0);
        Pebblepositions[i] = { (float)GetRandomValue(-29,29), heights[i] / 2.0f, (float)GetRandomValue(-25, 25) };
    }
 
    DisableCursor();                  
 
    SetTargetFPS(60);                 
    while (!WindowShouldClose())      
    {

        UpdateCamera(&camera, cameraMode);                    
        BeginDrawing();
 
        ClearBackground(ORANGE);
 
        BeginMode3D(camera);
 
        DrawPlane( { 0.0f, 0.0f, 0.0f },{ 64.0f, 64.0f }, RED);
        for (int i = 0; i < MAX_COLUMNS; i++)
        {
            DrawCube(Pebblepositions[i], 0.5f, 0.9f, 0.5f, LIGHTGRAY);
        }
 
       
        if (cameraMode == CAMERA_THIRD_PERSON)
        {
            DrawCube(camera.target, 0.5f, 0.5f, 0.5f, PURPLE);
        }
 
        EndMode3D();
 
        EndDrawing();
    }
 
   
    SetExitKey(KEY_ESCAPE);
    EnableCursor();
}
