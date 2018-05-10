#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Answer;

int main(void)
{
	int T, test_case, input, base, b, n;
	int in[11] = { 4,6,9,12,15,16,20,21,25,26,30 };
	setbuf(stdout, NULL);
	//T = 11;
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = -1;
		b = 2;
		scanf("%d", &input);
		//input = in[test_case];
		if (input == 2 || input == 1)
		{
			if (input == 2)
				Answer = 3;
			else
				Answer = 2;
		}
		else
		{
			while (b < sqrt(input))
			{
				n = input;
				base = n % b;
				while (n / b >= 0 && base != 0)
				{
					if (n%b != base)
						break;
					n /= b;
				}
				if (n == 0)
				{
					Answer = b;
					break;
				}
				else if (Answer == -1)
					b++;
				else
					b++;
			}
			if (Answer == -1)
				Answer = input - 1;
			printf("Case #%d\n", test_case + 1);
			printf("%d\n", Answer);
		}
	}
	//system("pause");
	return 0;
}