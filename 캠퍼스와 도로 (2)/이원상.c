#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 10001

int Answer = 0, node, edge, *check = NULL;

typedef struct _NODE {
	int length;
	int bridge;
}NODE;

NODE **graph = NULL;

int main(void)
{
	int T, test_case, row = 0, col = 0, length = 0;
	int minIndex = 0, minLength = 0;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d", &node, &edge);

		graph = (NODE**)malloc(sizeof(NODE*) * node);
		check = (int*)malloc(sizeof(int)* node);

		for (int i = 0; i < node; i++) {
			graph[i] = (NODE*)malloc(sizeof(NODE) * node);
			check[i] = 0;
			for (int j = 0; j < node; j++) {
				if (i == j)
					graph[i][j].length = 0;
				graph[i][j].length = INF;
				graph[i][j].bridge = -1;
			}
		}	
	
		for (int i = 0; i < edge; i++) {			
			scanf("%d %d %d", &row, &col, &length);
			graph[row - 1][col - 1].length = graph[col - 1][row - 1].length = length;
		}
		

		for (int k = 0; k < node; k++) {
			for (int i = 0; i < node; i++) {
				for (int j = i + 1; j < node; j++) {
					if (graph[i][j].length > graph[i][k].length + graph[k][j].length) {
						graph[j][i].length = graph[i][j].length = graph[i][k].length + graph[k][j].length;

						if (graph[i][j].bridge != -1) {
							check[graph[i][j].bridge]--;
						}
						
						graph[i][j].bridge = graph[i][j].bridge = k;
						check[k]++;
					}
					else if (graph[i][j].length == graph[i][k].length + graph[k][j].length) {
						check[graph[i][j].bridge]--;
					}
				}
			}
		}

		for (int i = 0; i < node; i++) {
			if (check[i] > 0) {
				Answer++;
			}
		}

		printf("Case #%d\n", test_case + 1);
		printf("%d", Answer);
		
		for (int i = 0; i < node; i++) {
			if (check[i] > 0) {
				printf(" %d", i + 1);
				Answer--;

				if (Answer == 0)
					break;
			}	
		}
		printf("\n");
	}

	return 0;
}
