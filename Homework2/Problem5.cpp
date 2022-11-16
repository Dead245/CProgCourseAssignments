#include <iostream>;
#include <fstream>;
#include <iomanip>;
#include <string>;
using namespace std;

int main(void) {
	string input;
	
	cout << "Enter a four letter word to see if it is a word in our four letter dictionary." << endl;
	cin >> input;
	
	if (input.size() != 4) {
		cout << "Error: Your input is not 4 charaters long." << endl;
		system("pause");
		exit(1);
	}

	ifstream inFile;
	inFile.open("dictionary_four_letter_words.txt");

	if (!inFile) {
		cout << "Error: Input file not opened." << endl;
		system("pause");
		exit(1);
	}

	string words[5000];
	int x = 0;
	while (!inFile.eof()) {
		inFile >> words[x];
		x++;
	}

	bool wordFound = false;
	for (int y = 0; y < x; y++) {
		if (input == words[y]) {
			wordFound = true;
		}
	}

	if (wordFound) {
		cout << "Your word '" << input << "' was found inside the dictionary." << endl;
	}
	else {
		cout << "Sorry, your word '" << input << "' was not found inside the dictionary." << endl;
	}

	system("pause");
}