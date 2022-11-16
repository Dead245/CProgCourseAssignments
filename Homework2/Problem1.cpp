#include <iostream>;
#include <fstream>;
#include <iomanip>;
using namespace std;

int main(void) {
	char star = '*';
	char blank = ' ';

	int rows = 10;
	int y = rows;
	for (int x = 0; x < rows*2; x += 2) {
		cout << setw(y) << setfill(blank) << star;
		cout << setw(x+1) << setfill(star) << blank << endl;
		y--;
	}
	
	system("pause");
}