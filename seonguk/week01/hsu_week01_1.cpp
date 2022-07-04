//문제
//프로그래밍을 할 때 가장 중요한 것 중 하나가 괄호의 개수를 맞추는 것이다.
//즉, 여는 괄호가 있으면 항상 닫는 괄호가 있고, 닫는 괄호가 있으면 여는 괄호도 있어야 한다.
//올바른 괄호를 확인하기 위해 가장 기본적인 방법 중 하나는 여는 괄호와 닫는 괄호의 개수를 세는 것이다.
//소괄호로 이루어진 문자열을 주어지면 괄호의 개수를 출력하는 프로그램을 작성하시오.
#include<iostream>
#include<string>
using namespace std;

int main() {
	//1.변수 설정
	string strg;
	int startBracket = 0;
	int endBracket = 0;

	//2. ()문자열 입력
	cout << "()가 들어간 문자열을 입력하세요";
	getline(cin, strg);

	//3.문자열 쪼개기
	for (int i = 0; i < strg.size(); i++) {
		if (strg[i] == '(')
			startBracket++;
		else if (strg[i] == ')')
			endBracket++;
	}
	//4.출력
	cout << "( 갯수는" << startBracket << "개 입니다." << endl;
	cout << ") 갯수는" << endBracket << "개 입니다." << endl;

	return 0;
}