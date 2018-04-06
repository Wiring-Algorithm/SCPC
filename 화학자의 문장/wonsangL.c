/*
삼성 SCPC 화학자의 문장 문제
점수: 91.63, 수행시간: 0.4, 메모리 6896
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Answer;
char grid[24][36] = { "al;ar;as;ag;au;at;ac;am",
	"be;b;br;ba;bi;bh;bk",
	"c;cl;ca;cr;co;cn;ce;cm;cf;cu;cd;cs",
	"db;ds;dy",
	"eu;er;es",
	"f;fe;fr;fl",
	"ga;ge;gd",
	"h;he;hf;hg;hs;ho",
	"in;i;ir",
	"k;kr",
	"li;lv;la;lu;lr",
	"mg;mn;mo;mt;md",
	"n;ne;na;ni;nb;nd;np;no",
	"o;os",
	"p;pd;pt;pb;po;pr;pm;pa;pu",
	"rb;ru;rh;re;rn;ra;rf;rg",
	"si;s;sc;se;sr;sn;sb;sg;sm",
	"ti;tc;te;ta;tl;tb;tm;th",
	"u",
	"v",
	"w",
	"x",
	"y;yb",
	"zn;zr"
};

int check(char *str, int index) {
	if (strlen(str) <= index) {
		return 1;
	}

	int curIndex = str[index] - 97;
	int result = 0;

	if (strchr(str, 'j') || strchr(str, 'q')) {
		return 0;
	}

	if (curIndex >= 16) {
		curIndex -= 2;
	}
	else if (curIndex >= 9) {
		curIndex -= 1; 
	}

	char *temp = (char*)malloc(sizeof(grid[curIndex]));
	strcpy(temp, grid[curIndex]);

	char* token = strtok(temp, ";");
	
	while (token != NULL && result == 0) {
		if (strlen(token) == 2) {
			if (token[1] == str[index + 1]) {
				result = check(str, index + 2);
			}
		}
		else {
			result = check(str, index + 1);
		}

		token = strtok(NULL, ";");
	}

	return result;
}

int main(void)
{
	int T, test_case;
	char input[50000];

	setbuf(stdout, NULL);

	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%s", input);

		Answer = check(input, 0);

		printf("Case #%d\n", test_case + 1);
		if (Answer == 0) {
			printf("NO\n"); 
		}
		else {
			printf("YES\n");
		}
	}

	return 0;
}