#include <iostream>

using namespace std;

int Min(int *arr, int restNum, int i) {
	arr[i] = 9999999;
	int smallest = arr[0];
	for (int k = 0; k < restNum; k++) {
		if (arr[k] <= smallest)
			smallest = arr[k];
	}
	return smallest;
}

int Budget(int restNum, int dayNum) {
	int a[100][101];
	int d[100][101];
	int smallest;
	int *arr = new int[restNum];

	for (int i = 0; i < restNum; i++) {
		for (int j = 1; j <= dayNum; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < restNum; i++) {
		a[i][0] = 0;
		d[i][0] = 0;
	}
	for (int j = 1; j <= dayNum; j++) {
		for (int i = 0; i < restNum; i++) {
			for (int k = 0; k < restNum; k++) {
				arr[k] = d[k][j - 1];
			}
			d[i][j] = Min(arr, restNum, i) + a[i][j];
		}
	}
	smallest = d[0][dayNum];
	for (int i = 0; i < restNum; i++) {
		if (d[i][dayNum] <= smallest)
			smallest = d[i][dayNum];
	}

	return smallest;
	delete[]arr;
	delete[]a;
	delete[]d;
}
int main()
{
	int testcase;
	int restNum, dayNum;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		cin >> restNum >> dayNum;
		cout << Budget(restNum, dayNum) << endl;
	}
	return 0;
}

