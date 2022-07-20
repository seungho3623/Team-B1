#include <iostream>
#include <string>
using namespace std;



float compare(float* food, int number) {
	float minFood = 0;
	
	for (int i = 1; i < number; i++) {
		if (food[i] >= food[i-1]) {
			minFood = food[i-1];
		}
	}
	return minFood;
}

int main() {
	float pasta[3];
	float juice[2];

	for (int i = 0; i < 3; i++) {
		cin >> pasta[i];
	}
	for (int i = 0; i < 2; i++) {
		cin >> juice[i];
	}

	cout << (compare(pasta, 3) + compare(juice, 2)) * 1.1;
}