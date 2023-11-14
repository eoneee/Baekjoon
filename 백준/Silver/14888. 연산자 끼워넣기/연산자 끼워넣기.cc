#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int n;
int num[N+1];
int calculation[N];
int minn = 1e9, maxx = -1e9;

int param(int step, int remain[]){
	//숫자개수만큼 step이 다 되면 
	if(step == n){
		int result = num[1];
		// 사칙연산 calculation (수의 개수만큼)
		for(int i = 1; i < n; i++){
			if(calculation[i] == 0){
				result = result + num[i+1];
			}
			if(calculation[i] == 1){
				result = result - num[i+1];
			}
			if(calculation[i] == 2){
				result = result * num[i+1];
			}
			if(calculation[i] == 3){
				result = result / num[i+1];
			}
		}
		//계산한 result값이 최대인지 확인
		if(result > maxx){
			maxx = result;
		}
		//계산한 result값이 최소인지 확인
		if(result < minn){
			minn = result;
		}
		return 0;
	}
	
	//cal 부호들 돌려가면서 확인
	for(int i = 0; i < 4; i ++){
		//cal이 남아있으면
		if(remain[i] > 0){
			//하나씩 줄여줌
			remain[i]--;
			//각 단계번재 배열에 i를 넣어준다.(+-*/ 중에 순서대로 남아잇는 부호를 넣어주는 중)
			calculation[step] = i;
			//두번째 단계, 부호의 남아있는 개수를 넣어준다 (개수-1 일듯)
			param(step + 1, remain);
			remain[i]++;
		}
	}
	return 0;
}

int main() {
	//숫자 개수
	cin >> n;
	//num 배열에 차례로 저장
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	int cal[4];
	//사칙연산 부호 개수 입력받기
	for(int i = 0; i < 4; i++){
		cin >> cal[i];
	}
	
	//1단계, 부호 배열 입력
	param(1,cal);
	cout << maxx << "\n" << minn;
	
	return 0;
}