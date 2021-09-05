#include <iostream>
#include <string>
using namespace std;

//*************************************************//
// --> BISHOP VALID MOVE CHECKING FUNCTION         //
//*************************************************//

bool Bishop_valid_move(string piece, int po_row, int po_column, int row, int column, string board[][8])
{
	int dum1=0,dum2=0;
	bool move_valid = false;

	// valid move checking 
	if (piece.at(0)== 'B'  || piece.at(0)=='b')
	{
		if (board[row][column] == "  ")
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
		for (int i = 1;i < 8;++i)
		{
			if ((((row == po_row + i) || (row == po_row - i)) && ((column == po_column + i) || (column == po_column - i))) && ((!isupper(board[row][column].at(0)) && piece.at(0) == 'B')||((!islower(board[row][column].at(0)) && piece.at(0) == 'b')) )   )
			{	
					move_valid = true;
					break;
			}
		}	
		return move_valid;
	}

	else
	{
		return false;
	}

}