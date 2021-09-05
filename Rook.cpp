#include <iostream>
#include <string>
using namespace std;

// Funtion to check for rook valid move

bool Rook_valid_move(string piece, int po_row, int po_column, int row, int column, string board[][8])
{
	int dum1 = 0, dum2 = 0;

	if (   ((piece.at(0)== 'R') && (board[row][column] == "  " || (islower(board[row][column].at(0)))))   ||   ( (piece.at(0) == 'r') &&  ((board[row][column] == "  " || (isupper(board[row][column].at(0))))) )    )
	{
		if (row != po_row && column != po_column)
		{
			return false;
		}
		else 
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
	}

	else
	{
		return false;
	}
}