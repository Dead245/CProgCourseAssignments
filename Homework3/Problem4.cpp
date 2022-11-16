/*
Author: Colton Higgins
Last Modified: February 2, 2019
Description: Searches word puzzle line by line for any lateral 4-letter words based off a dictionary file.
*/
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(void) {
	
	ifstream inFilePuzzle;
	inFilePuzzle.open("WordPuzzle.txt");
	if (!inFilePuzzle) {
		cout << "Unable to open puzzle file";
		return 1;
	}

	ifstream inFileDictionary;
	inFileDictionary.open("dictionary_four_letter_words.txt");
	if (!inFileDictionary) {
		cout << "Unable to open dictionary file";
		return 1;
	}
	
	string findings[100];
	int wordsFound = 0;
	while (!inFilePuzzle.eof()) {
		string line, tempSubstr, word;
		getline(inFilePuzzle, line);
		for (int i = 0; i < line.length() - 3; i++) {
			tempSubstr = line.substr(i, 4);
			while (!inFileDictionary.eof()) {
				inFileDictionary >> word;
				if (word.compare(tempSubstr) == 0) {
					findings[wordsFound] = tempSubstr;
					wordsFound++;
				}
			}
			inFileDictionary.clear();
			inFileDictionary.seekg(0, ios::beg);
		}
	}

	inFilePuzzle.close();
	inFileDictionary.close();

	cout << "Found These Words in Puzzle:" << endl;
	for (int i = 0; i < wordsFound; i++) {
		cout << findings[i] << endl;
	}
	system("pause");
}