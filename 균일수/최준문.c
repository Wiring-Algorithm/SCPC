/*
	수행시간 : 1.00026
	메모리   : 6500
	점수     : 106.5 점
*/

#include <stdbool.h>
#include <stdio.h>

int getBase(int n);
int Answer;

int main(void)
{
	int T, test_case, N;
	setbuf(stdout, NULL);
    
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &N);
		Answer = getBase(N);

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}

int getBase(int Num)
{
	int Ans = 0,b = 2;
	int Share = 0, Rest = 0;
	bool check = true;

	//if (Num % 2 == 0)	b = 3;
	
		for (int x = b; x <= 1000000000; x++)
		{
			Share = Num / x;
			Rest = Num % x;
			
			while (1)
			{
				if (Share == 0) break;
				if (Rest != Share % x) 
				{
					check = false; 
					break;
				}
				else
				{
					check = true;
				}
				Rest = Share % x;
				Share = Share / x;
			}
			
			if (check == true) 
			{
				Ans = x;
				break;
			}
		}

	return Ans;
}