//문제 (codeUP 4685)
//길이가 같은 두 개의 이진수 코드 A와 B가 있다고 하자.이 두 코드 사이의 해밍 거리는 A와 B의 각 비트를 왼쪽부터 오른쪽으로 차례대로 비교할 때 서로 다른 값을 가진 비트의 수이다.예를 들어, A = 010010, B = 011011 이라고 하면, 세 번째 비트와 여섯 번째 비트만 서로 다르므로 이 두 코드 사이의 해밍 거리는 2이다.
//우리는 총 N개의 이진 코드를 가지고 있고, 각 코드의 길이는 K로 같다.
//예를 들어, 다음과 같이 길이가 3인 5개의 이진 코드들이 있다.
//A = 000, B = 111, C = 010, D = 110, E = 001
//두 코드 A와 B사이의 해밍 거리를 H(A, B)로 표현한다.그러면, H(A, B) = 3, H(A, C) = 1, H(A, D) = 2, H(A, E) = 1 이다.
//우리는 이진 코드들에 대해 해밍 경로를 찾고자 한다.해밍 경로는 모든 인접한 두 코드사이의 해밍 거리가 1인 경로이다.위의 예에서(A, C, D)는 코드 와 의 해밍 거리가 1이고, 코드 C와 D의 해밍 거리가 1이므로 해밍 경로이다. (A, E, B)는 코드 A와 E의 해밍 거리는 1이지만, 코드 E와 B의 해밍 거리가 2이므로 해밍 경로가 아니다.
//이 문제는 주어진 두 코드 사이에 가장 짧은 해밍 경로를 구하는 프로그램을 작성하는 것이다.
//입력
//첫째 줄에는 두 개의 정수 N과 K가 빈칸을 사이에 두고 주어진다(3≤N≤1, 000, 2≤K≤30).
//둘째 줄부터 N개의 줄에는 각 줄마다 길이가 K인 이진 코드가 하나씩 주어진다.하나의 코드는 빈칸이 없이 주어진다.코드들은 주어진 순서대로 1부터 N까지의 번호로 구분된다.코드가 같은 경우는 없다.
//그 다음 줄에는 해밍 경로를 찾고자 하는 서로 다른 두 개의 코드 A와 B가 각각의 코드번호로 주어진다.
//출력
//입력으로 주어진 두 코드 사이에 해밍 경로가 존재하면 그 경로 중 가장 짧은 경로를 코드 A부터 코드 B까지 경로상의 코드 번호로 출력한다.코드 번호를 출력할 경우에는 코드 번호 사이에 하나의 빈칸을 사이에 두고 출력한다.만약 답이 여러 개 있으면 그 중에 하나만 출력하고, 경로가 존재하지 않으면 - 1을 출력한다.
#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;


vector<int> hamingCheck;
//거리확인하여 이동된 인덱스 체크

//인덱스 크기 확인 후 값에 맞게 증가 시키기
int checkSize(int &number, int &vectorSize) {
	number++;
	if (number >= vectorSize)
		number = number - vectorSize;

	return number;
}

//인덱스를 다 확인했는지 확인 후 했으면 반복분을 탈출 할 수 있는 함수(hamingCheck이용)
bool checkPrime(int number) {
	bool prime = true;
	for (int k = 0; k < number; k++) {
		if (hamingCheck[k]==1)
			prime = false;
		else {
			prime = true;
			break;
		}
	}
	return prime;
}
//길이 확인해서 1인 것만 출력
int hamingDistance(vector<string> &haming,int &number,int &length,int &startNumber, int &endNumber,int end) {
	int distance = 0;
	bool vectorPrime = true;
	while (vectorPrime) {
		if (hamingCheck[startNumber]==1) {
			vectorPrime =checkPrime(number);
			if (vectorPrime)
				continue;
			checkSize(startNumber, number);
		}
		else if (hamingCheck[endNumber]==1)
			checkSize(endNumber, number);
		else {//해밍 거리 확인
			for (int i = 0; i < length; i++) {
				if (haming[startNumber][i] != haming[endNumber][i])
					distance++;
			}

			//해밍 거리가 1이되면,
			if (distance == 1) {
				cout << startNumber+1 << " ";
				hamingCheck[startNumber] = 1;
				startNumber = endNumber;
				if (startNumber==end) {
					return end + 1; //도착 인덱스 확인했으면 함수 탈출
				}
				checkSize(endNumber, number);
				if (startNumber == endNumber)
					checkSize(endNumber, number);
				hamingDistance(haming, number, length, startNumber, endNumber,end);
				
			}//1이 아니면,
			else  {
				checkSize(endNumber, number);
				if (startNumber == endNumber)
					checkSize(endNumber, number);
				hamingDistance(haming, number, length, startNumber, endNumber,end);
			}
		}
	}
	//반복문 조건 안맞으면 -1 출력
	return -1;
}


int main() {
	//변수 설정
	int length;
	int number;
	vector<string> haming;
	string s;
	int startNumber, endNumber;
	//값 입력받기
	cin >> number >> length;

	for (int i = 0; i < number; i++) {
		cin >> s;
		haming.push_back(s); //값 넣은 vector
		hamingCheck.push_back(0); //체크한지 확인하기 위한 vector
	}

	cin >> startNumber >> endNumber;
	startNumber--; //입력시, index +1값 들어와서 수정하는 부분
	endNumber-- ;

	//거리 구하기
	const int end = endNumber; //경로가 끝나는 부분 설정
	cout <<hamingDistance(haming, number, length, startNumber, endNumber,end);
	
	return 0;
}