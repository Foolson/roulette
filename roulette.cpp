#include <iostream>

using namespace std;

int main() {

	double bank;
	double account;
	int    bet;
	
	cout << "Welcome to a new game of Roulette!" << endl;
	account = 1000;
	cout << "You have " << account << "sek in your account."  << endl;
	cout << "New bet!" << endl;
	cout << "Please bet 100, 300 or 500sek." << endl;
		
	while(cin >> bet) {
		if(bet==100 || bet==300 || bet==500) {
			cout << "Your bet is " << bet << "sek!" << endl;
			break;
		}
		else {
			cout << "Not a correct input!" << endl;
		}
	}

}
