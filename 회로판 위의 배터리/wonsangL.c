/*
수행시간: 0.00492
메모리: 8312
점수: 140
*/
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))

typedef struct node {
	int index;
	float value;
	struct node* previous;
	struct node* next;
}NODE;

void insertion(NODE** head, NODE** tail, int index, float value);
float getDistance(NODE* head, NODE* tail, float avg, int* count);

int main(void)
{
	int T, test_case, N;
	float buffer, distX, distY, sumX = 0, sumY = 0; // x / y좌표의 최대값과 합을 저장하는 변수

	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		scanf("%d", &N);

		int *countX = (int*)calloc(N, sizeof(int));
		int *countY = (int*)calloc(N, sizeof(int));

		NODE* headX = NULL; // 링크드 리스트의 head(최소값)
		NODE* tailX = NULL; // 링크드 리스트의 tail(최대값)
		
		NODE* headY = NULL;
		NODE* tailY = NULL;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 4; j++) {
				scanf("%f", &buffer);

				if (j % 2 == 0) {
					insertion(&headX, &tailX, i, buffer);
					countX[i]++;
					sumX += buffer;
				}
				else {
					insertion(&headY, &tailY, i, buffer);
					countY[i]++;
					sumY += buffer;
				}
			}
		}

		sumX /= N * 2;
		sumY /= N * 2;

		distX = getDistance(headX, tailX, sumX, countX);
		distY = getDistance(headY, tailY, sumY, countY);

		printf("Case #%d\n", test_case + 1);
		printf("%g\n", MAX(distX, distY));
	}

	return 0;
}

//오름차순으로 정렬하여 링크드 리스트를 생성
void insertion(NODE** head, NODE** tail, int index, float value) {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->index = index;
	newNode->value = value;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (*head == NULL) {
		*head = newNode;
		*tail = newNode;
		return;
	}

	NODE* current = *head;
	NODE* previous = NULL;

	while (current != NULL) {
		if (current->value > newNode->value) {
			if (previous == NULL) {
				newNode->next = current;
				*head = newNode;
				return;
			}

			previous->next = newNode;
			newNode->previous = previous;
			newNode->next = current;
			current->previous = newNode;
			return;
		}

		previous = current;
		current = current->next;
	}
	
	previous->next = newNode;
	newNode->previous = previous;
	*tail = newNode;
}

float getDistance(NODE* head, NODE* tail, float avg, int* count) {
	while (1) {
		if (head->index == tail->index) {	
			//최소값과 최대값의 같은 선분 안에 있을 경우
			int headCount = 0, tailCount = 0;
			NODE* tempHead = head;
			NODE* tempTail = tail;

			while (tempHead->value <= avg) {
				tempHead = tempHead->next;
				headCount++;
			}

			while (tempTail->value >= avg) {
				tempTail = tempTail->previous;
				tailCount++;
			}

			//평균값과 현재값(최대, 최소) 사이에 존재하는 점이 적을 경우 제외

			if (headCount > tailCount) {
				count[tail->index]--;
				tail = tail->previous;
			}
			else {
				count[head->index]--;
				head = head->next;
			}

		}

		//최대값 최소값을 제외
		if (count[head->index] > 1) {
			count[head->index]--;
			head = head->next;
		}

		if (count[tail->index] > 1) {
			count[tail->index]--;
			tail = tail->previous;
		}

		if (count[head->index] == 1 && count[tail->index] == 1)
			break;
	}

	return (tail->value - head->value) / 2.0;
}