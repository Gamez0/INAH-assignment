#include <iostream>

using namespace std;

int n;
int cost[10000];
int limit;
int sum[10001];
int max;

void solve()
{
	int s = 0, e = max, m;
	int cal, num;
	int i;

	while (s <= e) {
		m = (s + e) / 2;

		cal = 0;
		for (i = 0; i < n; i++) {
			if (cost[i] > m)    
				cal += m;
			else                
				cal += cost[i];
		}

		if (cal > limit)    
			e = m - 1;
		else                
			s = m + 1;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (cost[i] < e)
			sum += cost[i];
		else
			sum += e;
	}
	cout << sum << endl;
}

void test()
{
	int i;
	cin >> n;
	cin >> limit;
	for (i = 0; i < n; i++) {
		cin >> cost[i];
		if (cost[i] > max)    max = cost[i];
	}
	

	solve();
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		test();
	}
}