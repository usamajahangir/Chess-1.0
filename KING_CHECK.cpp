

#include <iostream>
#include <string>
using namespace std;

// function to check that if the king is in check or not

bool SEARCH_PIECE(string[][8], string, int&, int&);
bool search_temp_piece(string [][8], int, string& , int&, int&);

bool King_in_check(string temp_board[][8],int turn,string &Checking_piece)
{
	string piece = "k4";
	int row = 0, column = 0;
	search_temp_piece(temp_board,turn,piece, row,column);
	
		
		bool king_check = false, flagr1 = true, flagr2 = true, flagc1 = true, flagc2 = true;
		if (turn % 2 == 0)
		{

			//**********************************//
			//      WHITE PAWNS CHECK           //
			//**********************************//
			if (temp_board[row + 1][column + 1].at(0) == 'P')
			{
				Checking_piece = temp_board[row + 1][column + 1];
				return true;
			}
		    else if (temp_board[row + 1][column - 1].at(0) == 'P')
			{
				Checking_piece = temp_board[row + 1][column - 1];
				return true;
			}
			//**********************************//
			//      WHITE KNIGHTS CHECK         //
			//**********************************//

			if ((row > 1 && column > 0) && (temp_board[row - 2][column - 1].at(0) == 'K' && temp_board[row - 2][column - 1] != "K4"))
			{
				Checking_piece = temp_board[row - 2][column - 1];
				return true;
			 }
			else if ((row > 1 && column < 7) && (temp_board[row - 2][column + 1].at(0) == 'K' && temp_board[row - 2][column + 1] != "K4"))
			{
				Checking_piece = temp_board[row - 2][column + 1];
				return true;
			}
			else if ((row < 6 && column < 7) && (temp_board[row + 2][column + 1].at(0) == 'K' && temp_board[row + 2][column + 1] != "K4"))
			{
				Checking_piece = temp_board[row + 2][column + 1];
				return true;
			}
			else if ((row < 6 && column > 0) && (temp_board[row + 2][column - 1].at(0) == 'K' && temp_board[row + 2][column - 1] != "K4"))
			{
				Checking_piece = temp_board[row + 2][column - 1];
				return true;
			}
			else if ((row < 7 && column < 6) && (temp_board[row + 1][column + 2].at(0) == 'K' && temp_board[row + 1][column + 2] != "K4"))
			{
				Checking_piece = temp_board[row + 1][column + 2];
				return true;
			}
			else if ((row > 0 && column < 6) && (temp_board[row - 1][column + 2].at(0) == 'K' && temp_board[row - 1][column + 2] != "K4"))
			{
				Checking_piece = temp_board[row - 1][column + 2];
				return true;
			}
			else if ((row < 7 && column > 1) && (temp_board[row + 1][column - 2].at(0) == 'K' && temp_board[row + 1][column - 2] != "K4"))
			{
				Checking_piece = temp_board[row + 1][column - 2];
				return true;
			}
			else if ((row > 0 && column > 1) && (temp_board[row - 1][column - 2].at(0) == 'K' && temp_board[row - 1][column - 2] != "K4"))
			{
				Checking_piece = temp_board[row - 1][column - 2];
				return true;
			}


			//**********************************//
			//   WHITE (QUEEN & ROOK) + CHECK   //
			//**********************************//
			for (int i = 1;i < 8;++i)
			{
				if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
				if ((row + i < 8) && (temp_board[row + i][column] != "  ") && (flagr1 == true))
				{
					flagr1 = false;
					if ( (temp_board[row + i][column].at(0) == 'Q' || temp_board[row + i][column].at(0) == 'R'))
					{
						Checking_piece = temp_board[row + i][column];
						king_check = true;
						break;
					}
				}
				if ((row - i >= 0) && (temp_board[row - i][column] != "  ") && (flagr2 == true))
				{
					flagr2 = false;
					if ( (temp_board[row - i][column].at(0) == 'Q' || temp_board[row - i][column].at(0) == 'R'))
					{
						Checking_piece = temp_board[row - i][column];
						king_check = true;
						break;
					}
				}
				if ((column + i < 8) && (temp_board[row][column + i] != "  ") && (flagc1 == true))
				{
					flagc1 = false;
					if ( (temp_board[row][column + i].at(0) == 'Q' || temp_board[row][column + i].at(0) == 'R'))
					{
						Checking_piece = temp_board[row][column+i];
						king_check = true;
						break;
					}
				}
				if ((column - i >= 0) && (temp_board[row][column - i] != "  ") && (flagc2 == true))
				{
					flagc2 = false;
					if ( (temp_board[row][column - i].at(0) == 'Q' || temp_board[row][column - i].at(0) == 'R'))
					{
						Checking_piece = temp_board[row][column-i];
						king_check = true;
						break;
					}
				}
			}
			if (king_check == true)
			{
				return true;
			}
			//**********************************//
			//   WHITE (QUEEN & ROOK) * CHECK   //
			//**********************************//

			// reinitializing the flags
			flagr1 = true; flagr2 = true; flagc1 = true; flagc2 = true;

			for (int i = 1;i < 8;++i)
			{
				if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
				if (((row + i < 8) && (column + i < 8)) && (temp_board[row + i][column + i] != "  ") && (flagr1 == true))
				{
					flagr1 = false;
					if ( (temp_board[row + i][column + i].at(0) == 'Q' || temp_board[row + i][column + i].at(0) == 'B'))
					{
						Checking_piece = temp_board[row + i][column+i];
						king_check = true;
						break;
					}
					else {}
				}
				if (((row - i >= 0) && (column - i >= 0)) && (temp_board[row - i][column - i] != "  ") && (flagr2 == true))
				{
					flagr2 = false;
					if ((temp_board[row - i][column - i].at(0) == 'Q' || temp_board[row - i][column - i].at(0) == 'B'))
					{
						Checking_piece = temp_board[row - i][column - i];
						king_check = true;
						break;
					}
					else {}
				}
				if (((column + i < 8) && (row - i >= 0)) && (temp_board[row - i][column + i] != "  ") && (flagc1 == true))
				{
					flagc1 = false;
					if ( (temp_board[row - i][column + i].at(0) == 'Q' || temp_board[row - i][column + i].at(0) == 'B'))
					{
						Checking_piece = temp_board[row - i][column + i];
						king_check = true;
						break;
					}
					else{}
				}
				if (((column - i >= 0) && (row + i < 8)) && (temp_board[row + i][column - i] != "  ") && (flagc2 == true))
				{
					flagc2 = false;
					if ( (temp_board[row + i][column - i].at(0) == 'Q' || temp_board[row + i][column - i].at(0) == 'B'))
					{
						Checking_piece = temp_board[row + i][column - i];
						king_check = true;
						break;
					}
					else{}
				}
			}
			if (king_check == true)
			{
				return true;
			}
			else return false;
		}
		else if (turn % 2 != 0)
			{
			//**********************************//
			//      BLACK PAWNS CHECK           //
			//**********************************//
			if (temp_board[row - 1][column + 1].at(0) == 'p')
			{
				Checking_piece = temp_board[row - 1][column + 1];
				return true;
			}
			if (temp_board[row - 1][column - 1].at(0) == 'p')
			{
				Checking_piece = temp_board[row - 1][column - 1];
				return true;
			}
			//**********************************//
	    	//    BLACK KNIGHTS CHECK           //
		    //**********************************//

			if ((row > 1 && column > 0) && (temp_board[row - 2][column - 1].at(0) == 'k' && temp_board[row - 2][column - 1] != "k4"))
			{
				Checking_piece = temp_board[row - 2][column - 1];
				return true;
			}
			else if ((row > 1 && column < 7) && (temp_board[row - 2][column + 1].at(0) == 'k' && temp_board[row - 2][column + 1] != "k4"))
			{
				Checking_piece = temp_board[row - 2][column + 1];
				return true;
			}
			else if ((row < 6 && column < 7) && (temp_board[row + 2][column + 1].at(0) == 'k' && temp_board[row + 2][column + 1] != "k4"))
			{
				Checking_piece = temp_board[row + 2][column + 1];
				return true;
			}
			else if ((row < 6 && column > 0) && (temp_board[row + 2][column - 1].at(0) == 'k' && temp_board[row + 2][column - 1] != "k4"))
			{
				Checking_piece = temp_board[row + 2][column - 1];
				return true;
			}
			else if ((row < 7 && column < 6) && (temp_board[row + 1][column + 2].at(0) == 'k' && temp_board[row + 1][column + 2] != "k4"))
			{
				Checking_piece = temp_board[row + 1][column + 2];
				return true;
			}
			else if ((row > 0 && column < 6) && (temp_board[row - 1][column + 2].at(0) == 'k' && temp_board[row - 1][column + 2] != "k4"))
			{
				Checking_piece = temp_board[row - 1][column + 2];
				return true;
			}
			else if ((row < 7 && column > 1) && (temp_board[row + 1][column - 2].at(0) == 'k' && temp_board[row + 1][column - 2] != "k4"))
			{
				Checking_piece = temp_board[row + 1][column - 2];
				return true;
			}
			else if ((row > 0 && column > 1) && (temp_board[row - 1][column - 2].at(0) == 'k' && temp_board[row - 1][column - 2] != "k4"))
			{
				Checking_piece = temp_board[row - 1][column - 2];
				return true;
			}

			//**********************************//
		    //   BLACK (QUEEN & ROOK) + CHECK   //
		    //**********************************//
			for (int i = 1;i < 8;++i)
			{
				if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
				if ((row + i < 8) && (temp_board[row + i][column] != "  ") && (flagr1 == true))
				{
					flagr1 = false;
					if ((temp_board[row + i][column].at(0) == 'q' || temp_board[row + i][column].at(0) == 'r'))
					{
						Checking_piece = temp_board[row + i][column];
						king_check = true;
						break;
					}
				}
				if ((row - i >= 0) && (temp_board[row - i][column] != "  ") && (flagr2 == true))
				{
					flagr2 = false;
					if ( (temp_board[row - i][column].at(0) == 'q' || temp_board[row - i][column].at(0) == 'r'))
					{
						Checking_piece = temp_board[row - i][column];
						king_check = true;
						break;
					}
				}
				if ((column + i < 8) && (temp_board[row][column + i] != "  ") && (flagc1 == true))
				{
					flagc1 = false;
					if ( (temp_board[row][column + i].at(0) == 'q' || temp_board[row][column + i].at(0) == 'r'))
					{
						Checking_piece = temp_board[row][column + i];
						king_check = true;
						break;
					}
				}
				if ((column - i >= 0) &&(temp_board[row][column - i] != "  ") && (flagc2 == true))
				{
					flagc2 = false;
					if ( (temp_board[row][column - i].at(0) == 'q' || temp_board[row][column - i].at(0) == 'r'))
					{
						Checking_piece = temp_board[row][column - i];
						king_check = true;
						break;
					}
				}
			}
			if (king_check == true)
			{
				return true;
			}

			//**********************************//
			//  BLACK (QUEEN & ROOK) * CHECK    //
			//**********************************//

			// reinitializing the flags
			flagr1 = true; flagr2 = true; flagc1 = true; flagc2 = true;

			for (int i = 1;i < 8;++i)
			{
				if (!flagr1 && !flagr2 && !flagc1 && !flagc2)  break;
				if ((row + i < 8 && column + i < 8) && (temp_board[row + i][column + i] != "  ") && (flagr1 == true))
				{
					flagr1 = false;
					if ( (temp_board[row + i][column + i].at(0) == 'q' || temp_board[row + i][column + i].at(0) == 'b'))
					{
						Checking_piece = temp_board[row + i][column + i];
						king_check = true;
						break;
					}
					else {}
				}
				if ((row - i >= 0 && column - i >= 0) && (temp_board[row - i][column - i] != "  ") && (flagr2 == true))
				{
					flagr2 = false;
					if ( (temp_board[row - i][column - i].at(0) == 'q' || temp_board[row - i][column - i].at(0) == 'b'))
					{
						Checking_piece = temp_board[row - i][column - i];
						king_check = true;
						break;
					}
					else {}
				}
				if ((row - i >= 0 && column + i < 8) && (temp_board[row - i][column + i] != "  ") && (flagc1 == true))
				{
					flagc1 = false;
					if ( (temp_board[row - i][column + i].at(0) == 'q' || temp_board[row - i][column + i].at(0) == 'b'))
					{
						Checking_piece = temp_board[row - i][column + i];
						king_check = true;
						break;
					}
					else{}
				}
				if ((row + i < 8 && column - i >= 0) && (temp_board[row + i][column - i] != "  ") && (flagc2 == true))
				{
					flagc2 = false;
					if ( (temp_board[row + i][column - i].at(0) == 'q' || temp_board[row + i][column - i].at(0) == 'b'))
					{
						Checking_piece = temp_board[row + i][column - i];
						king_check = true;
						break;
					}
					else {}
				}
			}
			if (king_check == true)
			{
				return true;
			}
			else return false;
			}
	    else return false;
}



