#pragma once
#include "fishDefine.h"

// background
void make_background(Game* game);
void draw_background(Game* game, Fish shark);
void drawWall();
void gameOver();
void winCeremony(FishType ft[TypeNum]);

// fish
void init_fish(FishType ft[TypeNum], Fish* shark);
void drawFish(int x, int y, char* fish);
void drawFish2(Fish fish, int c);
Fish create_fish(Game game, Fish fish[MAXFISH], FishType ft[TypeNum], int* fcnt);
void move_fish(Fish* fish);
void moveShark(Fish* shark, int* preX, int* preY, int* newX, int* newY, int time);

// game
int hit(Game* game, Fish* shark, Fish fish[MAXFISH], int fcnt, int* dcnt);
char* LevelUp(char* shape);
int runningGame(Fish shark, FishType ft[TypeNum]);