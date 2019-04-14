#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool wordCheck(string str1, string str2) {
	bool firstWord[26] = { false };
	bool secondWord[26] = { false };
	bool ans = true;
	int cnt = 0;

	int length1 = str1.length();
	int length2 = str2.length();

	int longlength = max(length1, length2);

	for (int i = 0; i < length1; i++) {
		firstWord[str1[i] - 'A'] = true;
	}
	for (int i = 0; i < length1; i++) {
		secondWord[str2[i] - 'A'] = true;
	}
	for (int i = 0; i < 26; i++) {
		if (firstWord[i] != secondWord[i]) {
			ans = false;
		}
	}
	if (ans)
		return true;
	else
		return false;
}


int main() {
	std::ios::sync_with_stdio(false);

	string str1;
	string str2;

	int Testcase;

	cin >> Testcase;
	for (int i = 0; i < Testcase; i++) {
		getline(cin, str1, ' ');
		getline(cin, str2);

		if (wordCheck(str1, str2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;

}