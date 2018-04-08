#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
double Answer;


int main(void)
{
	int T, test_case, num;
	double bigX = 0, bigY = 0; // 받은 점 중 가장 큰 x값과 y값 저장
	double BatteryX = 0, BatteryY = 0; // 배터리의 좌표
	double** cor;

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 999999;
		BatteryX = 0; BatteryY = 0;
		bigX = 0; bigY = 0;
		scanf("%d", &num);
		cor = (double*)malloc(sizeof(double) * num);
		for (int i = 0; i < num; i++)
			cor[i] = (double*)malloc(sizeof(double) * 4);

		for (int i = 0; i < num; i++)
		{
			scanf("%lf %lf %lf %lf", &cor[i][0], &cor[i][1], &cor[i][2], &cor[i][3]);
			if (bigX < cor[i][0])
				bigX = cor[i][0];
			if (bigX < cor[i][2])
				bigX = cor[i][2];
			if (bigY < cor[i][1])
				bigY = cor[i][1];
			if (bigY < cor[i][3])
				bigY = cor[i][3];
		}

		for (double i = 0; i < bigX; i++)
		{
			for (double j = 0; j < bigY; j++)
			{
				double maxdistance = 0;
				for (int k = 0; k < num; k++)
				{
					double distance1 = MAX(fabs(cor[k][0] - i), fabs(cor[k][1] - j));
					double distance2 = MAX(fabs(cor[k][2] - i), fabs(cor[k][3] - j));
					double distance3 = MIN(distance1, distance2);
					if (maxdistance < distance3)
						maxdistance = distance3;
				}
				if (Answer > maxdistance)
					Answer = maxdistance;
			}
		}

		//printf("bigX = %lf, bigY = %lf\n", bigX, bigY);
		printf("Case #%d\n", test_case + 1);
		printf("%lf\n", Answer);

		for (int i = 0; i < num; i++)
			free(cor[i]);
		free(cor);

	}

	return 0;//Your program should return 0 on normal termination.
}