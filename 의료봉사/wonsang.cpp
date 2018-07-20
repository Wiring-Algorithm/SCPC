#include<iostream>
#include<vector>

using namespace std;

int C, N, P, M, f, h, j, k;
bool **check;
int *counter;
vector<vector<vector<int>>> graph;

bool Check(int week, int region) {
	bool result = false;
	
	if (week == P)
		return true;
	
	for (int m = 0; m < graph[week][region].size(); m++) {
		if (check[graph[week][region][m]][week] && counter[graph[week][region][m]] < M) {				
			check[graph[week][region][m]][week] = false;
			counter[graph[week][region][m]]++;
			
			if (region == graph[week].size() - 1)
				result = Check(week + 1, 0);
			else
				result = Check(week, region + 1);

			check[graph[week][region][m]][week] = true;
			counter[graph[week][region][m]]--;
		}

		if (result)
			return result;
	}
		
	return false;
}

int main() {
	cin >> C;

	for (int i = 0; i < C; i++) {
		bool flag = false;
		cin >> N >> P >> M;

		graph.resize(P);
		check = new bool*[N];
		counter = new int[N];

		for (int m = 0; m < P; m++) {
			cin >> f;
			graph[m].resize(f);
		}

		for (int m = 0; m < N; m++) {
			cin >> h;
			check[m] = new bool[P];
			counter[m] = 0;

			for (int n = 0; n < h; n++) {
				cin >> j >> k;
				graph[j - 1][k - 1].push_back(m);
			}
		}

		flag = Check(0, 0);

		cout << flag << endl;

		graph.clear();
		delete[] check;
		delete[] counter;
	}
}