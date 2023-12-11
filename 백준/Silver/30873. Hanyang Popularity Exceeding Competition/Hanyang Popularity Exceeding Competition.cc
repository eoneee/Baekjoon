#include <bits/stdc++.h>
using namespace std;

int main() {
		int N;
		cin >> N;

		vector<pair<int, int>> celebrities(N);

		for (int i = 0; i < N; ++i) {
				cin >> celebrities[i].first >> celebrities[i].second;
		}
		int current = 0;
		for (int i = 0; i < N; ++i) {
				int popularitySub = abs(celebrities[i].first - current);
				if (popularitySub <= celebrities[i].second) {
						current++;
				}
		}

		cout << current << endl;

		return 0;
}
