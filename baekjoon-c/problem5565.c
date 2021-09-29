#include <stdio.h>
int main(void) {
    int sum;
    scanf("%d",&sum);
    for(int i=0;i<9;i++){
        int n;
        scanf("%d", &n);
        sum-=n;
    }
    printf("%d\n",sum);
    return 0;
}