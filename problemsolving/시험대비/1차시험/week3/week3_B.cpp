#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int lca[100010];
int doc[100010];
int parent[100010];
int q, a, b, c;
int N, K;
int getlca(int a, int b, int k) {
	if (a == b) {
		return a;
	}
	int cnt = 0;
	while (a&&cnt < 100001) {
		lca[a] = k;
		a = parent[a];
		cnt++;
	}
	cnt = 0;
	while (b&&cnt < 100001) {
		if (lca[b] == k)
			return b;
		b = parent[b];
	}
	return 0;
}




int main() {
	scanf_s("%d%d", &N, &K);
	for (int i = 0; i < N; i++) {
		doc[i] = 1;
	}
	for (int i = 1; i <= K; i++) {
		scanf_s("%d%d%d", &q, &a, &b);
		if (q == 1) {
			scanf_s("%d", &c);
			int anc = getlca(a, b, i);
			while (a != anc) {
				doc[a] = c;
				a = parent[a];
			}
			while (b != anc) {
				doc[b] = c;
				b = parent[b];
			}
		}
		else if (q == 2) {
			parent[a] = b;
		}
		else {
			if (a == b) {
				printf("0\n");
				continue;
			}
			set<int> st;
			int anc = getlca(a, b, i);
			while (a != anc) {
				st.insert(doc[a]);
				a = parent[a];
			}
			while (b != anc) {
				st.insert(doc[b]);
				b = parent[b];
			}
			printf("%d\n",st.size());
		}
	}
	return 0;
}