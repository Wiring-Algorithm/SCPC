#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)

int Answer;
struct Line {
	int x;
	int y;
};

int main(void)
{
	int T, t, test_case, Test_case;
	int i, j, distance_first, distance_second, max_first, max_second, max_all;
	struct Line L1[100][2];

	scanf("%d", &T);

	for (Test_case = 0; Test_case < T; Test_case++)
	{
		scanf("%d", &t);
		for (test_case = 0; test_case < t; test_case++) {
			scanf("%d %d %d %d", &L1[test_case][0].x, &L1[test_case][0].y, &L1[test_case][1].x, &L1[test_case][1].y);
		}
		max_all = 0;
		for (i = 0; i < t; i++) {

			max_first = 0;
			max_second = 0;
			for (j = 0; j < t; j++) {
				if (i != j) {
		distance_first = min( max( abs(L1[i][0].x - L1[j][0].x), abs(L1[i][0].y - L1[j][0].y)), max(abs(L1[i][0].x - L1[j][1].x), abs(L1[i][0].y - L1[j][1].y)));
		if (distance_first > max_first)
		max_first = distance_first;
		distance_second = min( max( abs(L1[i][1].x - L1[j][0].x), abs(L1[i][1].y - L1[j][0].y)), max(abs(L1[i][1].x - L1[j][1].x), abs(L1[i][1].y - L1[j][1].y)));
					
					if (distance_second> max_second)
						max_second = distance_second;
				}
			}
			if (min(max_first, max_second) > max_all)
				max_all = min(max_first, max_second);
		}
		Answer = max_all;
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
