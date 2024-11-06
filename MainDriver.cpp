#define _CRT_SECURE_NO_WARNINGS
#include "chess.h"
#include "string.h" 

int main() {
    int rows = 8;
    int* board_column_size = (int*)malloc(rows * sizeof(int));
    int i = 0;
    for (i; i < rows; i++) {
        board_column_size[i] = (i + 2);
    }

    BOARD * board = alloc_board(board_column_size, rows);
    print_board(board);

    FIGURE fig1;
    fig1.color = 10;
    fig1.name = (char*)malloc(10 * sizeof(char));
    strcpy(fig1.name, "Fig 1");
    POSITION position;
    position.column = 0;
    position.row = 0;
    POSITION_HISTORY position_history;
    position_history.next = NULL;
    position_history.position = &position;
    fig1.history = &position_history;

    FIGURE fig2;
    fig2.color = 20;
    fig2.name = (char*)malloc(6 * sizeof(char));
    strcpy(fig2.name, "Fig 2");
    POSITION position_fig2;
    position_fig2.column = 0;
    position_fig2.row = 0;
    POSITION_HISTORY position_history_fig2;
    position_history_fig2.next = NULL;
    position_history_fig2.position = &position_fig2;
    fig2.history = &position_history_fig2;

    POSITION new_pos;
    new_pos.column = 2;
    new_pos.row = 1;
    if (move_figure(&fig1, board, new_pos) != MOVE_OK) {
        printf("Invalid move");
    }
    print_board(board);
    new_pos.column = 3;
    new_pos.row = 2;
    if (move_figure(&fig1, board, new_pos) != MOVE_OK) {
        printf("Invalid move");
    }
    print_board(board);

    new_pos.column = 5;
    new_pos.row = 3;
    if (move_figure(&fig2, board, new_pos) != MOVE_OK) {
        printf("Invalid move");
    }

    new_pos.column = 4;
    new_pos.row = 3;
    if (move_figure(&fig2, board, new_pos) != MOVE_OK) {
        printf("Invalid move");
    }

    print_board(board);

    print_fig_history(&fig1);
    print_fig_history(&fig2);
    dealloc_board(board);
    return 0;
}