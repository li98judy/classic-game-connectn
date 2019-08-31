#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "winner.h"

// Declares if the winner is player1, or player2 
void declare_winner(char** board, int turn, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win){
    if(game_won(board, rows, cols, number_of_pieces_in_a_row_needed_to_win)){
        if(turn == 1){
            printf("Player 1 Won!\n");
        }
        else{
            printf("Player 2 Won!\n");
        }
    }
    else{
        printf("Tie game!\n");
    }
}

// Checks if anyone won the function
bool game_won(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    return row_win(board, rows, cols, number_of_pieces_in_a_row_needed_to_win) || col_win(board, rows, cols, number_of_pieces_in_a_row_needed_to_win) || diag_win(board, rows, cols, number_of_pieces_in_a_row_needed_to_win);
}

/*
    Checks if a someone got the same number of pieces down a left diagonal
*/
bool left_diag_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    int i = 0;
    int k = 0;
    int m = 0;
    int cols_copy = cols;
    int same_num_pieces = 1;
    char player1_piece = 'X';
    char player2_piece = 'O';
    
    for (i = 0; i < rows; ++i) {
        for (k = 0; k < cols; ++k) {
            //locate the left upper corner && identifies a potential left-diagonal win
            if ((board[i][k] == player1_piece) && ((k + (number_of_pieces_in_a_row_needed_to_win - 1)) < cols_copy) && (i + (number_of_pieces_in_a_row_needed_to_win - 1) < rows) ) {
                /* once there is an identified upper-left bound potential win for player X
                 then check if there is a diagonal win
                 */
                for (m = 1; m <= (number_of_pieces_in_a_row_needed_to_win - 1); ++m) {
                    // account for going out of bound
                    if ((i + m < rows) && (k + m < cols)) {
                        if (board[i + m][k + m] != player1_piece) {
                            break;
                        }
                        else{
                            same_num_pieces = same_num_pieces + 1;
                            if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        same_num_pieces = 1;
    }
    
    same_num_pieces = 1;
    
    for (i = 0; i < rows; ++i) {
        for (k = 0; k < cols; ++k) {
            //locate the left upper corner && identifies a potential left-diagonal win
            if ((board[i][k] == player2_piece) && ((k + (number_of_pieces_in_a_row_needed_to_win - 1)) < cols_copy) && (i + (number_of_pieces_in_a_row_needed_to_win - 1) < rows) ) {
                /* once there is an identified upper-left bound potential win for player X
                 then check if there is a diagonal win
                 */
                for (m = 1; m <= (number_of_pieces_in_a_row_needed_to_win - 1); ++m) {
                    // account for going out of bound
                    if ((i + m < rows) && (k + m < cols)) {
                        if (board[i + m][k + m] != player2_piece) {
                            break;
                        }
                        else{
                            same_num_pieces = same_num_pieces + 1;
                            if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        same_num_pieces = 1;
    }
    
    return false;
}

/*
    Checks if a someone got the same number of pieces down a right diagonal
*/
bool right_diag_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    int i = 0;
    int k = 0;
    int m = 0;
    int same_num_pieces = 1;
    char player1_piece = 'X';
    char player2_piece = 'O';
    
    for (i = 0; i < rows; ++i) {
        for (k = 0; k < cols; ++k) {
            //locate the right upper corner && identifies a potential right-diagonal win
            if ((board[i][k] == player1_piece) && ((i + (number_of_pieces_in_a_row_needed_to_win - 1)) < rows) && (k - (number_of_pieces_in_a_row_needed_to_win - 1) >= 0) ) {
                /* once there is an identified upper-right bound potential win for player X
                 then check if there is a diagonal win
                 */
                for (m = 1; m <= (number_of_pieces_in_a_row_needed_to_win - 1); ++m) {
                    if ((i + m < rows) && (k - m >= 0)) {
                        if (board[i + m][k - m] != player1_piece) {
                            break;
                        }
                        else{
                            same_num_pieces = same_num_pieces + 1;
                            if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        same_num_pieces = 1;
    }
    
    same_num_pieces = 1;
    
    for (i = 0; i < rows; ++i) {
        for (k = 0; k < cols; ++k) {
            //locate the right upper corner && identifies a potential right-diagonal win
            if ((board[i][k] == player2_piece) && ((i + (number_of_pieces_in_a_row_needed_to_win - 1)) < rows) && (k - (number_of_pieces_in_a_row_needed_to_win - 1) >= 0)) {
                /* once there is an identified upper-right bound potential win for player X
                 then check if there is a diagonal win
                 */
                for (m = 1; m <= (number_of_pieces_in_a_row_needed_to_win - 1); ++m) {
                    if ((i + m < rows) && (k - m >= 0)) {
                        if (board[i + m][k - m] != player2_piece) {
                            break;
                        }
                        else{
                            same_num_pieces = same_num_pieces + 1;
                            if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        same_num_pieces = 1;
    }
    return false;
}
bool diag_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    return right_diag_win(board, rows, cols, number_of_pieces_in_a_row_needed_to_win) || left_diag_win(board, rows, cols, number_of_pieces_in_a_row_needed_to_win);
}


// Checks if there is a tie, there is a tie when the board is full and no one has won
bool game_tie(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    int i, k;
    char blank_space = '*';
    
    for (i = 0; i < rows; ++i) {
        for (k = 0; k < cols; ++k) {
            if (board[i][k] == blank_space) {
                return false;
            }
        }
    }
    
    return !game_won(board, rows, cols, number_of_pieces_in_a_row_needed_to_win);
    
}

// Checks if someone has won if their pieces are in a row the number of pieces to win times

bool row_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    
    int i = 0;
    int k = 0;
    int same_num_pieces = 0;
    char player1_piece = 'X';
    char player2_piece = 'O';
    
    // This checks if the first player got the same pieces in a row
    for (i = 0; i < rows; ++i) {
        for (k = 0; k < cols; ++k){
            if (board[i][k] == player1_piece) {
                
                same_num_pieces = same_num_pieces + 1;
                
                if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win){
                    return true;
                }
            } 
            else {
                same_num_pieces = 0;
            }
        }
        same_num_pieces = 0;
    }
    
    same_num_pieces = 0;
    
    //This checks if the second player got the same number pieces in a row
    for (i = 0; i < rows; ++i) {
        for (k = 0; k < cols; ++k){
            if (board[i][k] == player2_piece) {
                
                same_num_pieces = same_num_pieces + 1;
                
                if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win){
                    return true;
                }
            } 
            else {
                same_num_pieces = 0;
            }
        }
        same_num_pieces = 0;
    }
    
    return false;
}

// Checks if someone has won if their pieces are in a column the number of pieces to win times
bool col_win(char** board, int rows, int cols, int number_of_pieces_in_a_row_needed_to_win) {
    int i = 0;
    int k = 0;
    int same_num_pieces = 0;
    char player1_piece = 'X';
    char player2_piece = 'O';
    
    for (k = 0; k < cols; ++k) {
        for (i = 0; i < rows; ++i){
            if (board[i][k] == player1_piece) {
                
                same_num_pieces = same_num_pieces + 1;
                
                if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win){
                    return true;
                }
            } 
            else {
                same_num_pieces = 0;
            }
        }
        same_num_pieces = 0;
    }
    
    same_num_pieces = 0;
    
    //This checks if the second player got the same number pieces in a row
    for (k = 0; k < cols; ++k) {
        for (i = 0; i < rows; ++i){
            if (board[i][k] == player2_piece) {
                
                same_num_pieces = same_num_pieces + 1;
                
                if (same_num_pieces == number_of_pieces_in_a_row_needed_to_win){
                    return true;
                }
            } 
            else {
                same_num_pieces = 0;
            }
        }
        same_num_pieces = 0;
    }
    
    return false;
}

