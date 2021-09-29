#include <stdio.h>
int main(void){
    int apt[15][14];
    int tc;
    for(int i=0;i<14;i++)
        apt[0][i] = i+1;
    for(int i=1;i<=14;i++){
        //j==0일때
        apt[i][0] = apt[i-1][0];
        //j>0일때
        for(int j=1;j<14;j++)
            apt[i][j] = apt[i-1][j] + apt[i][j-1];
    }

    scanf("%d",&tc);
    for(int t=0;t<tc;t++) {
        int k, n;
        scanf("%d %d",&k, &n);
        printf("%d\n",apt[k][n-1]);
    }
    return 0;
}