#define _CRT_SECURE_NO_WARNINGS // protection of scanf error

#include <stdio.h>
#include "BinaryTree.h"


int main() {
	BTreeNode * rootNode = MakeBTreeNode();
	BTreeNode * curNode = rootNode;
	int num, menu, top_menu;

	printf("Enter the Root Node : ");
	scanf("%d", &num);
	SetData(rootNode, num);

	while (1) {

		printf("-Root Node : ");
		PrintData(rootNode);
		printf("-Select Node : ");
		PrintData(curNode);

		if (curNode != NULL) {
			printf("Data of left node : ");
			PrintData(curNode->left);
			printf("Data of right node : ");
			PrintData(curNode->right);
		}
		else {
			curNode = rootNode;
			printf("-Error. Fail to move.( Can't move to NULL )\n");
			printf("Comeback to Root Node\n");
			continue;
		}

		
	//	do {
			//메뉴 반복
			printf("\n 1 : Move the node\n");
			printf(" 2 : Add the node\n");
			printf(" 3 : EXIT\n");
			printf("Enter the menu : ");
			scanf("%d", &top_menu);
			// move data 이거 move 하기전에 데이터 뜨게끔 만약 데이터 왼쪽 오른쪽이 널이면 바로 와일문 컨티뉴로 메뉴로 돌아가게 만들자
			switch (top_menu) {
			case 1:
				printf("Move node ( 1: Left / 2 : Right / 3 : Root ) : ");
				scanf("%d", &menu);
				/*
				printf("Seleted Node : ");
				PrintData(curNode);
				if (curNode != NULL) {
				printf("Data of left node : ");
				PrintData(curNode->left);
				printf("Data of right node : ");
				PrintData(curNode->right);
				}
				else break;
				*/

				if (menu == 1 || menu == 2 || menu == 3) {
					switch (menu) {
					case 1:
						curNode = curNode->left;
						break;
					case 2:
						curNode = curNode->right;
						break;
					case 3:
						curNode = rootNode;
						break;
					}
				}

				break;

			case 2:
				// Add Node Code
				printf("Add node ( 1 : Left / 2 : Right ) : ");
				scanf("%d", &menu);
				if (menu == 1 || menu == 2) {
					printf("Enter the data of next node : ");
					scanf("%d", &num);

					BTreeNode * newNode = MakeBTreeNode();
					SetData(newNode, num);

					if (menu == 1) {
						MakeLeftSubTree(curNode, newNode);
					}
					else if (menu == 2) {
						MakeRightSubTree(curNode, newNode);
					}
					else {
						printf("Invalid menu!\n");
					}
				}
				break; // last sentence of switch.
			}
		

		if (top_menu == 3) {
			printf("\n\n*** EXIT **\n");
			Traversal(rootNode);
			break;
		}

//	} while (top_menu == 1 || top_menu == 2);
		
		
	}
	return 0;

}