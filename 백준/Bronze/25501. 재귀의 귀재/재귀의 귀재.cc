#include <bits/stdc++.h>
using namespace std;
int n;
string arr[1000];
int cnt[1000];
int recursion(const char *s, int l, int r, int inputnum){
		cnt[inputnum]++;
    if(l >= r) return 1; //재귀를 돌리다가 왼쪽오른쪽 글자 자리수가 같거나 왼쪽이 오른쪽보다 커지는 경우 모든 string을 다 확인한것으로 간주
    else if(s[l] != s[r]) return 0; //대칭의 글자가 다름
	//두글자를 비교후 다시 재귀함수를 불러옴(다음 글자로)
    else return recursion(s, l+1, r-1, inputnum);
}

int isPalindrome(const string& s, int inputnum){
    return recursion(s.c_str(), 0, s.length()-1, inputnum);
	
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < n; i++){
		cout << isPalindrome(arr[i], i) << " " << cnt[i] << endl;;
		
	}
	return 0;
}