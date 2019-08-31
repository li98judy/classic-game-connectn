#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "winner.h"
#include "makeboard.h"

// asks for input on command line
void read_args(int argc){
    const int num = 4;
    
    if (argc < num){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
    if (argc > num){
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns\n");
        printf("number_of_pieces_in_a_row_needed_to_win\n");
        exit(0);
    }
}

void play_game(int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    // ? set up
    char** board = NULL;
    int turn = 0;
    int userMove;
    
    board = create_board(rows, cols);
    //print board after it has been created
    print_board(board, rows, cols);
    
    // while loop
    while(!game_over(board, rows, cols, number_of_pieces_in_a_row_needed_to_win)) {
        
        // gets move from user
        userMove = get_play(board, turn, cols);
        
        // plays that move given from the user
        play_move(&board, turn, userMove, rows);
        
        // displays the board
        print_board(board, rows, cols);
        
        // changes turns
        change_turn(&turn);
    }
    // print_board(board, rows, cols);
    declare_winner(board, turn, rows, cols, number_of_pieces_in_a_row_needed_to_win);
    destroy_board(&board, rows);
}

char** create_board(int rows, int cols) {
    char blank_space = '*';
    int i, k;
    
    char** board = (char**)malloc(rows * sizeof(char*));
    
    for (i = 0; i < rows; ++i) {
        *(board + i) = (char*)malloc(cols * sizeof(char));
        
        for (k = 0; k < cols; ++k) {
            board[i][k] = blank_space;
            
        }
    }
    
    return board;
}

void play_move(char*** board, int turn, int user_move, int rows) {
    int i = 0;
    char blank_space = '*';
    char player_char;
    
    if (turn == 0){
        player_char = 'X';
    }
    else{
        player_char = 'O';
    }
    
    // ASK: how break statements work
    for(i = rows - 1; i >= 0; --i) {
        if ((*board)[i][user_move] == blank_space){
            (*board)[i][user_move] = player_char;
            break;
        }
    }
}

//validates move
bool play_is_valid(int numArgsRead, int numArgsNeeded, double value, int cols, char** board){
    bool validFormat = (numArgsRead == numArgsNeeded);
    bool valid;
    char lastChar;
    int iteration2 = (int) value;
    double check;
    
    /* constraints met 
       ~ move cannot go out of bound
    */
    if (iteration2 > (cols - 1)) {
        return false;
    }
    else {
        check = value / iteration2;
    }
    
    if (value < cols - cols) {
        return false;
    }
    else {
        check = value / iteration2;
    }
    
    if (iteration2 < cols || iteration2 >= 0) {
        if (is_blank_space(board, iteration2)) {
            valid = true;
        }
    }
    
    
    if ((validFormat == true) && (value > 2)) {   
        if (check != 1) {
            valid = false;
        }
        else {
            valid = true;
        }
        do {
            scanf("%c", &lastChar);
            
            if (!isspace(lastChar)){
                valid = false;
            }
        } while (lastChar != '\n');
    }
    else{
        do {
            scanf("%c", &lastChar);
            
            if (!isspace(lastChar)){
                valid = false;
            }
        } while (lastChar != '\n');
    }

    return valid;
    
}


bool game_over(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    return game_won(board, rows, cols, number_of_pieces_in_a_row_needed_to_win) || game_tie(board, rows, cols, number_of_pieces_in_a_row_needed_to_win);
}

//prints board
void print_board(char** board, int rows, int cols){
    int i, k, m;
    int count_rows = rows - 1;
    int count_cols = cols;
    
    for (i = 0; i < rows; ++i) {
        printf("%d ", count_rows);
        count_rows = count_rows - 1;
        
        for (k = 0; k < cols; ++k) {
            printf("%c ", board[i][k]);
        }
        
        printf("\n");
    }
    
    printf("  ");
    for (m = 0; m < count_cols; ++m) {
        printf("%d ", m);
        
    }
    printf("\n");
}

bool is_blank_space(char** board, int value){
    char blank_space = '*';
    
    if (board[0][value] != blank_space) {
        return false;
    }
    else {
        return true;
    }
}

void change_turn(int* turn) {
    *turn = (*turn + 1) % 2;
}

void destroy_board(char*** board, int rows){
    int i = 0;
    
    for (i = 0; i < rows; ++i){
        free((*board)[i]);
    }
    free(*(board));
    *board = NULL;
}

//asks for move
int get_play(char** board, int turn, int cols) {
    int numArgsRead = 0;
    int value = 0;
    int boardRange = cols - 1;
    do {
        printf("Enter a column between 0 and %d to play in: ", boardRange);
        numArgsRead = scanf("%d", &value);
        
    } while(!play_is_valid(numArgsRead, 1, value, cols, board));
    
    return value;
}
