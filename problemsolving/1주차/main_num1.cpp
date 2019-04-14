#include <iostream>
#include <string>
using namespace std;


int main() {
	std::ios::sync_with_stdio(false);


	int testcase;
	int money;
	int price;
	int typenum;
	int idx = 0;
	int ans = 0;

	cin >> testcase;				// testcase 입력

	for (int i = 0; i < testcase; i++) {	// testcase 만큼 반복
		cin >> price;
		money = 10000 - price;		// 거스름돈 계산

		cin >> typenum;

		int * array = new int[typenum];
		for (int n = typenum - 1; n >-1; n--) {
			cin >> array[n];
		}
		int available = money%array[typenum - 1];
		if (available == 0) {
			while (money != 0) {
				int change = money / array[idx];
				money -= change * array[idx++];
				ans += change;
			}
		}



		if (money == 0) {
			cout << ans << endl;
		}
		else if (available != 0) {
			cout << '0' << endl;
		}
		//	else if(money <=0){
		//		cout << '0';
		//	}
		idx = 0;
		ans = 0;
		delete[] array;
	}

	//string blank;
	//getline(cin, blank);
	//cout << blank;

}