#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string word1;
	string word2;
	vector<string>result;
	int n;
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cin >> word1;
		word2 = word1;
		next_permutation(word1.begin(), word1.begin() + word1.length());
		if (word1 > word2)
			cout << word1 << endl;
		else
			cout << word2 << endl;

	}
}