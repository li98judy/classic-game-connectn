#include "winner.h"
#include "makeboard.h"

/* Connect N Game:
   
       ~ Two players take turns dropping their pieces into a
       column until either player gets N of their pieces in a row either horizontally,
       vertically, or diagonally, or until their or no more spaces to play.
       
   Rules:
        ~ program should not allow the user to make an impossible play but should 
          continue to ask the user for a play until a valid play is entered 
          (Invalid plays consist of plays made outside the board or in to columns that
           are already full)
           
        ~ The token used to represent Player 1 is X
        ~ The token used to represent Player 2 is O
        ~ After the game is over the winner should be declared or if 
          there is no winner a tie should be declared
*/

// This is the main function in the main file and it calls all the other functions
// The main function also takes in the input with the command line

int main(int argc, char* argv[]){
    /*  3 command line parameters in this order: 
        ~ number of rows, 
        ~ number of columns, 
        ~ number of pieces in a row to win
    */
    
    int num_rows, num_columns,number_of_pieces_in_a_row_needed_to_win;
   
    read_args(argc);
    
    sscanf(argv[1], "%d", &num_rows);
    sscanf(argv[2], "%d", &num_columns); 
    sscanf(argv[3], "%d", &number_of_pieces_in_a_row_needed_to_win);
    
    play_game(num_rows, num_columns, number_of_pieces_in_a_row_needed_to_win);
    
    return 0;
}