#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

int win = 0;

void Initial(char arr[rows][cols],char set) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = set;
		}
	}
}
void print_arr(char arr[rows][cols]) {
	for (int j = 0; j <= col; j++) {
		printf(" %-2d|",j);
	}
	printf("\n");
	for (int i = 1; i <= row; i++) {
		printf(" %-2d|", i);
		for (int j = 1; j <= col; j++) {
			printf(" %-2c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void setboom(char arr[rows][cols]) {
	int x, y;
	int count = Easy_level;
	printf("--------------------         ��ը����       -------------------\n");
	Sleep(2000);
	while (count) {
		x = rand() % row +1;
		y = rand() % col +1;
		if (arr[x][y] == '0') {
			arr[x][y] = '1';
			count--;
		}
	}
}
int num_boom(char arr[rows][cols],int x, int y) {
	return arr[x - 1][y - 1] +
		arr[x][y - 1] +
		arr[x + 1][y - 1] +
		arr[x - 1][y] +
		arr[x + 1][y] +
		arr[x - 1][y + 1] +
		arr[x][y + 1] +
		arr[x + 1][y + 1] - 8 * '0';
}

void findotherboom(char arr[rows][cols],char arr2[rows][cols], int x, int y) {
	if (x>=1 && x<= row && y>=1 && y<= col && arr2[x][y] == '*') 
	{
		if (arr[x][y] != '1') 
		{
			int count = num_boom(arr, x, y);
			if (count == 0)
			{
				arr2[x][y] = ' ';
				win++;
				//print_arr(arr2);
				findotherboom(arr, arr2, x - 1, y - 1);
				findotherboom(arr, arr2, x, y - 1);
				findotherboom(arr, arr2, x + 1, y - 1);
				findotherboom(arr, arr2, x - 1, y);
				findotherboom(arr, arr2, x - 1, y);
				findotherboom(arr, arr2, x + 1, y);
				findotherboom(arr, arr2, x - 1, y + 1);
				findotherboom(arr, arr2, x, y + 1);
				findotherboom(arr, arr2, x + 1, y + 1);
					
			}
			else 
			{
				arr2[x][y] = count + '0';
				win++;
				//print_arr(arr2);
			}
		}	
	}
	return;
}


void findboom(char arr[rows][cols], char arr2[rows][cols]) {
	int x, y;
	char flag;
	while (win < row*col - Easy_level) {
		printf("����������:(1<=x<=%d  1<=y<=%d  w:ɨ�� q:���) ��:1,1,w\n",col,row);
		scanf("%d,%d,%c", &y, &x, &flag);
		if ((1 <= x <= row) && (1 <= y <= col)) {
			if (flag == 'w') {
				if (arr2[x][y] == '*' || arr2[x][y] == '#') {
					if (arr[x][y] == '1') {
						printf("���ź����㱻ը���ˣ�\n");
						print_arr(arr);
						break;
					}
					else {
						int count = num_boom(arr, x, y);
						//�Ų���Χ����
						if (count == 0) {
							findotherboom(arr, arr2, x, y);
						}
						else {
							arr2[x][y] = count + '0';
							win++;
						}
						print_arr(arr2);
					}
				}
				else {
					printf("��λ����ɨ��������ѡ��λ��\n");
				}
			}
			else if(flag == 'q') {		
				arr2[x][y] = '#';
				print_arr(arr2);
			}
			else {
				printf("�ַ���������������");
			}
		}
		else {
			printf("����Ƿ������������룡\n");
		}
	}
	if (win == row * col - Easy_level) {
		printf("��ϲ���׳ɹ�\n");
		print_arr(arr);
	}
}

void game() {
	printf("****************����ɨ����Ϸ***************\n");
	char black_board[rows][cols] = { 0 };
	char white_board[rows][cols] = { 0 };
	Initial(black_board,'0');
	Initial(white_board, '*');
	//print_arr(black_board);
	print_arr(white_board);
	//����
	setboom(black_board);
	//print_arr(black_board);
	//ɨ��
	findboom(black_board, white_board);
	

}