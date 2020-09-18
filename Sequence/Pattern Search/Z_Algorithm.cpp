//    ____            _
//   / ___| ___ _ __ (_) ___
//  | |  _ / _ \ '_ \| |/ _ \
//  | |_| |  __/ | | | |  __/
//   \____|\___|_| |_|_|\___|
 
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace std;
using namespace boost::multiprecision;
#define endl '\n'

void getZarr(string str, int Z[]) {
	int n = str.size();
	int l, r, k;
	l = r = 0;
	for (int i = 1; i < n; ++i) {
		if (i > r) {
			l = r = i;
			while (r < n && str[r - l] == str[r])
				++r;
			Z[i] = r - l;
			--r;
		} else {
			k = i - l;
			if (Z[k] < r - i + 1) {
				Z[i] = Z[k];
			} else {
				l = i;
				while (r < n && str[r - l] == str[r])
					++r;
				Z[i] = r - l;
				--r;
			}
		}
	}
}

void Z_Search(string text, string pattern) {
	string concat = pattern + "$" + text;
	int l = concat.size();
	int Z[l];
	getZarr(concat, Z);
	for (int i = pattern.size() + 1; i < l; ++i)
		if (Z[i] == pattern.size())
			cout << "Pattern Found At Index " << i - pattern.size() - 1 << endl;
}
 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string text = "xabcabzabc";
	string pattern = "abc";
	Z_Search(text, pattern);
}
