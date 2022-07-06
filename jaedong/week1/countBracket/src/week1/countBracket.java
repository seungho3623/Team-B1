package week1;

import java.util.Scanner;

public class countBracket {
    void countBracket()
    {
        System.out.printf("괄호 입력 : ");  //안내 문구 출력

        Scanner Scan = new Scanner(System.in);
        String input = Scan.next();     //괄호 입력

        int openBracket = 0;
        int closeBracket = 0;

        for(int i = 0; i < input.length(); i++)     //괄호 갯수 count
        {
            if(input.charAt(i) == '(') openBracket++;
            else if(input.charAt(i) == ')') closeBracket++;
        }

        System.out.println("open : " + openBracket + ", close : " + closeBracket);      //결과 출력
    }
}
