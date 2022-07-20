#include <iostream>
#include <string>
using namespace std;

int main() {
	int day, num,inDay, outDay = 0;

	cin >> day; //10
	cin >> num; // 7

	string* sit = new string[day];
	
	for (int i = 0; i < day; i++) {
		cin >> sit[i];
	}

	cin >> inDay;
	cin >> outDay;

	int count = 0;
	int move = 0;


	for (int i = inDay - 1; i < outDay-1; i++) {
		for (int j = 0; j < num; j++) {	
			if (sit[i][j] == 'X') {
				count++;
			}
		}
		if (count == 7) {
			cout << -1;
			break;
		}
		count = 0;
	}

	cout << move;







}