#include <bits/stdc++.h>
using namespace std;

int full, start, goal, up, down;
const int MAXX = 1e6 + 1;
bool visited[MAXX];
int building[MAXX];
queue<int> movement;

int bfs(int startFloor){
	int dy[] = {up, down};
	
	
	if(startFloor == goal)
		return building[goal];
	
	
	movement.push(startFloor);
	
	building[startFloor] = 0;
	visited[startFloor] = true;

	while(!movement.empty()){
		int y = movement.front();
		movement.pop();
		
		for(int i = 0; i < 2; i++){
			int ny = y + dy[i];
			
			if(ny >= 1 && ny <= full && visited[ny] == 0){
				building[ny] = building[y] + 1;
				visited[ny] = true;
				movement.push(ny);
				if (ny == goal) {
					return building[ny];
				}
			}
			
		}
	}
	return -1;
}



int main() {

	cin >> full >> start >> goal >> up >> down;
	//memset(visited, 0, sizeof(visited));
	//memset(building, 0, sizeof(building));
	
	while(!movement.empty())
		movement.pop();
	
	down *= -1;
	
	int ans = bfs(start);
	if(ans == -1){
		cout << "use the stairs";
	}else{
		cout << building[goal] << endl;
	}
	
	return 0;
}

