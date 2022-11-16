#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {
	
	int start, ending, increment;

	cout << "A table will be created showing the Fahrenheit and Kelvin versions of the temperatures after you give the Celsius inputs." << endl
		<< endl << "What degree Celsius would the table start at? ";
	cin >> start;

	cout << endl << "What degree Celsius would the table end at? ";
	cin >> ending;

	cout << endl << "How much should the table increment per row? ";
	cin >> increment;

	//The start of the table
	cout << left << endl
		<< setw(20) << "Celsius" << setw(20) << "Fahrenheit" << setw(20) << "Kelvin" << endl;
	
	double fahren, kelvin;
	for (int cel = start; cel <= ending;cel += increment) {
		//Calculation of Fahrenheit and Kelvin variants
		fahren = (9 / 5) * cel + 32;
		kelvin = 273.15 + cel;
		
		//Prints out line of Celsius, Fahrenheit, and Kelvin
		cout << setprecision(2) << left << fixed
			<< setw(20) << cel << setw(20) << fahren << setw(20) << kelvin << endl;

	}
	
	system("pause");
}