/*
회로판 위에 배터리		손승범
수행시간: 0.00382 ~ 0.00437
메모리: 8 ~ 8312
점수: 200
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
int Answer;
struct point {
	int x;
	int y;
};
int amax(int a, int b) {
	if (a >= b) {
		return a;
	}
	else {
		return b;
	}
}
int main(void)
{
	int T, t, test_case, Test_case;
	int i, j, coo[100][100], c1, c2, max1, max2, max;
	struct point p1[100][2];
	freopen("input2.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (Test_case = 0; Test_case < T; Test_case++)
	{
		scanf("%d", &t);
		for (test_case = 0; test_case < t; test_case++) {
			//데이터 받아오기
			scanf("%d %d %d %d", &p1[test_case][0].x, &p1[test_case][0].y, &p1[test_case][1].x, &p1[test_case][1].y);
		}
		max = 0;
		for (i = 0; i < t; i++) {
			max1 = 0;
			max2 = 0;
			for (j = 0; j < t; j++) {
				if (i == j) {
				}
				else {
					//선분의 각점에서 가장 짧은 거리 계산
					c1 = min(max(abs(p1[i][0].x - p1[j][0].x), abs(p1[i][0].y - p1[j][0].y)), max(abs(p1[i][0].x - p1[j][1].x), abs(p1[i][0].y - p1[j][1].y)));
					c2 = min(max(abs(p1[i][1].x - p1[j][0].x), abs(p1[i][1].y - p1[j][0].y)), max(abs(p1[i][1].x - p1[j][1].x), abs(p1[i][1].y - p1[j][1].y)));
					if (c1 > max1)
						max1 = c1;
					if (c2> max2)
						max2 = c2;

				}
			}
			//두점의 거리중에 작은 값이 가장 크게 만들기
			if (min(max1, max2) > max)
				max = min(max1, max2);
		}
		Answer = max;
		printf("Case #%d\n", Test_case + 1);
		if (Answer % 2 == 0) {
			printf("%d\n", Answer / 2);
		}
		else {
			printf("%d.5\n", Answer / 2);
		}
	}

	return 0;
}