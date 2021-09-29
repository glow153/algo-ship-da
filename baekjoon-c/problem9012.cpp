#include <cstdio>
#include <cstring>
#define MAX 25
class Stack{
private:
	bool stack[MAX];
	int stkptrTop;
public:
	Stack(){
		for(int i=0;i<MAX;i++){
			stack[i] = false;
		}
		stkptrTop = -1;
	}
	bool push(){
		if(stkptrTop + 1 > MAX - 1)
			return false;
		stack[++stkptrTop] = true;
		return true;
	}
	bool pop(){
		if(stkptrTop < 0)
			return false;
		stack[stkptrTop--] = false;
		return true;
	}
	bool isStackVoid(){
		return (stkptrTop == -1)?true:false;
	}
};
int main(void){
	Stack* s;
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++){
		s = new Stack();
		char sInput[50];
		int len;
		scanf("%s",sInput);
		len = strlen(sInput);
		bool bPrinted = false;
		for(int i=0;i<len;i++){
			if(sInput[i] == '('){
				if(!s->push()){
					printf("NO\n");
					bPrinted = true;
					break;
				}
			}
			else if(sInput[i] == ')'){
				if(!s->pop()){
					printf("NO\n");
					bPrinted = true;
					break;
				}
			}
			else{
				break;
			}
		}
		if(!bPrinted)
			printf("%s\n",s->isStackVoid()?"YES":"NO");
		delete(s);
	}
	return 0;
}