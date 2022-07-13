#include <stdio.h>

#define COL 7
#define ROW 7

int buf[ROW][COL];

int result(int x, int y, int data, int *count)
{
    if(x == -1 || x == 7 || y == -1 || y == 7) return ;
    
    if(buf[x][y] != data) return ;
    
    if(buf[x][y] == data){
        buf[x][y] = 0;
        *count += 1;

        result(x, y + 1, data, count);
        result(x, y - 1, data, count);
        result(x - 1, y, data, count);
        result(x + 1, y, data, count);
    }
}

int main(){
    int cnt = 0, flag = 0, i, j;
    
    for(i = 0; i < sizeof(buf) / sizeof(buf[0]); i++){
        for(j = 0; j < sizeof(buf[i]) / sizeof(int); j++){
            scanf("%d", &buf[i][j]);
        }
    }

    for(i = 0; i < sizeof(buf) / sizeof(buf[0]); i++){
        for(j = 0; j < sizeof(buf[i]) / sizeof(int); j++){
            if(buf[i][j] != 0){
                flag = 0;

                result(i, j, buf[i][j], &flag);
            
                if(flag >= 3){
                    cnt++;
                }
            }
        }
    }

    printf("%d", cnt);
}