#include <stdio.h>
#include <stdlib.h>
short stack[500][500][500] = { 0 };
short count[500][500];
short answer[500];
short cost[500][500];
int main(void)
{
	int Road, Case;
	
	int T, Test_case;
	int r1, r2, cc;
	int i, j, k;
	
	int c,t;
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (Test_case = 0; Test_case < T; Test_case++)
	{
		//초기화
		c = 0;
		for (i = 0; i < 500; i++) {
			for (j = 0; j < 500; j++) {
				count[i][j] = 0;
				if (i == j) {
					cost[i][j] = 0;
				}
				else {
					cost[i][j] = 10001;
				}
			}
		}
		scanf("%d %d", &Road, &Case);
		for (i = 0; i < Case; i++)
		{
			scanf("%d %d %d", &r1, &r2, &cc);
			cost[r1 - 1][r2 - 1] = cc;
			cost[r2 - 1][r1 - 1] = cc;
		}
		
		//플로이드 워셜
		for (k = 0; k < Road; k++) {
			for (i = 0; i < Road;i++) {
				for (j = 0; j < Road;j++) {
					
					if (cost[i][j] > cost[i][k] + cost[k][j]) {
						cost[i][j] = cost[i][k] + cost[k][j];
						count[i][j]=0;
						stack[i][j][count[i][j]] = k;
						count[i][j]++;
					}
					else if (i!=k&&j!=k&&cost[i][j] == cost[i][k] + cost[k][j]) {
						stack[i][j][count[i][j]] = k;
						count[i][j]++;
					}
				}
			}
		}
		//조건 검색
		for (i = 0; i < Road; i++) {
			for (j = 0; j < Road; j++) {
				if (count[i][j] == 1) {
					t = 1;
					for (k = 0; k < c; k++) {
						if (answer[k] == stack[i][j][0]) {
							t = 0;
							break;
						}
					}
					if (t == 1) {
						answer[c] = stack[i][j][0];
						c++;
					}
				}
			}
		}
		//sorting
		for (i = 0; i < c; i++) {
			for (j = 0; j < c; j++) {
				if (answer[i] < answer[j]) {
					t = answer[i];
					answer[i] = answer[j];
					answer[j] = t;
				}
			}
		}
		//출력
		printf("Case #%d\n", Test_case + 1); 
		printf("%d ", c);
		for (i = 0; i < c; i++) {
			printf("%d ", answer[i]+1);
		}
		printf("\n");
	}
	return 0;
}
