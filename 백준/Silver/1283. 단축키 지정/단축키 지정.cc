#include <bits/stdc++.h>
using namespace std;
int n;
string wordList[30][5];
int chk[30][5][10];
map<char, int> visitt;
int wordLen[30];
// char findXthChar(string a, int number){
// 	return 'a';
// }

int main() {
	cin >> n;
	string temp;
	getline(cin, temp);
	for(int i = 0; i < n; i++){
		getline(cin, temp);
		int ptr = 0;
		int k = 0;
		for(int j = 0; j < temp.size(); j++){
			if(temp[j] == ' '){ // [ptr, j-1] = word
				wordList[i][k] = temp.substr(ptr, (j-1 - ptr) + 1);
				ptr = j+1;
				// cout << wordList[i][k] << wordLen[i] << endl;
				k++;
			}
		}
		wordList[i][k] = temp.substr(ptr, (temp.size() - 1) + 1);
		wordLen[i] = k+1;
		// cout << wordList[i][k] << wordLen[i] << endl;
	}
	
	for(char a = 'a'; a <= 'z'; a++)
		visitt[a] = 0;
	
	for(int i = 0; i < n; i++){ // i번째 문장
		int flag = 0;
		for(int k = 0; k < wordLen[i]; k++){ // i번째 문장의 k번째 단어
			// 첫번째 문자들 테스트
			if(visitt[ tolower(wordList[i][k][0])] == 0){ // wordList[i][k][j] 사용했나?
				visitt[ tolower(wordList[i][k][0]) ] = 1; // i문장의 단축키는 wordList i k j 
				chk[i][k][0] = 1;
				flag = 1;
				break;
			}
		}
		
		// 왼쪽부터 차례대로 탐색
		if(flag == 0){
			for(int j = 0; j < wordLen[i]; j++){
				for(int k = 0; k < wordList[i][j].size(); k++){
					if( visitt[ tolower(wordList[i][j][k]) ] == 0 ){
						visitt[ tolower(wordList[i][j][k]) ] = 1;
						chk[i][j][k] = 1;
						j = wordLen[i];
						break;
					}
				}
			}
		}	
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < wordLen[i]; j++){
			for(int k = 0; k < wordList[i][j].size(); k++){
				if(chk[i][j][k] == 1){ // 해당 글자가 단축키인 경우
					cout << "[" << wordList[i][j][k] << "]";
				}
				else{
					cout << wordList[i][j][k];
				}
			}
			cout << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
