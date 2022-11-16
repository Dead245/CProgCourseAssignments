#include <iostream>;
#include <fstream>;
#include <iomanip>;
#include <string>;
using namespace std;

int main(void) {
	int hour, min, sec;
	string time;

	cout << "Enter a time in the 12-hour format to get the 24-hour format (Ex: 05:30:50 PM)." << endl;
	getline(cin, time);
	
	hour = stoi(time.substr(0,2));
	min = stoi(time.substr(3,2));
	sec = stoi(time.substr(6,2));
	
	if (time[9] == 'A') {
		if (hour == 12) {
			hour = 0;
		}
		cout << setw(2) << setfill('0') << hour << ':' 
			<< setw(2) << setfill('0') << min << ':'
			<< setw(2) << setfill('0') << sec << endl;
	}
	else if (time[9] == 'P') {
		if (hour != 12) {
			hour += 12;
		}
		cout << setw(2) << setfill('0') << hour << ':'
			<< setw(2) << setfill('0') << min << ':'
			<< setw(2) << setfill('0') << sec << endl;
	}
	else {
		cout << "You have given an incorrect input" << endl;
		system("pause");
		exit(0);
	}
	
	
	system("pause");
}