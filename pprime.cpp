/*
ID: 3dmailb
PROG: pprime
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

vector<int> primes, palin, palinPrimes;
vector<string> palinStr;
bool isPrime[11111];

void gen_primes() {
	for (int i=2; i<MAX; i++)
		isPrime[i] = true;
	for (int i=2; i<MAX; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (int j=i*i; j<MAX; j+=i) {
				isPrime[j]=false;
			}
		}
	}
}

string intToString(int n) {
	string ans = "";
	while (n) {
		char c = '0' + n%10;
		ans = c + ans;
		n/=10;
	}
	return ans;
}

int stringToInt(string s) {
	int index = s.size()-1;
	int ten = 1;
	int ans = 0;
	while (index>=0) {
		ans += (s[index]-'0')*ten;
		index--;
		ten*=10; 
	}
	return ans;
}

void gen_palinStr(int start, int end) {
	for (int i=start; i<=end; i++) {
		string s = intToString(i);
		string tmp = s;
		reverse(tmp.begin(), tmp.end());
		palinStr.push_back(s+tmp);
		for (char c = '0'; c<='9'; c++) {
			palinStr.push_back(s+c+tmp);
		}
	}
}

void gen_full_palinStr() {
	palinStr.push_back("5");
	palinStr.push_back("7");
	gen_palinStr(1,9);
	gen_palinStr(10,99);
	gen_palinStr(100,999);
}

void gen_full_palin() {
	for (int i=0; i<palinStr.size(); i++) {
		palin.push_back(stringToInt(palinStr[i]));
	}
	sort(palin.begin(), palin.end());
}

bool checkPrime(int n) {
	bool prime = true;
	for (int i=0; i<primes.size(); i++) {
		if (primes[i]*primes[i]>n) 
			break;
		if (n % primes[i] == 0) 
			prime = false;
	}
	return prime;
}

void gen_full_palin_primes() {
	for (int i=0; i<palin.size(); i++) 
		if (checkPrime(palin[i]))
			palinPrimes.push_back(palin[i]);
}

void print_all(vector<int> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
}

int main() {
	freopen("pprime.in", "r", stdin);
	freopen("pprime.out", "w", stdout);
	gen_primes();
	gen_full_palinStr();
	//print_all(palinStr);
	gen_full_palin();
	gen_full_palin_primes();
	//print_all(palinPrimes);
	int a,b;
	cin >> a >> b;
	int low = lower_bound(palinPrimes.begin(), palinPrimes.end(), a) - palinPrimes.begin();
	int upp = upper_bound(palinPrimes.begin(), palinPrimes.end(), b) - palinPrimes.begin();
	for (int i=low; i<upp; i++) 
		cout << palinPrimes[i] << endl;
	return 0; 
}