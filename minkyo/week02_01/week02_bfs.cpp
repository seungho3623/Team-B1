// 캔디팡 강민교
// 여러줄 겹쳤을때 중복해서 터지는 오류가 있네요

#include <iostream>
#include <string>
using namespace std;


int main() {


	int grid[7][7]; // 7*7 캔디팡 정보를 입력하는 배열 생성 
	int gid[7];
	for (int i = 0; i < 7; i++) { //배열에 캔디팡 정보 입력 
		for (int j = 0; j < 7; j++) {
			//	cout << "입력" << j << " : ";
			cin >> gid[j];
			grid[i][j] = gid[j];
		}
	}

	//for (int i = 0; i < 7; i++) {		 // 배열에 잘 입력되었는지 확인
	//	for (int j = 0; j < 7; j++) {

	//		cout << grid[i][j];
	//	}
	//	cout << endl;
	//}

	int count = 0;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if((grid[i][j] != grid[i - 1][j]) && ((j==0)||(grid[i][j] != grid[i][j-1]))) // 겹치는 부분을 우측과 하단만 비교하므로 상단 및 좌측 비교 생략


				if (grid[i][j] == grid[i + 1][j]) // 세로로 같으면 밑의 블럭과 주위의 블럭 비교 
				{
					if (grid[i + 1][j] == grid[i + 2][j] // 아래
						|| (grid[i + 1][j] == grid[i][j - 1] && (i != 0))      // 좌측 위
						|| (grid[i + 1][j] == grid[i + 1][j - 1] && (i != 0))  // 좌측 아래
						|| (grid[i + 1][j] == grid[i + 1][j + 1] && (i != 6))  // 우측 아래
						|| (grid[i + 1][j] == grid[i][j + 1] && (i != 6)))     // 우측 위
					{
						cout << "1조건 " << i << " " << j << endl;
						count++;
					}
				}

				else if ((grid[i][j] == grid[i][j + 1])) // 가로로 같으면 우측의 블럭 비교
				{
					if ((grid[i][j + 1] == grid[i][j + 2]) && (j != 5) && (j != 6))  // 우측과 비교 ㅡㅡㅡ모양 
					{
						cout << "2조건 " << i << " " << j << endl;
						count++;
					}

				}
			
		}

	}
		cout << "터질 수 있는 개수 : " << count;
	
}
