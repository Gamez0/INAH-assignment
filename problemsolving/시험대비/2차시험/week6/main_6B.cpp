#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	string word1;
	string word2;

	cin >> t;
	while (t--) {
		cin >> word1;
		word2 = word1;

		next_permutation(word1.begin(), word1.begin() + word1.length());

		if (word1 > word2)
			cout << word1 << endl;
		else
			cout << word2 << endl;
	}
}