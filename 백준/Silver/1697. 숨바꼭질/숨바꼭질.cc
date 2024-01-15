#include <bits/stdc++.h>
using namespace std;
int n, k;
queue<int> graph;
int visited[100001];
int minn = 100000;
int sec;

int bfs(int starty){
	if(starty == k){
		sec = min(minn, sec);
		return sec;
	}
	graph.push(starty);
	visited[starty] = true;

	while(!graph.empty()){
		int size = graph.size();
		for(int j = 0; j < size; j++){
			int y = graph.front();
			graph.pop();
			if(y == k){
				sec = min(minn, sec);
				return sec;
				
			}
				
			int ny;
			for(int i = 0; i < 3; i++){
				if(i == 0)
					ny = y + 1;
				else if(i == 1)
					ny = y - 1;
				else if(i == 2)
					ny = y * 2;
				if(ny >= 0 && ny <= 100000 && visited[ny] == 0){
				visited[ny] = true;
				graph.push(ny);
				}
			}
		}
		sec++;
		
	}
	return -1;
}
int main() {
	cin >> n >> k;
	cout << bfs(n);
	return 0;
}