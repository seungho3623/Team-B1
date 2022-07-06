#include <iostream>
#include <string>
using namespace std;

int main() {
	int cutCount = 0;
	int closeCount = 0;

	string stick;
	getline(cin, stick);
	int sSize = stick.size();
	
	for (int i = 0; i <= sSize; i++) {
		if ((stick[i] == '(') && (stick[i + 1] == '(')) {
			int openCount = 0;
			for (int j = i; j <= sSize; j++) {
				if ((stick[j] == '(') && (stick[j + 1] == '(')) {
					openCount += 1;
				}
				if ((stick[j] == '(') && (stick[j + 1] == ')')) {
					cutCount++;
				}
				if ((stick[j] == ')') && (stick[j + 1] == ')')) {
					openCount--;
					if (openCount == 0) {
						cutCount++;
						break;
					}
				}
			}
		}
	}
	cout  << cutCount;
	return 0;
}



