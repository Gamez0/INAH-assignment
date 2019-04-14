#include<iostream>
using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}

void test() {
	
	int i;
	int j;
	int price;
	int typenum;
	int money;
	int maximum = 10001;
	int array[501];
	int ans[10001];
	

	 
		cin >> price;			// 10000-k
		cin >> typenum;			// n
		money = 10000 - price;	// k

		for (i = 1; i <= typenum; i++) {
			cin >> array[i];
		}

		for (i = 1; i <= money; i++) {
			ans[i] = 10001;
			ans[0] = 0;
		}
		for (i = 1; i <= typenum; i++) {
			for (j = array[i]; j <= money; j++) {
				ans[j] = Min(ans[j], ans[j - array[i]] + 1);
			}
		}
		if (ans[money] == 10001) {
			ans[money] = 0;
		}
		cout << ans[money] << endl;

	


}
int main() {
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		test();
	}
	
	}