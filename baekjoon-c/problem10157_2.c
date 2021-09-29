#include <stdio.h>
int min(int a, int b){return a<b?a:b;}
int seat[1000][1000]={0}, dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
int r,c,n,cx,cy;
void snail(){
    int dir=0;
    cx=0; cy=r;
    for(int i=1;i<=n;i++){
        int tx=cx+dx[dir], ty=cy+dy[dir];
        if(tx<0||tx>=c||ty<0||ty>=r||seat[tx][ty]!=0)
            dir=(dir+1)%4;
        cx+=dx[dir]; cy+=dy[dir];
        seat[cy][cx]=i;
    }
}
void print(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",seat[i][j]);
        }
        putchar('\n');
    }
}
int main(){
    scanf("%d%d%d",&c,&r,&n);
    if(n>r*c){
        printf("0\n");
    } else {
        snail();
        print();
        printf("%d %d\n", cx+1, r+1-cy);
    }
    
    return 0;
}