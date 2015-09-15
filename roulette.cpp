#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{

	double bank;
	double account;
	int    bet;
	string color_number;
	string color;
	int    random_number;
	bool   even_number;
	string winning_color;
	double price;
	int    number;
	
	cout << "Welcome to a new game of Roulette!" << endl;
	account = account + 1000;
	
	cout << "You have " << account << "sek in your account."  << endl;
	
	cout << "New bet!" << endl;
	cout << "Please bet 100, 300 or 500sek:" << endl;
	
	//User gets to input bet	
	while(cin >> bet) 
	{   //only these three is accepted, letters will make the program crash and i dont know why
		if(bet==100 && bet<=account ||
           bet==300 && bet<=account ||
		   bet==500 && bet<=account  ) 
		{
			cout << "Your bet is " << bet << "sek!" << endl;
			break;
		}
		else 
		{
			cout << "Not a correct input!" << endl; 
		}
	}
	
	//Bet moved from account to bank
	account = account - bet;
	bank = bank + bet;
	
	//Player chooses if they want to bet on a color or a number
	cout << "Bet on a color or a number:" << endl;
	while(cin >> color_number) 
	{
		//Same as in the bet part, ony these two inputs are accepted	
		if(color_number=="color"  ||
		   color_number=="number"  ) 
		{
			break;			
		}
		else 
		{
			cout << "Not a correct input!" << endl;
		}

	}
	
	//At this place a split begins in the program, color or number
	//The first one is the color part
	if(color_number=="color")
	{	//Player picks color
		cout << "Pick red or black:" << endl;
		while(cin >> color)
		{	//Only "red" and "black" are accepted inputs, same method as the other inputs
			if(color=="red"   ||
               color=="black"  )
			{
				break;
			}
			else
			{
				cout << "Not a correct input!" << endl;
			}
		}
		//A number between 1-36 i randomly generated
		srand(time(NULL));
		random_number = rand() % 36 + 1;
		//To know if the players color is the winning color the code checks if the number is even or odd
		if(random_number % 2 == 0)
		{
			winning_color="black";
		}
		else
		{
			winning_color="red";
		}
		
		//If the players color matches the winning color defined above the player will win
		if(color==winning_color)
		{	//Price money is calculated and the price money + bet money is moved to the players account
			price = bet * 2;
			account = account + price + bet;
			bank = bank - bet;
			
			//The winning color is declared for the player and that they won, they also get to know how much they have won
			cout << "Winning color: " << winning_color << endl;
			cout << "You won!" << endl;
			cout << "A total of " << price << "sek in price money has been moved to your account and your " << bet << "sek bet is back as well." << endl; 
		}
		else
		{   //The winning color is declared for the player and that they have lost
			cout << "Winning color: " << winning_color << endl;
			cout << "You lost!" << endl;
		}
	}
	//The number part of the split begins here
	else
	{	//The player picks a number between 1-36
		cout << "Pick a number 1-36:" << endl;
		while(cin >> number)
		{	//Only a number between 1-36 is accepted. Numbers greater than or equal to 1 or numbers lesser or equal to 36
			if(number >= 1 &&  number <= 36)
			{
				break;
			}
			else
			{
				cout << "Not a correct input!" << endl;
			}
		}
		//A number between 1-36 is randomly generated
		srand(time(NULL));
		random_number = rand() % 36 + 1;
		//If the random number is the same as the number the player picked they will win
		if(random_number==number)
		{   //Price money is calculated and price + bet money is transfered to the players account
			price = bet * 10;
			account = account + price + bet;
			bank = bank - bet;
			
			//The winning number is declared and the player and that tey won, they also get to know how much they have won
			cout << "Winning number: " << random_number << endl;
			cout << "You Won!" << endl;
			cout << "A total of " << price << "sek in price money has been moved to your account and your " << bet << "sek bet is back as well." << endl; 
		}
		else
		{	//The winning number is declared for the player and that they have lost
			cout << "Winning number: " << random_number << endl;
			cout << "You lost!" << endl;
		}
	}
	
}
