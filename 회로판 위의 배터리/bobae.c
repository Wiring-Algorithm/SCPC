/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct dot {
	int x;
	int y;
}dot;

typedef struct line {
	dot A;
	dot B;
}line;

dot sumPosition = { 0,0 };

double dmax(double x, double y) {
	return (x > y) ? x : y;
}
double dmin(double x, double y) {
	return (x > y) ? y : x;
}

double ChebyshevDistance(dot chebyDot) {

	return dmax(fabs(chebyDot.x - sumPosition.x), fabs(chebyDot.y - sumPosition.y));
	// fabs 실수형 절대값
}

double distance(dot A, dot B) {
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

dot batteryPosition(line LA, line LB) {
	// 선분 두개에서 점들간의 거리를 비교해 최소 거리를 나타냄
	double min = distance(LA.A, LB.A);
	dot Battery;
	int arrow = 0;

	if (min > distance(LA.A, LB.B)) {
		arrow = 1;
	}

	if (min > distance(LA.B, LB.A)) {
		arrow = 2;
	}

	if (min > distance(LA.B, LB.B)) {
		arrow = 3;
	}

	switch (arrow) {
	case 1:
		Battery.x = (LA.A.x + LB.B.x) / 2;
		Battery.y = (LA.A.y + LB.B.y) / 2;
		break;
	case 2:
		Battery.x = (LA.B.x + LB.A.x) / 2;
		Battery.y = (LA.B.y + LB.A.y) / 2;
		break;
	case 3:
		Battery.x = (LA.B.x + LB.B.x) / 2;
		Battery.y = (LA.B.y + LB.B.y) / 2;
		break;

	default: // case == 0 ( arrow == 0)
		Battery.x = (LA.A.x + LB.A.x) / 2;
		Battery.y = (LA.A.y + LB.A.y) / 2;
	}
	return Battery;

}

int Answer = 0;

int main(void)
{
	int T, lineNum, test_case, k;
	line *lineMain;

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
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int i, j, count = 0;

		scanf("%d", &lineNum);
		lineMain = (line *)malloc(sizeof(line)*lineNum);

		for (k = 0; k < lineNum; k++) { //선분의 갯수 입력한 것

			scanf("%d %d %d %d", &(lineMain[k].A.x), &(lineMain[k].A.y), &(lineMain[k].B.x), &(lineMain[k].B.y));
		}

		for (i = 0; i < lineNum; i++) {
			for (j = i + 1; j < lineNum; j++, count++) {
				sumPosition.x += batteryPosition(lineMain[i], lineMain[j]).x;
				sumPosition.y += batteryPosition(lineMain[i], lineMain[j]).y;
			}
		}

		sumPosition.x /= count;
		sumPosition.y /= count;

		for (i = 0; i < lineNum; i++) {
			if (distance(lineMain[i].A, sumPosition) < distance(lineMain[i].B, sumPosition)) {
				if (Answer < ChebyshevDistance(lineMain[i].A)) {	// 선분의 양 점에서와 배터리 점과의 거리 비교 B가 더 짧으면 B와 배터리 점과의 전원거리 계산
					Answer = ChebyshevDistance(lineMain[i].A);	// 그 전원거리가 최소값보다 작으면 최소값 갱신.(모든 선의 최소의 전원거리)
				}
			}
			else {
				if (Answer < ChebyshevDistance(lineMain[i].B)) {	// 선분의 양 점에서와 배터리 점과의 거리 비교 B가 더 짧으면 B와 배터리 점과의 전원거리 계산
					Answer = ChebyshevDistance(lineMain[i].B);	// 그 전원거리가 최소값보다 작으면 최소값 갱신.(모든 선의 최소의 전원거리)
				}
			}
		}

		free(lineMain);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);
	}
	return 0;//Your program should return 0 on normal termination.
}