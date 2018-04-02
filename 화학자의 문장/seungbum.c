#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int Answer;

char ele[114][2] = { "h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al",

"si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe",

"co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr",

"y","zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb",

"te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au",

"hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg",

"bh", "hs", "Mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd",

"pm", "sm", "Eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac",

"th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md",

"no", "lr" };

int main(void)

{

	int T, test_case;

	char str[50001];

	int i, j,  check;



	setbuf(stdout, NULL);



	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)

	{

		Answer = 0;

		check = 0;

		scanf("%s", &str);

		i = 0;

		while (i<strlen(str)) {

			for (j = 0; j<114; j++) {

				if (str[i] == ele[j][0]) {

					Answer = 1;

					check++;

					if (ele[j][1]== 0) {

					    i++;

						break;

					}

					if (str[i + check] == ele[j][1]) {

						i+=2;

						break;

					}

					else{

						Answer = 0;

						check = 0;

					}

				}

				else {

					Answer = 0;

					check = 0;

				}

			}

			if (check == 0)

				break;

			

		}

		printf("Case #%d\n", test_case + 1);

		if (Answer == 1)

			printf("YES\n");

		else

			printf("NO\n");



	}



	return 0;
}
