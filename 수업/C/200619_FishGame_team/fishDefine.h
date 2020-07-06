#pragma once

// background 
#define WallW   27
#define WallH   57 
#define MapWallHStart 1
#define MapWallHEnd1 24
#define MapWallHEnd2 25
#define MapWallHEnd3 26
#define MapWallHEnd4 56

// game
#define MAXFISH 200
#define CREATABLEFISH 10
#define TypeNum 6

// struct
typedef struct _FishType {
	char shape[30];
	char rshape[30];
	int type;
}FishType;

typedef struct _Fish {
	int x, y, Endx;
	int life, dir;
	FishType ft;
}Fish;

typedef struct _Game {
	int time, level, score, eat;
}Game;