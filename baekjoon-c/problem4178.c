#include <stdio.h>
int main(void){
    int m, n;
    int ocnt = 0, rcnt = 0;
    char board[2000][2000] = {(char)0};
    int or[2000] = {0};
    int oc[2000] = {0};
    int xr[2000] = {0};
    int xc[2000] = {0};
    int olu2rd = 0, oru2ld = 0, xlu2rd = 0, xru2ld = 0;

    // input
    scanf("%d %d", &m, &n);
    for (int i=0;i<m;i++){
        char line[2000];
        scanf("%s", line);

        for (int j=0;j<n;j++){
            switch(board[i][j]){
                case 'O':
                    ocnt++;
                    or[i]++;
                    oc[j]++;
                    if(i==j) olu2rd++;
                    if(i==j) oru2ld++;
                    break;
                case 'X':
                    xcnt++;
                    xr[i]++;
                    xc[j]++;
                    if(i==j) xlu2rd++;
                    break;
                case '.':
                default:
                    break;
            }
        }
    }

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            switch(board[i][j]){
            case 'O':
                or[i]++;
                oc[j]++;
                if(i==j) olu2rd++;
                if(i==j) oru2ld++;
                break;
            case 'X':
                xr[i]++;
                xc[j]++;
                if(i==j) xlu2rd++;
                break;
            case '.':
            default:
                break;
            }
        }
    }

    // judge


    return 0;
}