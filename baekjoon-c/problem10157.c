#include <stdio.h>
#define DEBUG 0
int row, col;
int co[2];
int min(int a, int b){return a<b?a:b;}
int v(int i){
    if (i<=0)
        return 0;
    else
        return row-1 - 2*(i-1);
}
int h(int i){
    if (i<=0)
        return 0;
    else
        return col-1 - 2*(i-1);
}
int s(int i) {
    return 2*v(i) + 2*h(i);
}

int getCoord(int n) {
    int startNo = 1;
    int shellNo;
    shellNo = (min(row,col) + 1) / 2;
    if(row==col&&row%2&&n==row*col){
        co[0]=row/2+1;
        co[1]=col/2+1;
        return 1;
    }

    for(int i=1;i<=shellNo;i++) {
        startNo += s(i-1);
        if(DEBUG)
            printf("startNo=%d, n=%d, startNo+s(i)=%d\n", startNo, n, startNo+s(i));
        if(startNo <= n && n < startNo + s(i)) {
            if(DEBUG)
                printf("1. startNo=%d\n",startNo);
            if(startNo + v(i) > n) {
                co[0] = i;
                co[1] = i + (n-startNo);
                return 1;
            }
            startNo += v(i);
            if(DEBUG)
                printf("2. startNo=%d\n",startNo);
            if (startNo <= n && n < startNo + h(i)) {
                co[0] = i + (n-startNo);
                co[1] = col - (i-1);
                return 1;
            }
            startNo += h(i);
            if(DEBUG)
                printf("3. startNo=%d\n",startNo);
            if (startNo <= n && n < startNo + v(i)) {
                co[0] = col - (i-1);
                co[1] = row - (n-startNo) - (i-1);
                return 1;
            }
            startNo += v(i);
            if(DEBUG)
                printf("4. startNo=%d\n",startNo);
            if (startNo <= n && n < startNo + h(i)) {
                co[0] = col - (n-startNo) - (i-1);
                co[1] = i;
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int num;
    scanf("%d %d", &col, &row);
    scanf("%d", &num);
    if(num > row*col){
        printf("0\n");
    } else {
        if(getCoord(num))
            printf("%d %d\n", co[0], co[1]);
        else
            printf("0\n");
    }
    return 0;
}
