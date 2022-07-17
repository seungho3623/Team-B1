#include <stdio.h>

int N, K; 
char code[1000 + 10][30 + 5];
int visited[1000 + 10];
int path[1000 + 10];
int A, B;

typedef struct ele {
    int idx;
    int time;
}ELE;

ELE q[100 * 100 + 10];
int rp, wp;

void enq(int idx, int time) {
    q[wp].idx = idx;
    q[wp].time = time;
    wp++;
}

ELE deq() {
    ELE tmp = q[rp];
    rp++;
    return tmp;
}

int isEmpty() {
    return rp == wp;
}

int isHamming(int a, int b) {
    int cnt = 0;
    for (int i = 0; i < K; i++) {
        if (code[a][i] != code[b][i]) cnt++;
        if (cnt > 1) return 0;
    }
    return 1;
}

int BFS(void) {

    enq(A, 1);
    visited[A] = 1;

    while (!isEmpty()) {
        ELE cur = deq();
        if (cur.idx == B) {	
            return cur.time;	
        }
        for (int i = 1; i <= N; i++) {
            if (cur.idx == i) continue;
            if (visited[i] != 0) continue;	

            if (isHamming(cur.idx, i)) {
                visited[i] = 1;	
                path[i] = cur.idx;	
                enq(i, cur.time + 1);	
            }
        }
    }
    return 0;
}

int main(void) {

    int res, k;
    int ans[1000 + 10];
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%s", &code[i]);
    }
    scanf("%d %d", &A, &B);

    res = BFS();
    
    if (res == 0) printf("-1");
    k = B;
    for (int i = 0; i < res; i++) {
        ans[res-1-i] = k;
        k = path[k];
    }
    
    for (int i = 0; i < res; i++) {
        printf("%d ", ans[i]);
    }

    return 0;

}