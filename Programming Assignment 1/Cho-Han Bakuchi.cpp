//============================================================================
// Name        : Cho-Han.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Player{
	public:
		string getName();
		int getBalance();
		void autoBet(Player &p);
		void cinBet();
		bool takeTurn();
		bool isBroke();
		Player(string n);
	private:
		string name;
		int balance;
		int bet;
};
Player::Player(string n){
	name = n;
	balance = 100;
	bet = 0;
}
string Player::getName(){
	return name;
}
bool Player::isBroke(){
	return balance <= 0;
}
void Player::autoBet(Player &p){
	int b;
	if(balance < p.getBalance()){
		b = balance / 2;
		if(b == 0)
			b++;
	}
	else{
		b = balance;
	}
	bet = rand() % b;
}
void Player::cinBet(){
	cout << "  Enter \"c\" (even) or \"h\" (odd) and an amount you bet: ";
	char c;
	int bet;
	cin >> c;
	cin >> bet;
	if(!cin || bet > balance || bet == 0 || (c != 'c' && c != 'h')){
		cout << "  Invalid bet. Try again." << endl;
		cin.clear();
		cin.ignore(INT_MAX,'\n');
		cinBet();
	}
}
int Player::getBalance(){
	return balance;
}
bool Player::takeTurn(){
	cout << "  " << name << " bet $" << bet << " -> ";
	bool won = rand() % 2 == 0;
	if(won){
		balance += bet;
		cout << "won..." << endl;
	}
	else{
		balance -= bet;
		cout << "lost..." << endl;
	}
	return isBroke();
}
void printBalances(vector<Player> players){
	cout << "You have $" << players[0].getBalance() << endl;
	for(int i = 1; i < players.size(); i++){
		cout << "  " << players[i].getName() << " has $" << players[i].getBalance() << endl;
	}
	cout << endl;
}
int main(){
	srand(time(0));
	vector<Player> players;
	players.push_back(Player("You"));
	players.push_back(Player("Player 1"));
	players.push_back(Player("Player 2"));
	Player &user = players[0];
	for(int i = 0;;i++){
		i = i % players.size();
		Player &cp = players[i];
		if(i == 0){
			printBalances(players);
			cp.cinBet();
		}
		else{
			cp.autoBet(user);
		}
		bool b = cp.takeTurn();
		if(b){
			if(i == 0){
				cout << "  You are broke..." << endl;
				cout << "  Bye..." << endl;
				break;
			}
			else{
				cout << "  "<< cp.getName() << " is broke..." << endl;
				players.erase(players.begin() + i);
				i--;
			}
		}
		if(players.size() == 1){
			cout << "  You Win!" << endl;
			break;
		}
		if(i == players.size() - 1)
			cout << endl;
	}
	return 1;
}
