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
	
	cout << "Welcome to a new game of Roulette!" << endl;
	account = account + 1000;
	
	cout << "You have " << account << "sek in your account."  << endl;
	
	cout << "New bet!" << endl;
	cout << "Please bet 100, 300 or 500sek:" << endl;
	
	//User gets to input bet	
	while(cin >> bet) 
	{
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

	cout << "Bet on a color or a number:" << endl;
	while(cin >> color_number) 
	{
		
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

	if(color_number=="color")
	{
		cout << "Pick red or black:" << endl;
		while(cin >> color)
		{
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
		
		srand(time(NULL));
		random_number = rand() % 36 +1;
		if(random_number % 2 == 0)
		{
			winning_color="black";
		}
		else
		{
			winning_color="red";
		}

		if(color==winning_color)
		{
			price = bet * 2;
			account = account + price + bet;
			bank = bank - bet;

			cout << "Winning color: " << winning_color << endl;
			cout << "You won!" << endl;
			cout << "A total of " << price << "sek in price money has been moved to your account and your " << bet << "sek bet is back as well." << endl; 
		}
		else
		{
			cout << "Winning color: " << winning_color << endl;
			cout << "You lost!" << endl;
		}
	}
	else
	{
		
	}
	
}
