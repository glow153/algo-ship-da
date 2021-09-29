#include <iostream>
#define QSIZE 100
using namespace std;
bool maze[100][100] = {false};
bool visited[100][100] = {false};
typedef struct _Coord{
	int row;
	int col;
}Coord;
class CoArrayQueue{
private:
	Coord* queue;
	int front;
	int tail;
	int max;
	int size;
public:
	CoArrayQueue(int m = QSIZE) : front(0), tail(0), size(0), max(m) {
		queue = new Coord[m];
	}
	~CoArrayQueue(){
		delete queue;
	}
	bool enqueue(int r, int c){
		if((tail+1)%max==front)
			return false;
		queue[tail].row = r;
		queue[tail].col = c;
		tail = (tail + 1) % max;
		size++;
		return true;
	}
	bool enqueue(Coord co){
		if((tail+1)%max==front)
			return false;
		queue[tail] = co;
		tail = (tail + 1) % max;
		size++;
		return true;
	}
	Coord dequeue(){
		Coord content = {0,0};
		if(front == tail)
			return content;
		content = queue[front];
		front = (front+1) % max;
		size--;
		return content;
	}
	bool isEmpty(){return (front == tail && size == 0);}
	bool isFull(){return size == max;}
	Coord getFront(){return queue[front];}
	int getSize(){return size;}
};

int bfs(int rsize, int csize){
	int exitR = rsize - 1, exitC = csize - 1;
	CoArrayQueue q(10);
	q.enqueue(0,0);
	visited[0][0] = true;
	for(int count = 1;;count++){
		int len = q.getSize();
		for(int i=0;i<len;i++){
			Coord co = q.dequeue();
			if(co.row+1<rsize && maze[co.row+1][co.col]){ //search down
				if(exitR == co.row+1 && exitC == co.col){
					return count + 1;
				} else if(visited[co.row+1][co.col] == false) {
					q.enqueue(co.row+1, co.col);
					visited[co.row+1][co.col] = true;
				}
			}
			if(co.col+1<csize && maze[co.row][co.col+1]){ //search right
				if(exitR == co.row && exitC == co.col+1){
					return count + 1;
				} else if(visited[co.row][co.col+1] == false) {
					q.enqueue(co.row, co.col+1);
					visited[co.row][co.col+1] = true;
				}
			}
			if(co.row-1<rsize && maze[co.row-1][co.col]){ //search up
				if(exitR == co.row-1 && exitC == co.col){
					return count + 1;
				} else if(visited[co.row-1][co.col] == false) {
					q.enqueue(co.row-1, co.col);
					visited[co.row-1][co.col] = true;
				}
			}
			if(co.col-1<csize && maze[co.row][co.col-1]){ //search left
				if(exitR == co.row && exitC == co.col-1){
					return count + 1;
				} else if(visited[co.row][co.col-1] == false) {
					q.enqueue(co.row, co.col-1);
					visited[co.row][co.col-1] = true;
				}
			}
		}
	}
}

int main(void){
	int n,m;
	int count;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char sInput[100];
		scanf("%s",sInput);
		for(int j=0;j<m;j++)
			if(sInput[j] == '1')
				maze[i][j] = true;
	}
	cout<<bfs(n, m)<<endl;
	return 0;
}
