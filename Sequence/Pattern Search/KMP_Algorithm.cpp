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

void Compute_LPS_Array(string pattern, int m, int lps[]) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < m) {
		if (pattern[i] == pattern[len]) {
			++len;
			lps[i] = len;
			++i;
		} else {
			if (len != 0) {
				len = lps[len - 1];
			} else {
				lps[i] = 0;
				++i;
			}
		}
	}
}

void KMP_Search(string pattern, string text) {
	int m = pattern.size();
	int n = text.size();
	int lps[m];
	Compute_LPS_Array(pattern, m, lps);
	int i = 0, j = 0;
	while (i < n) {
		if (pattern[j] == text[i])
			++j, ++i;
		if (j == m) {
			cout << "Pattern Found At Index " << i - j << endl;
			j = lps[j - 1];
		} else if (i < n && pattern[j] != text[i]) {
			if (j != 0) {
				j = lps[j - 1];
			} else {
				++i;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string text = "xabcabzabc";
	string pattern = "abc";
	KMP_Search(pattern, text);
}
