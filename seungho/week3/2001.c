#include <stdio.h>

int main(){
    int buf;

    int pasta = 2000, juice = 2000;

    for(int i = 0; i < 5; i++){
        if(i < 3){
            scanf("%d", &buf);
            if(pasta > buf) pasta = buf;
        }
        else{
            scanf("%d", &buf);
            if(juice > buf) juice = buf;
        }
    }

    printf("%.1f", (float)(pasta + juice) * 1.1);
}