#include <raylib.h>

int main() 
{
  const int gameWidth{1024};
  const int gameHeight{720};
  InitWindow(gameWidth, gameHeight, "Dapper Dasher!");
  SetTargetFPS(60);
  while(!WindowShouldClose()) 
  {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
}
