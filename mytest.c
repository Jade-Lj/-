#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu() {
	printf("----------------------------------------------\n");
	printf("--------------    ɨ����Ϸ    ----------------\n");
	printf("--------------  1.Play  0.Exit  --------------\n");
	printf("----------------------------------------------\n");
}
void test() {
	int input;
	do {
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}
int main() {
	srand((unsigned)time(NULL));
	test();
	return 0;
}
 