/*
ID: 3dmailb
PROG: preface
LANG: C++11
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
 
#define Inf 2147483647
#define Pi acos(-1.0)
#define N 1000000
#define LL long long
 
inline LL Power(int b, int p) { LL ret = 1; for ( int i = 1; i <= p; i++ ) ret *= b; return ret; }
const int dr [] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc [] = {0, 1, 1, 1, 0, -1, -1, -1};
 
#define F(i, a, b) for( int i = (a); i < (b); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define Set(a, s) memset(a, s, sizeof (a))
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)
 
using namespace std;
 
int cnt [7 + 3];
 
string romanLetter (int p) {
 
    if ( p == 0 ) return "";
 
    if ( p < 10 ) {
        if ( p == 1 ) return "I";
        if ( p == 2 ) return "II";
        if ( p == 3 ) return "III";
        if ( p == 4 ) return "IV";
        if ( p == 5 ) return "V";
        if ( p == 6 ) return "VI";
        if ( p == 7 ) return "VII";
        if ( p == 8 ) return "VIII";
        if ( p == 9 ) return "IX";
    } else if ( p < 100 ) {
        if ( p / 10 == 1 ) return "X" + romanLetter (p % 10);
        if ( p / 10 == 2 ) return "XX" + romanLetter (p % 10);
        if ( p / 10 == 3 ) return "XXX" + romanLetter (p % 10);
        if ( p / 10 == 4 ) return "XL" + romanLetter (p % 10);
        if ( p / 10 == 5 ) return "L" + romanLetter (p % 10);
        if ( p / 10 == 6 ) return "LX" + romanLetter (p % 10);
        if ( p / 10 == 7 ) return "LXX" + romanLetter (p % 10);
        if ( p / 10 == 8 ) return "LXXX" + romanLetter (p % 10);
        if ( p / 10 == 9 ) return "XC" + romanLetter (p % 10);
    } else if ( p < 1000 ) {
        if ( p / 100 == 1 ) return "C" + romanLetter (p % 100);
        if ( p / 100 == 2 ) return "CC" + romanLetter (p % 100);
        if ( p / 100 == 3 ) return "CCC" + romanLetter (p % 100);
        if ( p / 100 == 4 ) return "CD" + romanLetter (p % 100);
        if ( p / 100 == 5 ) return "D" + romanLetter (p % 100);
        if ( p / 100 == 6 ) return "DC" + romanLetter (p % 100);
        if ( p / 100 == 7 ) return "DCC" + romanLetter (p % 100);
        if ( p / 100 == 8 ) return "DCCC" + romanLetter (p % 100);
        if ( p / 100 == 9 ) return "CM" + romanLetter (p % 100);
    } else {
        if ( p / 1000 == 1 ) return "M" + romanLetter (p % 1000);
        if ( p / 1000 == 2 ) return "MM" + romanLetter (p % 1000);
        if ( p / 1000 == 3 ) return "MMM" + romanLetter (p % 1000);
        return "";
    }
 
 
}
 
string convertToRoman (int n) {
    string roman = "";
 
    if ( n > 999 ) {
        roman += romanLetter (n / 1000 * 1000); n %= 1000;
        roman += romanLetter (n / 100 * 100); n %= 100;
        roman += romanLetter (n / 10 * 10); n %= 10;
        roman += romanLetter (n);
 
    } else if ( n > 99 ) {
        roman += romanLetter (n / 100 * 100); n %= 100;
        roman += romanLetter (n / 10 * 10); n %= 10;
        roman += romanLetter (n);
 
    } else if ( n > 9 ) {
        roman += romanLetter (n / 10 * 10); n %= 10;
        roman += romanLetter (n);
 
    } else roman += romanLetter (n);
 
    return roman;
}
 
void cntRomanLetters (string str) {
    Fs (i, str) {
        if ( str [i] == 'I' ) cnt [0]++;
        else if ( str [i] == 'V' ) cnt [1]++;
        else if ( str [i] == 'X' ) cnt [2]++;
        else if ( str [i] == 'L' ) cnt [3]++;
        else if ( str [i] == 'C' ) cnt [4]++;
        else if ( str [i] == 'D' ) cnt [5]++;
        else cnt [6]++;
    }
}
 
int main ()
{
    freopen ("preface.in", "r", stdin);
    freopen ("preface.out", "w", stdout);
 
    int n; scanf ("%d", &n);
 
    Set (cnt, 0);
 
    for ( int i = 1; i <= n; i++ ) {
        string roman = convertToRoman (i);
        //cout << i << ": " << roman << endl;
        cntRomanLetters (roman);
    }
 
    if ( cnt [0] ) printf ("I %d\n", cnt [0]);
    if ( cnt [1] ) printf ("V %d\n", cnt [1]);
    if ( cnt [2] ) printf ("X %d\n", cnt [2]);
    if ( cnt [3] ) printf ("L %d\n", cnt [3]);
    if ( cnt [4] ) printf ("C %d\n", cnt [4]);
    if ( cnt [5] ) printf ("D %d\n", cnt [5]);
    if ( cnt [6] ) printf ("M %d\n", cnt [6]);
 
    return 0;
}
 