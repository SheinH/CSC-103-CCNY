//============================================================================
// Name        : Programming.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctype.h>
using namespace std;
int charToNum(char c){
	if(c == 'r')
		return 0;
	if(c == 'p')
		return 1;
	if(c == 's')
		return 2;
	else
		return 3;
}
int judge(char c){
	int player = charToNum(c);
	if(player == 3){
		cout << "Oops..." << endl;
		return 2;
	}
	int computer = rand() % 3;
	if(computer == 0){
		cout << "I'm rock, ";
	}
	else if(computer == 1){
		cout << "I'm paper, ";
	}
	else if(computer == 2){
		cout << "I'm scissors, ";
	}
	if((player + 1) % 3 == computer){
		cout << "I won :)" << endl;
		return -1;
	}
	else if((player - 1) % 3 == computer){
		cout << "you won :(" << endl;
		return 1;
	}
	else{
		cout << "tied..." << endl;
		return 0;
	}
}
int main() {
	char command;
	int wins = 0, losses = 0, ties = 0;
	cout << "Rock-paper-scissors shoo: "; // prints !!!Hello World!!!
	cin >> command;
	command = tolower(command);
	cin.ignore(10000, '\n');
	while(command != 'q'){
		int result = judge(command);
		if(result == -1){
			++losses;
		}
		else if(result == 1){
			++wins;
		}
		else if(result == 0){
			++ties;
		}
		cout << "Rock-paper-scissors shoo: ";
		cin >> command;
		command = tolower(command);
		cin.ignore(10000, '\n');
	}
	if (wins + losses == 0) {
		cout << "Why didn't you play? :(";
		return 0;
	}
	double winRate = (double) wins / (wins + losses) * 100;
	cout << "You won " << wins;
	cout << ", lost " << losses;
	cout << ", tied " << ties;
	cout << ". You won " << winRate << "%." << endl;

	return 0;
}
