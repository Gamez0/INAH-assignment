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
				if (a[i][k] && a[k][j]) {
					a[i][j] = 1;
				}
			}
		}
	}

	for (int i = 1; (i <= n) && noLoop==true; i++) {
		for (int j = 1; (j <= n) && noLoop == true; j++) {
			if (a[i][j] == a[j][i])
				if(a[i][j]==1)
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
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int n, m;
	while (t--) {
		cin >> n >> m;
		test(n, m);
	}
}
/*
해결 됬습니다.

이전 코드는
for 문밖에서
int num=1;
for 문안에서
cout << ((n - ans) - b[num]) << ' ' << b[num++] << endl;

바꾼 코드는
for문안에서 i=1; i<=n;i++
cout << ((n - ans) - b[i]) << ' ' << b[i] << endl;

제거로는 둘다 되는데 서버에서는 왜 위에는 안되고 아래것만 되는지..
잘모르겠습니다.
*/