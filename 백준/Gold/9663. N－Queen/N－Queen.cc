#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n;
int queen[15][15];


bool isPossible(int y, int x){
        for(int i=1; i<y; ++i){
                if(queen[i][x])
                        return false;
        }
        
        for(int i=1; i<min(y, x); ++i){
                if(queen[y-i][x-i])
                        return false;
        }
        
        for(int i=1; i<min(y, n-x+1); i++){
                if(queen[y-i][x+i])
                        return false;
        }
        
        return true;
}





void pro(int row){ 
                
        if(row == n + 1){
                ans++;
                return;
        }
        
        for(int i=1; i<=n; i++){
                if(isPossible(row, i)){
                        queen[row][i] = 1;
                        pro(row+1);
                        queen[row][i] = 0;
                }
        }
        
        return;
}

int main(){
        
        cin.tie(NULL);
        ios::sync_with_stdio(false);
        
        cin >> n;
        
        pro(1);
        
        cout << ans;
                
        return 0;
}