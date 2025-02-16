#include <raylib.h>
#include <stdio.h>

Texture2D nebulaTexture;
Texture2D playerSprite;

typedef struct AnimationData {
  Rectangle rec;
  Vector2 pos;
  int frame;
  float updateTime;
  float runningTime;
} AnimationData;

const int nebulaAmount = 2;
int playerGroundPosition;
AnimationData scarfyData;
AnimationData nebulaData[nebulaAmount];

typedef struct Game 
{
  const int width = 1024;
  const int height = 720;
  const int FPS = 60;
  const char* title = "Dapper Dasher!";
  float deltaTime;
  float runningTime;
} Game;

Game game;
const int gravity = 1000;

void applyGravity()
{
  if(scarfyData.pos.y != player.groundPosition)
  {
    player.velocity.y += gravity * game.deltaTime;
  }
}
void handleJump()
{
  bool isJumping = IsKeyDown(KEY_SPACE);
  if(isJumping && player.pos.y == player.groundPosition) 
  {
    player.velocity.y = -600;
    player.isInAir = true;
  }
}
void fallToTheGround()
{
  player.pos.y += player.velocity.y * game.deltaTime;
  if(player.pos.y > player.groundPosition) 
  {
    player.pos.y = player.groundPosition;
    player.velocity.y = 0;
    player.isInAir = false;
  }
}
void run()
{
  float updateTime = 1.0 / 12; //update 1 times per second
  game.runningTime += game.deltaTime;
  float cycles = game.runningTime / updateTime;
  float currentSprite = (int)cycles % 6;
  float nebulaSprite = (int)cycles % 61;
  if(!player.isInAir)
    player.sprite.x = currentSprite * player.sprite.width;
  for(int i = 0; i < nebulaAmount; i++){
    nebulas[i].position.x -= nebulas[i].velocity * game.deltaTime;
    nebulas[i].sprite.x = (int)nebulaSprite % 8 * nebulas[i].sprite.width;
    nebulas[i].sprite.y = (int)nebulaSprite / 8 * nebulas[i].sprite.height;
  }
}

void loadTextures() 
{
  playerSprite = LoadTexture("textures/scarfy.png");
  nebulaTexture = LoadTexture("textures/12_nebula_spritesheet.png");
}
void initializeScarfyData()
{
  scarfyData.rec.x = 0;
  scarfyData.rec.y = 0;
  scarfyData.rec.width = playerSprite.width / 6;
  scarfyData.rec.height = playerSprite.height;
  scarfyData.pos.x = game.width / 2 - scarfyData.rec.width / 2;
  playerGroundPosition = game.height - scarfyData.rec.height;
  scarfyData.pos.y = playerGroundPosition;
  scarfyData.frame = 0;
  scarfyData.updateTime = 1.0 / 12;
  scarfyData.runningTime = 0.0;
}
void initializeNebulaData()
{
  AnimationData nebulaData[nebulaAmount];
  for(int i = 0; i < nebulaAmount; i++)
  {
    nebulaData[i].rec.x = 0;
    nebulaData[i].rec.y = 0;
    nebulaData[i].rec.width = nebulaTexture.width / 8;
    nebulaData[i].rec.height = nebulaTexture.height / 8;
    nebulaData[i].frame = 0;
    nebulaData[i].updateTime = 1.0 / 12;
    nebulaData[i].runningTime = 0.0;
  }
}
int main() 
{
  InitWindow(game.width, game.height, game.title);
  initialize();
  SetTargetFPS(game.FPS);
  loadTextures();
  initializeScarfyData();
  initializeNebulaData();

  placePlayer();
  while(!WindowShouldClose()) 
  {  
    game.deltaTime = GetFrameTime();
    BeginDrawing();
    applyGravity();
    handleJump();
    run();
    fallToTheGround();
    DrawTextureRec(playerSprite, player.sprite, player.pos, WHITE);
    for(int i = 0; i < nebulaAmount; i++){
      DrawTextureRec(nebulaTexture, nebulas[i].sprite, nebulas[i].position, WHITE);
    }
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
  UnloadTexture(playerSprite);
  UnloadTexture(nebulaTexture);
  CloseWindow();
}

