#include <bits/stdc++.h>
using namespace std;
const int N = 100;
bool visited[N + 1] = {0, };
vector<int> graph[N + 1];
int dfs(int v){
	visited[v] = true;
	for(int i = 0; i < graph[v].size(); i++){
		if(!visited[ graph[v][i] ]){
			dfs(graph[v][i]);
		}
	}
	return 0;
}
int main() {
	int n, connect;
	cin >> n >> connect;
	int cnt = 0;
	for(int i = 0; i < connect; i++){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for(int i = 2; i <= n; i++){
		if(visited[i]){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}