//문제
//캔디팡은 7 * 7 모양의 격자 판에 같은 색깔이 연속 3개 이상인 부분을 찾아 터치하면 터지면서 점수를 얻는 게임이다.이때 연속된 부분은 상, 하, 좌, 우만 판단한다.
//위 캔디팡 화면에서 터치하면 터지는 영역은 총 4군데 존재한다.
//캔디팡 격자 정보가 주어졌을 때 터치하면 터지는 영역의 개수를 출력하는 프로그램을 작성하시오.
//
//캔디팡 격자판(7 * 7)의 색깔 정보(1~5)가 입력된다.
//※ 색깔정보
//빨강 = 1, 노랑 = 2, 파랑 = 3, 초록 = 4, 보라 = 5

#include<iostream>
using namespace std;
//지역 변수 설정
const int max_row = 7; //최대 열값
const int max_col = 7; //최대 행값
int candyBoard[max_row][max_col] = {0}; //캔디팡용 색깔(숫자)를 입력할 배열
int checkBoard[max_row][max_col] = {0}; //확인 했는지 체크할 배열

//주변 확인용 함수
int checkPoint(int row,int col) {
	int count = 1; //같은 색깔 블럭 확인
	int color = candyBoard[row][col]; //색깔 저장용 변수
	checkBoard[row][col] = 1; //확인한 타일 체크

	//index하나씩 늘려가며 같은 숫자 있는 지 확인(재귀함수 이용)
		if (color == candyBoard[row + 1][col] && row < max_row - 1) {
			if (color == candyBoard[row + 2][col] && row < max_row - 2 && checkBoard[row+2][col]==0) {
				count++;
				count += checkPoint(row + 1, col);
			}if (color == candyBoard[row + 1][col + 1] && col < max_col - 1 && checkBoard[row + 1][col + 1] == 0) {
				count++;
				count += checkPoint(row + 1, col);
			}if (color == candyBoard[row + 1][col - 1] && col > 0 && checkBoard[row + 1][col - 1] == 0) {
				count++;
				count += checkPoint(row + 1, col);
			}
		}
		if (color == candyBoard[row - 1][col] && row > 0) {
			if (color == candyBoard[row - 2][col] && row > 1 && checkBoard[row - 1][col] == 0) {
				count++;
				count += checkPoint(row - 1, col);
			}if (color == candyBoard[row - 1][col + 1] && col < max_col - 1 && checkBoard[row - 1][col + 1] == 0) {
				count++;
				count += checkPoint(row - 1, col);
			}if (color == candyBoard[row - 1][col - 1] && col > 0 && checkBoard[row - 1][col - 1] == 0) {
				count++;
				count += checkPoint(row - 1, col);
			}
		}
		if (color == candyBoard[row][col + 1] && col < max_col - 1) {
			if (color == candyBoard[row - 1][col + 1] && row > 0 && checkBoard[row - 1][col + 1] == 0) {
				count++;
				count += checkPoint(row, col + 1);
			}if (color == candyBoard[row + 1][col + 1] && row < max_row - 1 && checkBoard[row + 1][col + 1] == 0) {
				count++;
				count += checkPoint(row, col + 1);
			}if (color == candyBoard[row][col + 2] && col < max_col - 2 && checkBoard[row][col + 2] == 0) {
				count++;
				count += checkPoint(row, col + 1);
			}
		}
		if (color == candyBoard[row][col - 1] && col > 0) {
			if (color == candyBoard[row + 1][col - 1] && row < max_row - 1 && checkBoard[row + 1][col - 1] == 0) {
				count++;
				count += checkPoint(row, col - 1);
			}if (color == candyBoard[row - 1][col - 1] && row > 0 && checkBoard[row - 1][col - 1] == 0) {
				count++;
				count += checkPoint(row, col - 1);
			}if (color == candyBoard[row][col - 2] && col > 1 && checkBoard[row][col - 2] == 0) {
				count++;
				count += checkPoint(row, col - 1);
			}
		}
	return count;
}



int main() {
	int point = 0;
	//타일 채우기(입력 받기)
	cout << "타일 입력" << "\n";
	for (int i = 0; i < max_row; i++)
		for (int j = 0; j < max_col; j++)
			cin >> candyBoard[i][j];
	//타일 확인
	for (int i = 0; i < max_row; i++) {
		for (int j = 0; j < max_col; j++) {
			if(checkPoint(i, j)>=3) //count(같은 색깔) 갯수가 3개 이상일시 +1 point
				point++;
		}
	}
	//출력
	cout << point;
	return 0;
}