#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(void) {
	int amountOfGrades = 0;
	int lowestGrade = 100;
	int grades[100];

	cout << "Enter grades (0 - 100) to find their average, the lowest grade will be dropped from calculation." << endl << "Enter any letter to quit." << endl;
	
	int i = 0;
	
	do {
		cin >> grades[i];
		if (grades[i] == NULL) {
			break;
		}
		
		amountOfGrades++;
		
		if (grades[i] < lowestGrade) {
			lowestGrade = grades[i];
		}
		
		i++;

	} while (grades[i] != NULL);

	// prints grades and creates Total with dropped grade
	int total = 0;
	cout << endl << "Inputted Grades: " << endl;
	for (int z = 0; z < i; z++) {
		cout << grades[z] << endl;
		total += grades[z];
	}
	cout << "Dropped Grade: " << lowestGrade << endl << endl;
	
	//Calculate and print average
	total -= lowestGrade;									//removes dropped grade amount
	double average = total / (amountOfGrades - 1);			//Subtracts 1 from amountOfGrades to remove dropped grade
	
	cout << "Final Average : " << average << endl << endl;	//Prints average rounded down to nearest whole integer

	system("pause");
}