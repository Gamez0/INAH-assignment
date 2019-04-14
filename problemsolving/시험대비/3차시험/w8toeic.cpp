#include <iostream>

using namespace std;

void test(int n, int m) {
	int a[51][51] = { 0, };
	int b[51] = { 0, };
	bool noLoop = true;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][k] && a[k][j])
					a[i][j] = 1;
			}
		}
	}
	for (int i = 1; (i <= n) && noLoop == true; i++) {
		for (int j = 1; (j <= n) && noLoop == true; j++) {
			if (a[i][j] == a[j][i])
				if (a[i][j] == 1)
					noLoop = false;
		}
	}
	if (noLoop == false) {
		cout << "-1" << endl;
	}
	else if (noLoop == true) {
		for (int i = 1; i <= n; i++) {
			int ans = 0;
			for (int j = 1; j <= n; j++) {
				if (!a[i][j] && !a[j][i]) ans++;
				b[i] += a[i][j];
			}
			cout << ((n - ans) - b[i]) << ' ' << b[i] << endl;
		}
	}
}
int main() {
	int t;
	cin >> t;
	int m, n;

	while (t--) {
		cin >> n >> m;
		test(n, m);
	}
}