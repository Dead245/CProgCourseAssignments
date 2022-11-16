/*
Author: Colton Higgins
Last Modified: February 6, 2019
Description: Uses file "Filtered_AL_Weather_Station.txt" for a variety of uses that the user can select from
*/
#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void case1();
void case2();
void case3();
void case4();
void case5();

int main(void) {
	cout << "Choose 1 option from the list: " << endl
		<< "1: Total Precipitation from all stations for a single day" << endl
		<< "2: Total Precipitation over a range of dates" << endl
		<< "3: Total Precipitation by Station for March." << endl
		<< "4: Temperature Extremes and Average by Station" << endl
		<< "5. Temperature Extremes and Average by Station over a range of dates" << endl
		<< "6. Quit" << endl;
	int input;
	cin >> input;
	while (input != 6) {
		if (input == 1) {
			case1();
		} else if (input == 2) {
			case2();
		} else if (input == 3) {
			case3();
		} else if (input == 4) {
			case4();
		} else if (input == 5) {
			case5();
		} else {
			cout << "Incorrect Input, Ending Program..." << endl;
			break;
		}
		cin >> input;
	}

	system("pause");
	return 0;
}

void case1() {
	cout << "You selected Option 1." << endl 
		<< "Enter Date in MM DD YYYY format (Ex:'03 01 2018'). Will return Total Precipitation for that day." << endl;
	string date, month = "", day = "", year = "";
	cin.ignore();
	getline(cin, date);
	
	month = date.substr(0,2);	//Reconstructs date into 'YYYYMMDD' format
	day = date.substr(3,2);
	year = date.substr(6,4);
	date = year + month + day;

	ifstream inFile;
	inFile.open("Filtered_AL_Weather_Station.txt");
	if (!inFile) {
		cout << "Error opening data file" << endl;
		return;
	}
	
	string line;
	getline(inFile, line);		//Skip first 2 lines
	getline(inFile, line);
	
	double total = 0;
	while (!inFile.eof()) {
		getline(inFile, line);
		if (line.substr(69,8) == date) {
			total += stod(line.substr(96,4));
		}
	}
	cout << "The total precipitation on March " << day << " is " << total << " inches." << endl;
	inFile.close();
	cout << "Please choose another option." << endl;
}
void case2() {
	cout << "Please specify range in MM DD YYYY format (Ex. '03 01 2018')." << endl << "Will return total precipitation from all stations over the date range." << endl
		<< "What is the start date?" << endl;
	string line;
	int startDay, endDay;
	cin.ignore();
	getline(cin,line);
	startDay = stoi(line.substr(3,2));
	cout << "Now, what is the end date?" << endl;
	getline(cin,line);
	endDay = stoi(line.substr(3,2));

	ifstream inFile;
	inFile.open("Filtered_AL_Weather_Station.txt");
	if (!inFile) {
		cout << "Error opening data file" << endl;
		return;
	}
	double total = 0;
	getline(inFile, line);		//Skip first 2 lines
	getline(inFile, line);
	while (!inFile.eof()) {
		getline(inFile, line);
		int lineDay = stoi(line.substr(75, 2));
		if (lineDay <= endDay && lineDay >= startDay) {
			total += stoi(line.substr(96, 4));
		}
	}
	inFile.close();
	
	cout << "From March " << startDay << " to March " << endDay << ":" << endl
		<< "The total Precipitation is: " << total << " inches" << endl
		<< "Please choose another option." << endl;
}
void case3() {
	cout << "Enter a station, its total precipitation for that month will be given (Enter the name in all capital letters).";
	string stationName, line;
	cin.ignore();
	getline(cin, stationName);

	ifstream inFile;
	inFile.open("Filtered_AL_Weather_Station.txt");
	if (!inFile) {
		cout << "Error opening data file" << endl;
		return;
	}

	double total = 0;
	string lineStation;
	getline(inFile, line);		//Skip first 2 lines
	getline(inFile, line);
	while (!inFile.eof()) {
		getline(inFile, line);
		lineStation = line.substr(17,45);
		for (int i = 0; i < 45; i++) {				//Removes whitespace in front of the station names
			if (lineStation.substr(0, 1) == " ") {
				lineStation.erase(0, 1);
			}
			else {
				break;
			}
		}

		if (lineStation.substr(0,stationName.length()) == stationName) {
			total += stod(line.substr(96, 4));
		}
	}
	inFile.close();

	cout << "Total precipitation for " << stationName << " is: " << total << " inches." << endl
		<< "Please choose another option." << endl;
}
void case4() {
	cout << "Enter station name in all capital letters (EX. 'HUNTSVILLE'). Input must match exactly to station name." << endl
		<< "Program will find and return the max temp, min temp, average high temperature, " << endl << "and average low temperature for station during March.";
	string stationName;
	cin.ignore();
	getline(cin,stationName);

	ifstream inFile;
	inFile.open("Filtered_AL_Weather_Station.txt");
	if (!inFile) {
		cout << "Error opening data file" << endl;
		return;
	}
	
	string line, lineStation;
	double min = 1000, max = 0, avgHigh = 0, avgLow = 0;
	int counter = 0;
	getline(inFile, line);		//Skip first 2 lines
	getline(inFile, line);
	while (!inFile.eof()) {
		getline(inFile, line);
		lineStation = line.substr(17, 45);
		for (int i = 0; i < 45; i++) {				//Removes whitespace in front of the station names
			if (lineStation.substr(0, 1) == " ") {
				lineStation.erase(0, 1);
			}
			else {
				break;
			}
		}

		if (stationName.compare(lineStation) == 0) {
			if (min > stod(line.substr(132,2))) {
				min = stod(line.substr(132,2));
			}
			if (max < stod(line.substr(123,2))) {
				max = stod(line.substr(123,2));
			}
			avgHigh += stod(line.substr(123, 2));
			avgLow += stod(line.substr(132, 2));
			counter++;
		}
	}

	avgHigh = avgHigh / counter;
	avgLow = avgLow / counter;

	cout << "For " << stationName << ": " << endl
		<< "Min Temp " << min << endl
		<< "Max Temp " << max << endl
		<< "Avg High Temp " << setprecision(4) << avgHigh << endl
		<< "Avg Low Temp " << avgLow << endl
		<< "Please choose another option." << endl;

	inFile.close();
}
void case5() {
	cout << "Enter station name in all capital letters (Ex. 'GUNTERSVILLE'). Input must match exactly to station name." << endl;
	string stationName;
	cin.ignore();
	getline(cin, stationName);
	
	cout << "Now input a range of dates in MM DD YYYY format (Ex. '03 01 2018'). Program will find the temp extremes and averages." << endl
		<< "When will that start date be?" << endl;
	int startDay, endDay;
	string date;
	getline(cin,date);
	startDay = stoi(date.substr(3, 2));
	
	cout << "Now, what is the end date?";
	getline(cin, date);
	endDay = stoi(date.substr(3, 2));

	ifstream inFile;
	inFile.open("Filtered_AL_Weather_Station.txt");
	if (!inFile) {
		cout << "Error opening data file" << endl;
		return;
	}

	string line, lineStation;
	double min = 1000, max = 0, avgHigh = 0, avgLow = 0;
	int counter = 0;
	
	getline(inFile, line);		//Skip first 2 lines
	getline(inFile, line);
	while (!inFile.eof()) {
		getline(inFile, line);
		lineStation = line.substr(17, 45);
		int lineDay = stoi(line.substr(75, 2));
		for (int i = 0; i < 45; i++) {				//Removes whitespace in front of the station names
			if (lineStation.substr(0, 1) == " ") {
				lineStation.erase(0, 1);
			}
			else {
				break;
			}
		}

		if (stationName.compare(lineStation) == 0 && lineDay <= endDay && lineDay >= startDay) {
			if (min > stod(line.substr(132, 2))) {
				min = stod(line.substr(132, 2));
			}
			if (max < stod(line.substr(123, 2))) {
				max = stod(line.substr(123, 2));
			}
			avgHigh += stod(line.substr(123, 2));
			avgLow += stod(line.substr(132, 2));
			counter++;
		}
	}

	avgHigh = avgHigh / counter;
	avgLow = avgLow / counter;

	cout << "For: " << stationName << "between March " << startDay << " and March " << endDay << ": " << endl
		<< "Max Temp: " << max << endl
		<< "Min Temp: " << min << endl
		<< "Avg High Temp: " << setprecision(4) << avgHigh << endl
		<< "Avg Low Temp: " << min << endl
		<< "Please choose another option" << endl;
		inFile.close();
}