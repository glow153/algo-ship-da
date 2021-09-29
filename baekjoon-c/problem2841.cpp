#include <iostream>
#define MAX 300000

class Stack{
private:
	int stack[MAX];
	int stkptrTop;
public:
	Stack(){
		for(int i=0;i<MAX;i++)
			stack[i] = 0;
		stkptrTop = -1;
	}
	bool push(int content){
		if(stkptrTop >= MAX - 1)
			return false;
		stack[++stkptrTop] = content;
		return true;
	}
	int pop(){
		if(stkptrTop < 0)
			return -1;
		return stack[stkptrTop--];
	}
	int getTop(){return stack[stkptrTop];}
	bool isStackVoid(){
		return (stkptrTop == -1)?true:false;
	}
};

int main(void){
	int num, max, count=0;
	Stack* stack[6];
	for(int i=0;i<6;i++)
		stack[i] = new Stack();
	scanf("%d %d",&num, &max);
	for(int i=0;i<num;i++){
		int strNum, fret;
		scanf("%d %d",&strNum,&fret);

		while(1){
			if(stack[strNum-1]->isStackVoid() ||
					stack[strNum-1]->getTop() < fret){
				stack[strNum-1]->push(fret);
				count++;
				break;
			}
			else if(stack[strNum-1]->getTop() > fret){
				stack[strNum-1]->pop();
				count++;
				continue;
			}
			else if(stack[strNum-1]->getTop() == fret)
				break;
		}
	}
	printf("%d\n",count);
	return 0;
}