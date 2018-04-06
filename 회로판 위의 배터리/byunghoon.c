/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>
#include <math.h>

int Answer;

int main(void)
{
	int T, test_case;
	int num;
	int x1[100], x2[100];
	int y1[100], y2[100];
	double xmax = 0, ymax = 0, xmaxmin=100000000, ymaxmin=100000000;
	double xtemp, ytemp;
	double xaver, yaver;
	// freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		}
		for (int i = 0; i < num; i++) {
			for (int j = 1; j < num; j++) {
				xaver = (x1[i] + x2[j]) / 2;
				yaver = (y1[i] + y2[j]) / 2;
				for (int k = 0; k < num; k++) {
					xtemp = fmin(xaver - x1[k], xaver - x2[k]);
					ytemp = fmin(xaver - x1[k], xaver - x2[k]);
					if (xmax < xtemp)xmax = xtemp;
					if (ymax < ytemp)ymax = ytemp;
				}
				if (xmax < xmaxmin)xmaxmin = xmax;
				if (ymax < ymaxmin)ymaxmin = ymax;
			}
			xmax = 0; 
			ymax = 0;
		}
		if (xmaxmin < ymaxmin)Answer = xmaxmin;
		else if (xmaxmin > ymaxmin)Answer = ymaxmin;
		else Answer = ymaxmin;
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}