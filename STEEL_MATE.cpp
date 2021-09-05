#include <iostream>
#include <string>

using namespace std;

// Function to check STEEL MATE case


// Other function used in the steel mate
void COPY_BOARD(string[][8], string[][8], bool);
bool Possible_move(char, int, int, int[], int[], string [][8], int, string&, bool&, bool& , string []);


bool STELL_MATE(string board[][8], int turn, string em_piece,bool em_flag, bool castling)
{
	string temp_piece, temp_board[8][8], dum, d[4] = { "" };
	int p_row = 0, p_column = 0;
	bool st;
	int row[8] = { 0,1,2,3,4,5,6,7 };
	int column[8] = { 0,1,2,3,4,5,6,7 };

	COPY_BOARD(board, temp_board, false);

	// Passing diffrent pieces for every position of board

	st = Possible_move('q', p_row, p_column, row, column, temp_board, turn, em_piece, em_flag, castling, d);
	if (st) return false;
	
	st = Possible_move('k', p_row, p_column, row, column, temp_board, turn, em_piece, em_flag, castling, d);
	if (st) return false;

	st = Possible_move('r', p_row, p_column, row, column, temp_board, turn, em_piece, em_flag, castling, d);
	if (st) return false;

	st = Possible_move('b', p_row, p_column, row, column, temp_board, turn, em_piece, em_flag, castling, d);
	if (st) return false;

	st = Possible_move('k', p_row, p_column, row, column, temp_board, turn, em_piece, em_flag, castling, d);
	if (st) return false;

	st = Possible_move('p', p_row, p_column, row, column, temp_board, turn, em_piece, em_flag, castling, d);
	if (st) return false;

	else return true;
}