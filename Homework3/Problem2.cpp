/*
Author: Colton Higgins
Last Modified: Febuary 2, 2019
Description: User can enter a sentence and it will be given back to them backwards.
*/
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

int main(void) {
	string words[100];
	char letters[50];
	string line;

	cout << "Enter a sentence and it will be given back to you backwards." << endl;
	getline(cin, line);
	
	int wordCount = 0, letterCount = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ' || line[i] == '.') {
			words[wordCount] = letters;
			words[wordCount].erase(letterCount,99);
			wordCount++;
			letterCount = 0;
		}
		else {
			letters[letterCount] = line[i];
			letterCount++;
		}

		if (i == line.length() - 1 && line[i] != ' ' && line[i] != '.') { //Gets last word of sentence if user did not put a period at the end.
			words[wordCount] = letters;
			words[wordCount].erase(letterCount, 99);
			wordCount++;
			letterCount = 0;
		}
	}

	for (int i = wordCount; i >= 0; i--) {
		cout << words[i] << ' ';
	}
	cout << endl << endl;
	system("pause");
}