#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{

	double bank;
	double account;
	int    bet;
	string color_number;
	
	cout << "Welcome to a new game of Roulette!" << endl;
	account = account + 1000;
	
	cout << "You have " << account << "sek in your account."  << endl;
	
	cout << "New bet!" << endl;
	cout << "Please bet 100, 300 or 500sek." << endl;
	
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

	cout << "Do you want to bet on a color or a number?" << endl;
	while(cin >> color_number) 
	{
		if(color_number=="color"  ||
		   color_number=="number" ||
           color_number=="COLOR"  ||
           color_number=="NUMBER" ||
           color_number=="Color"  ||
           color_number=="Number" ||
           color_number=="c"      ||
		   color_number=="C"      ||
		   color_number=="n"      ||
		   color_number=="N"       ) 
		{
			break;			
		}
		else 
		{
			cout << "Bad!" << endl;
		}
	}
	
}
