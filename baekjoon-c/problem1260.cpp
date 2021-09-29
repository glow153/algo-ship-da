#include <cstdio>
int adjMtx[1000][1000];
bool visited[1000]={false};

class CArrayQueue{
private:
	int* queue;
	int front;
	int tail;
	int max;
	int size;
public:
	bool v[1000];
	CArrayQueue(int m = 10000) : front(0), tail(0), size(0), max(m) {
		queue = new int[m];
		for(int i=0;i<1000;i++)
			v[i] = false;
	}
	~CArrayQueue(){
		delete queue;
	}
	bool push(int co){
		if((tail+1)%max==front)
			return false;
		queue[tail] = co;
		tail = (tail + 1) % max;
		v[co] = true;
		printf("%d ",co+1);
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

void dfs(int r, int max){
	printf("%d ",r+1);
	visited[r] = true;
	for(int i=0;i<max;i++)
		if(adjMtx[i][r] == 1 && !visited[i])
			dfs(i, max);
}
void bfs(int start, int max){
	CArrayQueue queue;
	queue.push(start);
	for(int i=0;!queue.isEmpty();i++){
		int a = queue.pop();
		for(int j=0;j<max;j++){
			if(adjMtx[j][a] == 1 && !queue.v[j] && j!=a){
				queue.push(j);
			}
		}
	}
}

int main(void){
	int noNode, noEdge, startNum;
	scanf("%d%d%d",&noNode,&noEdge,&startNum);
	for(int t=0;t<noEdge;t++){
		int s,e;
		scanf("%d%d",&s,&e);
		adjMtx[s-1][e-1] = adjMtx[e-1][s-1] = 1;
	}
	dfs(startNum - 1, noNode);
	putchar('\n');
	bfs(startNum - 1, noNode);
	putchar('\n');
	return 0;
}