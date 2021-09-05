#include <iostream>
#include <string>
using namespace std;

// Function for checking the knights valid move

bool Knight_valid_move(string piece, int po_row, int po_column, int row, int column,string board[][8])
{
	if ((piece.at(0)== 'K'&& piece != "K4")|| (piece.at(0) == 'k' && piece != "k4"))
	{
		if ((((column == po_column + 2) || (column == po_column - 2)) && ((row == po_row + 1) || (row == po_row - 1))) && ((!isupper (board[row][column].at(0)) && piece.at(0)=='K')|| (!islower(board[row][column].at(0)) && piece.at(0) == 'k'))   )
		{
				return true;
		}
		else if ((((row == po_row + 2) || (row == po_row - 2)) && ((column == po_column + 1) || (column == po_column - 1))) && ((!isupper(board[row][column].at(0)) && piece.at(0) == 'K') || (!islower(board[row][column].at(0)) && piece.at(0) == 'k')))
		{
				return true;
		}
		else
		{
			return false;
		}
	}

	else
	{
		return false;
	}
}