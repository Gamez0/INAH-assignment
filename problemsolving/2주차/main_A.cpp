#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool wordCheck(string str1, string str2) {
	bool alpa[26] = { false };
	bool word[26] = { false };
	int cnt = 0;

	int length1 = str1.length();
	int length2 = str2.length();
	int longlength = max(length1, length2);
	for (int i = 0; i < length1; i++) {
		alpa[str1[i] - 'A'] = true;
	}
	for (int i = 0; i < length2; i++) {
		word[str2[i] - 'A'] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (alpa[i] != word[i]) {
			cnt=1;
		}
	}
	if (cnt ==0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	
	std::ios::sync_with_stdio(false);

	string str;
	string str2;
	
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		getline(cin, str,' ');
		getline(cin, str2);

		if (wordCheck(str, str2)==true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}