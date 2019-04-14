#include <iostream>
#include <algorithm>

using namespace std;

int dynamic(int price, int typeNum) {
	int money = 10000 - price;

	int a[10001];
	int d[501];

	for (int i = 1; i <= typeNum; i++) {
		cin >> d[i];
	}
	for (int i = 1; i <= money; i++) {
		a[i] = 10001;
		a[0] = 0;
	}
	for (int i = 1; i <= typeNum; i++) {
		for (int j = d[i]; j <= money; j++) {
			a[j] = min(a[j], a[j - d[i]] + 1);
		}
	}
	if (a[money] == 10001)
		return 0;
	else
		return a[money];

	delete[]a;
	delete[]d;
}

int main() {
	int testcase,price, typeNum;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> price >> typeNum;
		cout<<dynamic(price, typeNum)<<endl;
	}
}








/*int money = 10000 - price;
	int a[10001];
	int d[501];
	for (int i = 1; i<=typeNum; i++) {
		cin >> d[i];
	}
	for (int i = 1; i <= money; i++) {
		a[i] = 10001;
		a[0] = 0;
	}
	
	for (int i = 1; i <= typeNum; i++) {
		for (int j = d[i]; j <= money; j++) {
			a[j] = min(a[j], a[j - d[i]] + 1);
		}
	}
	if (a[money] == 10001)
		return 0;
	else
		return a[money];*/