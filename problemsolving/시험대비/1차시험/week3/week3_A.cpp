#include <iostream>

using namespace std;

int Testcase;
int N;
int blackcnt = 0;
int whitecnt = 0;
int input[256][256];

void quadTree(int x, int y, int size) {
	int cur = input[y][x];
	
	bool flag = true;
	for (int i = y; i < (y + size) && flag; i++) {
		for (int j = x; j < (x + size) && flag; j++) {
			if (cur != input[i][j]) {
				flag = false;
			}
		}
	}
	if (flag) {
		if (cur == 1) {
			blackcnt++;
		}
		else if (cur == 0) {
			whitecnt++;
		}
	}
	else {
		quadTree(x,y,size/2);
		quadTree(x+size/2,y,size/2);
		quadTree(x,y+size/2,size/2);
		quadTree(x+size/2,y+size/2,size/2);

	}
}



int main() {
	cin >> Testcase;

	for (int i = 0; i < Testcase; i++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> input[i][j];
			}
		}
		quadTree(0, 0, N);
		cout << whitecnt << ' ' << blackcnt << endl;
		whitecnt = 0;
		blackcnt = 0;
	}
}