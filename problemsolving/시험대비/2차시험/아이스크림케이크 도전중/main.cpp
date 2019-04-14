#include <iostream>
#include <queue>
#include <deque>

using namespace std;

void test() {
	char word;
	int fruit[8];
	cin >> word;
	int chk[9];
	int buf = 0;
	queue<int> q1;


	switch (word) {
	case 'D':
		int d;
		cin >> d;
		fruit[d] += 1;
		break;
	case 'O':
		int x;
		cin >> x;
		int *arr = new int[x];
		int val = 0;
		for (int i = 0; i < x; i++) {
			cin >> arr[i];
			val += pow(10, arr[i]);
		}
		delete[]arr;
		val += buf * 100000000;
		buf++;
		q1.push(val);
		break;
	}
	if (!q1.empty()) {
		int s = q1.size();
		for (int q = 0; q < s; q++) {
			int a;
			int cn = 0;
			a = q1.front();
			chk[8] = a / 100000000;
			for (int i = 0; i < 8; i++) {
				chk[i] = a % 10;
				if (fruit[i] - chk[i] < 0) {
					cn = 1;
					break;
				}
				a = a / 10;
			}
			if (cn == 1) {
				int f = q1.front();
				q1.push(f);
			}
			else {
				for (int i = 0; i < 8; i++) {
					fruit[i] = fruit[i] - chk[i];
				}
				cout << chk[8] << endl;
			}
			q1.pop();
		}
		
	}

}
int main() {
	int n;
	cin >> n;
	while (n--) {
		test();
	}
}