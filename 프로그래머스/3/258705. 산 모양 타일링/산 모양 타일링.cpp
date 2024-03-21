#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
const int MODN = 10007;
int D[MAXN][2];

int solution(int n, vector<int> tops) {
    // init
    D[0][0] = D[0][1] = 1;
    
    //DP
    for(int i=0; i<n-1; i++){ // i -> i+1
        D[i+1][0] = D[i][0] + D[i][1] * (tops[i]+1);
        D[i+1][1] = D[i][0] + D[i][1] * (tops[i]+2);
        
        D[i+1][0] %= MODN;
        D[i+1][1] %= MODN;
    }
    
    // 마지막 오른쪽 아래 삼각형 더해주는 경우의수
    return (D[n-1][0] + D[n-1][1]*(tops[n-1]+2)) % MODN;
}