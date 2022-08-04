#include<stdio.h>

int risawa(int m, int n){
    if(m == 0){ //0丁目
        return n+1; //n+1リサワ
    }
    else if(n == 0){ //0番地
        return risawa(m-1, 1);
    }
    else {
        return risawa(m-1, risawa(m, n-1));
    }
}

int main(void){
    int m, n;
    printf("m丁目？"); scanf("%d", &m);
    printf("n番地？"); scanf("%d", &n);
    printf("%d丁目%d番地のリサワ数は%dです。\n", m, n, risawa(m, n));
    return 0;
}