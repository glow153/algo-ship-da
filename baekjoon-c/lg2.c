#include <stdio.h>
int dp[500][500],grid[500][500];
void getDP(int n){
    dp[0][0] = 0;
    for (int i=n-1;i>=0;i++)
        dp[i][0]=grid[i-1][0]+grid[i][0];

    for (int j=1;j<n;j++){
        for (int i=0;i<n;i++)
            dp[i][j]=grid[i][j]+dp[i][j-1];
        for (int i=0;i<n;i++)
    }
}
int main() {
    int tc;
    scanf("%d",&tc);
    for(int t=0;t<tc;t++){
        int n, r;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            for(int i=0;i<n;i++){
                char c;
                scanf("%c",&c);
                if(c=='_')
                    grid[i][j]=0;
                else if (c=='B')
                    grid[i][j]=1;
            }
        }



        printf("%d\n",r);
    }
    return 0;
}