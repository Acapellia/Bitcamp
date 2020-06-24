#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#include<windows.h>

#define BOARD_SIZE 18
#define CARD_SIZE 4
#define CARD_NUM 8
struct Card {
	int card;
};
struct Select {
	int x, y;
	int card;
};
int board[BOARD_SIZE][BOARD_SIZE] = { 0 };
void init_board(Card card[CARD_NUM]) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		board[0][i] = -1;	board[BOARD_SIZE - 1][i] = -1; board[i][0] = -1; board[i][BOARD_SIZE - 1] = -1;
	}
	int idx = 0;
	/*printf("Card Set\n");
	for (int i = 0; i < CARD_NUM*2; i++)
		printf("%d ", card[i].card);
	printf("\n\n");*/
	for (int i = 1; i < BOARD_SIZE - 1; i=i+CARD_SIZE) {
		for (int j = 1; j < BOARD_SIZE - 1; j=j+CARD_SIZE) {
			for (int x = 0 + i; x < CARD_SIZE + i; x++) {
				for (int y = 0 + j; y < CARD_SIZE + j; y++) {
					board[x][y] = card[idx].card;
				}
			}
			idx++;
		}
	}
	/*for (int i = 1; i < BOARD_SIZE - 1; i++) {
		for (int j = 1; j < BOARD_SIZE - 1; j = j++) {
			printf("%d ", board[i][j]);
		}printf("\n");
	}*/
}
void show_board() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j = j++) {
			if (board[i][j] == -1) { printf("¢Ì"); }
			else if (board[i][j] == 0) { printf("¡Ú"); }
			else if (board[i][j] == 1) { printf("¢Ä"); }
			else if (board[i][j] == 2) { printf("¡Ý"); }
			else if (board[i][j] == 3) { printf("¢¼"); }
			else if (board[i][j] == 4) { printf("¢¾"); }
			else if (board[i][j] == 5) { printf("¢À"); }
			else if (board[i][j] == 6) { printf("¡ß"); }
			else if (board[i][j] == 7) { printf("¢Ã"); }
			else if (board[i][j] == 8) { printf("¢Ý"); }
			else if (board[i][j] == 9) { printf("¡Ø"); }
			
		}printf("\n");
	}
}
int success[10] = { 0 };
void hide_board() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j = j++) {
			if (board[i][j] == -1) { printf("¢Ì"); }
			else if (success[0] == 1 && board[i][j] == 0) { printf("¡Ú"); }
			else if (success[1] == 1 && board[i][j] == 1) { printf("¢Ä"); }
			else if (success[2] == 1 && board[i][j] == 2) { printf("¡Ý"); }
			else if (success[3] == 1 && board[i][j] == 3) { printf("¢¼"); }
			else if (success[4] == 1 && board[i][j] == 4) { printf("¢¾"); }
			else if (success[5] == 1 && board[i][j] == 5) { printf("¢À"); }
			else if (success[6] == 1 && board[i][j] == 6) { printf("¡ß"); }
			else if (success[7] == 1 && board[i][j] == 7) { printf("¢Ã"); }
			else if (success[8] == 1 && board[i][j] == 8) { printf("¢Ý"); }
			else if (success[9] == 1 && board[i][j] == 9){ printf("¡Ø"); }
			else { 
				if (i % CARD_SIZE == 0 && j % CARD_SIZE == 0) { printf("¡à"); }
				else if (i % CARD_SIZE == 0 || j % CARD_SIZE == 0) { printf("¡á"); }
				else { printf("¡à"); }
			}
		}printf("\n");
	}
}
void create_card(Card card[CARD_NUM],int idx[10]) {
	int check[20] = { 0 };
	int tempNum[20] = { 0 };
	int c = 0;
	while (c < CARD_NUM*2) {
		int n = rand() % 8 +1;
		if (check[n] < 2) {
			check[n]++; tempNum[c++] = n;
		}
	}
	/*for (int i = 0; i < CARD_NUM*2; i++) {
		printf("%d ", tempNum[i]);
	}printf("\n");*/
	int Ccheck[10] = { 0 };
	for (int i = 1; i <= CARD_NUM; i++) {
		int r;
		while (1) {
			r = rand() % 10;
			if (Ccheck[r] == 1) continue;
			break;
		}
		for (int j = 0; j < CARD_NUM * 2; j++) {
			if (tempNum[j] == i) card[j].card = r;
		}
		Ccheck[r] = 1;		
	}
}
void show_selected(Select select[2]) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j = j++) {
			if (board[i][j] == -1) { printf("¢Ì"); }
			else {
				int exist=0;
				for (int k = 0; k < 2; k++) {
					if ((i - 1) / CARD_SIZE == select[k].x && (j - 1) / CARD_SIZE == select[k].y) {
						if (board[i][j] == 0) { printf("¡Ú"); exist = 1; break;}
						else if (board[i][j] == 1) { printf("¢Ä"); exist = 1; break;}
						else if (board[i][j] == 2) { printf("¡Ý"); exist = 1; break;}
						else if (board[i][j] == 3) { printf("¢¼"); exist = 1; break;}
						else if (board[i][j] == 4) { printf("¢¾"); exist = 1; break;}
						else if (board[i][j] == 5) { printf("¢À"); exist = 1; break;}
						else if (board[i][j] == 6) { printf("¡ß"); exist = 1; break;}
						else if (board[i][j] == 7) { printf("¢Ã"); exist = 1; break;}
						else if (board[i][j] == 8) { printf("¢Ý"); exist = 1; break;}
						else if (board[i][j] == 9) { printf("¡Ø"); exist = 1; break;}
					}
				}
				if (exist == 0) {
					if (success[0] == 1 && board[i][j] == 0) { printf("¡Ú"); continue;}
					else if (success[1] == 1 && board[i][j] == 1) { printf("¢Ä"); continue; }
					else if (success[2] == 1 && board[i][j] == 2) { printf("¡Ý"); continue;}
					else if (success[3] == 1 && board[i][j] == 3) { printf("¢¼"); continue; }
					else if (success[4] == 1 && board[i][j] == 4) { printf("¢¾"); continue; }
					else if (success[5] == 1 && board[i][j] == 5) { printf("¢À"); continue; }
					else if (success[6] == 1 && board[i][j] == 6) { printf("¡ß"); continue; }
					else if (success[7] == 1 && board[i][j] == 7) { printf("¢Ã"); continue; }
					else if (success[8] == 1 && board[i][j] == 8) { printf("¢Ý"); continue; }
					else if (success[9] == 1 && board[i][j] == 9) { printf("¡Ø"); continue; }
					if (i % CARD_SIZE == 0 && j % CARD_SIZE == 0) { printf("¡à"); }
					else if (i % CARD_SIZE == 0 || j % CARD_SIZE == 0) { printf("¡á"); }
					else { printf("¡à"); }
				}
			}
		}printf("\n");
	}
}
int main()
{
	srand(time(NULL));
	Card card[CARD_NUM*2];
	Select select[2];
	char picture[10] = { '¡Ú','¢Ä','¡Ý','¢¼','¢¾','¢À','¡ß','¢Ã','¢Ý','¡Ø' };
	int idx[20];
	int time = 0, correct = 0;
	create_card(card, idx);
	/*for (int i = 0; i < CARD_NUM*2; i++) {
		printf("%d ", card[i].card);
	}*/
	init_board(card);
	int selectCnt = 0;
	while (1) {
		if (correct == CARD_NUM / 2) {
			printf("\nSuccess!!!\n");
			break;
		}
		show_board();
		while (time++ < 100) {
			Sleep(50);
		}
		system("cls");
		hide_board();
		int x, y;
		printf("select first card : ");
		scanf("%d %d", &x, &y);
		x *= CARD_SIZE; y *= CARD_SIZE;
		select[selectCnt].x = (x - 1) / CARD_SIZE;
		select[selectCnt].y = (y - 1) / CARD_SIZE;
		select[selectCnt].card = board[x][y];
		selectCnt = 1;
		if (selectCnt == 1) {
			while (1) {
				system("cls");
				show_selected(select);
				printf("select Second card : ");
				scanf("%d %d", &x, &y);
				x *= CARD_SIZE; y *= CARD_SIZE;
				select[selectCnt].x = (x - 1) / CARD_SIZE;
				select[selectCnt].y = (y - 1) / CARD_SIZE;
				select[selectCnt].card = board[x][y];
				int stime = 0;
				while (stime++<20) {
					system("cls");
					show_selected(select);
				}
				if (select[0].card != select[1].card) { 
					selectCnt = 0;
					select[0].x = -1; select[0].y = -1; select[0].card = -2;
					select[1].x = -1; select[1].y = -1; select[1].card = -2;
					printf("different\n");  break;
				}
				else {
					selectCnt = 0; success[select[0].card] = 1; correct = 1;
					select[0].x = -1; select[0].y = -1; select[0].card = -2;
					select[1].x = -1; select[1].y = -1; select[1].card = -2;
					printf("same\n"); break;
				}
			}
		}
		
	}
	
	return 0;
}