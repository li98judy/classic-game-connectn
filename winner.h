#ifndef WINNER_H
    #define WINNER_H
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    bool game_tie(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    bool game_won(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    bool row_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    bool col_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    bool diag_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    bool right_diag_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    bool left_diag_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
    void declare_winner(char** board, int turn, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win);
#endif
