#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define CANVAS_WIDTH 10
#define CANVAS_HEIGHT 20


typedef enum {
	EMPTY = -1,
	I,
	J,
	L,
	O,
	S, 
	T,
	Z
} ShapeId ;

typedef enum {
	RED = 41,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE,
	BLACK = 0,
} Color;

typedef struct {
	ShapeId shape;
	Color color;
	int size;
	char rotates[4][4][4];
} Shape;

typedef struct {
	Color color;
	ShapeId shape;
	bool current;
}Block;

Shape shape[7] = {
	{
		.shape = I,
		.color = CYAN,
		.size = 4,
		.rotates = {
			{
				{0, 0, 0, 0},
				{1, 1, 1, 1},
				{0, 0, 0, 0},
				{0, 0, 0, 0}
			},{
				{0, 0, 1, 0},
				{0, 0, 1, 0},
				{0, 0, 1, 0},
				{0, 0, 1, 0}
			},{
				{0, 0, 0, 0},
				{0, 0, 0, 0},
				{1, 1, 1, 1},
				{0, 0, 0, 0}
			},{
				{0, 1, 0, 0},
				{0, 1, 0, 0},
				{0, 1, 0, 0},
				{0, 1, 0, 0}
			}
		}
	},{
		.shape = J,
		.color = BLUE,
		.size = 3,
		.rotates = {
			{
				{1, 0, 0},
				{1, 1, 1},
				{0, 0, 0}
			},{
				{0, 1, 1},
				{0, 1, 0},
				{0, 1, 0}
			},{
				{0, 0, 0},
				{1, 1, 1},
				{0, 0, 1}
			},{
				{0, 1, 0},
				{0, 1, 0},
				{1, 1, 0}
			}
		}
	},{
		.shape = O,
		.color = WHITE,
		.size = 2,
		.rotates = {
			{
				{1, 1},
				{1, 1}
			},{
				{1, 1},
				{1, 1}
			},{
				{1, 1},
				{1, 1}
			},{
				{1, 1},
				{1, 1}
			}
		}
	},{
		.shape = L,	
		.color = YELLOW,
		.size = 3,
		.rotates = {
			{
				{0, 0, 1},
				{1, 1, 1},
				{0, 0, 0}
			},{
				{0, 1, 0},
				{0, 1, 0},
				{0, 1, 1}
			},{
				{0, 0, 0},
				{1, 1, 1},
				{1, 0, 0}
			},{
				{1, 1, 0},
				{0, 1, 0},
				{0, 1, 0}
			}
		}
	},{
		.shape = S,
		.color = GREEN,
		.size = 3,
		.rotates = {
			{
				{0, 1, 1},
				{1, 1, 0},
				{0, 0, 0}
			},{
				{0, 1, 0},
				{0, 1, 1},
				{0, 0, 1}
			},{
				{0, 0, 0},
				{0, 1, 1},
				{1, 1, 0}
			},{
				{1, 0, 0},
				{1, 1, 0},
				{0, 1, 0}
			}
		}
	},{
		.shape = T,
		.color = PURPLE,
		.size = 3,
		.rotates = {
			{
				{0, 1, 0},
				{1, 1, 1},
				{0, 0, 0}
			},{
				{0, 1, 0},
				{0, 1, 1},
				{0, 1, 0}
			},{
				{0, 0, 0},
				{1, 1, 1},
				{0, 1, 0}
			},{
				{0, 1, 0},
				{1, 1, 0},
				{0, 1, 0}
			}
		}
	}, {
		.shape = Z,
		.color = RED,
		.size = 3,
		.rotates = {
			{
				{1, 1, 0},
				{0, 1, 1},
				{0, 0, 0}
			},{
				{0, 0, 1},
				{0, 1, 1},
				{0, 1, 0}
			},{
				{0, 0, 0},
				{1, 1, 0},
				{0, 1, 1}
			},{
				{0, 1, 0},
				{1, 1, 0},
				{1, 0, 0}
			}
		}
	}
};

void setBlock(Block* block, ShapeId shape, Color color, bool current) {
	block->shape = shape; // 設定方塊的形狀
	block->color = color; // 設定方塊的顏色
	block->current = current; // 設定方塊為當前方塊
}

void resetBlock(Block* block) {
	block->shape = EMPTY; // 重置方塊的形狀為空
	block->color = BLACK; // 重置方塊的顏色為黑色
	block->current = false; // 重置當前方塊標記
}



int main() {
	Block canvas[CANVAS_HEIGHT][CANVAS_WIDTH]; // 畫布
	// 初始化畫布
	for (int i = 0; i < CANVAS_HEIGHT; i++) {
		for (int j = 0; j < CANVAS_WIDTH; j++) {
			resetBlock(&canvas[i][j]);
		}
	}

	// 設定一個方塊
	for (int i = 0; i < CANVAS_HEIGHT; i++) {
		printf("|");
		for (int j = 0; j < CANVAS_WIDTH; j++) {
			printf("-1");
		}
		printf("|\n");
	}

	return 0;
}