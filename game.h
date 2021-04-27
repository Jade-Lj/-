#pragma once
#ifndef __GAME_H__
#define __GAME_H__
#define row 9
#define col 9
#define rows row+2
#define cols col+2
#define Easy_level 10

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

extern int win;

void Initial(char arr[rows][cols], char set);
void print_arr(char arr[rows][cols]);
void game();
void findboom(char arr[rows][cols], char arr2[rows][cols]);
void setboom(char arr[rows][cols]);
int num_boom(char arr[rows][cols], int x, int y);
void findotherboom(char arr[rows][cols], char arr2[rows][cols], int x, int y);
#endif // !__GAME_H__
