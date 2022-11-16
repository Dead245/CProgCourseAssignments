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
	inFile.open("weather_station_five_column.txt");
	if (!inFile) {
		cout << "Failed to open input file";
		return 1;
	}
	string line, minStations[10], maxStations[10];
	double min = 1000, max = 0, lineMin = 0, lineMax = 0;
	
	getline(inFile, line);				//Moves past first two lines.
	getline(inFile, line);
	char check = ' ';
	while (inFile >> check) {			//Find max/min
		getline(inFile, line);
		lineMax = stod(line.substr(89,4));
		lineMin = stod(line.substr(109, 4));
		if (lineMin < min) {
			min = lineMin;
		}
		if (lineMax > max) {
			max = lineMax;
		}
	}
	inFile.clear();
	inFile.seekg(0, ios::beg);

	getline(inFile, line);				//Moves past first two lines again
	getline(inFile, line);

	int minX = 0, maxX = 0;
	string temp, minDates[10], maxDates[10];
	while (!inFile.eof()) {				//Find the stations with the max/mins
		getline(inFile, line);
		lineMin = stod(line.substr(110, 4));
		if (lineMin == min) {
			minStations[minX] = line.substr(0, 49);
			minDates[minX] = line.substr(53, 2);
			minX++;
		}
		lineMax = stod(line.substr(90, 4));
		if (lineMax == max) {
			maxStations[maxX] = line.substr(0, 49);
			maxDates[maxX] = line.substr(53,2);
			maxX++;
		}
	}

	cout << "Min Temp for March 2018: " << min << endl << "Max Temp for March 2018: " << max << endl;
	for (int i = 0; i < minX; i++) {
		cout << minStations[i] << "recorded a low temp of " << min << " on March " << minDates[i] << endl;
	}
	for (int i = 0; i < maxX; i++) {
		cout << maxStations[i] << "recorded a high temp of " << max << " on March " << maxDates[i] << endl;
	}
	
	system("pause");
	return 0;
}