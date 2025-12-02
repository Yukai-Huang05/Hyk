#include <iostream>
#include<string>

using namespace std;

int nexta[1000000];

void GetNext(string s) {
	int i = 0, k = -1;
	int l = s.length();
	nexta[0] = -1;
	while (i < l) {
		if (k == -1 || s[i] == s[k]) {
			i++;
			k++;
			nexta[i] = k;
		}
		else k = nexta[k];
	}
	for (int i = 0; i < l; i++) {
		cout << nexta[i] << " ";
	}
	cout << endl;
}

int KMP(string s, string s1) {
	int i = 0;
	int j = 0;
	int ls = s.length();
	int ls1 = s1.length();
	GetNext(s1);
	while (i < ls && j < ls1) {
		if (j == -1 || s[i] == s1[j]) {
			i++;
			j++;
		}
		else {
			j = nexta[j];
		}
	}
	if (j == ls1) return i - j + 1;
	else return 0;
}

int main() {
	int t;
	cin >> t; 
	while (t--) {
		string s, s1;
		cin >> s >> s1;
		cout << KMP(s, s1) << endl;
	}
	return 0;
}