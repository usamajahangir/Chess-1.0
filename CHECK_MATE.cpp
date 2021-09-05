#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//*************************************************//
// --> CHECKMATE STATE CHECKING FUNCTION           //
//*************************************************//

// Function used in this checkmate function
void COPY_BOARD(string[][8], string[][8], bool);
bool SEARCH_PIECE(string[][8], string, int&, int&);
bool Search_Check_area(string [][8], string,int[],int[],int);
bool Possible_move(char ,int ,int , int [], int [], string [][8], int, string& , bool& , bool& ,string []);

bool search_temp_piece(string [][8], int, string &,int &,int &);
bool Check_temp_piece( string [][8],int);

bool King_in_check(string[][8], int, string&);
bool take_move(string, int , int, int, int, string [][8], int, string&, bool&, bool&);


bool Check_mate ( string board[][8], int turn, bool king_s_check,string em_piece,bool em_flag,string Checking_piece)
{
	// local variables
	bool check_mate_status = false,dummy = false,status=false;
	string temp_piece = "", temp_board[8][8], dum = "", temp = "", dum_1[4];
	int p_row = 0, p_column = 0, row = 0, column = 0;
	int rows[8] = { 0 }, columns[8] = { 0 }, temp_var_1 = 0, temp_var_2 = 0;

	COPY_BOARD(board, temp_board, false);

	// only check this state is the king is cehck state
	if (king_s_check)
	{
		//*******************************************//
        // CAN KING MOVE                             //
        //*******************************************//
		temp_piece = "k4";
		status = search_temp_piece(temp_board, turn, temp_piece, p_row, p_column);
		row = p_row; column = p_column;
		if (status/*if successful search*/ && (temp_piece.at(0) == 'K' || temp_piece.at(0) == 'k'))
		{
			if (p_row < 7 && p_column < 7)
			{
				status = take_move(temp_piece, p_row, p_column, (row + 1), (column + 1), board, turn,em_piece,em_flag , dummy);
				if (status)return false;
			}
			if (p_row > 0 && p_column > 0)
			{
				status = take_move(temp_piece, p_row, p_column, (row - 1), (column - 1), board, turn, em_piece, em_flag, dummy);
				if (status)return false;
			}
			if (p_row > 0 && p_column < 7)
			{
				status = take_move(temp_piece, p_row, p_column, (row - 1), (column + 1), board, turn, em_piece, em_flag, dummy);
				if (status)return false;
			}
			if (p_row < 7 && p_column > 0)
			{
				status = take_move(temp_piece, p_row, p_column, (row + 1), (column - 1), board, turn, em_piece, em_flag, dummy);
				if (status)return false;
			}
			if (p_row < 7)
			{
				status = take_move(temp_piece, p_row, p_column, (row + 1), (column), board, turn, em_piece, em_flag, dummy);
				if (status)return false;
			}
			if (p_column < 7)
			{
				status = take_move(temp_piece, p_row, p_column, (row), (column + 1), board, turn, em_piece, em_flag, dummy);
				if (status)return false;
			}
			if (p_column > 0)
			{
				status = take_move(temp_piece, p_row, p_column, (row ), (column - 1), board, turn, em_piece, em_flag, dummy);
				if (status)return false;
			}
			if (p_row > 0)
			{
				status = take_move(temp_piece, p_row, p_column, (row - 1), (column), board, turn, em_piece, em_flag, dummy);
				if (status)return false;
			}
		}

	// search the checking area
		status  = Search_Check_area(temp_board, Checking_piece,rows,columns, turn);
		if (!status) cout << "\nUnable to search the Checking Area.";Sleep(2000);

		// pass pieces to possible move function 
		for (int j = 1;j < 9;j++)
		{
			// Taking pawn
			temp_piece = dum + 'p' + static_cast <char> (j + 48);
			status = search_temp_piece(temp_board, turn, temp_piece, p_row, p_column);
			if (!status)
			{
				continue;
			}
			for (int i = 2; i < 8;i++)
			{
				if (rows[i] == 0 && columns[i] == 0 && rows[i + 1] == 0 && columns[i + 1] == 0)break;
				else if (temp_board[rows[i]][columns[i]] == "k4" || temp_board[rows[i]][columns[i]] == "K4")
				{
					break;
				}
				else
				{
					temp_var_1 = rows[i];
					temp_var_2 = columns[i];
					status = take_move(temp_piece, p_row, p_column, temp_var_1, temp_var_2, temp_board, turn, em_piece, em_flag, dummy);
					if (status)
					{
						temp_board[p_row][p_column] = "  ";
						temp_board[rows[i]][columns[i]] = temp_piece;
						status = Check_temp_piece(temp_board, turn);
						if (status) continue;
						else return false;
					}
					else continue;
				}
			}
			continue;				
		}

		// Taking knight
		dum_1[0] = { "k4" }; dum_1[1] = { "K4" }; dum_1[2] = { "k3" }; dum_1[3] = { "K3" };
        status = Possible_move('k',p_row,p_column,rows,columns,temp_board,turn, em_piece,em_flag,dummy,dum_1);
		if (status)return false;

		//Taking queen
		dum_1[0] = { "q4" }; dum_1[1] = { "Q4" }; dum_1[2] = { "q3" }; dum_1[3] = { "Q3" };
		status = Possible_move( 'q', p_row, p_column,rows,columns, temp_board, turn, em_piece, em_flag, dummy, dum_1);
		if (status)return false;

		// Taking BISHOP
		dum_1[0] = { "b4" }; dum_1[1] = { "B4" }; dum_1[2] = { "b3" }; dum_1[3] = { "B3" };
		status = Possible_move( 'b', p_row, p_column, rows,columns, temp_board, turn, em_piece, em_flag, dummy, dum_1);
		if (status)return false;

		// Taking rook
		dum_1[0] = { "r4" }; dum_1[1] = { "R4" }; dum_1[2] = { "r3" }; dum_1[3] = { "R3" };
		status = Possible_move( 'r', p_row, p_column, rows, columns, temp_board, turn, em_piece, em_flag, dummy, dum_1);
		if (status)return false;
		else 
	     return true;
	}
	else
		return false;

}

bool search_temp_piece(string board[][8], int turn, string &temp_piece, int& p_row, int& p_column) /*Searching the temporary piece*/
{
	if (turn % 2 != 0)
	{
		// Casting the first char of piece
		if (islower(temp_piece.at(0)))
		{
			temp_piece.at(0) = static_cast <char> (((int)(temp_piece.at(0))) - 32);
		}
	    // Finding the position of white's piece 
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (board[i][j] == temp_piece)
				{
					p_row = i;
					p_column = j;
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		if (isupper(temp_piece.at(0))) /*casting if piece is capital*/
		{
			temp_piece.at(0) = static_cast <char> (((int)(temp_piece.at(0))) + 32);
		}
		// Finding the position of black's piece
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if (board[i][j] == temp_piece)
				{
					p_row = i;
					p_column = j;
					return true;
				}
			}
		}
		return false;
	}

}

bool Check_temp_piece( string temp_board[][8],int turn) /*Check check state for the searched pieces*/
{
	int tp_row, tp_column;
	string dummy, temp_piece = "k4";
	bool state = false; 

	 search_temp_piece(temp_board, turn, temp_piece, tp_row, tp_column);
	 state=  King_in_check(temp_board, turn,dummy);
	 return state;
}

bool Search_Check_area(string board[][8], string Checking_piece, int rows[], int columns[],int turn) /*Searching the area of check*/
{
	string king = "k4";

	search_temp_piece(board, turn, king,rows[0],columns[0]);
	SEARCH_PIECE(board, Checking_piece,rows[1],columns[1]);


	//*******************************************//
    // CHECKING DIAGONAL AREA OF CHECKING PIECE  //
	//*******************************************//

	if ((rows[0] != rows[1] && columns[0] != columns[1] && Checking_piece.at(0) != 'k' && Checking_piece.at(0) != 'K') && (Checking_piece.at(0) == 'Q' || Checking_piece.at(0) == 'q' || Checking_piece.at(0) == 'B' || Checking_piece.at(0) == 'b' || Checking_piece.at(0) == 'P' || Checking_piece.at(0) == 'p' ))
	{
		if (rows[0] > rows[1] && columns[0] > columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1] + i][columns[1] + i] == king) return true;
				else
				{
					rows[i + 2] = rows[1] + i;
					columns[i + 2] = columns[1] + i;
				}
			}
		}
		else if (rows[0] < rows[1] && columns[0] < columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1] - i][columns[1] - i] == king) return true;
				else
				{
					rows[i + 2] = rows[1] - i;
					columns[i + 2] = columns[1] - i;
				}
			}
		}
		else if (rows[0] > rows[1] && columns[0] < columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1] + i][columns[1] - i] == king) return true;
				else
				{
					rows[i + 2] = rows[1] + i;
					columns[i + 2] = columns[1] - i;
				}
			}
		}
		else if (rows[0] < rows[1] && columns[0] > columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1] - i][columns[1] + i] == king) return true;
				else
				{
					rows[i + 2] = rows[1] - i;
					columns[i + 2] = columns[1] + i;
				}
			}
		}
		else return false;
	}
	
	//*******************************************//
    // CHECKING PLUS AREA OF CHECKING PIECE      //
    //*******************************************//

	else if ( (rows[0] == rows[1] || columns[0] == columns[1]) && (Checking_piece.at(0) == 'r' || Checking_piece.at(0) == 'R' || Checking_piece.at(0) == 'q' || Checking_piece.at(0) == 'Q'))
	{
		if (rows[0] == rows[1] && columns[0] > columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1]][columns[1] + i] == king) return true;
				else
				{
					rows[i + 2] = rows[1];
					columns[i + 2] = columns[1] + i;
				}
			}
		}
		else if (rows[0] == rows[1] && columns[0] < columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1]][columns[1] - i] == king) return true;
				else
				{
					rows[i + 2] =rows[1];
					columns[i + 2] = columns[1] - i;
				}
			}
		}
		else if (rows[0] > rows[1] && columns[0] == columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1]+i][columns[1]] == king) return true;
				else
				{
					rows[i + 2] =rows[1]+i;
					columns[i + 2] =columns[1];
				}
			}
		}
		else if (rows[0] < rows[1] && columns[0] == columns[1])
		{
			for (int i = 0;i < 8;i++)
			{
				if (board[rows[1]-i][columns[1]] == king) return true;
				else
				{
					rows[i + 2] = rows[1] -i;
					columns[i + 2] =columns[1];
				}
			}
		}
		else return false;
	}
	else return false;
}

bool Possible_move(char piece_1_ch, int p_row, int p_column, int rows[], int columns[], string temp_board[][8], int turn, string& em_piece, bool& em_flag, bool& castling,string dum_1[])
{

	// Check for the passed piece that if it can go on the searched places or not

	string dum = "",board[8][8],temp_piece;
	bool status = false, dummy=false;
	COPY_BOARD(board, temp_board, true);
	// loop to go to all the searched area
	for (int j = 1;j < 9;j++)
	{
		temp_piece = dum + piece_1_ch + static_cast <char> (j + 48);
		status = search_temp_piece(board, turn, temp_piece, p_row, p_column);
	    if (!status)continue;
		else
		{
			for (int i = 2; i < 8;i++)
			{
				if (rows[i] == 0 && columns[i] == 0 && rows[i + 1] == 0 && columns[i + 1] == 0)break;
				else if (board[rows[i]][columns[i]] == "k4" || board[rows[i]][columns[i]] == "K4")
				{
					break;
				}
				status = take_move(temp_piece, p_row, p_column, rows[i], columns[i], board, turn, em_piece, em_flag, dummy);
				if (status)
				{
					board[p_row][p_column] = "  ";
					board[rows[i]][columns[i]] = temp_piece;
					status = Check_temp_piece(board, turn);
					if (status) continue;
					
					else return true;
				}
				else continue;
			}
		}
		continue;
	}
	return false;
}

