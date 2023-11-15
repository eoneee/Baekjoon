#include <bits/stdc++.h>
using namespace std;
bool box[3000][3000];
int order[7][2]={0,1, 0,2, 1,0, 1,2, 2,0, 2,1, 2,2}; 
void draw(int d){
        if(d == 1){
                box[1][1] = true;
                return;
        }
        draw(d/3);
        for(int i=0; i<7; i++){
                int xw = order[i][0] * (d/3), yw = order[i][1] *(d/3);
                for(int k=1; k<=d/3; k++){
                        for(int t=1; t<=d/3; t++){
                                box[k+xw][t+yw] = box[k][t];
                        }
                }
        }
}

int main(){
        int a;
        cin >> a;
        draw(a);

        for(int i=1; i<=a; i++){
                for(int j=1; j<=a; j++){
                        if(box[i][j])
                                cout << '*';
                        else
                                cout << ' ';
                }
                cout << "\n";
        }
        return 0;
}