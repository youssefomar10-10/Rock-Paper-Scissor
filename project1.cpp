// project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;
enum EnGameTyp{Stone=1, Paper=2, Scissors=3};
enum EnGameStatue{Win=1,Draw=2,Lose=3};
//enum EnPlayres{Player1=1,Computer=2};
struct stPlayerCounter {
	int PlayerCount = 0;
	int ComputerCount = 0;
	int DrawCount = 0;
};
int Random(int From, int To)
{
	int Mix = rand() % (To - From + 1) + From;
	return Mix;
}
int ReadHowManyRounds(string Message)
{
	int Number = 0;
	do {
		cout << Message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
EnGameTyp PlayerChoose()
{
	int PlayerChoise = 0;
	do {

		cout << "Your Choise: [1]Stone, [2]Paper, [3]Scissors";
		cin >> PlayerChoise;
		 
	} while (1 > PlayerChoise || PlayerChoise > 3);

	return EnGameTyp(PlayerChoise);

}
EnGameTyp FillComputerChoise()
{
	EnGameTyp Typ = (EnGameTyp) Random(1, 3);
	
	return Typ;
}
string FillChoises(EnGameTyp Choise)
{
	switch (Choise)
	{
	case Stone:
		return "Stone\n";
		break;
	case Paper:
		return "Paper\n";
		break;
	case Scissors:
		return "Scissors\n";
		break;
	default:
		return "Wrong Choise\n";
		break;
	}
}
string Comparing(EnGameTyp Player, EnGameTyp Computer)
{
	
	 
	if (Player == Computer)
	{
		system("color E0");
		return "[No Winner]\n";
		
	}
	else if (Player == Stone && Computer == Paper)
	{
		cout << "\a";
		system("color C0");
		return "Computer Wins";
		
		
	}
	else if (Player == Paper && Computer == Scissors)
	{
		cout << "\a";
			system("color C1");
		return "Computer Wins";
		
		
	}
	else if (Player == Scissors && Computer == Stone)
	{
		cout << "\a";
		system("color C0");
		return "Computer Wins";
		
	
	}
	else
	{
		system("color A0");
		return "Player1 Wins";
		
		
	}
}
void Counter(stPlayerCounter& Count, string Winner)
{
	if ("Player1 Wins" == Winner)
	{
		Count.PlayerCount++;
	}
	else if ("Computer Wins" == Winner)
	{
		Count.ComputerCount++;
	}
	else
	{
		Count.DrawCount++;
	}

}

void RoundResult(int RoundsLength,stPlayerCounter& Count)
{
	

	for (int i = 1; i <= RoundsLength; i++)
	{
		//FillRounds(i);
		cout << endl;
		cout << "Round[" << i << "] begins:\n";
		EnGameTyp Player = PlayerChoose();
		EnGameTyp Computer = FillComputerChoise();
		string Winner = Comparing(Player, Computer);
		Counter(Count,Winner);
		cout << "________________________Round [" << i  << "]________________________\n\n";
		cout << "Player1 Choise: " << FillChoises(Player);
		cout << "Computer Choise: " << FillChoises(Computer);
		cout << "Round Winner: " << Winner<<endl;
		cout << "_________________________________________________________________________\n\n";
	}
}
void GameResult(stPlayerCounter Count, int RoundsLength)
{
	cout << "\t_____________________________________________________________________________\n\n\n";
	cout << "\t\t\t\t  +++ G A M E  O V E R +++ \n\n";
	cout << "\t_____________________________________________________________________________\n\n";
	cout << "\t________________________________[ Game Result ]______________________________\n\n";
	cout << "\tGame Rounds                     :" << RoundsLength << endl;
	cout << "\tPlayer1 won times               :" << Count.PlayerCount << endl;
	cout << "\tComputer won times              :" << Count.ComputerCount << endl;
	cout << "\tDraw times                      :" << Count.DrawCount << endl;
	if (Count.PlayerCount > Count.ComputerCount)
	{
		cout << "\tFinal Winner                : Player1" << endl; 
	}
	else if (Count.PlayerCount < Count.ComputerCount)
	{
		cout << "\tFinal Winner               : Computer" << endl; 
	}
	else {
		cout << "\tFinal Winner               : No Winner" << endl;
	}
}
bool NewGame()
{
	char NGame;
	
	cout << "Do you wanna play new game?Y/N";
	cin >> NGame;
	if (NGame == 'Y' || NGame == 'y')
	{
		system("cls");
		return true;
	}else 
	{
		return false;
	}

	
}
void AllGame()
{
	int RoundLength = ReadHowManyRounds("Please enter how many rounds do you want to play\n");
	stPlayerCounter Count;
	RoundResult(RoundLength,Count);
	GameResult(Count, RoundLength);
	
	
	


}

int main()
{
	srand((unsigned)time(NULL));
	do {
		AllGame();

	} while (NewGame());
	

}

