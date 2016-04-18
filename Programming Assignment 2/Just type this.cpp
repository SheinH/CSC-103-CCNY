//============================================================================
// Name        : Just.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <chrono>
using namespace std;

struct uinput{
	string text;
	int time;
};
char randChar(){
	char start;
	int r = rand();
	if(r % 2 == 0)
		start = 'A';
	else
		start = 'a';
	start += r % 26;
	return start;
}
string genString(int i){
	string ret;
	for(;i > 0;i--){
		ret.push_back(randChar());
	}
	return ret;
}
uinput getInput(){
	uinput inp;
	chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
	getline(cin,inp.text);
	chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
	chrono::milliseconds elapsed = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
	inp.time = elapsed.count();
	return inp;
}
int penalty(string s1, string s2){
	int pen = 0;
	int len = max(s1.length(),s2.length());
	for(int i = 0;i < len;i++){
		char c1,c2;
		c1 = i >= s1.length()?' ':s1[i];
		c2 = i >= s2.length()?' ':s2[i];
		pen += abs(c1 - c2);
	}
	return pen;
}
uinput takeTurn(int points, int length, string text){
	cout << "Your current points " << points;
	cout << ", just type [" << length << "] -> " << text << ": ";
	return getInput();
}
void start(){
	int points = 1000, level = 0, combo = 0;
	while(points > 0){
		int len = 5 + level;
		int interval = 5000 - (250 * level);
		string text = genString(len);
		uinput in = takeTurn(points,len,text);
		if(!in.text.compare("end"))
			break;

		cout << in.time << " milliseconds, ";
		bool madeit;
		if(in.time <= interval){	
			cout << "you made it";
			madeit = true;
		}
		else{
			cout << "you *failed* it";
			madeit = false;
		}
		cout << " within the interval of " << interval << "..." << endl;
		int offset = penalty(text,in.text);
		int pen = offset * (madeit?1:2);
		if(offset){
			cout << "String offset is " << offset;
			cout << ", your penalty is " << pen << "..." << endl;
		}
		points -= pen;
		if(pen){
			if(combo >= 0)
				combo = -1;
			else
				combo--;
		}
		else if(madeit && pen == 0){
			points += 100;
			if(combo <= 0)
				combo = 1;
			else
				combo++;
		}
		switch(combo){
			case 3:
				combo = 0;
				level++;
				break;
			case 2:
				cout << "One more for next challenge!!!" << endl;
				break;
			case -2:
				cout << "Make next round for not going back!!!" << endl;
				break;
			case -3:
				combo = 0;
				level--;
				break;

		}
		cout << endl;
	}
}
int main(){
	srand(time(0));
	start();
	return 0;
}
