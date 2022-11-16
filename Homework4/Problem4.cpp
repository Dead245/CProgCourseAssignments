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
		cout << "Failed to open input file";
		return 1;
	}
	ofstream outFile;
	outFile.open("North_AL_Station_Data.txt");
	if (!inFile) {
		cout << "Failed to open output file";
		return 1;
	}

	string line, stationName;

	getline(inFile, line);		//Copies first 2 lines over from input file
	outFile << line << endl;
	getline(inFile, line);
	outFile << line << endl;
	cout << "Compiling and Sorting through Input..." << endl;
	while (!inFile.eof()) {
		getline(inFile, line);
		stationName = line.substr(17,45);
		for (int i = 0; i < 45; i++) {				//Removes whitespace in front of the station names
			if (stationName.substr(0, 1) == " ") {
				stationName.erase(0, 1);
			}
			else {
				break;
			}
		}
		if (stationName.substr(0,6) == "ATHENS") {
			outFile << line << endl;
		} else if (stationName.substr(0, 7) == "DECATUR") {
			outFile << line << endl;
		} else if(stationName.substr(0, 7) == "CULLMAN") {
			outFile << line << endl;
		} else if (stationName.substr(0, 17) == "OWENS CROSS ROADS") {
			outFile << line << endl;
		} else if (stationName.substr(0, 13) == "MUSCLE SHOALS") {
			outFile << line << endl;
		} else if (stationName.substr(0, 10) == "SCOTTSBORO") {
			outFile << line << endl;
		} else if (stationName.substr(0, 10) == "HUNTSVILLE") {
			outFile << line << endl;
		}
	}
	cout << "Process Complete." << endl;
	inFile.close();
	outFile.close();
	system("pause");
	return 0;
}