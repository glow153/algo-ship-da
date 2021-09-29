#include <stdio.h>
int main(void) {
    int i;
    scanf("%d",&i);
    while(!(i % 2))
        i /= 2;
    printf("%d\n",i==1 ? 1 : 0);
    return 0;
}