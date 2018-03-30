#include <stdio.h>



int main(void)
{
	int T, test_case;
	int N=0, i;
	float x1=0, y1=0, x2=0, y2=0;
	float x = 0, y = 0;

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		
		printf("Case #%d\n", test_case + 1);
		printf("선분의 수? ");
		scanf("%d", N);

		for (i = 0; i < N; i++)
		{
			printf("Line #%d: ", i + 1);
			scanf("%f %f %f %f", x1, y1, x2, y2);
		}

		printf("Battery Location: ");
		scanf("%f %f", x, y);







	}

	return 0;//Your program should return 0 on normal termination.
}