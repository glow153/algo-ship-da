#include <stdio.h>
int main(void){
    int tc;
    int a[41][2]={0};
    a[0][0] = 1;
    a[0][1] = 0;
    a[1][0] = 0;
    a[1][1] = 1;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++){
        int n;
        scanf("%d",&n);
        for(int i=2;i<=n;i++){
            a[i][0] = a[i-1][0] + a[i-2][0];
            a[i][1] = a[i-1][1] + a[i-2][1];
        }
        printf("%d %d\n", a[n][0], a[n][1]);
    }
    return 0;
}