//import java.util.*;

public class Week02 {

	public static void main(String[] args) {
		
		int[][] candy = new int[7][7];
		
		for(int i=0;i<=6;i++) {
			for(int j=0;j<=6;j++) {
			candy[i][j] = (int) (Math.random()*5)+1;
			}
		}
		
		boolean[][] visit = new boolean[7][7];
		
		for(int i=0;i<=6;i++) {
			for(int j=0;j<=6;j++) {
			visit[i][j] = false;
			}
		}
		
		
		for(int i=0;i<=6;i++) {
			for(int j=0;j<=6;j++) {
				if(j==6) {
					System.out.print(candy[i][j]+"\n");
				}else {
					System.out.print(candy[i][j]+" ");
				}
			}
				
		}
		
		int count = 0;
		int total = 0;
		int a = 0;
		
		for(int i=0;i<=6;i++) {
			
			for(int j=0;j<=6;j++) {
				
				if(visit[i][j]==false) {
					
					a = candy[i][j];
					
					if(a==candy[i][j+1]) {
						count += 1;
						visit[i][j+1] = true;
					
					}else if(j-1>=0) {
						if(a==candy[i][j-1]) {
							count += 1;
							visit[i][j-1] = true;
						}
					
					}else if(a==candy[i+1][j]) {
						count += 1;
						visit[i+1][j] = true;
					
					}else if(i-1>=0) {
						if(a==candy[i-1][j]) {
							count += 1;
							visit[i-1][j] = true;
						}
					}	
				}
				if(count>=3) {
					total +=1;
				}
				
			}
		}
		
		System.out.println("터치 가능 개수: "+total);
		
		
		
	}

}
