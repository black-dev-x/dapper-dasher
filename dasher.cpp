#include <raylib.h>

int main() 
{
  const int gameWidth{1024};
  const int gameHeight{720};
  InitWindow(gameWidth, gameHeight, "Dapper Dasher!");
  SetTargetFPS(60);

  const int width{50};
  const int height={80};
  
  int posY{gameHeight - height};
  int velocity{-10};
  
  while(!WindowShouldClose()) 
  {
    BeginDrawing();
    posY += velocity;
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();
}
