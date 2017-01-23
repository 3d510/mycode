/*
ID: 3dmailb
PROG: hamming
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int hammingDis(int a, int b) {
	return __builtin_popcount(a^b);
}

int main() {
	freopen("hamming.in", "r", stdin);
	freopen("hamming.out", "w", stdout);
	int n,b,d,tmp=0;
	cin >> n >> b >> d;
	while (v.size()!=n) {
		bool val = true;
		for (int i=0; i<v.size(); i++) 
			if (hammingDis(tmp, v[i]) < d)
				val = false;
		if (val) 
			v.push_back(tmp);
		tmp++;
	}
	for (int i=0; i<n; i++) {
		if (i%10==9) cout << v[i] << endl;
		else if (i!=v.size()-1) cout << v[i] << " ";
		else cout << v[i] << endl;
	}
	return 0; 
}