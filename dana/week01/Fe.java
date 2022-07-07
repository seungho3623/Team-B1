import java.util.*;

public class Fe {

	public static void main(String[] args) {
		
		System.out.println("괄호를 입력하세요.(길이 100,000 이하)");

		Scanner sc = new Scanner(System.in);
		
		String g = sc.next();
		
		char[] gg = g.toCharArray();
		
		int tot = 0;
		int ct;
		
		for(int i=0;i<g.length();i++) {
			if(gg[i]=='(' && gg[i+1]==')') {
				ct=0;
				int a = i;
				int b = i;
				while(a>0) {
					if(gg[a-1]=='(') {
						ct++;
						a--;
					}else if(gg[a-1]!='(') {
						a=0;
					}
				}
				
				while(b+2<g.length()) {
					if(gg[b+2]==')') {
						ct++;
						b++;
					}else if(gg[b+2]!=')') {
						b=g.length();
					}
				}
				tot = tot+ct;
				
				if(i+3<g.length()) {
					if(gg[i+2]=='(' && gg[i+3]==')') {
						tot = tot+ct;
					}
				}
			}
			
		}
		
		System.out.println(g.length());
		System.out.println(tot);
		
	}

}
