/*
Author: Colton Higgins
Last Modified: February 2, 2019
Description: Counts all word in text file then replaces all instances of "UAHuntsville" with "UAH".
*/
#include <fstream>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ifstream inFile;
	inFile.open("UAHSampleText.txt");
	
	if (!inFile) {
		cout << "Unable to open input file";
		system("pause");
		return 1;
	}

	ofstream outFile;
	outFile.open("NewUAHSampleTest.txt");
	if (!outFile) {
		cout << "Unable to open output file";
		system("pause");
		return 1;
	}
	
	int wordCount = 0;
	string word;
	//Finds the word count of the text file.
	while (!inFile.eof()) {
		inFile >> word;
		wordCount++;
	}
	

	inFile.clear();
	inFile.seekg(0, ios::beg);
	
	word = "";
	while (!inFile.eof()) {
		getline(inFile, word);
		while (word.find("UAHuntsville") != -1) {
			word.replace(word.find("UAHuntsville"), 12, "UAH");
		}
		outFile << word << endl;
	}
	outFile.close();

	cout << "Word Count: " << wordCount << endl;
	
	system("pause");
}
