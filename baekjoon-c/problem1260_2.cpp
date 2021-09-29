#include <iostream>
#include <queue>
using namespace std;

int adjMtx[1000][1000];
bool dv[1000]={false};

void dfs(int r, int max){
	printf("%d ",r+1);
	dv[r] = true;
	for(int i=0;i<max;i++)
		if(adjMtx[i][r] == 1 && !dv[i])
			dfs(i, max);
}
void bfs(int start, int max){
	bool* v = new bool[max];
	queue<int> q;
	q.push(start);
	v[start] = true;
	cout<<start+1<<' ';
	for(int i=0;!q.empty();i++){
		int a = q.front();
		q.pop();
		for(int j=0;j<max;j++){
			if(adjMtx[j][a] == 1 && !v[j]){
				q.push(j);
				v[j] = true;
				cout<<j+1<<' ';
			}
		}
	}
	delete v;
}

int main(void){
	int noNode, noEdge, startNum;
	cin>>noNode>>noEdge>>startNum;
	for(int t=0;t<noEdge;t++){
		int s,e;
		cin>>s>>e;
		adjMtx[s-1][e-1] = adjMtx[e-1][s-1] = 1;
	}
	dfs(startNum - 1, noNode);
	cout<<'\n';
	bfs(startNum - 1, noNode);
	cout<<endl;
	return 0;
}