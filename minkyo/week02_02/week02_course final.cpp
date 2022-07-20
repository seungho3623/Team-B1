#include <iostream>
#include <string>

using namespace std;

int main() {

	int a[2];

	for (int i = 0; i < 2; i++) {
		cin >> a[i];
	}

	int col = a[0];  // 입력하는 줄의 개수
	int row = a[1];  // 이진 코드의 길이

	string* range = new string[col]; //동적할당

	cout << "코드 입력" << endl;
	for (int i = 0; i < col; i++) {
		cin >> range[i];
	}


	//for (int i = 0; i < col; i++) {
	//	cout << range[i] << endl;
	//}

	int b[2];

	for (int i = 0; i < 2; i++) {
		cin >> b[i];
	}

	int start = b[0] - 1;  // 시작 경로의 코드 번호, 첫번째 코드는 1번째이나 배열에서는 0으로 받아들임
	int end = b[1] - 1;

	//해밍 경로 탐색, 해밍 경로는 해밍 거리가 1인 경로,
	//각 코드의 숫자를 비교해 다를 경우 count++, count가 1일 시 해밍 거리가 1이므로 출력;
	int sameCount = 0;
	int count = 0;

	int minus = 0; 
	while (1) {
		for (int i = 0; i < col; i++) {
			
			for (int j = 0; j < row; j++) {
				if ((start + i) > (col - 1)) { //비교하는 배열의 크기 이상일 경우 앞으로 돌아와서 탐색할 수 있도록 minus 사용
					minus = col;
				}
				else{
					minus = 0;
				}
				if (range[start][j] != range[start + i - minus][j]) {
					count++;
				}
			}
			if (count == 1) {
				if (sameCount == 0) {
					cout << b[0] << " "; //경로가 있을 경우 시작 코드번호 입력
				}
				cout << start + i + 1 - minus << " " ;
				start = start + i - minus;
				count = 0;
				sameCount++;
				break;
			}
			count = 0;
		}
		if (start == (b[0] - 1)) { //start의 값이 변화가 없다면(경로가 없다면) -1 출력 후 반복문 탈출
			cout << -1;
			break;
		}

		else if (start == end) { //해밍 경로를 찾았다면 반복문 탈출
			break;
		}
	}






	delete[] range; // 힙메모리 제거

	return 0;
}