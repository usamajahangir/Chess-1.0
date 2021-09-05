#include <iostream>
#include <string>
using namespace std;


// KING VALID MOVE CHECKING FUNCTION

void COPY_BOARD(string [][8], string [][8], bool);

bool King_valid_move(string piece, int po_row, int po_column, int row, int column, string dummy_board[][8],int turn,bool& castling)
{
	// local variables 
	string board[8][8] = {"  "};
	COPY_BOARD(dummy_board, board, false);
	board[po_row][po_column] = "  ";

	bool king_check = false, flagr1 = true, flagr2 = true, flagc1 = true, flagc2 = true,op_check = false;

	if (  (  (piece == "K4") && ((islower(board[row][column].at(0))) || (board[row][column] == "  "))) || ( (piece == "k4") && ((isupper(board[row][column].at(0))) || (board[row][column] == "  ")))  )
	{
		if ( (   ((row == po_row + 1) || (row == po_row - 1) || (row == po_row))  && ((column == po_column + 1) || (column == po_column - 1) || (column == po_column))  )  || (row == po_row && (column == po_column+2||column == po_column -3 )) )
		{
			if (row == po_row && column == po_column)
			{
				return false;
			}
			if (turn % 2 == 0)
			{
				//*********************************//
                //          IF PAWN CHECK          //
                //*********************************//
        	    if ((board[row + 1][column + 1].at(0) == 'P') || (board[row + 1][column - 1].at(0) == 'P'))
				{
					return false;
				}
				//*********************************//
		     	//       IF KNIGHT CHECK           //
		     	//*********************************//
				if (
					((row > 1 && column > 0) && (board[row - 2][column - 1].at(0) == 'K' && board[row - 2][column - 1] != "K4")) ||
					((row > 1 && column < 7) && (board[row - 2][column + 1].at(0) == 'K' && board[row - 2][column + 1] != "K4")) ||
					((row < 6 && column < 7) && (board[row + 2][column + 1].at(0) == 'K' && board[row + 2][column + 1] != "K4")) ||
					((row < 6 && column > 0) && (board[row + 2][column - 1].at(0) == 'K' && board[row + 2][column - 1] != "K4")) ||
					((row < 7 && column < 6) && (board[row + 1][column + 2].at(0) == 'K' && board[row + 1][column + 2] != "K4")) ||
					((row > 0 && column < 6) && (board[row - 1][column + 2].at(0) == 'K' && board[row - 1][column + 2] != "K4")) ||
					((row < 7 && column > 1) && (board[row + 1][column - 2].at(0) == 'K' && board[row + 1][column - 2] != "K4")) ||
					((row > 0 && column > 1) && (board[row - 1][column - 2].at(0) == 'K' && board[row - 1][column - 2] != "K4")))
				{
					return false;
				}

				// opponent kings check
				if (
					((row > 0 && column > 0) && (board[row - 1][column - 1] == "K4")) ||
					((row > 0 && column < 7) && (board[row - 1][column + 1] == "K4")) ||
					((row < 7 && column < 7) && (board[row + 1][column + 1] == "K4")) ||
					((row < 7 && column > 0) && (board[row + 1][column - 1] == "K4")) ||
					((row < 8 && column < 7) && (board[row    ][column + 1] == "K4")) ||
					((row < 8 && column > 0) && (board[row    ][column - 1] == "K4")) ||
					((row < 7 && column < 8) && (board[row + 1][column    ] == "K4")) ||
					((row > 0 && column < 8) && (board[row - 1][column    ] == "K4")))
				{		
					return false;
				}

				//  Rook and Queen + check checking code
				for (int i = 1;i < 8;++i)
				{
					if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
					if ((board[row + i][column] != "  ") && (flagr1 == true))
					{
						flagr1 = false;
						if ((row + i < 8) && (board[row + i][column].at(0) == 'Q' || board[row + i][column].at(0) == 'R'))
						{
							king_check = true;
							break;
						}
					}
					if ((board[row - i][column] != "  ") && (flagr2 == true))
					{
						flagr2 = false;
						if ((row - i >= 0) && (board[row - i][column].at(0) == 'Q' || board[row - i][column].at(0) == 'R'))
						{
							king_check = true;
							break;
						}
					}
					if ((board[row][column + i] != "  ") && (flagc1 == true))
					{
						flagc1 = false;
						if ((column + i < 8) && (board[row][column + i].at(0) == 'Q' || board[row][column + i].at(0) == 'R'))
						{
							king_check = true;
							break;
						}
					}
					if ((board[row][column - i] != "  ") && (flagc2 == true))
					{
						flagc2 = false;
						if ((column - i >= 0) && (board[row][column - i].at(0) == 'Q' || board[row][column - i].at(0) == 'R'))
						{
							king_check = true;
							break;
						}
					}
					else continue;
				}
				if (king_check == true)
				{
					return false;
				}
				// reinitializing the flags
				flagr1 = true; flagr2 = true; flagc1 = true; flagc2 = true,king_check = false;
				//	Bishop and Queen cross checks checking code
				for (int i = 1;i < 8;++i)
				{
					if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
					if ((board[row + i][column + i] != "  ") && (flagr1 == true))
					{
						flagr1 = false;
						if (((row + i < 8) && (column + i < 8)) && (board[row + i][column + i].at(0) == 'Q' || board[row + i][column + i].at(0) == 'B'))
						{
							king_check = true;
							break;
						}
					}
					if ((board[row - i][column - i] != "  ") && (flagr2 == true))
					{
						flagr2 = false;
						if (((row - i >= 0) && (column - i >= 0)) && (board[row - i][column - i].at(0) == 'Q' || board[row - i][column - i].at(0) == 'B'))
						{
							king_check = true;
							break;
						}
					}
					if ((board[row - i][column + i] != "  ") && (flagc1 == true))
					{
						flagc1 = false;
						if (((column + i < 8) && (row - i >= 0)) && (board[row - i][column + i].at(0) == 'Q' || board[row - i][column + i].at(0) == 'B'))
						{
							king_check = true;
							break;
						}
					}
					if ((board[row + i][column - i] != "  ") && (flagc2 == true))
					{
						flagc2 = false;
						if (((column - i >= 0) && (row + i < 8)) && (board[row + i][column - i].at(0) == 'Q' || board[row + i][column - i].at(0) == 'B'))
						{
							king_check = true;
							break;
						}
					}
					else continue;
				}
				if (king_check == true)
				{
					return false;
				}

				//  Castling case
				if (board[row][column] == "  ")
				{
					if ((board[po_row][po_column + 1] == "  ") && (board[po_row][po_column + 3].at(0) == 'r'))
					{
						castling = true;
						return true;
					}
					else if ((board[po_row][po_column - 1] == "  ") && (board[po_row][po_column - 4].at(0) == 'r') && (board[po_row][po_column - 2] == "  "))
					{
						castling = true;
						return true;
					}
				}
			

				else return true;
			}
			else if (turn % 2 != 0)
			{

			
				// check from pawn checking
				if ((board[row - 1][column + 1].at(0) == 'p') || (board[row - 1][column - 1].at(0) == 'p'))
				{
					return false;
				}
				//// check from knights checking
				if (
					((row > 1 && column > 0) && (board[row - 2][column - 1].at(0) == 'k' && board[row - 2][column - 1] != "k4")) ||
					((row > 1 && column < 7) && (board[row - 2][column + 1].at(0) == 'k' && board[row - 2][column + 1] != "k4")) ||
					((row < 6 && column < 7) && (board[row + 2][column + 1].at(0) == 'k' && board[row + 2][column + 1] != "k4")) ||
					((row < 6 && column > 0) && (board[row + 2][column - 1].at(0) == 'k' && board[row + 2][column - 1] != "k4")) ||
					((row < 7 && column < 6) && (board[row + 1][column + 2].at(0) == 'k' && board[row + 1][column + 2] != "k4")) ||
					((row > 0 && column < 6) && (board[row - 1][column + 2].at(0) == 'k' && board[row - 1][column + 2] != "k4")) ||
					((row < 7 && column > 1) && (board[row + 1][column - 2].at(0) == 'k' && board[row + 1][column - 2] != "k4")) ||
					((row > 0 && column > 1) && (board[row - 1][column - 2].at(0) == 'k' && board[row - 1][column - 2] != "k4")))
				{
					return false;
				}

				// opponent kings check
				if (
					((row > 0 && column > 0) && (board[row - 1][column - 1] == "k4")) ||
					((row > 0 && column < 7) && (board[row - 1][column + 1] == "k4")) ||
					((row < 7 && column < 7) && (board[row + 1][column + 1] == "k4")) ||
					((row < 7 && column > 0) && (board[row + 1][column - 1] == "k4")) ||
					((row < 8 && column < 7) && (board[row][column + 1] == "k4")) ||
					((row < 8 && column > 0) && (board[row][column - 1] == "k4")) ||
					((row < 7 && column < 8) && (board[row + 1][column] == "k4")) ||
					((row > 0 && column < 8) && (board[row - 1][column] == "k4")))
				{
					return false;
				}
				//   Queen and rook + check
				for (int i = 1;i < 8;++i)
				{
					if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
					if ((row + i < 8) && (board[row + i][column] != "  ") && (flagr1 == true))
					{
						flagr1 = false;
						if ((board[row + i][column].at(0) == 'q' || board[row + i][column].at(0) == 'r'))
						{
							king_check = true;
							break;
						}
					}
					if ((row - i >= 0) && (board[row - i][column] != "  ") && (flagr2 == true))
					{
						flagr2 = false;
						if ((board[row - i][column].at(0) == 'q' || board[row - i][column].at(0) == 'r'))
						{
							king_check = true;
							break;
						}
					}
					if ((column + i < 8) && (board[row][column + i] != "  ") && (flagc1 == true))
					{
						flagc1 = false;
						if ((board[row][column + i].at(0) == 'q' || board[row][column + i].at(0) == 'r'))
						{
							king_check = true;
							break;
						}
					}
					if ((column - i >= 0) && (board[row][column - i] != "  ") && (flagc2 == true))
					{
						flagc2 = false;
						if ((board[row][column - i].at(0) == 'q' || board[row][column - i].at(0) == 'r'))
						{
							king_check = true;
							break;
						}
					}
					else continue;
				}
				if (king_check == true)
				{
					return false;
				}
				// reinitializing the flags
				flagr1 = true; flagr2 = true; flagc1 = true; flagc2 = true;
				//	Bishop and Queen cross checks checking code
				for (int i = 1;i < 8;++i)
				{
					if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
					if ((row + i < 8 && column + i < 8) && (board[row + i][column + i] != "  ") && (flagr1 == true))
					{
						flagr1 = false;
						if ((board[row + i][column + i].at(0) == 'q' || board[row + i][column + i].at(0) == 'b'))
						{
							king_check = true;
							break;
						}
					}
					if ((row - i >= 0 && column - i >= 0) && (board[row - i][column - i] != "  ") && (flagr2 == true))
					{
						flagr2 = false;
						if ((board[row - i][column - i].at(0) == 'q' || board[row - i][column - i].at(0) == 'b'))
						{
							king_check = true;
							break;
						}
					}
					if ((row - i >= 0 && column + i < 8) && (board[row - i][column + i] != "  ") && (flagc1 == true))
					{
						flagc1 = false;
						if ((board[row - i][column + i].at(0) == 'q' || board[row - i][column + i].at(0) == 'b'))
						{
							
							king_check = true;
							break;
						}
					}
					if ((row + i < 8 && column - i >= 0) && (board[row + i][column - i] != "  ") && (flagc2 == true))
					{
						flagc2 = false;
						if ((board[row + i][column - i].at(0) == 'q' || board[row + i][column - i].at(0) == 'b'))
						{
							king_check = true;
							break;
						}
					}
					else continue;
				}
				if (king_check == true)
				{
					return false;
				}

				//  Castling case
				if (board[row][column] == "  ")
				{
					if ((board[po_row][po_column + 1] == "  ") && (board[po_row][po_column + 3].at(0) == 'R'))
					{
						castling = true;
						return true;
					}
					else if ((board[po_row][po_column - 1] == "  ") && (board[po_row][po_column - 4].at(0) == 'R') && (board[po_row][po_column - 2] == "  "))
					{
						castling = true;
						return true;
					}
				}
				else
				{
					return true;
				}
			}
				
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
	return true;
}








