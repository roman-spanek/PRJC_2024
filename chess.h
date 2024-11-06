#pragma once
#include <stdlib.h>
#include "stdio.h"
#define OUT_OF_BOARD_ROW_ERROR 101
#define OUT_OF_BOARD_COLUMN_ERROR 102
#define MOVE_OK 100

typedef struct position {
    int row;
    int column;
} POSITION;

typedef struct position_history {
    POSITION* position;
    struct position_history* next;
} POSITION_HISTORY;

typedef struct figure {
    int color;
    char* name;
    POSITION_HISTORY* history;
} FIGURE;

typedef struct board {
    FIGURE*** position;
    int* board_column_size;
    int rows;
} BOARD;

BOARD * alloc_board(int* board_column_size, int rows);
void dealloc_board(BOARD* board);
int check_move(FIGURE* fig, BOARD* board, POSITION figure_new_position);
int move_figure(FIGURE* fig, BOARD* board, POSITION figure_new_position);
void print_fig_history(FIGURE* fig);
void print_move_history(POSITION_HISTORY* history);
void print_board(BOARD* board);