#include <stdio.h>
int Answer = 0, n, anw[501];
struct point {
	int dis[501];
	int path[501];
};
struct point point[501];
int main(void) {
	void floyd_warshall();
	void init();
	int T, test_case, m, a, b, c;
	setbuf(stdout, NULL);
	scanf("%d", &test_case);
	for (T = 0; T < test_case; T++) {
		scanf("%d %d", &n, &m);
		Answer = 0;
		init();
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			point[a].dis[b] = c;
			point[b].dis[a] = c;
		}
	
		floyd_warshall();

		printf("Case #%d\n", T + 1);
		for (int i = 1; i <= n; i++)
			if (anw[i] != 0)
				Answer++;
		printf("%d", Answer);
		for (int i = 1; i <= n; i++)
			if (anw[i] != 0)
				printf(" %d", i);
		printf("\n");

	}
	return 0;
}
void floyd_warshall() {
	int k, i, j;
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			if (i == k)
				continue;
			for (j = i + 1; j <= n; j++) {
				if (j == k)
					continue;
				//printf("%d %d %d %d %d %d\n", k, k, j, point[i].dis[j], point[i].dis[k], point[k].dis[j]);
				if (point[i].dis[k] == 10001 || point[k].dis[j] == 10001)
					continue;
				if (point[i].dis[j] >= point[i].dis[k] + point[k].dis[j]) {
					//	printf("ij = %d ik = %d jk = %d\n", point[i].dis[j], point[i].dis[k], point[k].dis[j]);
					//	printf("k = %d\n", k);
				//	anw[point[i].path[j]]--;
					if (point[i].dis[j] > point[i].dis[k] + point[k].dis[j]) {
						point[i].dis[j] = point[i].dis[k] + point[k].dis[j];
						point[j].dis[i] = point[i].dis[k] + point[k].dis[j];
					//	point[i].path[j] = k;
						anw[k]++;
					}
					else{
					 //   point[i].path[j]=0;
					}
					
				}	
			}
		}
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				point[i].dis[j] = 0;
				point[j].dis[i] = 0;
			}
			else {
				point[i].dis[j] = 10001;
				point[j].dis[i] = 10001;
			}
			point[i].path[j] = 0;
		}
		anw[i] = 0;
	}
}
