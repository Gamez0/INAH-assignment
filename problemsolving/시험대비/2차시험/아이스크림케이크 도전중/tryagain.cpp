#include <iostream>

using namespace std;

int fruit[8] = { 0, };
bool check(unsigned char order) {
	bool flag = true;
	for (int i = 0; i < 8; i++) {
		if ((order & (1 << i) && (fruit[i] == 0))) {
			flag = false;
			break;
		}
	}
	return flag;
}

int main() {
	int t;
	char word;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> word;
		if (word == 'O') {
			int num;
			int sum = 0;
			unsigned char order = 0;
			cin >> num;
			for (int i = 0; i < num; i++) {

			}
		}
		if (word == 'D') {

		}
	}
}