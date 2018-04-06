
#include "stdafx.h"
#include <stdio.h>
#include<math.h>
int Answer;

int main(void)
{
	int find(int, int[], int[], int[], int[]);
	int max(int, int);
	int min(int, int);
	int test_case, T, n, x1[100], x2[100], y1[100], y2[100];
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	// freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	//setbuf(stdout, NULL);

	scanf_s("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).
		scanf_s("%d", &n);
		for (int q = 0; q < n; q++)
			scanf_s("%d %d %d %d", &x1[q], &y1[q], &x2[q], &y2[q]);
		printf("Case #%d\n", test_case + 1);
		Answer = find(n, x1, y1, x2, y2);
		if (Answer % 2 == 0)
			printf("%d\n", Answer / 2);
		else
			printf("%d.5\n", Answer / 2);

	}

	return 0;//Your program should return 0 on normal termination.
}
int min(int x, int y) {
	if (x >= y)
		return y;
	return x;
}
int max(int x, int y) {
	if (x >= y)
		return x;
	return y;
}

int find(int n, int x1[], int y1[], int x2[], int y2[]) {
	int i, j, dis = 0, mindis = 100000001;
	for (i = 0; i < n-1; i++) {
		for (j = i+1; j < n; j++) {
			if (mindis > max(abs(x1[j] - x1[i]), abs(y1[j] - y1[i])))
				mindis = max(abs(x1[j] - x1[i]), abs(y1[j] - y1[i]));
			printf("%d\n", mindis);
			if (mindis > max(abs(x2[j] - x2[i]), abs(y2[j] - y2[i])))
				mindis = max(abs(x2[j] - x2[i]), abs(y2[j] - y2[i]));
			printf("%d\n", mindis);
			if (dis < mindis)
				dis = mindis;
			mindis = 100000001;
		}
		
	}
	return dis;
}


