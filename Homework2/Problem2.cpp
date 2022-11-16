#include <iostream>;
#include <fstream>;
#include <iomanip>;
using namespace std;

int main(void) {
	cout << setw(20) << "Values of 2^n" << endl;

	int rows = 63;

	for (int i = 0; i <= rows; i++) {
		cout << fixed << setw(2) << i << ":" << setw(20) << setprecision(0) << pow(2,i) << endl;
	}

	system("pause");
}