#include <iostream>
#include <vector>
using namespace std;
struct Card{
	int suit;
	int kind;
	operator int() const{
		return suit * 13 + kind;
	}
	ostream& operator<<(std::ostream& os, const Card& obj){
		switch(obj.suit){
			case 0:
				cout <<  'D';
				break;
			case 1:
				ret += 'C';
				break;
			case 2:
				ret += 'H';
				break;
			case 3:
				ret += 'S';
				break;
		}
		if(c.kind > 1 && c.kind < 11){
			ret += to_string(c.kind);
		}
		else{
			switch(c.kind){
				case 1:
					ret += 'A';
					break;
				case 11:
					ret += 'J';
					break;
				case 12:
					ret += 'Q';
					break;
				case 13:
					ret += 'K';
					break;
			}
		}
		return ret;
	    return os;
	}
	operator
};
typedef vector<Card> Hand;
