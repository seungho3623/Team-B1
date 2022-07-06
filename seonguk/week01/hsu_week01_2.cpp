//문제
//여러 개의 쇠막대기를 레이저로 절단하려고 한다.효율적인 작업을 위해서 쇠막대기를 아래에서 위 로 겹쳐 놓고, 레이저를 위에서 수직으로 발사하 여 쇠막대기들을 자른다.쇠막대기와 레이저의 배 치는 다음 조건을 만족한다.
//- 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다.
//- 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완 전히 포함되도록 놓되, 끝점은 겹치지 않도록 놓는다.
//- 각 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
//- 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다.
//
//이러한 레이저와 쇠막대기의 배치는 다음과 같이 괄호를 이용하여 왼쪽부터 순서대로 표현할 수 있 다.
//(a)레이저는 여는 괄호와 닫는 괄호의 인접한 쌍 ‘() ’ 으로 표현된다.또한, 모든 ‘() ’는 반드 시 레이저를 표현한다.
//(b)쇠막대기의 왼쪽 끝은 여는 괄호 ‘(’ 로, 오 른쪽 끝은 닫힌 괄호 ‘) ’ 로 표현된다.
//
//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 이 주어졌을 때, 잘려진 쇠막대기 조각의 총 개수 를 구하는 프로그램을 작성하시오.
#include<iostream>
#include<string>
using namespace std;

int main() {
	//1.변수 설정
	string strg;
	int startBracket = 0;
	int result = 0;

	//2. ()문자열 입력
	cout << "()가 들어간 문자열을 입력하세요";
	getline(cin, strg);

	//3.문자열 쪼개기
	for (int i = 0; i < strg.size(); i++) {
		if (strg[i] == '(')
			startBracket++;
		else if (strg[i] == ')') {
			if (strg[i - 1] == '(') {
				startBracket--;
				result += startBracket;
				
			}
			else {
				result++;
				startBracket--;
			}
		}
			
	}
	//4.출력
	cout << "파이프 갯수는" << result << "개 입니다." << endl;

	return 0;
}