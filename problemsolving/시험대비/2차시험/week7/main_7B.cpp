#include <iostream>

using namespace std;

void test() {
	int c, k;
	cin >> k >> c;

	for (int i = 0; i < c; i++) {
		int m, n;
		cin >> m >> n;
		if (m > n && m > n + (k - n) / 2 + 1 || m <= n && n > m + (k - m + 1) / 2)
			cout << '0' << endl;
		else
			cout << '1' << endl;
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		test();
	}
}