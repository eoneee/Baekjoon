#include <bits/stdc++.h>
using namespace std;
int main() {
	int weightSum = 0;
	int time = 0;

	queue<int> truck;
	deque<pair<int, int>> bridge;
	int n, width, weight;
	cin >> n >> width >> weight;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		truck.push(a);
	}

	while(true){
		if(truck.empty() && bridge.empty()){
			cout << time + 1; // 마지막 트럭이 마지막다리에서 꼬리를빼는 순간(+1초 추가)
			break;
		}else{
			time++; // 트럭이 남거나, 다리가 비어있지 않은 경우 1초 추가
		}
		
		if(!truck.empty() && weightSum + truck.front() <= weight){ //트럭이 남아있고, 다리위의 트럭들 무게합과 남은트럭중 첫 트럭의 무게의 합이 다리 하중무게 이하일 경우
			bridge.push_back(pair<int, int>(truck.front(), 0)); // 다리 제일 뒤에 남은 트럭중 첫 트럭과 0초를 집어 넣음
			weightSum += truck.front(); // 총 무게 += 새로 들어온 트럭 무게
			truck.pop(); // 트럭 큐에서 pop
		}
		for(int i = 0; i < bridge.size(); i++){ // 트럭이 남아있지 않은 경우나, 남은 트럭 중 첫 트럭의 무게를 더했을 경우 하중 무게보다 넘는 경우 push하지 않고 진행
			bridge[i].second++; // 다리 사이즈만큼 for문을 돌리며 다리위의 트럭들에 1초씩 더해준다
		}	
		if(bridge.front().second == width){ // 다리의 앞 부분에 있는 트럭의 초가 길이와 동일해 지면 -> 다리 끝에 도착한 것
			weightSum -= bridge.front().first; // 총 무게에서 다리에 도착한 트럭의 무게를 뺌
			bridge.pop_front(); // 다리큐에서 제일 앞의 트럭을 pop, 가장 위 else문에서 1초를 더해줌
		}
	}
	return 0;
}