#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct xyPoint
{
	//int x;
	//int y;
	short x;
	short y;
} xyPoint;

int size(int l, int r, int t, int b) {
	return (r - l)*(t - b);
}

int main() {
	std::ios::sync_with_stdio(false);
	int t;
	xyPoint* Position;
	int num;        
	short top, bottom,left, right;    // 4 점의좌표
	cin >> t;

	while (t--) {
		cin >> num;
		Position = (xyPoint*)malloc(sizeof(xyPoint)*num);
		// 좌표를모두읽어온다

		for (int i = 0; i < num; ++i)
			cin >> Position[i].x >> Position[i].y;


		// 좌표들의최소값/최대값을찾는다

		left = Position[0].x;

		right = Position[0].x;

		top = Position[0].y;

		bottom = Position[0].y;

		for (int i = 1; i < num; ++i){
			if (top < Position[i].y) {
				top = Position[i].y;
			}
			if (bottom > Position[i].y) {
				bottom = Position[i].y;
			}
			if (left > Position[i].x) {
				left = Position[i].x;
			}
			if (right < Position[i].x) {
				right = Position[i].x;
			}
		}

		//cout << size(left, right, top, bottom) << endl;
		cout << (right - left)*(top - bottom) << endl;
	
		free(Position);

	}
}
// 참고 사이트https://m.blog.naver.com/PostView.nhn?blogId=xtelite&logNo=50037742762&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F