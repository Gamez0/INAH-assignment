#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct xyPoint {
	short x;
	short y;
}xyPoint;

int main() {
	int t;
	xyPoint* Position;
	int num;
	short top, bottom, left, right;
	cin >> t;
	while (t--) {
		cin >> num;
		Position = (xyPoint*)malloc(sizeof(xyPoint)*num);

		for (int i = 0; i < num; ++i)
			cin >> Position[i].x >> Position[i].y;
		left = Position[0].x;
		right= Position[0].x;
		top = Position[0].y;
		bottom = Position[0].y;

		for (int i = 1; i < num; ++i) {
			if (top < Position[i].y) {
				top = Position[i].y;
			}
			if (bottom > Position[i].y) {

			}
		}
	}
}