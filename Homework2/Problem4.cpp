#include <iostream>;
#include <fstream>;
#include <iomanip>;
#include <string>;
using namespace std;

int main(void) {
	ifstream inFile;
	inFile.open("temps.txt");
	
	if (!inFile) {
		cout << "Unable to open input file.";
		return 1;
	}

	float cel[100], far[100], kel[100];
	
	int x = 0;
	string line;
	
	while (!inFile.eof()) {
		inFile >> cel[x];
		far[x] = ((9.0/5.0)  * cel[x]) + 32;
		kel[x] = cel[x] + 273.15;
		x++;
	}
	
	inFile.close();
	ofstream outFile;
	outFile.open("table.txt");
	
	if (!outFile) {
		cout << "Unable to open output file.";
		return 1;
	}

	outFile << setw(15) << "Celsius"
		<< setw(15) << "Fahrenheit"
		<< setw(15) << "Kelvin"
		<< endl;
	for (int y = 0; y < x; y++) {
		outFile << fixed << setprecision(2)
			<< setw(15) << cel[y]
			<< setw(15) << far[y]
			<< setw(15) << kel[y]
			<< endl;
	}
	
	outFile.close();
	system("pause");
}