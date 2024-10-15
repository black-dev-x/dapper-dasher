#include <raylib.h>

typedef struct Player 
{
  int posX = 0;
  int posY = 0;
  int velocityX = 0;
  int velocityY = 0;
  const int width = 50;
  const int height = 80;
} Player;

typedef struct Game 
{
  const int width = 1024;
  const int height = 720;
  const int FPS = 60;
  const char* title = "Dapper Dasher!";
} Game;

Game game;
Player player;
const int gravity = 1;
const int groundPosition = game.height - player.height;

void placePlayer() 
{
  player.posX = game.width / 2 - player.width / 2;
  player.posY = groundPosition;
}

void applyGravity()
{
  if(player.posY != groundPosition)
  {
    player.velocityY += gravity;
  }
}
void handleJump()
{
  bool isJumping = IsKeyDown(KEY_SPACE);
  if(isJumping && player.posY == groundPosition) 
  {
    player.velocityY = -20;
  }
}
void fallToTheGround()
{
  player.posY += player.velocityY;
  if(player.posY > groundPosition) 
  {
    player.posY = groundPosition;
    player.velocityY = 0;
  }
}
int main() 
{
  InitWindow(game.width, game.height, game.title);
  SetTargetFPS(game.FPS);
  placePlayer();
  while(!WindowShouldClose()) 
  {
    BeginDrawing();
    applyGravity();
    handleJump();
    fallToTheGround();
    DrawRectangle(player.posX, player.posY, player.width, player.height, RED);
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  CloseWindow();
}

