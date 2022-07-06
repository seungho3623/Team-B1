package countStick;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static int startIndex = 0;   //'(' index
    public static int totalPiece = 0;   //총 막대기 갯수

    public static ArrayList<Integer> openBracketList = new ArrayList<>();   //막대기 start index 판단하기 위한 '(' index 배열
    public static ArrayList<Laser> laserList = new ArrayList<>();   //레이저 객체 배열
    public static ArrayList<Stick> stickList = new ArrayList<>();   //막대기 객체 배열

    private static void checkBracket(String input, int i)
    {
        if(input.charAt(i) == '(')
        {
            startIndex = i;
            openBracketList.add(i);     //'(' 배열에 추가
        }
        else if(input.charAt(i) == ')')
        {
            int len = openBracketList.size() - 1;
            if(startIndex == i - 1)     //"()" 인 경우 (레이저)
            {
                laserList.add(new Laser(startIndex));   //레이저 객체 배열에 추가
            }
            else    //아닌 경우 (막대기)
            {
                stickList.add(new Stick(openBracketList.get(len), i));  //막대기 객체 배열에 추가
            }
            openBracketList.remove(len);    //'(' 배열에서 pop
        }
    }
    public static void main(String[] args) {
        System.out.print("막대 입력 : ");

        Scanner Scan = new Scanner(System.in);
        String input = Scan.next();

        if(input.length() > 100000) input = input.substring(0, 100000);

        for(int i = 0; i < input.length(); i ++)
        {
            checkBracket(input, i);
        }

        for(int i = 0; i < stickList.size(); i++)
        {
            int thisStickPiece = 0;
            for(int j = 0; j < laserList.size(); j++)
            {   //막대기 start와 end 사이에 레이저가 있을 경우 조각 추가
                if((laserList.get(j).getStart() > stickList.get(i).getStart()) && (laserList.get(j).getStart() < stickList.get(i).getEnd()))
                {
                    thisStickPiece ++;
                }
            }
            totalPiece += thisStickPiece + 1;
        }
        System.out.print(totalPiece);
    }
}
