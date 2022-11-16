/*
Author: Colton Higgins
Last Modified: Febuary 2, 2019
Description: Converts binary to decimal
*/
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

int convertToDecimal(string binary);

int main(void) {
	string binaryOne = "100100101", binaryTwo = "010000", binaryThree = "0100";
	int decimal;

	decimal = convertToDecimal(binaryOne);
	cout << binaryOne << " is: " << decimal << endl;
	
	decimal = convertToDecimal(binaryTwo);
	cout << binaryTwo << " is: " << decimal << endl;
	
	decimal = convertToDecimal(binaryThree);
	cout << binaryThree << " is: " << decimal << endl;
	
	system("pause");
}

//Using the mathematical route to convert binary to decimal
int convertToDecimal(string binary) {
	string temp;
	int decimal = 0, tempInt, y = 0;
	for (int x = binary.length() - 1; x >= 0; x--) {
		temp = binary.substr(y,1);
		tempInt = stoi(temp);
		decimal += tempInt * pow(2,x);
		y++;
	}
	return decimal;
}