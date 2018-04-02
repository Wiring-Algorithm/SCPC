/*
삼성 SCPC 화학자의 문장 문제
점수: 88
수행시간: 0.38
메모리:8312
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#pragma warning(disable:4996)

int Answer;

int main(void)
{
	int T, test_case, len, count = 0, i, two = 1;
	char str[1000001];
	char* ele[] = {
		"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al",
		"Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe",
		"Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr",
		"Y","Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb",
		"Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au",
		"Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Rf", "Db", "Sg",
		"Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd",
		"Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
		"Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md",
		"No", "Lr"
	};

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++){
		Answer = 1;
		fgets(str, sizeof(str), stdin);
		len = strlen(str);
		while (len >= count){
			char tmp[3];

			if (len - count > 2){
				if (two == 1){
					tmp[0] = str[count];
					tmp[1] = str[count + 1];
					tmp[2] = '\0';
				}
				else{
					tmp[0] = str[count];
					tmp[1] = '\0';
				}
			}
			else{
				tmp[0] = str[count];
				tmp[1] = '\0';
			}

			for (i = 0; i < 114; i++){

				if (strcasecmp(tmp, ele[i]) == 0){
					break;
				}
				else{
					continue;
				}
			}

			if (i == 114){
				if (two == 1){
					two = 0;
				}
				else{
					Answer = 0;
					break;
				}
			}
			else{
				if (two == 1)
					count = count + 2;
				else
					count++;

				two = 1;
			}
		}

		printf("Case #%d\n", test_case + 1);
		if (Answer == 1)
			printf("YES\n");
		else
			printf("NO\n");
		count = 0;
	}

	return 0;//Your program should return 0 on normal termination.
}