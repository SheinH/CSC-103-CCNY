// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
using namespace std;

string repeatChar(char c, int n) {
	string out;
	for (; n > 0; n--) {
		out.push_back(c);
	}
	return out;
}
vector<string> getInput() {
	vector<string> output;
	string line;
	cout << "Enter text, empty return will quit the input" << endl;
	do {
		cout << "> ";
		getline(cin, line);
		if (line.empty())
			continue;
		istringstream in(line);
		string word;
		while (in.good()) {
			in >> word;
			if (!word.empty())
				output.push_back(word);
		}

	} while (!line.empty());
	return output;
}
void printLine(vector<string>::iterator start, vector<string>::iterator end,
		int width) {
	if(start == end)
		return;
	int chars = 0;
	int spaces = -1;
	vector<string> currentLine;
	for (; start != end; start++) {
		string &word = *start;
		int newchars = chars + word.length();
		int newspaces = spaces + 1;
		if (newchars + newspaces <= width) {
			currentLine.push_back(word);
			chars = newchars;
			spaces = newspaces;
		} else
			break;
	}
	cout << '|';
	if (spaces <= 0) {
		cout << currentLine[0] << repeatChar(' ', (width - chars));
	} else {
		int spaceWidth = (width - chars) / spaces;
		int extraWidth = (width - chars) % spaces;
		int i;
		for (i = 0; i < currentLine.size() - 1; i++) {
			cout << currentLine[i];
			cout << repeatChar(' ', spaceWidth);
			if (extraWidth > 0) {
				cout << ' ';
				extraWidth--;
			}
		}
		cout << currentLine[i];
	}
	cout << '|' << endl;
	printLine(start, end, width);
	return;
}
void printJustify(vector<string> words, int width) {
cout << '+' << repeatChar('-', width) << '+' << endl;
printLine(words.begin(), words.end(), width);
cout << '+' << repeatChar('-', width) << '+' << endl;
}
int main() {
vector<string> input = getInput();
int maxWidth = 0;
for (int i = 0; i < input.size(); i++) {
	maxWidth = (input[i].length() > maxWidth) ? input[i].length() : maxWidth;
}
int width;
do {
	cout << "> Enter width of text: ";
	cin >> width;
	if (width == 0)
		continue;
	width = (width < maxWidth) ? maxWidth : width;
	printJustify(input, width);
} while (width > 0);
return 0;
}
