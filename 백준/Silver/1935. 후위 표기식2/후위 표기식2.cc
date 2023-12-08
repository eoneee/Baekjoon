#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	string equation;
	cin >> n >> equation;

	vector<int> vectorr(n);
	stack<double> stackk;

	for (int i = 0; i < n; i++) {
			cin >> vectorr[i];
	}

	for (int i = 0; i < equation.length(); i++) {
		if (equation[i] >= 'A' && equation[i] <= 'Z') {
			//스택에 차례대로 쌓아줌
			stackk.push(vectorr[equation[i] - 'A']); // A는 1부터 숫자로 인식
		} else {
			//스택이 비지 않은 경우, equation 변수에 글자가 아니라 사칙연산이 나오면
			if(!stackk.empty()){
				//벨류는 스택의 제일 위 수(부호가 나오기전 숫자)
				double value = stackk.top();
				//스택에서 가장 위 숫자를 뽑음
				stackk.pop();
				//새로 제일 위에 저장된 숫자와 방금뽑은 벨류를 계산해줌
				switch (equation[i]) {
					case '+':
							value = stackk.top() + value;
							break;
					case '-':
							value = stackk.top() - value;
							break;
					case '*':
							value = stackk.top() * value;
							break;
					case '/':
							value = stackk.top() / value;
							break;
				}
				stackk.pop();
				stackk.push(value);
			}
		}
	}

	cout << fixed << setprecision(2) << stackk.top() << endl;

	return 0;
}