#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {
	
	double x, y;

	x = 3.73;
	
	double r = 3 * pow(x, 2) + 5 * x + 1;

	cout << "X = " << x << endl
		<< "3x^2 + 5x + 1 = " << r << endl << endl;

	x = 9.385;

	double s = (pow(x, 2) - 12 * x + 27) / pow(x - 6, 2);
	
	cout << "X = " << x << endl
		<< "(x^2 - 12x + 27) / (x - 6)^2 = " << s << endl << endl;
	
	x = 2.25;
	y = 3.5;

	double t = ((pow(x, 2) + 3) / pow(y, 3)) + ((x + 2) / pow(y, 2)) + (1 / y);

	cout << "X = " << x << endl
		<< "Y = " << y << endl
		<< "((x^2 + 3) / y^3) + ((x + 2) / y^2) + (1 / y) = " << t << endl << endl;

	system("pause");
}