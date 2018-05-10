#include <stdio.h>
//#pragma warning(disable:4996)
int Answer;

int main(void)
{
	int n;
	int T, test_case;
	
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int basis = 2;
		int indicator = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		scanf("%d", &n);
		while (indicator == 0) 
		{
			int temp_basis = basis; // basis 고정
			int current_basis = basis; // 현재 차수
			int temp_n = n;

			if (n < basis)
			{
				break;
			}

			while (current_basis < n)
			{
				current_basis = current_basis * temp_basis;
			}

			current_basis = current_basis / temp_basis;

			while (1)
			{
				int next = temp_n % current_basis; // 다음 순번

				if (current_basis >= temp_basis) // 다음 다음 순번이 있을 때
				{
					if (temp_n / current_basis != next / (current_basis / temp_basis)) // 현재 것과 다음 것이 같은지 확인
					{
						break;
					}
				}
				else // 다음 다음 순번이 없을 때
				{
					indicator = 1;
					break;
				}

				temp_n = temp_n % current_basis;
				current_basis = current_basis / temp_basis;
			}

			if(indicator == 0)
				basis++;
		}
		/////////////////////////////////////////////////////////////////////////////////////////////

		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", basis);

	}

	return 0;
}