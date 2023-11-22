#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int place[15];
bool check(int row, int col){
   for(int i = 0; i < row; i++){
      //열중복
      if(place[i] == col){
         return false;
      }
      
      int dy = (row - i);
      //왼쪽대각선중복
      if(place[i] - dy == col){ // place[i] = (i, place[i]), (row, col) => row - i
         return false;
      }
      //오른쪽대각선
      if(place[i] + dy == col){
         return false;
      }
   }
   return true;
}

int queen(int row){
   if(row == n){
      ans++;
      return 0;
   }
   
   for(int i = 0; i < n; i++){
      if(check(row, i) == true){
         place[row] = i;
         queen(row + 1);
      }
   }
   return 0;
}
int main() {
   cin >> n;
   queen(0);
   cout << ans;
   return 0;
}