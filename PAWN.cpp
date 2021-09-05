
#include <iostream>
#include <string>
using namespace std;

// Function to check pawns valid move

// PAWN EM-PASSANT MOVE is also added
// Pawn promotion is also added

bool Pawn_valid_move(string piece, int po_row, int po_column, int row, int column, string board [][8],string &em_piece,bool &em_flag)
{
	int check = true;
	if (board[row][column] != "  " && column == po_column)
	{
		return false;
	}
	else if (row == po_row)
		return false;
	if (piece.at(0) == 'P')
	{
		// same team piece at required position
		if (isupper(board[row][column].at(0)))
 	    {
		    return false;
     	}
		// Pawn en passant move
		else if ( (po_row == 3) && (em_flag == true) && (board[row + 1][column] == em_piece))
		{
			return true;
		}
		// Kill code for white pawns
		else if (row == po_row - 1 && (column == po_column - 1 || column == po_column + 1) && islower (board[row][column].at(0)))
		{
			return true;
		}
		// Pawn first move
		else if (po_row == 6 && (column == po_column && row > 3 && row < po_row))
		{
			em_piece = piece;
			em_flag = true;
			return true;
		}
		
		else if (column == po_column && row == po_row -1)
			{
			   return true;
			}
		
		else
			{
				return false;
			}
		
		return true;
	}

	else if (piece.at(0) == 'p')
	{
		// same team piece at required position
		if (islower (board[row][column].at(0)))
		{
			return false;
		}
		// Pawn en passant move
		else if ((po_row == 4) && (em_flag == true) && (board[row - 1][column] == em_piece ))
		{
			return true;
		}

		// Kill code for white pawns
		else if (row == po_row +1 && (column == po_column - 1 || column == po_column + 1) && isupper(board[row][column].at(0)))
		{
			return true;
		}
		// Pawn first move
		else if (po_row == 1 && (column == po_column && row < 4 && row > po_row))
		{
			em_piece = piece;
			em_flag = true;
		
				return true;
		}

		// Simple forward move
		else if (column == po_column && row == po_row + 1)
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