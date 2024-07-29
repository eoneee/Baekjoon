#include<bits/stdc++.h>

using namespace std;

const int N = 1e2 + 1;

int cards[N];

int main(){
	int n, m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++)
		cin >> cards[i];
	
	int ans = 0;
	
	for(int a=1; a<=n; a++)
		for(int b=a+1; b<=n; b++)
			for(int c=b+1; c<=n; c++)
				if(cards[a] + cards[b] + cards[c] <= m)
					ans = max(ans, cards[a] + cards[b] + cards[c]);
	
	cout << ans;
	return 0;
}