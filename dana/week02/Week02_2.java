import java.util.*;

public class Week02_2 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		int i = sc.nextInt();
		int j = sc.nextInt();
		
		int[][] arr = new int[i][j];
		
		for(int a=0;a<i;a++) {
			String f =sc.next();
			String ff[] = f.split("");
			for(int b=0;b<j;b++) {
				for(int c=0;c<j;c++) {
					arr[a][c] = Integer.parseInt(ff[c]);
				}
			}
		}
		
		System.out.println(arr[0][0]+" "+arr[0][1]+" "+arr[0][2]);

	}

}
