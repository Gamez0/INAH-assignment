#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	string word1;
	string word2;
	int n;
	cin >> n;
	while (n--) {
		cin >> word1;
		word2 = word1;
		next_permutation(word1.begin(), word1.begin() + word1.length());
		if (word1 > word2)
			cout << word1 << endl;
		else
			cout << word2 << endl;
	}
}