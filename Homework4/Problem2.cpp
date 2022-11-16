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
	inFile.open("Filtered_AL_Weather_Station.txt");
	if (!inFile){
		cout << "Failed to open input file";
		return 1;
	}

	ofstream outFile;
	outFile.open("weather_station_five_column.txt");
	if (!outFile) {
		cout << "Failed to open output file";
		return 1;
	}
	
	outFile << left << setw(50) << "STATION NAME" << setw(20) << "DATE" << setw(20) << "PRCP" << setw(20) << "TMAX" << setw(20) << "TMIN" << endl
			<< setw(120) << setfill('-') << "" << endl;
	string line, stationName, date, month, day, year, prcp;
	double tmax, tmin;

	getline(inFile, line);	//To skip the first two lines in the file
	getline(inFile, line);
	while (!inFile.eof()) {
		getline(inFile, line);
		stationName = line.substr(17, 45);
		prcp = line.substr(96,4);
		year = line.substr(69, 4);
		month = line.substr(73, 2);
		day = line.substr(75, 2);
		tmax = stod(line.substr(123, 2));
		tmin = stod(line.substr(132, 2));

		for (int i = 0; i < 45; i++) {				//Attempt to remove whitespace in front of the station names
			if (stationName.substr(0,1) == " ") {
				stationName.erase(0,1);
			}
			else {
				break;
			}
		}

		date = month + string(" ") + day + string(" ") + year;
		tmax = ((tmax / 10) * (9 / 5)) + 32;
		tmin = ((tmin / 10) * (9 / 5)) + 32;
		
		outFile << left << setw(50) << setfill(' ') << stationName << setw(20) << date << setw(20) << prcp << setw(20) <<tmax << setw(20) << tmin << endl;
	}

	inFile.close();
	outFile.close();

	system("pause");
	return 0;
}