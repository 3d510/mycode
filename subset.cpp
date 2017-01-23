/*
ID: 3dmailb1
PROG: subset
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

long long cnt=0;
long long n;
long long res[400][44];

long long recur(long long curSum, int curNum) {
	if (res[curSum][curNum]!=-1) return res[curSum][curNum];
	if (curSum<0 || curNum>n) return 0;
	if (curSum==0) {
		return res[curSum][curNum]=1;
	}
	return res[curSum][curNum]=recur(curSum, curNum+1)+recur(curSum-curNum, curNum+1);
}

void print() {
	for (int i=0; i<=(n*(n+1))/2; i++) {
		for (int j=1; j<=n; j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}

int main() {
	freopen("test.in", "r", stdin);
	//freopen("subset.out", "w", stdout);

	cin >> n;
	for (int i=0; i<400; i++) for (int j=0; j<44; j++)
		res[i][j]=-1;
	//print();
	long long sum = (n*(n+1))/2;
	if (sum%2) cout << 0 << endl;
	else {
		long long ans = recur(sum/2,1);
		cout << ans << endl;
	}
	return 0; 
}