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
} ShapeId;

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


int main() {
	Color cur;
	// 有幾種方塊
	for (int i = 0; i < 7; i++) {
		// 印出方塊樣式
		for (int r = 0; r < 4; r++) {
			for (int s = 0; s < shape[i].size; s++) {
				for (int t = 0; t < shape[i].size; t++) {
					if (shape[i].rotates[r][s][t] == 0) {
						cur = WHITE;
					}
					else {
						cur = shape[i].color;
					}
					printf("\033[%dm  \033[0m", cur);
				}
				printf("\n");
			}
			printf("\n");
		}
	}
	return 0;
}