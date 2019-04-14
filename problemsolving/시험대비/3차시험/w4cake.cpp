#include <iostream>
#include <map>

using namespace std;

map<int, int> m_a, m_b;

void get_map(int *array, map<int, int>& m, int size) {
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int sum = 0;
			for (int k = 1; k <= i; k++) {
				if (j + k - 1 >= size) {
					sum += array[j + k - 1 - size];
				}
				else {
					sum += array[j + k - 1];
				}
			}
			m[sum] += 1;
		}
	}
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	m[sum] += 1;
}
void test() {
	//ios_base::sync_with_stdio(false);
	int target;
	cin >> target;

	int sizeA, sizeB;
	cin >> sizeA >> sizeB;

	//int A[sizeA], B[sizeB];
	int *A = new int[sizeA];
	int *B = new int[sizeB];
	for (int i = 0; i < sizeA; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < sizeB; i++) {
		cin >> B[i];
	}

	get_map(A, m_a, sizeA);
	get_map(B, m_b, sizeB);

	int count = 0;
	count = m_a[target] + m_b[target];

	for (int i = 1; i <= target; i++) {
		if (m_a[i] && m_b[target - i]) {
			count += m_a[i] * m_b[target - i];
		}
	}
	cout << count << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		test();
		m_a.clear(), m_b.clear();
	}
}