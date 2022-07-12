import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static int[][] inputBoard(int boardSize)
    {
        Scanner Scan = new Scanner(System.in);
        int[][] board = new int[boardSize][boardSize];

        for(int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                board[i][j] = Scan.nextInt();
            }
        }
        return board;
    }

    public static int checkCandy(int[][] board, boolean[][] visited, Stack stack)
    {
        int result = 0;
        for(int i = 0; i < board.length; i++)
        {
            for(int j = 0; j < board[i].length; j++)
            {
                result += dfs(i, j, board, visited, stack);
            }
        }
        return result;
    }

    public static int dfs(int i, int j, int[][] board, boolean[][] visited, Stack stack)
    {
        int sameBlock = 0;

        stack.push(new int[]{i, j});
        while(!stack.empty())
        {
            int[] location = (int[]) stack.pop();

            if(!visited[location[0]][location[1]])
            {
                visited[location[0]][location[1]]= true;
                sameBlock ++;

                if(location[0] - 1 >= 0)    //상 확인
                {
                    if (board[location[0]][location[1]] == board[location[0] - 1][location[1]])
                    {
                        stack.push(new int[]{location[0] - 1, location[1]});
                    }
                }

                if(location[0] + 1 < board.length)  //하 확인
                {
                    if (board[location[0]][location[1]] == board[location[0] + 1][location[1]])
                    {
                        stack.push(new int[]{location[0] + 1, location[1]});
                    }
                }

                if(location[1] - 1 >= 0)    //좌 확인
                {
                    if (board[location[0]][location[1]] == board[location[0]][location[1] - 1])
                    {
                        stack.push(new int[]{location[0], location[1] - 1});
                    }
                }

                if(location[1] + 1 < board.length)  //우 확인
                {
                    if (board[location[0]][location[1]] == board[location[0]][location[1] + 1])
                    {
                        stack.push(new int[]{location[0], location[1] + 1});
                    }
                }
            }
        }
        if(sameBlock >= 3) return 1;
        else return 0;
    }

    public static void main(String[] args) {
        System.out.println("7 X 7 게임 판을 입력하세요. (1 ~ 5)");

        int boardSize = 7;
        boolean[][] visited = new boolean[boardSize][boardSize];
        Stack<Integer[]> stack = new Stack<>();

        int[][] board = inputBoard(boardSize);
        int result = checkCandy(board, visited, stack);

        System.out.println(result);
    }
}