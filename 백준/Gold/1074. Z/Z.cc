#include <bits/stdc++.h>
using namespace std;
int r, c, ans, cnt;

int pro(int x, int y, int d){
	if(r >= x && r < x + d && c >= y && c < y + d){
		if(d == 2){
			if(r == x && c == y){
				ans = cnt;
			}else if(r == x && c == y + 1){
				ans = cnt + 1;
			}else if(r == x + 1 && c == y){
				ans = cnt + 2;
			}else{
				ans = cnt + 3;
			}
			return 0;
		}
		pro(x, y, d/2);
		pro(x, y + d/2, d/2);
		pro(x + d/2, y, d/2);
		pro(x + d/2, y + d/2, d/2);
	}
	else
		cnt += d * d;

	return 0;
}


int main() {
	int tmp;
	int n = 1;
	cin >> tmp >> r >> c;
	pro(0, 0, n << tmp);
	
	cout << ans;

	
	return 0;
}
