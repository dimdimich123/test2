#include "lib.h"
#include "game.h"
void pole(int **A, int *B, int flag, int jk) {
	int j;
	clear();
	printw("1: ");
	for (j = 0; j < B[0]; j++) printw(" %d|", A[0][j]);
	printw("\n2: ");
	for (j = 0; j < B[1]; j++) printw(" %d|", A[1][j]);
	printw("\n3: ");
	for (j = 0; j < B[2]; j++) printw(" %d|", A[2][j]);
    printw("\n");
	if (jk == 4) {
		printw("4: ");
		for (j = 0; j < B[3]; j++) printw(" %d|", A[3][j]);
		printw("\n");
	}
	if (flag)
		printw("Now your turn\n");
	else{
		printw("Now computer turn\n");
	    getch();
    }
	return;
}

void difficulty() {
	int dif;
	clear();
	printw("difficulty\n1-Standart\n2-Mariband\n3-go back");
	while (1) {
		dif = getch();
		switch (dif) {
			case '1':
				standart(3);
				clear();
				return;
			case '2':
				standart(4);
				clear();
				return;
			case '3':
				clear();
				return;
		}
	}
}

int winner(int *B, int w, int jk) {
	if (w) {
		if (jk == 3) {
			if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
				printw("You Won. YHuuuu!!!\n");
				getch();
				return 1;
			}
		}
		if (jk == 4) {
			if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
				printw("You Won. YHuuuu!!!\n");
				getch();
				return 1;
			}
		}
	}
	if (w == 0) {
		if (jk == 3) {
			if (B[0] == 0 && B[1] == 0 && B[2] == 0) {
				printw("You lose");
				getch();
				return 0;
			}
		}
		if (jk == 4) {
			if (B[0] == 0 && B[1] == 0 && B[2] == 0 && B[3] == 0) {
				printw("You lose");
				getch();
				return 0;
			}
		}
	}
	return 2;
}
