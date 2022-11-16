/*
Author: Colton Higgins
Last Modified: February 6, 2019
Description:
*/
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ifstream inFile;
	inFile.open("WeatherStationData.txt");
	if (!inFile) {
		cout << "Unable to open input file.";
		return 1;
	}
	ofstream outFile;
	outFile.open("Filtered_AL_Weather_Station.txt");
	if (!outFile) {
		cout << "Unable to open output file.";
		return 1;
	}
	

	string line;
	while (!inFile.eof()) {
		getline(inFile, line);
		if (line.substr(96, 5) == "-9999") {
			line = "";
		} else if (line.substr(123,5) == "-9999") {
			line = "";
		} else if (line.substr(132, 5) == "-9999") {
			line = "";
		} else {
			outFile << line << endl;
		}
	}

	inFile.close();
	outFile.close();

	return 0;
}