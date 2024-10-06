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
    bool isJumping = IsKeyPressed(KEY_SPACE);
    if(isJumping) 
    {
      posY += velocity;
    }
    DrawRectangle(gameWidth / 2 - width / 2, posY, width, height, RED);
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  CloseWindow();
}
