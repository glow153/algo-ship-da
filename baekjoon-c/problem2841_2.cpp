#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(void){
	int num, max, count=0;
	vector< stack<int> > stk(6);
	cin>>num>>max;
	for(int i=0;i<num;i++){
		int strNum, fret;
		cin>>strNum>>fret;
		while(1){
			if(stk.at(strNum-1).empty() ||
					stk.at(strNum-1).top() < fret){
				stk[strNum-1].push(fret);
				count++;
				break;
			}
			else if(stk.at(strNum-1).top() > fret){
				stk.at(strNum-1).pop();
				count++;
				continue;
			}
			else if(stk.at(strNum-1).top() == fret)
				break;
		}
	}
	printf("%d\n",count);
	return 0;
}