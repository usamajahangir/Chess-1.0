                                                         //***************************************************//
                                                         //               CHESS PROJECT (FOP)                 //
                                                         //  --> DEVELPER :: USAMA JAHANGIR                   //
                                                         //  --> DEGREE   :: DE-41-MTS-A                      //
                                                         //  --> CMS ID   :: 295503                           //
                                                         //  --> SUBMISSION DATE :: 05-July-2020              //
                                                         //***************************************************//

//***************************************************//
// -->Used different Libraries and Header file       //
//      ->IOSTREAM (INPUT & OUTPUT)                  //
//      ->STRING   (GAME THEME is based on strings)  //
//      ->FSTREAM  (SAVING AND MOVE TAKE_BACK)       //
//      ->CTYPE    (CHAR HANDLIND)                   //
//      ->WINDOWS  (WINDOWS FUNCTIONS FOR CONSOLE)   //
//***************************************************//

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

using namespace std;


//***************************************************//
// -->Functions Prototypes used in CHESS_MAIN        //
//       --> Void type                               //
//       --> int type                                //
//       --> Boolian type                            //
//  Also one compulsory MAIN FUNCTION of int type    //
//***************************************************//

void FRONT_GRAPHICS();
bool  MAIN_MENU();
int  PAUSE_SCREEN(string[][8], int&, string&, bool&, bool&, string, string[], char&, string&, bool&, bool&, int*, int*);
void CHESS_BOARD_SETUP(string[][8], int&);
void COPY_BOARD(string[][8], string[][8], bool);
void Board_visual(string[][8], char&,string&,bool&);
void DECRYPT_MOVE(string&, char[], int&, int&, string&, string&);
bool SEARCH_PIECE(string[][8], string, int&, int&);
bool SAVE(string[][8], int, string, bool, bool, string[], bool, int*, int*, string);
bool LOAD(string[][8], int&, string&, bool&, bool&, string[], bool&, int*, int*, string&);
bool NEW_GAME();
bool LOAD_GAME();
bool MULTIPLAYER_GAME(string[][8], int&, string[][8], string[], bool, int*, int*,bool);
bool GAME_SETTINGS(char&,string&,bool&);
void SETTING_DISPLAY(string[]);
bool SPECIAL_MODE(string[][8], int&, string[][8], string[], int*, int*,bool);
void SCORE_BOARD(string, int, int*, int*,string);
void ABOUT();
void WIN_SCREEN(string, string, string[], int*, int* , int, string[][8],char);


//**********************************************************//
// --> GAME RUNTIME FUNCTIONS  (TO CHECK MOVE POSIIBILITY)  //
//                 (PROTOTPYES)                             //
//**********************************************************//

bool King_in_check(string[][8], int, string&);
bool King_valid_move(string, int, int, int, int, string[][8], int, bool&);
bool Queen_valid_move(string, int, int, int, int, string[][8]);
bool Rook_valid_move(string, int, int, int, int, string[][8]);
bool Bishop_valid_move(string, int, int, int, int, string[][8]);
bool Knight_valid_move(string, int, int, int, int, string[][8]);
bool Pawn_valid_move(string, int, int, int, int, string[][8], string&, bool&);

bool take_move(string, int, int, int, int, string[][8], int, string&, bool&, bool&);
bool Check_mate(string[][8], int, bool, string, bool, string);
bool STELL_MATE(string [][8], int, string , bool, bool);

//**************************************//
// GLOBAL VARIABLES                     //
//**************************************//
bool status = false;
int score_p1 = 0;
int score_p2 = 0;
char temp= '`';
//**************************************//
// MAIN FUNCTION                        //
//**************************************//

int main()
{
		system("cls");
		// Display welcome screen
		FRONT_GRAPHICS();
		// PROGRAM OUTER MOST LOOP
		// It is ended only from the main menu
	while (true)
	{
		status = MAIN_MENU();
		if (!status)break;
		else continue;
		system("cls");
	}
	cout << "\n\n\n\n\n\n\n\n\n\n";
	return 0;
}

//***************************************************//
// -->  FUNCTION DEFINATIONS                         //
//       ->These are most used function others       //
//         less used or for specific locations are   //
//         defined repectively                       //
//***************************************************//


void FRONT_GRAPHICS()    /*This is the WELCOME screen function to display*/
{
	
	//******************************************************************//
	// --> Using Windows Console control for BackGround and text color  //
	// --> Used (Wide string) to make the text to be printed            //
	// --> Wide string just keeps the indivual strings in contact and   //
	//     to be printed or used using single variable                  //
	//******************************************************************//

		system("cls");
		system("color F4");
		Sleep(50);
		wstring front;
		cout << "\n\n\n\n\n\n\n\n";
		front.append(L"                                                                                     \n");
		front.append(L"	  	               			                                                                           _:_       \n");
		front.append(L"	  	               		                                                                                  '-.-'  \n");
		front.append(L"	                                                                                                         ()      __.'.__              \n");
		front.append(L"	                                                                                                      .-:--:-.  |_______|	         \n");
		front.append(L"                                                                                                       ()      \\____/    \\=====/   \n");
		front.append(L"                                                                                                       /\\      {====}     )___(     \n");
		front.append(L"                                      (\\=,                                                            //\\\\      )__(     /_____\\   \n");
		front.append(L"                      __    |'-'-'|  //  .\\        ________                                          (    )    /____\\     |   |\n");
		front.append(L"                     /  \\   |_____| (( \\_  \\      /                                                   )__(      |  |      |   | \n");
		front.append(L"                     \\__/    |===|   ))  `\\_)    /                     _______  ______   ______      /____\\     |  |      |   |\n");
		front.append(L"                    /____\\   |   |  (/     \\    /           |       | |        |        |             |  |      |  |      |   |\n");
		front.append(L"                     |  |    |   |   | _.-'|   /            |       | |        |        |             |  |      |  |      |   |\n");
		front.append(L"                     |__|    )___(    )___(    \\            |_______| |______  |______  |______      /____\\    /____\\    /_____\\   \n");
		front.append(L"                    (====)  (=====)  (=====)    \\           |       | |               |        |    (======)  (======)  (=======)\n");
		front.append(L"                    }===={  }====={  }====={     \\          |       | |               |        |    }======{  }======{  }======={\n");
		front.append(L"                   (______)(_______)(_______)     \\________ |       | |_______  ______|  ______|   (________)(________)(_________)\n");


		cout << "\t\t\t\t\t\t\t\t\t\t";
		wcout << front;
		cout << "\n\n\t\t\t\t\t\t\t\t  --------- BY ---------";
		cout << "\n\t\t\t\t\t\t\t\t  --- USAMA JAHANGIR ---";
	
	_getch();
}

bool MAIN_MENU() /*TO giv user main options*/
{

	system("cls");
	// LOCAL FUNCTION VARIABLES 
	// Used register variable for faster access
	register int i = 0, op = 0, user_input = 0;
	register string option[3] = { "-->","   ","   " };
	// Uisng wide string to print 
	wstring up;
	up.append(L"  |\\  /|  /\\   0  |\\ |   |\\  /|    \n\t\t\t\t\t\t\t\t");
	up.append(L"  | \\/ | /--\\ _|_ | \\| o | \\/ | enu  \n");

	//MAIN MENU MAIN LOOP
	// Designed in such the way to read arrow keys with two ASCII codes (e.g. 224 80 for down key)
	while (true)
	{
		//*************************//
		//     ARROW Handling      //
		//*************************//

		if (op == 80 /*down arrow*/)
		{
			option[user_input] = "   ";
			if (user_input == 2) user_input -= 3;
			option[user_input + 1] = "-->";
		}

		//*************************//
		//    DISPLAY MENU         //
		//*************************//

		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
		wcout << up;
		cout << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[0] << "     New Game\n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[1] << "     Load Game \n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[2] << "     About \n";
		cout << "\t\t\t\t\t\t\t\t\tESC     QUIT\n";
		
		cout << "\n\n\n\n\n\n";
	    cout << "  \t\t\t\t\t\t\t (use DOWN ARROW to choose and press SPACE BAR to do)";
		cout << "\n\t\t\t\t\t\t\t     (while playing enter move like --> P2B5 etc)";
		//*************************//
		//     USER INPUT          //
		//*************************//

		op = _getch();
		if (op == 224) // if arrow key pressed
		{
			continue;
		}
		else
		{
			for (i = 0;i < 3;i++)
			{
				if (option[i] == "-->")user_input = i;
			}
			if (op == 27)  // if ESC key pressed
			{ 
				return false;
			}
			else if (op == 32) // if space bar pressed
			{
				user_input += 1;
				if (user_input == 1)
				{
					status = NEW_GAME();
					if (!status)
					return false;
					else continue;
				}
				else if (user_input == 2)
				{
					status = LOAD_GAME();
					if (!status)
						continue;
					else return false;
				}
				else if (user_input == 3)
				{
					ABOUT();
					continue;
				}
			}
		}
	}
	return false;
}

bool NEW_GAME()  /*This is the New game menu*/
{
	// LOCAL FUNCTION VARIABLES
	string board[8][8], temp_board[8][8] = { ".." };
	int turn = 1;
	string player_names[2];
	bool special = false;
	bool back = false;
	int* score_1 = &score_p1;
	int* score_2 = &score_p2;
	*score_1 = 0;
	*score_2 = 0;

	register int i = 0, op = 0, user_input = 0;
	register string option[3] = { "-->","   ","   " };
	// New game main loop 
	while (true)
	{
		//*************************//
		//     ARROW Handling      //
		//*************************//

		if (op == 80 /*down arrow*/)
		{
			option[user_input] = "   ";
			if (user_input == 2) user_input -= 3;
			option[user_input + 1] = "-->";
		}

		//*************************//
		// DISPLAY NEW GAME MENU   //
		//*************************//

		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[0] << "     Multiplayer \n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[1] << "     Special Modes \n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[2] << "     Main Menu \n";

		//*************************//
		//     USER INPUT          //
		//*************************//

		op = _getch();
		if (op == 224)
		{
			continue;
		}
		else
		{
			for (i = 0;i < 3;i++)
			{
				if (option[i] == "-->")user_input = i;
			}
			if (op == 27)
			{
				user_input = 27;
				break;
			}
			else if (op == 32)
			{
				user_input += 1;
				break;
			}
			else continue;
		}
	}

	if (user_input == 1)
	{
		cout << "\n\n\n\n\t\t\t\t\t\t\tEnter player 1 (WHITE) : ";
		getline(cin, player_names[0]);
		cout << "\n\t\t\t\t\t\t\tEnter player 2 (BLACK) : ";
		getline(cin, player_names[1]);

		CHESS_BOARD_SETUP(board, turn);
		status = MULTIPLAYER_GAME(board, turn, temp_board, player_names,special,score_1,score_2,false);
		if (!status) return false;
		else return true;
	}
	else if (user_input == 2)
	{

		cout << "\n\n\n\n\t\t\t\t\t\t\tEnter player 1 (WHITE) : ";
		getline(cin, player_names[0]);
		cout << "\n\t\t\t\t\t\t\tEnter player 2 (BLACK) : ";
		getline(cin, player_names[1]);

		CHESS_BOARD_SETUP(board, turn);
		status = SPECIAL_MODE(board,turn, temp_board,player_names,score_1,score_2,false);
		if (!status)return false;
		else return true;
	}
	else if (user_input == 3)
	{
		status = MAIN_MENU();
		if (!status)
			return false;
		else return true;
	}
	else return true;

}

bool LOAD_GAME()  /*This is the LOAD game menu*/
{
	// local function variables
	bool  special = false;
	string board[8][8], temp_board[8][8],player_names[2];
	int turn = 1;
	int* score_1 = &score_p1;
	int* score_2 = &score_p2;

	register int i = 0, op = 0, user_input = 0;
	register string option[3] = { "-->","   ","   " };

	// LOAD game main loop
	while (true)
	{
		//*************************//
		//     ARROW Handling      //
		//*************************//

		if (op == 80 /*down arrow*/)
		{
			option[user_input] = "   ";
			if (user_input == 1) user_input -= 2;
			option[user_input + 1] = "-->";
		}

		//*************************//
		// DISPLAY NEW GAME MENU   //
		//*************************//

		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[0] << "     Multiplayer \n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[1] << "     Special Modes \n";
		cout << "\t\t\t\t\t\t\t\t\tESC     GO BACK \n";

		//*************************//
		//     USER INPUT          //
		//*************************//

		op = _getch();
		if (op == 224)
		{
			continue;
		}
		else
		{
			for (i = 0;i < 3;i++)
			{
				if (option[i] == "-->")user_input = i;
			}
			if (op == 27)
			{
				return false;
			}
			else if (op == 32)
			{
				user_input += 1;
				if (user_input == 1)
				{
					status  = MULTIPLAYER_GAME(board, turn, temp_board, player_names, special, score_1, score_2, true);
					if (!status)
					return false;
				}
				else if (user_input == 2)
				{
					status = SPECIAL_MODE(board, turn, temp_board, player_names, score_1, score_2, true);
					if(!status)
					return false;
				}
				break;
			}
			else continue;
		}
	}
	return false;
}

void CHESS_BOARD_SETUP(string board[][8], int& turn) /*CHESS ARRAY initializing function*/
{
	turn = 1;
	board[0][0] = "r1";
	board[0][1] = "k1";
	board[0][2] = "b1";
	board[0][3] = "q1";
	board[0][4] = "k4";
	board[0][5] = "b2";
	board[0][6] = "k2";
	board[0][7] = "r2";
	board[1][0] = "p1";
	board[1][1] = "p2";
	board[1][2] = "p3";
	board[1][3] = "p4";
	board[1][4] = "p5";
	board[1][5] = "p6";
	board[1][6] = "p7";
	board[1][7] = "p8";


	board[7][0] = "R1";
	board[7][1] = "K1";
	board[7][2] = "B1";
	board[7][3] = "Q1";
	board[7][4] = "K4";
	board[7][5] = "B2";
	board[7][6] = "K2";
	board[7][7] = "R2";
	board[6][0] = "P1";
	board[6][1] = "P2";
	board[6][2] = "P3";
	board[6][3] = "P4";
	board[6][4] = "P5";
	board[6][5] = "P6";
	board[6][6] = "P7";
	board[6][7] = "P8";

	for (int i = 2;i < 6;++i)
	{
		for (int j = 0;j < 8;++j)
		{
			board[i][j] = "  ";
		}
	}
}

void Board_visual(string board[][8], char& design, string& color, bool& original) /*Board printing function depending upon user input else default*/
{
	int check = 0;
       
	// text and background colour cases
		if (original)
		{
			system("color 0F");
			design = '`';
			check = 1;
		}
		if (color == "color f1" && check == 0)
		{
			system("color F1");
		}
		else if (color == "color f2" && check == 0)
		{
			system("color F2");
		}
		else if (color == "color f4" && check == 0)
		{
			system("color F4");
		}
		else if (color == "color f5" && check == 0)
		{
			system("color F5");
		}
		else if (color == "color f8" && check == 0)
		{
			system("color F8");
		}

		// Printing the board with array elements as pieces
		unsigned char a = 219;
		unsigned char c = 32;
		if (design == '/')
		{
			const string WHITE = "©©©©©©©©©";
			const string BLACK = "         ";
			const string BOUNDRY = "#########";
			string whiteRow, blackRow, boundry;

			whiteRow = '#' + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + '#';
			blackRow = '#' + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + '#';
			boundry = BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY;


			cout << "\n\t\t\t\t\t#" << boundry << "#" << endl;
			for (int i = 1;i < 9;++i)
			{
				if (i % 2 != 0)
				{
					for (int j = 0;j < 4;++j)
					{

						if (j == 2)
						{
							cout << "\t\t\t\t      ";
							cout << i << " #    " << board[i - 1][0] << "   ©©  " << board[i - 1][1] << " ©©    " << board[i - 1][2] << "   ©©  "
								<< board[i - 1][3] << " ©©    " << board[i - 1][4] << "   ©©  " << board[i - 1][5] << " ©©    " << board[i - 1][6]
								<< "   ©©  " << board[i - 1][7] << " ©©#" << endl;
						}
						else if (j == 1)
						{
							cout << "\t\t\t\t\t#         ©©     ©©         ©©     ©©         ©©     ©©         ©©     ©©#" << endl;
						}
						else
						{
							cout << "\t\t\t\t\t";
							cout << whiteRow << endl;
						}
					}
				}
				else
				{
					for (int j = 0; j < 4;++j)
					{

						if (j == 2)
						{
							cout << "\t\t\t\t      ";
							cout << i << " #©©  " << board[i - 1][0] << " ©©    " << board[i - 1][1] << "   ©©  " << board[i - 1][2] << " ©©    "
								<< board[i - 1][3] << "   ©©  " << board[i - 1][4] << " ©©    " << board[i - 1][5] << "   ©©  " << board[i - 1][6]
								<< " ©©    " << board[i - 1][7] << "   #" << endl;
						}
						else if (j == 1)
						{
							cout << "\t\t\t\t\t#©©     ©©         ©©     ©©         ©©     ©©         ©©     ©©         #" << endl;
						}
						else
						{
							cout << "\t\t\t\t\t";
							cout << blackRow << endl;
						}
					}
				}

			}
			cout << "\t\t\t\t\t#" << boundry << "#" << endl;
			cout << "\t\t\t\t\t     A        B        C        D         E        F       G        H\n";
		}
		else if (design == '.')
		{
			const string WHITE = ".........";
			const string BLACK = "         ";
			const string BOUNDRY = "#########";
			string whiteRow, blackRow, boundry;

			whiteRow = '#' + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + '#';
			blackRow = '#' + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + WHITE + BLACK + '#';
			boundry = BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY + BOUNDRY;


			cout << "\n\t\t\t\t\t#" << boundry << "#" << endl;
			for (int i = 1;i < 9;++i)
			{
				if (i % 2 != 0)
				{
					for (int j = 0;j < 4;++j)
					{

						if (j == 2)
						{
							cout << "\t\t\t\t      ";
							cout << i << " #    " << board[i - 1][0] << "   ..  " << board[i - 1][1] << " ..    " << board[i - 1][2] << "   ..  "
								<< board[i - 1][3] << " ..    " << board[i - 1][4] << "   ..  " << board[i - 1][5] << " ..    " << board[i - 1][6]
								<< "   ..  " << board[i - 1][7] << " ..#" << endl;
						}
						else if (j == 1)
						{
							cout << "\t\t\t\t\t#         ..     ..         ..     ..         ..     ..         ..     ..#" << endl;
						}
						else
						{
							cout << "\t\t\t\t\t";
							cout << whiteRow << endl;
						}
					}
				}
				else
				{
					for (int j = 0; j < 4;++j)
					{

						if (j == 2)
						{
							cout << "\t\t\t\t      ";
							cout << i << " #..  " << board[i - 1][0] << " ..    " << board[i - 1][1] << "   ..  " << board[i - 1][2] << " ..    "
								<< board[i - 1][3] << "   ..  " << board[i - 1][4] << " ..    " << board[i - 1][5] << "   ..  " << board[i - 1][6]
								<< " ..    " << board[i - 1][7] << "   #" << endl;
						}
						else if (j == 1)
						{
							cout << "\t\t\t\t\t#..     ..         ..     ..         ..     ..         ..     ..         #" << endl;
						}
						else
						{
							cout << "\t\t\t\t\t";
							cout << blackRow << endl;
						}
					}
				}

			}
			cout << "\t\t\t\t\t#" << boundry << "#" << endl;
			cout << "\t\t\t\t\t     A        B        C        D         E        F       G        H\n";
		}
		else if (design == '`')
		{
			string b = "";
			string WB_LINE = b + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a;
			string BB_LINE = b + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c;
			string line1 = char(a) + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + char(a);
			string line2 = char(a) + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + char(a);
			string Blank = WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + (char)a + (char)a;

			int r = 0, d = 0;
			cout << "\t\t\t\t\t\t" << Blank << endl;
			for (int i = 0;i < 4;++i)
			{

				for (int j = 0;j < 3;++j)
				{
					cout << "\t\t\t\t\t\t" << line1 << endl;
					if (j == 1)
					{
						cout << "\t\t\t\t\t     " << r + 1 << "  " << char(a) + b << (b + (char)a + (char)a + (char)a) << board[r][d + 0] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 1] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 2] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 3] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 4] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 5] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 6] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 7] << (b + (char)c + (char)c + (char)c) << char(a) + b << endl;
					}
				}
				d = 0;
				++r;
				for (int k = 0;k < 3;++k)
				{
					cout << "\t\t\t\t\t\t" << line2 << endl;
					if (k == 1)
					{
						cout << "\t\t\t\t\t     " << r + 1 << "  " << char(a) + b << (b + (char)c + (char)c + (char)c) << board[r][d + 0] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 1] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 2] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 3] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 4] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 5] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 6] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 7] << (b + (char)a + (char)a + (char)a) << char(a) + b << endl;
					}
				}
				d = 0;
				++r;
			}
			cout << "\t\t\t\t\t\t" << Blank << endl;
			cout << "\n\t\t\t\t\t\t   A\t   B\t   C\t   D\t   E\t   F\t   G\t   H\n";
		}
		else {
		_getch();
             }
	
}

bool MULTIPLAYER_GAME(string board[][8], int& turn, string temp_board[][8], string player_names[], bool special, int* score_1, int* score_2,bool loading)  /*This is the main FUCTION of the game play*/
{
	// Function local variables
	string Checking_piece = "", killed_piece = "", check_s = "";
	string user_move = { "" }, piece = { "" }, dummy = { "" }, dum_piece = { "" }, em_piece = { ".." };
	string type, color = "color 0f";
	char user_move_data[10] = { '0' }, design = '`', pro_ch ;
	int row = 0, column = 0, po_row = 0, po_column = 0, user_input = 1, check_state = 1, k_row = 0, k_column = 0, go_1 = 0, go_2 = 0,steel = 0;
	bool move_is_valid = false, check_piece = false, king_check = false, clear_flag = true, em_flag = false, castling = false, done = true, Which_b = false, undo = false, check_mate = false,stell_mate =false;
	int dum1 = 5, dum2 = 5, undo_state = 1, get_ch = 0, deg = 0;
	bool state = false, original = true;
	if (loading) /*In case user ask for the loaded game*/
		{
			string game_required = "load_multiplayer";
			LOAD(board, turn, em_piece, em_flag, castling, player_names, king_check, score_1, score_2, game_required);
		}

	// The MAIN GAME LOOP (GAME PLAY)
	while (true)
	{
		if (turn > 2 && ((go_1 < 2 || go_2 == 0) && type == "special"))
		{
			SCORE_BOARD(killed_piece, turn, score_1, score_2, check_s);

			killed_piece = "  ";
			check_s = "  ";
			go_2 = 0;
		}
		system("cls");
		if (special)
		{
			cout << "\t\t\t\t\t\t\t\t\tPOWER & TERROR MODE";
			type = "special";
		}
		else
		{
			type = "multi";
			cout << "\t\t\t\t\t\t\t\t\tSTANDERED MODE";
		}
		cout << "\n(ESC)PAUSE GAME \t\t\t\t\t  (Upper case --> White) & (Lower case --> Black)\n";
		if (special)cout << player_names[0] << "'s SCORES : " << *score_1 << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << player_names[1] << "'s SCORES : " << *score_2 << endl;
		else cout << endl;

		Board_visual(board, design, color, original);

		// check king
		if (turn > 2)
		{/*
			if (turn % 2 == 0)
				dum_piece = "k4";

			else if (turn % 2 != 0)
				dum_piece = "K4";*/
			if (!king_check)
			{
				COPY_BOARD(board, temp_board, false);
			}
			SEARCH_PIECE(temp_board, dum_piece, k_row, k_column);
			//  Case if king is already in a check state
			king_check = King_in_check(temp_board, turn, Checking_piece);
			if (!king_check)
			{
				COPY_BOARD(board, temp_board, false);
			}
			if (king_check)
			{
				check_mate = Check_mate(board, turn, king_check, em_piece, em_flag, Checking_piece);
				if (check_mate)
				{
					check_s = "check_mate";
					stell_mate = false;
					break;
				}
				else if (go_1 == 0) check_s = "check";
				clear_flag = false;
				if (turn > 2 && ((go_1 < 2 || go_2 == 0) && type == "special"))
				{
					SCORE_BOARD(killed_piece, turn, score_1, score_2, check_s);
					system("cls");
					if (special)
					{
						cout << "\t\t\t\t\t\t\t\t\tPOWER & TERROR MODE";
						type = "special";
					}
					else
					{
						type = "multi";
						cout << "\t\t\t\t\t\t\t\t\tSTANDERED MODE";
					}
					cout << "\n(ESC)PAUSE GAME \t\t\t\t\t  (Upper case --> White) & (Lower case --> Black)\n";
					if (special)cout << player_names[0] << "'s SCORES : " << *score_1 << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << player_names[1] << "'s SCORES : " << *score_2 << endl;
					else cout << endl;

					Board_visual(board, design, color, original);

					killed_piece = "..";
					check_s = "..";
					go_2 = 0;
					++go_1;
				}
				cout << "\nCHECK! ";
				++check_state;
			}
			else
			{
				go_1 = 0;
				clear_flag = true;
				if (check_state > 1)
				{
					COPY_BOARD(board, temp_board, true);
					check_state = 0;
					goto take_move;
				}
			}
		}

		if (steel > 2)
		{
			status =STELL_MATE(board, turn, em_piece, em_flag, castling);
			if (status)
			{
				check_s = "stell_mate";
			 stell_mate = true;
				break;
			}

		}

		if (turn % 2 != 0)
		{
			cout << endl << player_names[0] << "'s turn (WHITE)";
			cout << "\nEnter your move (space,Piece,column,row) : ";
			get_ch = _getch();
			if (get_ch == 27)
			{
				deg = PAUSE_SCREEN(board, turn, em_piece, em_flag, castling,type, player_names, design, color, original,king_check, score_1, score_2);
				if (deg == 5)
				{
					Board_visual(board, design, color, original);
					continue;
				}
				else if (deg == 99)
				{
					return false;
				}
			}
			else
			{
				cin >> user_move;
			}
		}
		else if (turn % 2 == 0)
		{
			cout << endl << player_names[1] << "'s turn (BLACK)";
			cout << "\nEnter your move (space,Piece,column,row) : ";
			get_ch = _getch();
			if (get_ch == 27)
			{
				deg = PAUSE_SCREEN(board, turn, em_piece, em_flag, castling, type, player_names, design, color, original,king_check,score_1,score_2);
				if (deg == 5)
				{
					Board_visual(board, design, color, original);
					continue;
				}
				else if (deg == 99)
				{
					return false;
				}
			}
			else
			{
				cin >> user_move;
			}
		}

		DECRYPT_MOVE(user_move, user_move_data, column, row, dummy, piece);

		// Checking the player turns either black or white
		if ((islower(user_move_data[0]) && (turn % 2 == 0)) || (isupper(user_move_data[0]) && (turn % 2 != 0)))
		{
		}
		else continue;

		// Making the boundary of the chess board and maintaining restriction to cross that
		if (row > 7 || row < 0 || column > 7 || column < 0) continue;

		check_piece = SEARCH_PIECE(board, piece, po_row, po_column);

		// Check if piece is present or not 
		if (check_piece == false) continue;

		move_is_valid = take_move(piece, po_row, po_column, row, column, board, turn, em_piece, em_flag, castling);
	take_move:
		{
			if (clear_flag)
			{
				
				if (move_is_valid)
				{
					go_2 = 0;
					// PAWN PROMOTION 
					if (((piece.at(0) == 'p') && (row == 7)) || ((piece.at(0) == 'P') && (row == 0)))
					{
						board[po_row][po_column] = "  ";
						killed_piece = board[row][column];
						while (true)
						{
							dummy = { "" };
							cout << "\nPawn promotion (press): (Q)ueen , (R)ook , (K)night , (B)ishop";
							pro_ch = _getch();
							if (pro_ch == 'Q')
							{
								if (turn % 2 != 0)
								{
									board[row][column] = dummy + 'Q' + static_cast <char> (dum1 + 48);
									dum1++;
									++turn;
									break;
								}
								else
								{
									board[row][column] = dummy + 'q' + static_cast <char> (dum2 + 48);
									dum2++;
									++turn;
									break;
								}
							}
							if (pro_ch == 'R')
							{
								if (turn % 2 != 0)
								{
									board[row][column] = dummy + 'R' + (char)(dum1 + 48);
									dum1++;
									++turn;
									break;
								}
								else
								{
									board[row][column] = dummy + 'r' + (char)(dum2 + 48);
									dum2++;
									++turn;
									break;
								}
							}
							if (pro_ch == 'K')
							{
								if (turn % 2 != 0)
								{
									board[row][column] = dummy + 'K' + (char)(dum1 + 48);
									dum1++;
									++turn;
									break;
								}
								else
								{
									board[row][column] = dummy + 'k' + (char)(dum2 + 48);
									dum2++;
									++turn;
									break;
								}
							}
							if (pro_ch == 'B')
							{
								if (turn % 2 != 0)
								{
									board[row][column] = dummy + 'B' + (char)(dum1 + 48);
									dum1++;
									++turn;
									break;
								}
								else
								{
									board[row][column] = dummy + 'b' + (char)(dum2 + 48);
									dum2++;
									++turn;
									break;
								}
							}
						}
					}
					// EM-PASSENT MOVE
					else if (((piece.at(0) == 'p' && board[row - 1][column] == em_piece) || (piece.at(0) == 'P' && board[row + 1][column] == em_piece)) && em_flag == true)
					{
						killed_piece = em_piece;
						board[row][column] = piece;
						board[po_row][po_column] = "  ";
						if (turn % 2 != 0)
							board[row + 1][column] = "  ";
						if (turn % 2 == 0)
							board[row - 1][column] = "  ";

						cout << "Nice move.\n";
						++turn;
						em_flag = false;
					}
					// CASTLING MOVE
					else if ((piece == "k4" || piece == "K4") && (castling))
					{
						board[row][column] = piece;
						board[po_row][po_column] = "  ";
						if (row == 0 && column == 6 && board[row][column + 1].at(0) == 'r')
						{

							piece = board[row][column + 1];
							board[row][column + 1] = "  ";
							board[row][column - 1] = piece;
						}
						else if (row == 0 && column == 1 && board[row][column - 1].at(0) == 'r')
						{
							piece = board[row][column - 1];
							board[row][column - 1] = "  ";
							board[row][column + 1] = piece;
						}
						else if (row == 7 && column == 1 && board[row][column - 1].at(0) == 'R')
						{
							piece = board[row][column - 1];
							board[row][column - 1] = "  ";
							board[row][column + 1] = piece;
						}
						else if (row == 7 && column == 6 && board[row][column + 1].at(0) == 'R')
						{
							piece = board[row][column + 1];
							board[row][column + 1] = "  ";
							board[row][column - 1] = piece;
						}
						cout << "\nNice move.\n\n";
						castling = false;
						++turn;
					}
					// NORMAL MOVE
					else
					{
						killed_piece = board[row][column];
						board[row][column] = piece;
						board[po_row][po_column] = "  ";
						cout << "Nice move.\n";
						++turn;
					}
					undo = false;
					//UNDO_MOVE( board,undo_board, temp_b1,temp_w1,turn,undo);
					undo = true;
				}
				else
				{
				    ++steel;
					cout << "Invalid move.\n";
					_getch();
				}
			}
		}

		    if (!clear_flag)
			{
				++go_1;
				if (move_is_valid)
				{
					temp_board[row][column] = piece;
					temp_board[po_row][po_column] = "..";
				}
				else
				{
					cout << "Invalid move.\n";
					_getch();
				}
			}

			else continue;
		
	}

	// In case of special mode return result to score board
	if (special)
	{
		if (check_s == "check_mate" || check_s == "stell_mate")
		{
			temp = design;
			SCORE_BOARD(killed_piece, turn, score_1, score_2, check_s);
			return true;
		}
	}

	// In case of of check mate 
	else if (!stell_mate)
	{
		if (turn % 2 == 0)
		{
			WIN_SCREEN("check_mate_2", "multi", player_names, score_1, score_2, turn, board,design);
		}
		if (turn % 2 != 0)
		{
			WIN_SCREEN("check_mate_1", "multi", player_names, score_1, score_2, turn, board,design);
		}
	}
	// in case of steel mate the draw case
	else 
	{
		WIN_SCREEN("steel_mate", "multi", player_names, score_1, score_2, turn, board,design);
	}
	return true;

	// Return the value to new game function in case called from that
	// Return the value to Load game function in case called from that
	// Return the value to the SPECIAL MODE in case call from there
}

bool SPECIAL_MODE(string board[][8], int& turn, string temp_board[][8], string player_names[], int* score_1, int* score_2,bool loading)/*New special mode designed by myself based on scores*/
{
	// local variables
	bool Special = true , game_ended =false,em_flag,castling,king_check;
	string em_piece;
	*score_1 = 0;
	*score_2 = 0;
	// In case specail mode is loaded update the variables
	if (loading)
	{
		string game_required = "load_special_mode";
		LOAD(board, turn, em_piece, em_flag, castling, player_names, king_check, score_1, score_2, game_required);
	}
	// Get result from multiplayer game 
	game_ended = MULTIPLAYER_GAME(board, turn, temp_board, player_names, Special, score_1, score_2,false);

	// Show the win screen 
	if (game_ended)
	{
		WIN_SCREEN("special", "special", player_names, score_1, score_2, turn, board,temp);
		return true;
	}
	else return false;

	return false;
}

void SCORE_BOARD(string killed_piece, int turn, int* score_1, int* score_2, string check_s) /*Score calculater for special mode game*/
{
	int dum_score = 0;
	int check_s_score = 0;

	// ALL these cases are based on the international chess laws for pieces strategic importance

	if ((killed_piece.at(0) == 'p' && turn % 2 ==0 )|| (killed_piece.at(0) == 'P' && turn % 2 != 0))
	{
		dum_score += 1;
	}
	else if (((killed_piece.at(0) == 'k' && turn % 2 == 0) || (killed_piece.at(0) == 'K' && turn % 2 != 0)) && ((killed_piece != "k4" || killed_piece != "K4")))
	{
		dum_score += 3;
	}
	else if ((killed_piece.at(0) == 'b' && turn % 2 == 0) || (killed_piece.at(0) == 'B' && turn % 2 != 0))
	{
		dum_score += 3;
	}
	else if ((killed_piece.at(0) == 'r' && turn % 2 == 0) || (killed_piece.at(0) == 'R' && turn % 2 != 0))
	{
		dum_score += 5;
	}
	else if ((killed_piece.at(0) == 'q' && turn % 2 == 0) || (killed_piece.at(0) == 'Q' && turn % 2 != 0))
	{
		dum_score += 9;
	}
	if (check_s == "check_mate" || check_s == "CHECK_MATE")
	{
		check_s_score += 20;
	}
	else if (check_s == "check" || check_s == "CHECK")
	{
		check_s_score += 15;
	}
	
	// Update the new score to the score pointers
	if (turn % 2 == 0)
	{
		*score_1 = *score_1 + dum_score + check_s_score;
	}
	else
	{
		*score_2 = *score_2 + dum_score + check_s_score;
	}

}

void DECRYPT_MOVE(string& user_move, char user_move_data[], int& column, int& row, string& dummy, string& piece) /*Player move is decoded here*/
{
	// Seperating data from string (user_move)
	for (unsigned int i = 0;i < user_move.length();++i)
	{
		user_move_data[i] = user_move.at(i);
	}

	// Casting from column alphabet to int form.
	column = static_cast <int>(user_move_data[2]) - 65;
	row = ((static_cast <int>(user_move_data[3]) - 48)) - 1;

	// Getting compelete name of piece 
// add dummy string to get compelete as string otherwise they are added as integers

	piece = dummy + static_cast<char> (user_move_data[0]) + static_cast<char> (user_move_data[1]);

}

bool SEARCH_PIECE(string board[][8], string piece, int& po_row, int& po_column) /*Searching piece on the board and return its position coordinates*/
{
	// Finding current position of piece
	for (int i = 0;i < 8;++i)
	{
		for (int j = 0;j < 8;++j)
		{
			if (board[i][j] == piece)
			{
				po_row = i;
				po_column = j;
				return true;
			}
		}
	}
	return false;
}

bool take_move(string piece, int po_row, int po_column, int row, int column, string board[][8], int turn, string& em_piece, bool& em_flag, bool& castling)  /*Function to join all other piece functions to take move*/
{
	bool check_queen = false, check_king = false, check_pawn = false, check_knight = false, check_rook = false, check_bishop = false, king_in_check = false;
	string temp_board[8][8];
	// Copy board for check passing
	COPY_BOARD(board, temp_board, false);

	check_queen = Queen_valid_move(piece, po_row, po_column, row, column, board);
	check_king = King_valid_move(piece, po_row, po_column, row, column, board, turn, castling);
	check_bishop = Bishop_valid_move(piece, po_row, po_column, row, column, board);
	check_rook = Rook_valid_move(piece, po_row, po_column, row, column, board);
	check_knight = Knight_valid_move(piece, po_row, po_column, row, column, board);
	check_pawn = Pawn_valid_move(piece, po_row, po_column, row, column, board, em_piece, em_flag);

	// if any piece allow the move or not
	if ((check_queen == true || check_king == true || check_pawn == true || check_knight == true || check_rook == true || check_bishop == true))
	{
		// first check that if move is taken king is in check or not
		int temp_row = 0, temp_column = 0;
		string dum;
		temp_board[row][column] = piece;
		temp_board[po_row][po_column] = "  ";
		status = King_in_check(temp_board,turn,dum);
		if (status)
			return false;
		else 
		return true;
	}
	else  return false;

}

int PAUSE_SCREEN(string board[][8], int& turn, string& em_piece, bool& em_flag, bool& castling, string game, string p_names[],char& design,string& color,bool& original,bool& k_check,int* score_1,int* score_2)
{
	// This is the game pause screen
	//*********************************************//
	// --> It is made using the design of board    //
	//     just cutting it and added pause menu    //
	//********************************************//
	string game_required;
	bool back = false;
	register int i = 0, op = 0, user_input = 0;
	register string option[4] = { "-->","   ","   ","   " };
	// POPPING pause screen is only for the traditional board
	if (design == '`')
	{
	unsigned char a = 219;
	unsigned char c = 32;
		string b = "";
		string WB_LINE = b + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a;
		string BB_LINE = b + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c;
		string line1 = (char)a + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + (char)a;
		string line2 = (char)a + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + (char)a;
		string half_line1 = WB_LINE + BB_LINE;
		string half_line2 = BB_LINE + WB_LINE;
		string empty = b + (char)a + "                              " + (char)a;
		string Blank = WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + (char)a + (char)a;

		while (true)
		{
			int r = 0, d = 0;
			//*************************//
			//     ARROW Handling      //
			//*************************//

			if (op == 80 /*down arrow*/)
			{
				option[user_input] = "   ";
				if (user_input == 3) user_input -= 4;
				option[user_input + 1] = "-->";
			}

			//*******************************************//
			// DISPLAY PAUSE SCREEN                      //
			// --> Altered the game Display and added    //
			//     pause screen things to make like      //
			//     a popping window and giving           //
			//     (-- PAUSE ILLUSION --)                //
			//*******************************************//

			system("cls");
			if (game == "special")
			{
				cout << "\t\t\t\t\t\t\t\t\tPOWER & TERROR MODE";
			}
			else
			{
				cout << "\t\t\t\t\t\t\t\t\tSTANDERED MODE";
			}
			cout << "\n(ESC)PAUSE GAME \t\t\t\t\t  (Upper case --> White) & (Lower case --> Black)\n";
			if (game == "special")cout << p_names[0] << "'s SCORES : " << *score_1 << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << p_names[1] << "'s SCORES : " << *score_2 << endl;
			else cout << endl;
			cout << "\t\t\t\t\t\t" << Blank << endl;
			for (int i = 0;i < 4;++i)
			{
				for (int j = 0;j < 3;++j)
				{
					if (i == 1)
					{
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "\\                              /" << half_line1 << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << " \\                            / " << half_line1 << b + (char)a << endl;
						cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)a + (char)a + (char)a) << board[r][d + 0] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 1] << (b + (char)c + (char)c + (char)c)
							<< "  " << WB_LINE + WB_LINE + WB_LINE + (char)a + (char)a + (char)a + (char)a << "  "
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 6] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 7] << (b + (char)c + (char)c + (char)c) << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << (char)a << "        GAME PAUSED       " << (char)a << "  " << half_line1 << b + (char)a << endl;
						break;
					}
					if (i == 2)
					{
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << b + (char)a << "   " << option[2] << "  LOAD GAME" << "         " << b + (char)a << "  " << half_line1 << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << b + (char)a << "   " << option[3] << "  SETTINGS " << "         " << b + (char)a << "  " << half_line1 << b + (char)a << endl;
						cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)a + (char)a + (char)a) << board[r][d + 0] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 1] << (b + (char)c + (char)c + (char)c)
							<< "  " << b + (char)a << "   ESC  RESUME GAME" << "       " << b + (char)a << "  "
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 6] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 7] << (b + (char)c + (char)c + (char)c) << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << b + (char)a << "                          " << b + (char)a << "  " << half_line1 << b + (char)a << endl;
						break;
					}
					cout << "\t\t\t\t\t\t" << line1 << endl;
					if (j == 1)
					{
						cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)a + (char)a + (char)a) << board[r][d + 0] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 1] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 2] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 3] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 4] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 5] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 6] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 7] << (b + (char)c + (char)c + (char)c) << b + (char)a << endl;
					}
				}
				d = 0;
				++r;
				for (int k = 0;k < 3;++k)
				{
					if (i == 1)
					{
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << "                          " << b + (char)a << "  " << half_line2 << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << "                          " << b + (char)a << "  " << half_line2 << b + (char)a << endl;
						cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)c + (char)c + (char)c) << board[r][d + 0] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 1] << (b + (char)a + (char)a + (char)a)
							<< "  " << b + (char)a << "   " << option[0] << "  MAIN MENU" << "         " << b + (char)a << "  "
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 6] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 7] << (b + (char)a + (char)a + (char)a) << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << "   " << option[1] << "  SAVE GAME" << "         " << (char)a << "  " << half_line2 << b + (char)a << endl;
						break;
					}
					if (i == 2)
					{
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << "                          " << b + (char)a << "  " << half_line2 << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << WB_LINE + WB_LINE + WB_LINE + (char)a + (char)a + (char)a + (char)a << "  " << half_line2 << b + (char)a << endl;
						cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)c + (char)c + (char)c) << board[r][d + 0] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 1] << (b + (char)a + (char)a + (char)a)
							<< " /                            \\ "
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 6] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 7] << (b + (char)a + (char)a + (char)a) << b + (char)a << endl;
						cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "/                              \\" << half_line2 << b + (char)a << endl;
						break;
					}
					cout << "\t\t\t\t\t\t" << line2 << endl;
					if (k == 1)
					{
						cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)c + (char)c + (char)c) << board[r][d + 0] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 1] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 2] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 3] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 4] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 5] << (b + (char)a + (char)a + (char)a)
							<< (b + (char)c + (char)c + (char)c) << board[r][d + 6] << (b + (char)c + (char)c + (char)c)
							<< (b + (char)a + (char)a + (char)a) << board[r][d + 7] << (b + (char)a + (char)a + (char)a) << b + (char)a << endl;
					}
				}
				d = 0;
				++r;
			}
			cout << "\t\t\t\t\t\t" << Blank << endl;
			cout << "\n\t\t\t\t\t\t   A\t   B\t   C\t   D\t   E\t   F\t   G\t   H\n";

			if (turn % 2 == 0)
			{
				cout << endl <<p_names[1] << "'s turn (BLACK)";
			}
			else
			{
				cout << endl << p_names[0] << "'s turn (WHITE)";
			}
			cout << "\nEnter your move (space,Piece,column,row) : ";

			//*************************//
			//     USER INPUT          //
			//*************************//

			op = _getch();
			if (op == 224)
			{
				continue;
			}
			else
			{
				for (i = 0;i < 4;i++)
				{
					if (option[i] == "-->")user_input = i;
				}

				if (op == 27)
				{
					return 0;
				}

				else if (op == 32)
				{
					if (user_input + 1 == 1)
					{
						status = MAIN_MENU();
						if (!status)
							return 99;
						else 
						return 1;
					}
					else if (user_input + 1 == 2)
					{
						if (game == "multi")
						{
							SAVE(board, turn, em_piece, em_flag, castling, p_names, k_check, score_1, score_2,"save_multiplayer");
						}
						else if (game == "special")
						{
							SAVE(board, turn, em_piece, em_flag, castling, p_names, k_check, score_1, score_2,"save_special_mode");
						}
						continue;
					}
					else if (user_input + 1 == 3)
					{
						status  = LOAD_GAME();
						continue;
					}
					else if (user_input + 1 == 4)
					{
						status = GAME_SETTINGS(design, color, original);
						if (status)return 5;
						else
							return 3;
					}
					else continue;
				}
			}
		}
	}
	// for other two boards the design is basic
	else
	{
	while (true)
	{
		//*************************//
		//     ARROW Handling      //
		//*************************//

		if (op == 80 /*down arrow*/)
		{
			option[user_input] = "   ";
			if (user_input == 3) user_input -= 4;
			option[user_input + 1] = "-->";
		}

		//*************************//
		//    DISPLAY MENU         //
		//*************************//

		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
		cout << "\tGAME PAUSED";
		cout << "\n\n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[0] << "     MAIN MENU\n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[1] << "     SAVE GAME \n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[2] << "     LOAD GAME \n";
		cout << "\t\t\t\t\t\t\t\t\t" << option[3] << "     SETTINGS \n";
		cout << "\t\t\t\t\t\t\t\t\tESC     RESUME\n";
		cout << "\t\t\t\t\t\t\t\t\t";

		//*************************//
		//     USER INPUT          //
		//*************************//

		op = _getch();
		if (op == 224)
		{
			continue;
		}
		else
		{
			for (i = 0;i < 4;i++)
			{
				if (option[i] == "-->")user_input = i;
			}

			if (op == 27)
			{
				return 0;
			}

			else if (op == 32)
			{
				if (user_input + 1 == 1)
				{
					status = MAIN_MENU();
					if (!status)
						return 99;
					else
						return 1;
				}
				else if (user_input + 1 == 2)
				{
					if (game == "mutli")
					{
						SAVE(board, turn, em_piece, em_flag, castling, p_names, k_check, &score_p1, &score_p2, "save_multiplayer");
					}
					else if (game == "special")
					{
						SAVE(board, turn, em_piece, em_flag, castling, p_names, k_check, &score_p1, &score_p2, "save_special_mode");
					}
					continue;
				}
				else if (user_input + 1 == 3)
				{
					status = LOAD_GAME();
					continue;
				}
				else if (user_input + 1 == 4)
				{
					status = GAME_SETTINGS(design, color, original);
					if (status)return 5;
					else
						return 3;
				}
				else continue;
			}
		}
	}
    }
}

void COPY_BOARD(string board[][8], string Take_back_board[][8], bool Which_b) /*Coping function as board needed to be copied at many placec in the program*/
{
	if (Which_b) /*From 2nd to 1st board*/
	{
		for (int i = 0; i < 8;++i)
		{
			for (int j = 0; j < 8;++j)
			{
				board[i][j] = Take_back_board[i][j];
			}
		}
	}
	else /*From 2nd to 1st board*/
	{
		for (int i = 0; i < 8;++i)
		{
			for (int j = 0; j < 8;++j)
			{
				Take_back_board[i][j] = board[i][j];
			}
		}
	}

}

bool SAVE(string board[][8], int turn, string em_piece, bool em_flag, bool castling, string p_names[],bool king_check,int* score_1,int* score_2,string game_type)
{

	// This is saving function
	string save_file_name;
	// Saving multiplayer game
	if (game_type == "save_multiplayer")
	{
		ofstream saved_game("MULTI_PLAYER_SAVE.png");
		if (saved_game.is_open())
		{
			saved_game << endl << endl;
			for (int i = 0;i < 8;i++)
			{
				for (int j = 0;j < 8;j++)
				{
					saved_game << board[i][j] << endl;
				}
			}
			saved_game << turn << endl;
			saved_game << em_piece << endl;
			saved_game << em_flag << endl;
			saved_game << castling << endl;
			saved_game << king_check << endl;
			saved_game << p_names[0] << endl;
			saved_game << p_names[1] << endl;

			saved_game.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	// Saving Special mode game
	else if (game_type == "save_special_mode")
	{
		ofstream saved_game("SPECIAL_MODE_SAVE.png");
		if (saved_game.is_open())
		{
			saved_game << endl;
			for (int i = 0;i < 8;i++)
			{
				for (int j = 0;j < 8;j++)
				{
					saved_game << board[i][j] << endl;
				}
			}
			saved_game << turn << endl;
			saved_game << em_piece << endl;
			saved_game << em_flag << endl;
			saved_game << castling << endl;
			saved_game << *score_1 << endl;
			saved_game << *score_2 << endl;
			saved_game << p_names[0] << endl;
			saved_game << p_names[1] << endl;

			saved_game.close();
			return true;
		}
		else
		{
			return false;
		}
	}
	else return false;
}

bool LOAD(string board[][8], int& turn, string& em_piece, bool& em_flag, bool& castling, string p_names[],bool& king_check,int* score_1,int* score_2,string& game_required)
{
	// LOADING function to load an old game
	string dum;
	// loading the multiplayer game
    if ( game_required == "load_multiplayer")
	{
		ifstream saved_game("MULTI_PLAYER_SAVE.png");
		if (saved_game.is_open())
		{	
			while (saved_game.good())
			{
				getline(saved_game, dum);
				getline(saved_game, dum);
				for (int i = 0;i < 8;i++)
				{
					for (int j = 0;j < 8;j++)
					{
						getline(saved_game, board[i][j]);
					}
				}
				saved_game >> turn;
				saved_game >> em_piece;
				saved_game >> em_flag;
				saved_game >> castling;
				saved_game >> king_check;
				saved_game >> p_names[0];
				saved_game >> p_names[1];

				saved_game.close();
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	// loading the Special mode game
	else if ( game_required == "load_special_mode")
	{
		ifstream saved_game("SPECIAL_MODE_SAVE.png");
		if (saved_game.is_open())
		{	
	    	while (saved_game.good())
			{
				getline(saved_game, dum);
				for (int i = 0;i < 8;i++)
				{
					for (int j = 0;j < 8;j++)
					{
						getline(saved_game, board[i][j]);
					}
				}
				saved_game >> turn;
				saved_game >> em_piece;
				saved_game >> em_flag;
				saved_game >> castling;
				saved_game >> *score_1;
				saved_game >> *score_2;
				saved_game >> p_names[0];
				saved_game >> p_names[1];

				saved_game.close();
			}

			return true;
		}
		else
		{
			return false;
		}
	}
	else return false;

}

bool GAME_SETTINGS(char& design,string& color,bool& original)  /*Game setting unable to choose different design and colour combinations*/
{
	register int i = 0, op = 0, user_input = 0;
	register string option[8] = { "-->","   ","   " ,"-->","   ","   " ,"   " ,"   "};
	bool good;
	// Loop for settings
	while (true)
	{
		SETTING_DISPLAY(option);
		//*************************//
		//     USER INPUT          //
		//*************************//

		op = _getch();
		if (op == 27)
		{
			return true;
		}
	    else if (op == 49)
		{
			while (true)
			{
				if (op == 80 /*down arrow*/)
				{
					option[user_input] = "   ";
					if (user_input == 2) user_input -= 3;
					option[user_input + 1] = "-->";
				}

				SETTING_DISPLAY(option);

				op = _getch();
				if (op == 224)
				{
					continue;
				}
				for (i = 0;i < 3;i++)
				{
					if (option[i] == "-->")user_input = i;
				}
				if (op == 32)
				{
					user_input += 1;
					if (user_input == 1)
					{
						design = '.';
						original = false;
						break;
					}
					else if (user_input == 2)
					{
						design = '/';
						original = false;
						break;
					}
					else if (user_input == 3)
					{
						design = '`';
						original = false;
						break;
					}
					else continue;
				}
			}
			good = true;
			continue;
		}
		else if (op == 50)
		{
			while (true)
			{
				if (op == 80 /*down arrow*/)
				{
					option[user_input] = "   ";
					if (user_input == 7) user_input -= 5;
					option[user_input + 1] = "-->";
				}

				SETTING_DISPLAY(option);

				//*************************//
				//     USER INPUT          //
				//*************************//

				op = _getch();
				if (op == 224)
				{
					continue;
				}
				for (i = 3;i < 8;i++)
				{
					if (option[i] == "-->")user_input = i;
				}
				if (op == 32)
				{
					user_input += 1;
					if (user_input == 4)
					{
						color = "color f1";
						original = false;
						break;
					}
					else if (user_input == 5)
					{
						color = "color f4";
						original = false;
						break;
					}
					else if (user_input == 6)
					{
						color = "color f5";
						original = false;
						break;
					}
					else if (user_input == 7)
					{
						color = "color f2";
						original = false;
						break;
					}
					else if (user_input == 8)
					{
						color = "color f8";
						original = false;
						break;
					}
				
					else continue;
				}
			}
			good = true;
			continue;
		}
		else if (op == 51)
		{
		  original = true;
		  return true;
		}
		else continue;
	}
	if (good)
		return true;
	else return false;
}

void SETTING_DISPLAY(string option[]) // This is the game setting display function
{
	wstring up;
	up.append(L"   __              _     ___   _  ___ ___  _ _       _ _  __  ___  \n\t\t\t\t\t\t\t\t");
	up.append(L"  |    /\\  |\\  /| |_    |___  |_   |   |    |   |\\ |  |  |   |___  \n\t\t\t\t\t\t\t\t");
	up.append(L"  |_| /--\\ | \\/ | |_  o  ___| |_   |   |   _|_  | \\| _|_ |_|  ___| \n");

	//*************************//
    //    DISPLAY SETTINGS     //
    //*************************//

	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t";
	wcout << up;
	cout << "\n\n";
	cout << "\t\t\t\t\t\t\t\t\t 1-(BOARD-DESIGNS)\n\n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[0] << "     DOTS\n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[1] << "     FILLED \n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[2] << "     TRADITIONAL \n";

	cout << "\t\t\t\t\t\t\t\t\t 2-(COLOR--> (TEXT--BACKGROUND) )\n\n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[3] << "    BLUE--WHITE\n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[4] << "    RED---WHITE\n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[5] << "    PURPLE--WHITE \n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[6] << "    GREEN--WHITE \n";
	cout << "\t\t\t\t\t\t\t\t\t" << option[7] << "    GREY--WHITE\n\n";

	cout << "\t\t\t\t\t\t\t\t\t 3-( DEFAULT SETTINGS )\n\n";


	cout << "\t\t\t\t\t\t\t\t\tESC     QUIT\n";
	cout << "\t\t\t\t\t\t\t\t\t";
}

void ABOUT()  /*About screen it is something like credits in the games*/
{
//******************************************************************//
// --> Using Windows Console control for BackGround and text color  //
// --> Used (Wide string) to make the text to be printed            //
// --> Wide string just keeps the indivual strings in contact and   //
//     to be printed or used using single variable                  //
//******************************************************************//
	system("cls");
	system("color F4");
	wstring front;
	cout << "\n";
	front.append(L"                                                                                     \n");
	front.append(L"	  	               			                                                                           _:_       \n");
	front.append(L"	  	               		                                                                                  '-.-'  \n");
	front.append(L"	                                                                                                         ()      __.'.__              \n");
	front.append(L"	                                                                                                      .-:--:-.  |_______|	         \n");
	front.append(L"                                                                                                       ()      \\____/    \\=====/   \n");
	front.append(L"                                                                                                       /\\      {====}     )___(     \n");
	front.append(L"                                      (\\=,                                                            //\\\\      )__(     /_____\\   \n");
	front.append(L"                      __    |'-'-'|  //  .\\        ________                                          (    )    /____\\     |   |\n");
	front.append(L"                     /  \\   |_____| (( \\_  \\      /                                                   )__(      |  |      |   | \n");
	front.append(L"                     \\__/    |===|   ))  `\\_)    /                     _______  ______   ______      /____\\     |  |      |   |\n");
	front.append(L"                    /____\\   |   |  (/     \\    /           |       | |        |        |             |  |      |  |      |   |\n");
	front.append(L"                     |  |    |   |   | _.-'|   /            |       | |        |        |             |  |      |  |      |   |\n");
	front.append(L"                     |__|    )___(    )___(    \\            |_______| |______  |______  |______      /____\\    /____\\    /_____\\   \n");
	front.append(L"                    (====)  (=====)  (=====)    \\           |       | |               |        |    (======)  (======)  (=======)\n");
	front.append(L"                    }===={  }====={  }====={     \\          |       | |               |        |    }======{  }======{  }======={\n");
	front.append(L"                   (______)(_______)(_______)     \\________ |       | |_______  ______|  ______|   (________)(________)(_________)\n");
	front.append(L"                                                                                                                                    \n ");
	front.append(L"                                                                        ---BY---                                                                 \n ");
	front.append(L"                                       |   |  __                       -----                      ___ ___  __                       \n ");
	front.append(L"                                       |   | |__   /\\  |\\  /|  /\\        |    /\\  |__|  /\\  |\\ | |     |  |__)                \n ");
	front.append(L"                                       |___|  __| /--\\ | \\/ | /--\\  o  |_|   /--\\ |  | /--\\ | \\| |__| _|_ |\\_                 \n ");
	front.append(L"                                                                                                                                    \n ");
	front.append(L"                                                                                                                                    \n ");
	front.append(L"        (MECHATRONICS ENGINEERING  :: DEGREE -- 41 :: SEMESTER 2 (2020) :: SYNDICATE : A :: FOP PROJECT)                             \n ");
	front.append(L"                                                                                                                                    \n ");
	front.append(L"                                                                                                                                    \n ");
	front.append(L"       --> MULTIPLAYER CHESS BOARD             --> POWER & TERROR MODE (INNOVATION)        --> GAME SAVING FEATURE                  \n ");
	front.append(L"                                                                                                                                    \n ");
	front.append(L"       --> CONSOLE GRAPHICS (EXTENDED ASCII (code page 437))    --> MENU SYSTEM            --> POPPING PAUSE WINDOW                 \n ");
	front.append(L"       --> GAME SETTING FEATURE                                                                                                     \n\n\n ");

	front.append(L"       --> MULTIPLAYER BOARD (STANDERED & NEW MODE) FEATURES                                            \n\n ");
	front.append(L"                  --> PAWN EM--PASSANT MOVE                                      \n ");
	front.append(L"                  --> PAWN PROMOTION                                      \n ");
	front.append(L"                  --> CASTLING                                      \n ");
	front.append(L"                  --> CHECK--MATE                                     \n ");
	front.append(L"                  --> STEEL--MATE                                   \n\n\n");
	front.append(L"                                                                                      SUBMITTED TO:-  SIR MUHAMMAD UMAR MASOOD\n");




	cout << "\t\t\t\t\t\t\t\t\t\t";
	wcout << front;
	_getch();
}

void WIN_SCREEN(string text,string game,string p_names[],int* score_1,int* score_2,int turn,string board[][8],char design) /*This is win screen function*/
{
	string line_1, line_2, line_3, line_4, line_5, line_6, line_7, line_8, line_9, line_10;

	// In case of SPECIAL mode 
	if (game == "special" && text == "special")
	{
		if (*score_1 > * score_2)
		{
			line_1  = "       GAME ENDED         ";
			line_2  = "                          ";
			line_3  = "   WHITE player Won       ";
			line_4  = "                          ";
			line_5  = "       TERROR ++          ";
			line_6  = "       POWER ++           ";
			line_7  = "                          ";
			line_8  = "                          ";
			line_9  = "                          ";
			line_10 = "                          ";
		}
		else if (*score_2 > * score_1)
		{
			line_1 = "       GAME ENDED         ";
			line_2 = "                          ";
			line_3 = "   BLACK player Won       ";
			line_4 = "                          ";
			line_5 = "       TERROR ++          ";
			line_6 = "       POWER ++           ";
			line_7 = "                          ";
			line_8 = "                          ";
			line_9 = "                          ";
			line_10 = "                          ";
		
		}
		else if (*score_1 == *score_2)
		{
			line_1 = "       GAME ENDED         ";
			line_2 = "                          ";
			line_3 = "       GAME DRAW          ";
			line_4 = "                          ";
			line_5 = "       TERROR --          ";
			line_6 = "                          ";
			line_7 = "                          ";
			line_8 = "                          ";
			line_9 = "                          ";
			line_10 = "                          ";
		}
	}
	// In case of multiplayer and white player won
	else if (text == "check_mate_2" && game == "multi" && (turn % 2 == 0))
	{
		line_1 = "       GAME ENDED         ";
		line_2 = "                          ";
		line_3 = "       CHECK_MATE         ";
		line_4 = "                          ";
		line_5 = "      WHITE PLAYER        ";
		line_6 = "           IS             ";
		line_7 = "          THE             ";
		line_8 = "        WINNER            ";
		line_9 = "                          ";
		line_10 = "                          ";
	}
	// In case of mulitplayer and Black player won
	else if (text == "check_mate_1" && game == "multi" && (turn % 2 != 0))
	{
		line_1 = "       GAME ENDED         ";
		line_2 = "                          ";
		line_3 = "       CHECK_MATE         ";
		line_4 = "                          ";
		line_5 = "      BLACK PLAYER        ";
		line_6 = "           IS             ";
		line_7 = "          THE             ";
		line_8 = "        WINNER            ";
		line_9 = "                          ";
	   line_10 = "                          ";
	}
	// If he game is drawn
	else if (text == "steel_mate" && game == "multi")
	{
		line_1 = "       GAME ENDED         ";
		line_2 = "                          ";
		line_3 = "       STEEL_MATE         ";
		line_4 = "                          ";
		line_5 = "        GAME_DRAW         ";
		line_6 = "                          ";
		line_7 = "        NO WINNER         ";
		line_8 = "                          ";
		line_9 = "                          ";
		line_10 = "                          ";
	}

	// show the win screen as the popping screen 
	if (design == '`')
	{
		unsigned char a = 219;
		unsigned char c = 32;
		string b = "";
		string WB_LINE = b + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a + (char)a;
		string BB_LINE = b + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c + (char)c;
		string line1 = (char)a + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + (char)a;
		string line2 = (char)a + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + BB_LINE + WB_LINE + (char)a;
		string half_line1 = WB_LINE + BB_LINE;
		string half_line2 = BB_LINE + WB_LINE;
		string empty = b + (char)a + "                              " + (char)a;
		string Blank = WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + WB_LINE + (char)a + (char)a;


		//*******************************************//
		// DISPLAY WIN SCREEN                        //
		//*******************************************//

		system("cls");
		if (game == "special")
		{
			cout << "\t\t\t\t\t\t\t\t\tPOWER & TERROR MODE";
		}
		else
		{
			cout << "\t\t\t\t\t\t\t\t\tSTANDERED MODE";
		}
		cout << "\n(ESC)PAUSE GAME \t\t\t\t\t  (Upper case --> White) & (Lower case --> Black)\n";
		if (game == "special")cout << p_names[0] << "'s SCORES : " << *score_1 << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t" << p_names[1] << "'s SCORES : " << *score_2 << endl;
		else cout << endl;
		cout << "\t\t\t\t\t\t" << Blank << endl;
		int d = 0, r = 0;
		for (int i = 0;i < 4;++i)
		{
			for (int j = 0;j < 3;++j)
			{
				if (i == 1)
				{
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "\\                              /" << half_line1 << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << " \\                            / " << half_line1 << b + (char)a << endl;
					cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)a + (char)a + (char)a) << board[r][d + 0] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 1] << (b + (char)c + (char)c + (char)c)
						<< "  " << WB_LINE + WB_LINE + WB_LINE + (char)a + (char)a + (char)a + (char)a << "  "
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 6] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 7] << (b + (char)c + (char)c + (char)c) << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << (char)a << line_1 << (char)a << "  " << half_line1 << b + (char)a << endl;
					break;
				}
				if (i == 2)
				{
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << b + (char)a << line_6 << b + (char)a << "  " << half_line1 << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << b + (char)a << line_7 << b + (char)a << "  " << half_line1 << b + (char)a << endl;
					cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)a + (char)a + (char)a) << board[r][d + 0] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 1] << (b + (char)c + (char)c + (char)c)
						<< "  " << b + (char)a << line_8 << b + (char)a << "  "
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 6] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 7] << (b + (char)c + (char)c + (char)c) << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line1 << "  " << b + (char)a << line_9 << b + (char)a << "  " << half_line1 << b + (char)a << endl;
					break;
				}
				cout << "\t\t\t\t\t\t" << line1 << endl;
				if (j == 1)
				{
					cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)a + (char)a + (char)a) << board[r][d + 0] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 1] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 2] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 3] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 4] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 5] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 6] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 7] << (b + (char)c + (char)c + (char)c) << b + (char)a << endl;
				}
			}
			d = 0;
			++r;
			for (int k = 0;k < 3;++k)
			{
				if (i == 1)
				{
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << line_2 << b + (char)a << "  " << half_line2 << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << line_3 << b + (char)a << "  " << half_line2 << b + (char)a << endl;
					cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)c + (char)c + (char)c) << board[r][d + 0] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 1] << (b + (char)a + (char)a + (char)a)
						<< "  " << b + (char)a << line_4 << b + (char)a << "  "
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 6] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 7] << (b + (char)a + (char)a + (char)a) << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << line_5 << (char)a << "  " << half_line2 << b + (char)a << endl;
					break;
				}
				if (i == 2)
				{
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << b + (char)a << line_10 << b + (char)a << "  " << half_line2 << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "  " << WB_LINE + WB_LINE + WB_LINE + (char)a + (char)a + (char)a + (char)a << "  " << half_line2 << b + (char)a << endl;
					cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)c + (char)c + (char)c) << board[r][d + 0] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 1] << (b + (char)a + (char)a + (char)a)
						<< " /                            \\ "
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 6] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 7] << (b + (char)a + (char)a + (char)a) << b + (char)a << endl;
					cout << "\t\t\t\t\t\t" << b + (char)a << half_line2 << "/                              \\" << half_line2 << b + (char)a << endl;
					break;
				}
				cout << "\t\t\t\t\t\t" << line2 << endl;
				if (k == 1)
				{
					cout << "\t\t\t\t\t     " << r + 1 << "  " << b + (char)a << (b + (char)c + (char)c + (char)c) << board[r][d + 0] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 1] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 2] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 3] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 4] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 5] << (b + (char)a + (char)a + (char)a)
						<< (b + (char)c + (char)c + (char)c) << board[r][d + 6] << (b + (char)c + (char)c + (char)c)
						<< (b + (char)a + (char)a + (char)a) << board[r][d + 7] << (b + (char)a + (char)a + (char)a) << b + (char)a << endl;
				}
			}
			d = 0;
			++r;
		}
		cout << "\t\t\t\t\t\t" << Blank << endl;
		cout << "\n\t\t\t\t\t\t   A\t   B\t   C\t   D\t   E\t   F\t   G\t   H\n";

		if (turn % 2 == 0)
		{
			cout << endl << p_names[1] << "'s turn (BLACK)";
		}
		else
		{
			cout << endl << p_names[0] << "'s turn (WHITE)";
		}
		cout << "\nEnter your move (space,Piece,column,row) : ";
	}
	else
	{
	system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t" << line_1 << endl;
	cout << "\t\t\t\t\t\t\t" << line_2 << endl;
	cout << "\t\t\t\t\t\t\t" << line_3 << endl;
	cout << "\t\t\t\t\t\t\t" << line_4 << endl;
	cout << "\t\t\t\t\t\t\t" << line_5 << endl;
	cout << "\t\t\t\t\t\t\t" << line_6 << endl;
	cout << "\t\t\t\t\t\t\t" << line_7 << endl;
	cout << "\t\t\t\t\t\t\t" << line_8 << endl;
	cout << "\t\t\t\t\t\t\t" << line_9 << endl;
	cout << "\t\t\t\t\t\t\t" << line_10 << endl;
 }

		_getch();
}




