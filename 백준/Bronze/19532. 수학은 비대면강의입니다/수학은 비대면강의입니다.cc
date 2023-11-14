#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int x, y;
int main() {
	cin >> a >> b >> c >> d >> e >> f;
	x = (c*e - b*f)/(a*e - b*d);
	y = (c*d - a*f)/(b*d - a*e);
	cout << x << " " << y << endl;
	return 0;
}