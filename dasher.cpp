#include <raylib.h>

const int gameWidth = 800;
const int gameHeight = 450;
const char gameTitle = "Dasher";

int main() 
{

  InitWindow(800, 450, gameTitle);
  SetTargetFPS(60);
  while(true) 
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
}
