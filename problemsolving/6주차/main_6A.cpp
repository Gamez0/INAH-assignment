#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;
#define range 1001
int arrx[range], arry[range];
int his1[range], his2[range];
int N, M;
int fix[range];

int dis(int i, int j)
{
	return (abs(fix[i] - fix[j]));
}
void input()
{

	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> fix[i];
}
void func()
{
	for (int i = 0; i < range; i++)
	{
		arrx[i] = 0;
		arry[i] = 0;
		his1[i] = 0;
		his2[i] = 0;
	}
	arrx[0] = abs(fix[1] - 1);
	arry[0] = abs(fix[1] - N);
	int tmp1[range];
	int tmp2[range];
	int tmp3;
	for (int i = 2; i <= M; i++)
	{
		for (int j = 0; j <= i - 2; j++)
		{
			tmp1[j] = arrx[j] + dis(i, i - 1);
		}
		fix[0] = 1;
		tmp3 = -1;
		for (int j = 0; j <= i - 2; j++)
		{
			if (tmp3 > arry[j] + dis(j, i) || tmp3 == -1)
			{
				tmp3 = arry[j] + dis(j, i);
				his1[i] = j;
			}
		}
		tmp1[i - 1] = tmp3;
		for (int j = 0; j <= i - 2; j++)
		{
			tmp2[j] = arry[j] + dis(i, i - 1);
		}
		fix[0] = N;
		tmp3 = -1;
		for (int j = 0; j <= i - 2; j++)
		{
			if (tmp3 > arrx[j] + dis(j, i) || tmp3 == -1)
			{
				tmp3 = arrx[j] + dis(j, i);
				his2[i] = j;
			}
		}
		tmp2[i - 1] = tmp3;
		for (int j = 0; j <= i - 1; j++)
		{
			arrx[j] = tmp1[j];
			arry[j] = tmp2[j];
		}
	}
}
void print()
{
	int tmp1, tmp2, tmp3;
	tmp1 = -1;
	for (int i = 0; i <= M - 1; i++)
	{
		if (tmp1 == -1 || arrx[i]<tmp1)
		{
			tmp1 = arrx[i];
			tmp2 = 1;
			tmp3 = i;
		}
	}
	for (int i = 0; i <= M - 1; i++)
	{
		if (tmp1 == -1 || arry[i]<tmp1)
		{
			tmp1 = arry[i];
			tmp2 = 2;
			tmp3 = i;
		}
	}
	cout << tmp1 + 1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		input();
		func();
		print();
	}
}
