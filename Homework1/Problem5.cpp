#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int maximum(unsigned int *random);
int minimum(unsigned int *random);

int main(void) {
	unsigned int random[50];

	for (int i = 0; i <= 50; i++) {
		random[i] = rand() % 100;
	}

	cout << "50 random numbers 0-99:" << endl;
	int iteration = 0;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 10; y++) {
			cout << setw(5) << random[iteration];
			iteration++;
		}
		cout << endl;
	}

	int max = maximum(random);
	int min = minimum(random);

	cout << "Minimum Integer: " << min << endl
		<< "Maximum Integer: " << max << endl << endl;

	system("pause");
}

int maximum(unsigned int *grades) {
	int max = 0;
	for (int i = 0; i < 50; i++) {
		if (grades[i] > max) {
			max = grades[i];
		}
	}

	return max;
}

int minimum(unsigned int *grades) {
	int min = 100;
	for (int i = 0; i < 50; i++) {
		if (grades[i] < min) {
			min = grades[i];
		}
	}

	return min;
}