#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int bmiCalc(int weight, int feet, int inches);

int main(void) {
	int weight, heightFeet, heightInches;
	
	cout << "Enter your information correctly to get your Body Mass Index" << endl
		<< "Enter your weight in pounds." << endl;
	cin >> weight;

	cout << endl << "Now, enter your height in feet and inches (Such as an input of '5 4' would be 5 feet and 4 inches)" << endl;
	cin >> heightFeet >> heightInches;

	int bmi = bmiCalc(weight, heightFeet, heightInches);

	cout << endl << "Your BMI based on your inputs: " << bmi << endl << endl;

	system("pause");
}

int bmiCalc(int weight, int feet, int inches) {
	int totalInches = (feet * 12) + inches;
	
	int bmi = weight / pow(totalInches, 2) * 703;
	
	return bmi;
}