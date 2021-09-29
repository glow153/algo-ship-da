#include <stdio.h>
int s[50000]={0};
int top=-1;
void push(){
    top++;
    s[top]=1;
}
void pop(){
    s[top]=0;
    top--;
}
int main(){
    int n=0;
    int lastOp=0;//push:1,pop:2
    while(1){
        char c = getchar();
        if(c=='('){
            push();
            lastOp=1;
        }else if(c==')'){
            pop();
            if(lastOp==1){
                n+=(top+1);
            }else if(lastOp==2){
                n++;
            }
            lastOp=2;
        }else{
            break;
        }
    }
    printf("%d\n",n);
    return 0;
}