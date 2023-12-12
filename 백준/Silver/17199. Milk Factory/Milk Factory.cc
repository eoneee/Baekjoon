#include <bits/stdc++.h>
using namespace std;
const int N = 100;

bool visited[N+1] = {0, };
vector<int> graph[N + 1];
int minn = 101;
int flag = 0;
int dfs(int num){
	visited[num] = true;
	for(int i = 0; i < graph[num].size(); i++){
		if(!visited[ graph[num][i] ]){
			dfs(graph[num][i]);
			//1
			//2 1 3 -> visited[2] = true -> for문을 돌면서 1,3 만큼 visited[1 또는 3]이 faㅣse이기 때문에 방문을 해줌 dfs를 다시 돌림
			//dfs(1 또는 3) -> dfs(1) 아무것도 없어서 그냥 리턴;
			//dfs(3)도 그냥 리턴
			//3 -> 그냥 끝
			// 이떼 2가 출력 되려면 ? 
		}
		
	}
	return 0;
}

int main() {
	int n; 
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> b >> a;
		graph[a].push_back(b);
		
	}
	for(int i = 1; i <= n; i++){
		dfs(i);
		flag = 0;
		for(int j = 1; j <= n; j++){
			if(visited[j] == 0){
				flag = 1;
			}
			visited[j] = 0;
		}
		if(flag == 0){
			minn = min(minn, i);
			// minn = i;
		}
	}
	if(minn == 101)
		minn = -1;
	cout << minn << endl;
	return 0;
}