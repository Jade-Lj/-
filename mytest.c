#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
void menu() {
	printf("----------------------------------------------\n");
	printf("--------------    扫雷游戏    ----------------\n");
	printf("--------------  1.Play  0.Exit  --------------\n");
	printf("----------------------------------------------\n");
}
void test() {
	int input;
	do {
		menu();
		printf("请选择：->");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main() {
	srand((unsigned)time(NULL));
	test();
	return 0;
}
 