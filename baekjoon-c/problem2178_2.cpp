#include <iostream>
#include <queue>
using namespace std
bool maze[100][100] = {false};
bool visited[100][100] = {false};

int bfs(int rsize, int csize){
	int exitR = rsize - 1, exitC = csize - 1;
	queue< pair<int,int> > q;
	q.push(make_pair(0,0));
	visited[0][0] = true;
	for(int count = 1;;count++){
		int len = q.size();
		for(int i=0;i<len;i++){
			pair<int,int> co;
			co.first = q.front().first;
			co.second = q.front().second;
			q.pop();
			if(co.first+1<rsize && maze[co.first+1][co.second]){ //search down
				if(exitR == co.first+1 && exitC == co.second){
					return count + 1;
				} else if(visited[co.first+1][co.second] == false) {
					q.push(make_pair(co.first+1, co.second));
					visited[co.first+1][co.second] = true;
				}
			}
			if(co.second+1<csize && maze[co.first][co.second+1]){ //search right
				if(exitR == co.first && exitC == co.second+1){
					return count + 1;
				} else if(visited[co.first][co.second+1] == false) {
					q.push(make_pair(co.first, co.second+1));
					visited[co.first][co.second+1] = true;
				}
			}
			if(co.first-1 >= 0 && maze[co.first-1][co.second]){ //search up
				if(exitR == co.first-1 && exitC == co.second){
					return count + 1;
				} else if(visited[co.first-1][co.second] == false) {
					q.push(make_pair(co.first-1, co.second));
					visited[co.first-1][co.second] = true;
				}
			}
			if(co.second-1 >= 0 && maze[co.first][co.second-1]){ //search left
				if(exitR == co.first && exitC == co.second-1){
					return count + 1;
				} else if(visited[co.first][co.second-1] == false) {
					q.push(make_pair(co.first, co.second-1));
					visited[co.first][co.second-1] = true;
				}
			}
		}
	}
}

int main(void){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char sInput[100];
		cin>>sInput;
		for(int j=0;j<m;j++)
			if(sInput[j] == '1')
				maze[i][j] = true;
	}
	cout<<bfs(n, m)<<endl;
	return 0;
}
