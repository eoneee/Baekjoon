#include <bits/stdc++.h>
using namespace std;
const int MAXX = 50;
vector<int> graph[MAXX];
int cnt;
int b;
bool chk = false;
int dfs(int x){
	if(graph[x].empty()){
			cnt++;
		}
	for(auto i : graph[x]){
		if(i == b && graph[x].size() != 1)
			cnt--;
		dfs(i);
	}
	return 0;
}

int main(){
	int n;
	int a;
	int root;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a == -1){
			root = i;
			continue;
		}
		graph[a].push_back(i);
	}
	cin >> b;
	graph[b].clear();
	dfs(root);
	if(b == root)
		cnt = 0;
	// if(graph[b].size() == 1)
	cout << cnt;
	// else 
		// cout << cnt - 1;
	return 0;
}
