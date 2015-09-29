#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{

    int    account;
    int    bet;
    string color_number;
    string color;
    int    random_number;
    bool   even_number;
    string winning_color;
    int    price;
    int    number;
    bool   won_bet;
    string new_bet;
    string new_game;
    string ininp = "Not a correct input!";

    //Game starting in a while-loop to make it possible to restart the 
    //game from the end
    while(1)
    {

        //Declaring that the game has started for the player and adding 
        //money to the account
        cout << "Welcome to a new game of Roulette!" << endl;
        account = 1000;

        //The bet is also started in a while-loop so that 
        //bets can be restarted without needing the game to be restarted
        while(1)
        {

            //Declaring the amount on the account and that a new bet is starting
            cout << "You have " << account << "sek in your account."  << endl;
            cout << "New bet!" << endl;
            //Player gets to input a bet and only the correct amount works

            while(1) 
            {   

                cout << "How much do you want to bet?" << endl;
                cout << "100/300/500: ";
                cin  >> bet;

                if(bet==100 && bet<=account ||
                   bet==300 && bet<=account ||
                   bet==500 && bet<=account  ) 
                {
                    cout << "Your bet is " << bet << "sek!" << endl;
                    break;
                }
                else 
                {
                    cout << ininp << endl; 
                }

            }
            
            //Player choose between color or number. If they 
            //don't do that it will loop until they do.
            while(1) 
            {

                cout << "What do you want to bet on?" << endl;
                cout << "color/number: ";
                cin  >> color_number;

                if(color_number=="color"  ||
                   color_number=="number"  ) 
                {
                    break;          
                }
                else 
                {
                    cout << ininp << endl;
                }

            }
            
            //At this place a split begins in the program, color or number
            //The first one is the color part
            if(color_number=="color")
            {

                //Player gets to pick color
                while(1)
                {   

                    cout << "Which color do you want to bet on?" << endl;
                    cout << "red/black: ";
                    cin  >> color;

                    if(color=="red"   ||
                       color=="black"  )
                    {
                        break;
                    }

                    else
                    {
                        cout << ininp << endl;
                    }

                }

                //A number between 1-36 i randomly generated
                srand(time(NULL));
                random_number = rand() % 36 + 1;

                //To know if the players color is the winning color the code 
                //checks if the number is even or odd
                if(random_number % 2 == 0)
                {
                    winning_color="black";
                }
                else
                {
                    winning_color="red";
                }
                
                //If the players color matches the winning color defined above 
                //the player will win
                if(color==winning_color)
                {   

                    //Price money is calculated and the price money + bet money 
                    //is moved to the players account
                    price = bet * 2;
                    account = account + price;
                    
                    //The winning color is declared for the player and that 
                    //they won, they also get to know how much they have won
                    cout << "Winning color: " << winning_color << endl;
                    cout << "You won!" << endl;
                    cout << "A total of " << price << "sek in price money has been moved to your account" << endl;
                    
                    //Defines that the player has won
                    won_bet = true;

                }
                else
                {   

                    //The winning color is declared for the player and that they have lost
                    cout << "Winning color: " << winning_color << endl;
                    cout << "You lost!" << endl;
                    
                    //Defines that the player has lost
                    won_bet = false;

                }

            }

            //The number part of the split begins here
            else
            {   
            
                //The player picks a number between 1-36
                while(1)
                {   

                    cout << "Which number do you want to bet on?" << endl;
                    cout << "1-36: ";
                    cin  >> number;

                    if(number >= 1 &&  number <= 36)
                    {
                        break;
                    }
                    else
                    {
                        cout << ininp << endl;
                    }

                }

                //A number between 1-36 is randomly generated
                srand(time(NULL));
                random_number = rand() % 36 + 1;

                //If the random number is the same as the number the player 
                //picked they will win
                if(random_number==number)
                {   

                    //Price money is calculated and price + bet money is transfered 
                    //to the players account
                    price = bet * 10;
                    account = account + price;
                    
                    //The winning number is declared and the player and that
                    //they won, they also get to know how much they have won
                    cout << "Winning number: " << random_number << endl;
                    cout << "You Won!" << endl;
                    cout << "A total of " << price << "sek in price money has been moved to your account" << endl;
                    
                    //Defines that the player has won the bet
                    won_bet = true;

                }
                else
                {   

                    //The winning number is declared for the player and that they have lost
                    cout << "Winning number: " << random_number << endl;
                    cout << "You lost!" << endl;
                    
                    //Defines that the player has lost the bet
                    won_bet = false;

                }

            }
            
            //This happens if the player has won
            if(won_bet == true)
            {

                while(1)
                {

                    cout << "Do you want to play a new bet?" << endl;
                    cout << "yes/no: ";
                    cin  >> new_bet;

                    if(new_bet == "yes" || new_bet == "no")
                    {
                        break;
                    }
                    else
                    {
                        cout << ininp << endl;
                    }

                }

            }
            
            //This happens if the player has lost
            else
            {
                
                //Bet is moved from the account
                account = account - bet;
                
                //If the player has enough money they have the choice to continue to play
                if(account >= 100)
                {

                    while(1)
                    {

                        cout << "Do you want to play a new bet?" << endl;
                        cout << "yes/no: ";
                        cin  >> new_bet;

                        if(new_bet == "yes" || new_bet == "no")
                        {
                            break;
                        }
                        else
                        {
                            cout << ininp << endl;
                        }

                    }

                }

                //If the player is out of money they will not be able to play a new bet
                else
                {
                    cout << "You are out of money!" << endl;
                    new_bet = "no";
                }

            }
            
            //If the player don't want to place a new bet the loop will 
            //break and the code will continue
            if(new_bet == "no")
            {
                break;
            }

        }
        
        //The player gets the question to play a new game
        while(1)
        {

            cout << "Do you want to play a new game?" << endl;
            cout << "yes/no: ";
            cin  >> new_game;

            if(new_game == "yes" || new_game == "no")
            {
                break;
            }
            else
            {
                cout << ininp << endl;
            }
            
        }
        
        //If the player don't want to play the loop breaks and the game shuts down
        if(new_game == "no")
        {
            break;
        }

    }

}