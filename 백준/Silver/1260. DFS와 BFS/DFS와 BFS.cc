#include <bits/stdc++.h>
using namespace std;
bool visited[1001];
int n, m, x;
int arr[1001][1001];
int bfs(int x){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int next = q.front();
		visited[next] = 1;
		cout << next << " ";
		q.pop();
		
		for(int i = 1; i <= n; i++){
			if(arr[next][i] == 1 && visited[i] == 0){
				q.push(i);
				visited[i] = true;
			}
		}
	}
	return 0;
}

int dfs(int x){
	visited[x] = true;
	cout << x << " ";	
	for(int i = 1; i <= n; i++){
		if(arr[x][i] == 1 && visited[i] == 0){
			dfs(i);
		}
		if(i == n)
			return 0;
	}
}


int main() {
	int u, v;
	cin >> n >> m >> x;
	
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	dfs(x);
	cout << "\n";
	
	memset(visited, false, sizeof(visited));
	bfs(x);
	
	return 0;
	
}