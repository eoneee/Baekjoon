#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long a, b, c;

long long go(long long a, long long b){
	if(b == 1) return a % c;
	long long result = go(a, b/2);
    result = (result*result)%c;
    if(b%2) result = (result * a)%c;
    return result;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	cout << go(a, b) << "\n";
	return 0;
}