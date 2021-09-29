#include <stdio.h>
int main(void) {
    char c;
    while(1) {
        c = getchar();
        if(c == (char)-1)
            break;
        else
            putchar(c);
    }
    return 0;
}