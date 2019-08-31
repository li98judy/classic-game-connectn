#ifndef MAKEBOARD_H
    #define MAKEBOARD_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include "winner.h"
    void read_args(int argc);
    void play_game(int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    char** create_board(int rows, int cols);
    void play_move(char*** board, int turn, int user_move, int rows);
    bool play_is_valid(int numArgsRead, int numArgsNeeded, double value, int cols, char** board);
    bool game_over(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    void print_board(char** board, int rows, int cols);
    bool is_blank_space(char** board, int value);
    void change_turn(int* turn);
    void destroy_board(char*** board, int rows);
    int get_play(char**board, int turn, int cols);
#endif
