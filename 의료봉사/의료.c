#include <stdio.h>
#include<stdlib.h>

int Answer;
int N, P, M, linked[101][51][51], connected[51][51], J[51];
// linked[team][��][��ġ] linked[team][0][0] �� team�� ����Ȱ�� �� Ƚ�� linked[team][��][0]�� team�� �ش� �ֿ� �� ����Ȱ�� Ƚ��
// connected[��][��ġ]  i��° �� j��ġ�� �ִ� �������� ����� ���� ��
// J[i] i��° ���� ����Ȱ����� ��
int main(void)
{
	int T, test_case;
//	FILE *file;
	void initialize();
	int start(int, int);
	setbuf(stdout, NULL);
//	freopen_s(&file, "sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d %d %d", &N, &P, &M);
		for (int i = 1; i <= P; i++)
			scanf("%d", &J[i]);
		initialize();
		for (int length = 1; length <= N; length++) {
			int len;
			scanf("%d", &len);
			for (int i = 1; i <= len; i++) {
				int week, position;
				scanf("%d %d", &week, &position);
				linked[length][week][position] = 1;
				//printf("linked[%d][%d][%d]---=%d\n", length, week, position, linked[length][week][position]);
				connected[week][position]++;
			}
		}
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", start(1, 1));
	}
	return 0;//Your program should return 0 on normal termination.
}
void initialize() {
	for (int j = 0; j <= P; j++) {
		for (int q = 0; q <= J[j]; q++) {
			for (int i = 0; i <= N; i++) {
				linked[i][j][q] = 0;
			}
			connected[j][q] = 0;
		}
	}
}
int start(int week, int position) { // return 1 = possible 0 = impossible
	//printf("week %d  position %d\n", week, position);
	if (week > P) // ������ ���� ��츸 ����Ǳ� ������ week�� P�� �Ѿ��=> ��ġ�����ϴ�
		return 1;
	if (connected[week][position] == 0) // week, position�� ����� �������� ����
		return 0;
	else if (connected[week][position] == 1) { // week, position�� ����� ��������� 1���� �ִ�
		int i;
		for (i = 1; i <= N; i++) {
			if (linked[i][week][position] == 1) {     // ����� ������ ã��
				//		printf("connected==1 i = %d�� ����\n", i);
				break;
			}
		}
		//	printf("%d���� %d�ֿ� �� Ƚ��linked = %d\n", i,week,linked[i][week][0]);
		if (linked[i][week][0] != 0 || linked[i][0][0] >= M) { // i��° team�� week �ֿ� �̹� ����Ȱ�� �� or i��° ���� �� ����Ȱ�� Ƚ���� M�� �ʰ�
			//����� �������� �� �ֿ� �̹� ���縦 �߰ų� ���� Ƚ���� �ִ�ġ�� �ʰ�
	//		printf("�̹� ������ or Ƚ���ʰ�");
			return 0;   // ����� �� 1���ۿ� ���� ������ �ٷ� ����
		}
		else { // ���簡�� �����ߴٰ� ����
			linked[i][week][0]++; // i��° team week �ֿ� ����Ȱ�� Ƚ�� ����
			linked[i][0][0]++; // i��° team �� ����Ȱ�� Ƚ��

			if (position == J[week]) { // week �ֿ� �ִ� ������ �� ���� �ַ� �Ѿ��
				// 1�� 3��° �������̴� => ���� week position�� 2�� 1��° ������
				position = 1;
				week++;
			}
			else
				position++;
			// ���� week, position���� ���簡������ Ȯ��
			if (start(week, position)) // ���� ����
				return 1;
			else { // ���� ���� ����Ȱ�� �� ���� week, position ������ �ǵ�������
				linked[i][week][0]--; linked[i][0][0]--;
				if (position == 1)
				{
					week--;
					position = J[week];
				}
				else
					position--;
				return 0; // ����� �������� 1���ۿ� ���� ������ �ٷ� ����
			}
		}
		return 0;
	}
	else { // ����� �� 2�� �̻�
		int i,count=0;
		for (i = 1; i <= N; i++) {
			if (linked[i][week][position] == 1) { // ����� ������ ã��
			    count++;
				if (linked[i][week][0] != 0 || linked[i][0][0] >= M) // i��° team�� week �ֿ� �̹� ����Ȱ�� �� || i��° ���� �� ����Ȱ�� Ƚ�� �ʰ�
					continue; // ����� �� 2�� �̻��̱� ������ �̹� �������� �����ߴ��� ���� ������ Ȯ���ؾ���
				else { // ���缺���ߴٰ� ����
					linked[i][week][0]++; // i��° team week �ֿ� ����Ȱ�� Ƚ�� ����
					linked[i][0][0]++; // i��° ���� �� ����Ȱ�� Ƚ�� ����

					if (position == J[week]) {
						position = 1;
						week++;
					}
					else
						position++;
					if (start(week, position) == 1)
						return 1;
					else {
						if (position == 1)
						{
							week--;
							position = J[week];
						}
						else
							position--;
						linked[i][week][0]--; linked[i][0][0]--;
						//����� �� 2�� �̻��̱� ������ �������� �ʰ� ���� ������ã��
					}
				}
			}
			if (count > connected[week][position])
				return 0;
		}
		return 0;
	}
}
