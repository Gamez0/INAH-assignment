#include <iostream>

using namespace std;

void test() {
	int a[51][51] = { 0, };
	int b[51] = { 0, };
	int c[51] = { 0, };
	int n,m;
	bool noLoop = true;
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= m; i++) {
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
	for (int i = 1; i <= n && noLoop; i++) {
		for (int j = 1; j <= n && noLoop; j++) {
			if (a[i][j] == a[j][i])
				if (a[i][j])
					noLoop = false;
		}
	}
	for (int i = 1; i <= n && noLoop; i++) {
		for (int j = 1; j <= n && noLoop; j++) {
			b[i] += a[i][j];
		}
	}
	for (int j = 1; j <= n && noLoop; j++) {
		for (int i = 1; i <= n && noLoop; i++) {
			c[j] += a[i][j];
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}*/
	if (noLoop) {
		for (int i = 1; i <= n; i++) {
			cout << c[i] << ' ' << b[i] << endl;
		}
	}
	else
		cout << "-1" << endl;

}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		test();
	}
}