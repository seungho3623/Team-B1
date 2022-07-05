#include <stdio.h>
#include <string.h>
 
int main(){
    char buf[100001];

    int right = 0;
    int left = 0;
    //u_int8_t flag = 0;

    scanf("%s", buf);

    for (int i = 0; i < strlen(buf); i++){
        if (buf[i] == '('){
            left++;
        }

        else if(buf[i] == ')'){
            right++;
        }
    }
    
    if(right == left){
        printf("%d %d", right, left);
    }
    else{
        printf("false");
    }
    
    return 0;
}