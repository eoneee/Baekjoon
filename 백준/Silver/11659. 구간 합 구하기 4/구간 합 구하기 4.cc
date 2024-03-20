#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
int n, m;
int prefixSum[MAXN];
int input[MAXN];
int main() {
	
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> input[i];
		prefixSum[i] += input[i] + prefixSum[i - 1];
	}
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		cout << prefixSum[b] - prefixSum[a - 1] << "\n";
	}
	return 0;
}