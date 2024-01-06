#include <bits/stdc++.h>
using namespace std;
int flag = 0;

int findIdIdx(vector<string> id_list, string id){
    for(int i=0; i < id_list.size(); i++){
        if(id == id_list[i])
            return i;
    }
    return -1;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    string fir = "", sec = "";
    
    vector<string> arr[id_list.size()];
    int arrCnt[id_list.size()];
    memset(arrCnt, 0, sizeof(arrCnt));
    
    vector<string> chk;
    
    // report 공백기준 두개의 string으로 나누기
    // 나눠진 report를 연결 리스트로 구성 (중복없이)
    // for(auto i : report){
    for(int i = 0; i < report.size(); i++){
        flag = 0;
        int spaceIdx = report[i].find(' ');
        fir = report[i].substr(0, spaceIdx);
        sec = report[i].substr(spaceIdx + 1, report[i].size() - spaceIdx);
        
        int firIdx = findIdIdx(id_list, fir);
        for(int t = 0; t < arr[firIdx].size(); t++){
            if(arr[firIdx][t] == sec){
                sec = "";
                break;
            }
        }
        if(sec != ""){
            arr[firIdx].push_back(sec);
            arrCnt[findIdIdx(id_list, sec)]++;
        }
        
    }
   
    
        
    
    // k 이상일 경우 chk
    for(int i = 0; i < id_list.size(); i++){
        
        cout << arrCnt[i] << " " << i << "\n";
        if(arrCnt[i] >= k){
            chk.push_back(id_list[i]);
        }
    }
    
    // chk 된 변수들이 각 신고자리스트에 몇 개나 있는지 확인하여 배열로 출력
    vector<int> answer(id_list.size());
    
    for(int i = 0; i < id_list.size(); i++){
        for(int j = 0; j < arr[i].size(); j++){
            
            for(int q = 0; q < chk.size(); q++){
                if(chk[q] == arr[i][j]){
                    answer[i]++;    
                    break;
                }
            }
            
        }
    }
    return answer;
}