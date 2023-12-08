#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> popStudent;

int main() {
	int time = 0;
	cin >> n;
	queue <pair<int, int>> student;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		student.push({a,i});
	}
	// for(int i = 0; i < n; i++){
	// 	cout << student.front() << endl;
	// 	student.pop();
	// }
	vector<int> ans(n);
	int idx = 0;
	while(!student.empty()){
		if(student.front().first == 1){
			student.front().first -= 1;
			time++;
			
		}
		else if(student.front().first > 0){
			student.front().first -= 1;
			popStudent = student.front();
			student.pop();
			student.push(popStudent);
			time++;
			
		}
		if(student.front().first == 0){
			idx = student.front().second;
			student.pop();
			// time++;
			ans[idx] = time;
		}
	}
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i] << " ";
	return 0;
}