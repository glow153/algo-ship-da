#include <iostream>
#include <cstring>
using namespace std;
class CArrayQueue{
private:
	int* queue;
	int front;
	int tail;
	int max;
	int size;
public:
	CArrayQueue(int m = 10000) : front(0), tail(0), size(0), max(m) {
		queue = new int[m];
	}
	~CArrayQueue(){
		delete queue;
	}
	bool push(int co){
		if((tail+1)%max==front)
			return false;
		queue[tail] = co;
		tail = (tail + 1) % max;
		size++;
		return true;
	}
	int pop(){
		int content;
		if(front == tail)
			return -1;
		content = queue[front];
		front = (front+1) % max;
		size--;
		return content;
	}
	bool isEmpty(){return (front == tail && size == 0);}
	bool isFull(){return size == max;}
	int getFront(){return queue[front];}
	int getBack(){
		int idx = (tail - 1) % max;
		return queue[idx];
	}
	int getSize(){return size;}
};

int main(void){
	int numofCmd;
	CArrayQueue q(10000);
	cin>>numofCmd;
	for(int tc = 0; tc < numofCmd; tc++){
		char cmd[6];
		int output;
		cin>>cmd;
		if(!strcmp(cmd, "push")){
			int content;
			cin>>content;
			q.push(content);
			continue;
		}
		else if(!strcmp(cmd, "pop"))
			output = q.pop();
		else if(!strcmp(cmd, "size"))
			output = q.getSize();
		else if(!strcmp(cmd, "empty"))
			output = q.isEmpty()?1:0;
		else if(!strcmp(cmd, "front"))
			output = q.isEmpty()?-1:q.getFront();
		else if(!strcmp(cmd, "back"))
			output = q.isEmpty()?-1:q.getBack();
		cout<<output<<endl;
	}
	return 0;
}