
#include <iostream>
#include <string>
using namespace std;

// Function to check the Queens's valid move

bool Queen_valid_move(string piece, int po_row, int po_column, int row, int column, string board[][8])
{
	bool move_validity = false, B_check=false;
	int base = 2, dum1 = 0, dum2 = 0;
	if (piece.at(0)=='Q')
	{
		// Same team piece at required position
		if (isupper (board[row][column].at(0)))
		{
			return false;
		}

		// Rook type move with HURDLE CHECK.
		if ((board[row][column] == "  " || islower(board[row][column].at(0))) && (row==po_row || column==po_column))
		{
			for (int i = 0;i < 8;++i)
			{
				if (row == po_row && column > po_column) --dum2;
				else if (row == po_row && column < po_column) ++dum2;
				else if (column == po_column && row > po_row) --dum1;
				else if (column == po_column && row < po_row) ++dum1;
				if (row + dum1 == po_row && column + dum2 == po_column)
					break;
				if (board[row + dum1][column + dum2] != "  ")
					return false;
			}
			return true;
		}

		// King type move
		if (((row == po_row + 1) || (row == po_row - 1)) && ((column == po_column + 1) || (column == po_column - 1)))
		{
			return true;
		}
	
		// Bishop type move 
		for (int i = 1;i < 8;++i)
		{
			if (((row == po_row + i) || (row == po_row - i)) && ((column == po_column + i) || (column == po_column - i)))
			{
				B_check = true;
				move_validity = true;
				break;
			}
			else
			{
				move_validity = false;
			}
		}

		// Hurdle check for bishop type move.
		if (board[row][column] == "  " && B_check==true)
		{
			for (int i = 0;i < 8;++i)
			{
				if (row < po_row) ++dum1;
				else --dum1;
				if (column > po_column) --dum2;
				else ++dum2;
				if (row + dum1 == po_row || column + dum2 == po_column)
					break;
				if (board[row + dum1][column + dum2] != "  ")
					return false;
			}
		}
		return move_validity;
	}

	else if (piece.at(0) == 'q')
	{
		// Same team piece at required position
		if (islower(board[row][column].at(0)))
		{
			return false;
		}

		// Rook type move with HURDLE CHECK.
		if ((board[row][column] == "  " || isupper(board[row][column].at(0))) && (row == po_row || column == po_column))
		{
			for (int i = 0;i < 8;++i)
			{
				if (row == po_row && column > po_column) --dum2;
				else if (row == po_row && column < po_column) ++dum2;
				else if (column == po_column && row > po_row) --dum1;
				else if (column == po_column && row < po_row) ++dum1;
				if (row + dum1 == po_row && column + dum2 == po_column)
					break;
				if (board[row + dum1][column + dum2] != "  ")
					return false;
			}
			return true;
		}

		// King type move
		if (((row == po_row + 1) || (row == po_row - 1)) && ((column == po_column + 1) || (column == po_column - 1)))
		{
			return true;
		}

		// Bishop type move 
		for (int i = 1;i < 8;++i)
		{
			if (((row == po_row + i) || (row == po_row - i)) && ((column == po_column + i) || (column == po_column - i)))
			{
				B_check = true;
				move_validity = true;
				break;
			}
			else
			{
				move_validity = false;
			}
		}

		// Hurdle check for bishop type move.
		if (board[row][column] == "  " && B_check == true)
		{
			for (int i = 0;i < 8;++i)
			{
				if (row < po_row) ++dum1;
				else --dum1;
				if (column > po_column) --dum2;
				else ++dum2;
				if (row + dum1 == po_row || column + dum2 == po_column)
					break;
				if (board[row + dum1][column + dum2] != "  ")
					return false;
			}
		}
		return move_validity;
	}

	else
	{
		return false;
	}
}