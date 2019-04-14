#include <iostream>

using namespace std;

int greedy(int price, int typeNum) {
	int *coin = new int[typeNum];
	int cnt = 0;
	int money = 10000 - price;
	int idx = 0;
	for (int i = typeNum-1; i >-1; i--) {
		cin >> coin[i];
	}
	int available = money % coin[typeNum - 1];
	if(available==0){
		while (money != 0) {
			int change = money / coin[idx];
			money -= change * coin[idx++];
			cnt += change;
			
		}
	}
	if (money == 0)
		return cnt;
	else
		return 0;
	delete[]coin;
}
int main() {
	std::ios::sync_with_stdio(false);
	int testcase;

	cin >> testcase;

	int price;
	int typeNum;

	for (int i = 0; i < testcase; i++) {
		cin >> price >> typeNum;
		cout << greedy(price, typeNum) << endl;
	}
}