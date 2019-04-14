#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int Min(int arr[], int restNum, int i) {
	int smallest = 999999999;
	int *nrry = new int[restNum];
	nrry = arr;
	nrry[i] = 999999999;
	for (int i = 0; i < restNum; i++) {
		if (nrry[i] <= smallest)
			smallest = nrry[i];
	}
	return smallest;
	delete []nrry;
}

int cheapBudget(int restNum, int dayNum) {
	int a[100][101];
	int d[100][101];
	int nrry[100];
	int smallest;
	for (int i = 0; i < 100; i++) {
		a[i][0] = 0;
		d[i][0] = 0;
	}

	for (int i = 0; i < restNum; i++) {
		for (int j = 1; j <= dayNum; j++) {
			cin >> a[i][j];
		}
	}
	

	for (int j = 1; j <= dayNum; j++) {
		for (int i = 0; i < restNum; i++) {
			for (int k = 0; k < restNum; k++) {
				nrry[k] = d[k][j - 1];
			}
			d[i][j] = Min(nrry,restNum,i) + a[i][j];
		}
	}
	smallest = d[0][dayNum];
	for (int i = 0; i < restNum; i++) {
		if (d[i][dayNum] <= smallest)
			smallest = d[i][dayNum];
	}
	return smallest;
}

int main() {
	std::ios::sync_with_stdio(false);

	int testcase;
	int restNum;
	int dayNum;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {

		cin >> restNum >> dayNum;
		cout << cheapBudget(restNum, dayNum) << endl;
	}

	return 0;
}