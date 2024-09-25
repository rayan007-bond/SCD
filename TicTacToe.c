#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

//Here is declaration of Global Variables
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
const char COMPUTER = 'O';
char board[5][5];

//Here we declare some functions for further use in program
int openspaces();
void boardpattern();
void boardreset();
char winnercheck();
void player1();
void player2();
void computer();
void win(char winner);

//Here we do our main work.
int main() 
{
	char winner = ' '; //Here we initialize 'char' datatype of variable 'winner'
	char choice = 0; //Here we initialize 'char' datatype of variable 'choice'
	printf("Press a for Player1 vs Comupter!\t Press b for Player1 vs Player2!\n");
	choice = getchar();

	switch (choice)
	{
	case 'a':


		boardreset(); //Here we call the function of boardreset.
		while (winner == ' ' && openspaces != 0) //Here we call the datatype 'Char' and fuction for openspaces.
		{

			boardpattern(); //This is the called function for shape of board (boardpattern).
			player1(); //This is the called function 'player1' which shows how 'Player1' will play.
			winner = winnercheck(); //Here we take variable of datatype 'char' equal to function 'winnercheck' to see either 'player1' wins or not.
			if (winner != ' ' || openspaces() == 0) 
			{
				break;
			}
			computer(); //This is the called function 'computer' which shows how 'Computer' will play.
			winner = winnercheck(); //Here we take variable of datatype 'char' equal to function 'winnercheck' to see either 'computer' wins or not.
			if (winner != ' ' || openspaces() == 0)
			{
				break;
			}

		}
			boardpattern(); //Here we call shape of board 'boardpattern' fuction.
			win(winner); //Here we call function 'void win(char winner)'.
		break;

	//Here we do all of 'case1' steps again but there is little bit change in 'computer' portion. MEANS here we have 'player2' instead of 'computer' process
	case 'b':
		boardreset(); //In this case we again call 'boardreset' function.
		while (winner == ' ' && openspaces != 0) 
		{
			boardpattern(); //This is the called function for shape of board (boardpattern).
			player1(); //Here we again called function 'playermove1' which shows how 'Player1' will play.
			winner = winnercheck(); //Here we again take variable of datatype 'char' equal to function 'winnercheck' to see either 'player1' wins or not.
			if (winner != ' ' || openspaces() == 0)
			{
				break;
			}
			player2(); //Here we again called function 'player2' which shows how 'Player2' will play.
			winner = winnercheck(); //Here we again take variable of datatype 'char' equal to function 'winnercheck' to see either 'player2' wins or not.
			if (winner != ' ' || openspaces() == 0)
			{
				break;
			}

		}
		boardpattern(); //Here we call shape of board 'boardpattern' fuction.
		win(winner); //Here we call function 'void win(char winner)'.

	}

	return 0;
}
//Here we create one of before declared funtion for free spaces in board. 
int openspaces()
{

	int places = 25; //Here is the initialization of variable 'places'.
	for (int i = 0; i < 5; i++) //Here we use 'FOR' loops and in this loop we create 'NESTED' loop to make 5*5=25 spaces.
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] != ' ')
			{
				places--;
			}
		}
	}
	return places;
}
//Here we create one of before declared funtion for board shape.
void boardpattern()
{
	system("cls"); //This function is to clear game history after one time game.
	printf("    1      2     3     4     5\n"); //Numbers used to help players to play game. 
	printf("  +-----+-----+-----+-----+-----+\n");
	printf("1 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4]); //All outputs show indexing of 'X' and 'O'.
	printf("  +-----+-----+-----+-----+-----+\n");
	printf("2 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4]);
	printf("  +-----+-----+-----+-----+-----+\n");
	printf("3 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4]);
	printf("  +-----+-----+-----+-----+-----+\n");
	printf("4 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4]);
	printf("  +-----+-----+-----+-----+-----+\n");
	printf("5 |  %c  |  %c  |  %c  |  %c  |  %c  |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4]);
	printf("  +-----+-----+-----+-----+-----+\n");


}
//Here we create one of before declared funtion to show board again and again with history in one time game.
void boardreset()
{
	for (int i = 0; i < 5; i++) //In this function we use 'FOR' loop and in this loop we create 'NESTED' loop to reset board and call it again.
	{
		for (int j = 0; j < 5; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//Here we create one of declared funtion to check who is the winner.
char winnercheck()
{
// checking the board
	
	//check right  diagonal
	if (board[0][4] == board[1][3] && board[0][4] == board[2][2] && board[0][4] == board[3][1] && board[0][4] == board[4][0])
	{
		return board[0][4];
	}
	
	// check left diagonal
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3] && board[3][3] == board[4][4])
	{
		return board[0][0];
	}

	// checking all the columns
	for (int i = 0; i < 5; i++)   
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i] && board[0][i] == board[4][i])
		{
			return board[0][i];
		}
	}

	// checking all the rows 
	for (int i = 0; i < 5; i++) 
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3] && board[i][0] == board[i][4])
		{
			return board[i][0];
		}
	}
	return ' ';

}
//Here we create one of declared funtions to show how player1 plays.
void player1()
{
	int row = 0, col = 0; //Here we initialze rows and columns.

	do // DO-WHILE loop
	{
		printf("Enter the Row number : "); //Here we ask input for rows from 'player1'.
		scanf("%d", &row);
		row--;
		printf("Enter the Column number "); //Here we ask input for columns from 'player1'.
		scanf("%d", &col);
		col--;
		if (board[row][col] != ' ') //IF boardspace is not empty then it shows ERROR!
		{
			printf("ERROR ! ");

		}
		else
		{
			board[row][col] = PLAYER1; //ELSE it shows 'player1' input
			break;
		}
	} while (board[row][col] != ' ');
}
//Here we create one of declared funtions to show how player2 plays.
void player2()
{
	int row = 0, col = 0; //Here we initialze rows and columns.

	do //DO-WHILE loop
	{
		printf("Enter the Row number P2 : "); //Here we ask input for rows from 'player2'.
		scanf("%d", &row);
		row--;
		printf("Enter the Column number P2 : "); //Here we ask input for columns from 'player2'.
		scanf("%d", &col);
		col--;
		if (board[row][col] != ' ') //IF boardspace is not empty then it shows ERROR!
		{
			printf("ERROR ! "); 

		}
		else
		{
			board[row][col] = PLAYER2; //ELSE it shows 'player2' input
			break;
		}
	} while (board[row][col] != ' ');
}
//Here we create one of declared funtions to show how computer try to win.
void computer()
{
	// generate random number 
	srand(time(0));
	int row, col;


	if (openspaces() > 0)
	{
		// secures mid and corners 
		if (board[2][2] == ' ')
		{
			board[2][2] = COMPUTER;
		}
		else if (board[0][0] == ' ')
		{
			board[0][0] = COMPUTER;	
		}
		else if (board[4][0] == ' ')
		{
			board[4][0] = COMPUTER;
		}
		else if (board[4][4] == ' ')
		{
			board[4][4] = COMPUTER;
		}
		else if (board[0][4] == ' ')
		{
			board[0][4] = COMPUTER;
		}
		else
		{
			do
			{ 
				row = rand() % 5;
				col = rand() % 5;

			} 
			while (board[row][col] != ' ');
			board[row][col] = COMPUTER;
		}

	}
	else
	{
		win(' ');
	}
}
//Here we create one of declared funtions to show who wins and print congrats.
void win(char winner)
{ 
//Use IF-ELSE statement to show user who is the winner or loser.
	if (winner == PLAYER1) 
	{
		printf("CONGRATS !\nPLAYER 1 WON ");
	}
	else if (winner == PLAYER2)
	{
		printf("YOU LOSE!\nCOMPUTER WON ");
	}
	else if (winner == COMPUTER)
	{
		printf("CONGRATS !\nPLAYER 2 WON ");
	}
	else
	{
		printf("DRAW!");
	}
}

