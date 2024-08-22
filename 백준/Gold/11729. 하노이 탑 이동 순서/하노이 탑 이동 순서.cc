#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void pro(int from, int mid, int to, int n){
	if(n == 0)
		return;
	pro(from, to, mid, n -1);
	ans.push_back({from, to});
	pro(mid, from, to, n -1);
}


int main() {
       ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
		int n; 
		cin >> n; 
        if(n <= 20)
        {
	    	pro(1, 2, 3, n);
		    cout << ans.size() << "\n";
		    for (const auto &move : ans) {
			   	cout << move[0] << " " << move[1] << "\n";
		    }
        }

	
	return 0;
}
