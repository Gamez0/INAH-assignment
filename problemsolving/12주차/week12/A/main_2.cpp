#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;
const int MAX = 10000000;
typedef pair<int, int> two;

struct Edge {
	int way, d;
	bool ring;
	Edge *dual;
	Edge() : Edge(-1, 0) {}
	Edge(int to1, int d1) : way(to1), d(d1), ring(false), dual(nullptr) {}
};

int n, m, pre[1000];
vector<Edge*> adj[1000];
Edge *road[1000] = { nullptr };
Edge *change[1000] = { nullptr };
int time[1000];
void settime() {
	fill(time, time + n, MAX);
	time[0]=0;
}

int Dijkstra(bool test = false) {
	settime();
	bool visited[1000] = { 0 };
	priority_queue<two, vector<two>, greater<two>> prioryQ;
	prioryQ.push(two(0, 0));

	while (!prioryQ.empty()) {
		int temp;
		do {
			temp = prioryQ.top().second;
			prioryQ.pop();
		} while (!prioryQ.empty() && visited[temp]);
		if (visited[temp]) break;

		visited[temp] = true;
		for (Edge *e : adj[temp]) {
			int next = e->way, d = e->d;
			if (e->ring || visited[next]) continue;
			if (time[next] > time[temp] + d) {
				time[next] = time[temp] + d;
				prioryQ.push(two(time[next], next));
				if (test) {
					pre[next] = temp;
					road[next] = e;
				}
			}
		}
	}
	return time[n - 1];
	//delete time;
}

void test() {
	cin >> n >> m;
	for (int i = 0; i<m; i++) {
		int num1, num2, num3;
		cin >> num1 >> num2 >> num3;
		num1--; num2--;
		Edge *e1 = new Edge(num2, num3);
		Edge *e2 = new Edge(num1, num3);
		e1->dual = e2;
		e2->dual = e1;
		adj[num1].push_back(e1);
		adj[num2].push_back(e2);
	}

	int before = Dijkstra(true);
	int after = before;
	//Edge *change[1000] = { nullptr };
	for (int i = 0; i < 1000; i++) {
		change[i] = { nullptr };
	}
	int len = 0;
	for (int i = 0, j = n - 1; j != 0; i++, j = pre[j]) {
		change[i] = road[j];
		len++;
	}
	for (int i = 0; i<len; i++) {
		change[i]->ring = change[i]->dual->ring = true;
		after = max(after, Dijkstra());
		change[i]->ring = change[i]->dual->ring = false;
	}
	if (after == MAX) {
		cout << "-1" << endl;
	}
	else {
		cout << after - before << endl;
	}
	//delete change;
}
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		test();
		for (int i = 0; i < 1000; i++) {
			adj[i].clear();
		}
	}
}