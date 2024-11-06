#include "chess.h"

BOARD * alloc_board(int* board_column_size, int rows) {
    BOARD *board = (BOARD *)malloc(sizeof(BOARD));
    board->rows = rows;
    board->board_column_size = board_column_size;
    board->position = (FIGURE***)malloc(rows * sizeof(FIGURE**));
    int i = 0;
    int j = 0;
    for (i; i < rows; i++) {
        board->position[i] = (FIGURE**)malloc(sizeof(FIGURE) * board_column_size[i]);
        for (j = 0 ; j < board_column_size[i]; j++) {
            /* set all fields to NULL, to be able to check presents of a figure on chess board*/
            *(*(board->position +i)+j) = NULL;
        }
    }
    return board;
}
int check_move(FIGURE* fig, BOARD* board, POSITION figure_new_position) {
    if (figure_new_position.row < 0 || figure_new_position.row >= board->rows) return OUT_OF_BOARD_ROW_ERROR;
    if (figure_new_position.column < 0 || figure_new_position.column >= board->board_column_size[figure_new_position.row]) return OUT_OF_BOARD_COLUMN_ERROR;
    return MOVE_OK;
}
int move_figure(FIGURE* fig, BOARD* board, POSITION figure_new_position) {
    //check move
    int check = check_move(fig, board, figure_new_position);
    if (check != MOVE_OK) return check;

    //move figure
    board->position[figure_new_position.row][figure_new_position.column] = fig;
    board->position[fig->history->position->row][fig->history->position->column] = NULL;


    //change figure move history
    POSITION_HISTORY* position_history = (POSITION_HISTORY*)malloc(sizeof(POSITION_HISTORY));
    POSITION* figure_position = (POSITION *)malloc(sizeof(POSITION));
    figure_position->column = figure_new_position.column;
    figure_position->row = figure_new_position.row;
    position_history->position = figure_position;
    position_history->next = fig->history;
    fig->history = position_history;
    return MOVE_OK;
}

void print_board(BOARD* board) {
    int i,j;
    printf("\n");
    for (i = 0; i < board->rows; i++) {
        for (j = 0; j < board->board_column_size[i]; j++) {
            printf(" [%s] ", board->position[i][j] == NULL ? "EMPTY" : board->position[i][j]->name);
        }
        printf("\n");
    }
}
void print_fig_history(FIGURE * fig) {
        printf("\nFigure [%s] moves: \n", fig->name);
        print_move_history(fig->history);    
}

void print_move_history(POSITION_HISTORY * history) {
    if (history != NULL) {
        print_move_history(history->next);
        printf("[%d,%d] ", history->position->row, history->position->column);        
    }
}
void dealloc_board(BOARD* board) {    
    int i = 0;
    int j = 0;
    for (i; i < board->rows; i++) {        
        for (j = 0; j < board->board_column_size[i] && board->position[i][j] != NULL; j++) {
            free((FIGURE*)board->position[i][j]);
        }
        free((FIGURE**)board->position[i]);
    }
    free((FIGURE***)board->position);
}