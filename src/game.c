#include "lib.h"
#include "menu.h"
#include "game.h"

void BubbleSort(int *A, int n){
int i,j,k;
    for(i=0;i<n-1;i++){
       for(j=n-1;j>i;j--){              
        if(A[j]<A[j-1]){
         k=A[j];
         A[j]=A[j-1];
         A[j-1]=k;
        }
       }
    }
return;
}

void PlayerTurn(int **A, int *B, int jk) {
	int m, n;
	while (1) {
		pole(A, B, 1, jk);
		printw("Viberite kychky 0 or 1 or 2:\n");
		scanw("%d", &m);
		if (m > jk - 1 && m < 0) continue;
		printw("Viberite spichki 1-10:\n");
		scanw("%d", &n);
		if (n > 2000000000) continue;
		if (n < 1) continue;
		if (m == 1) {
			if (B[0] == 0) continue;
			if (B[0] >= n) {
				B[0] -= n;
				return;
			}
			if (B[0] < n) {
				B[0] = 0;
				return;
			}
		}
		if (m == 2) {
			if (B[1] == 0) continue;
			if (B[1] >= n) {
				B[1] -= n;
				return;
			}
			if (B[1] < n) {
				B[1] = 0;
				return;
			}
		}
		if (m == 3) {
			if (B[2] == 0) continue;
			if (B[2] >= n) {
				B[2] -= n;
				return;
			}
			if (B[2] < n) {
				B[2] = 0;
				return;
			}
		}
		if (m == 4) {
			if (B[3] == 0) continue;
			if (B[3] >= n) {
				B[3] -= n;
				return;
			}
			if (B[3] < n) {
				B[3] = 0;
				return;
			}
		}
	}
	return;
}

void ComputerTurn(int **A, int *B, int jk) {
	pole(A, B, 0, jk);
	int max1, i, min, med, med2, raz = 0, C[jk];
	if (jk == 3) {
		for (i = 0; i < jk; i++) C[i] = B[i];
		BubbleSort(C,jk);
		min = C[0];
		med = C[1];
		max1 = C[2];
        if (med == max1 && min == 0) med=max1-1;
		if (med == max1) med = min;
		raz = max1 + min - med;
		if (B[0] == max1) {
			B[0] -= raz;
			return;
		}
		if (B[1] == max1) {
			B[1] -= raz;
			return;
		}
		if (B[2] == max1) {
			B[2] -= raz;
			return;
		}
		return;
	}
	if (jk == 4) {
		for (i = 0; i < jk; i++) C[i] = B[i];
		BubbleSort(C,jk);
		min = C[0];
		med = C[1];
		med2 = C[2];
		max1 = C[3];
		raz = max1 + med - min - med2;
		if (raz == 0) raz = max1;
		if (B[0] == max1) {
			B[0] -= raz;
			return;
		}
		if (B[1] == max1) {
			B[1] -= raz;
			return;
		}
		if (B[2] == max1) {
			B[2] -= raz;
			return;
		}
		if (B[3] == max1) {
			B[3] -= raz;
			return;
		}
		return;
	}

	return;
}

void games(int **A, int *B, int jk) {
	clear();
	int win = 2;
	while (1) {
		ComputerTurn(A, B, jk);
		win = winner(B, 0, jk);
		if (win == 0) break;
		clear();
		PlayerTurn(A, B, jk);
		win = winner(B, 1, jk);
		if (win == 1) break;
	}
	return;
}

void standart(int jk) {
	int i, j, **A, *B;
	A = (int  **)malloc(jk*sizeof(int *));
	for (i = 0; i < jk; i++) {
		A[i] = (int *)malloc(10*sizeof(int));
		for (j = 0; j < 10; j++) A[i][j] = j + 1;
	}
	B = (int *)malloc(jk*sizeof(int));
	if (jk == 3) {
		B[0] = rand() % 3 + 1;
		B[1] = rand() % 3 + 4;
		B[2] = rand() % 4 + 7;
	} else {
		B[0] = 1;
		B[1] = 3;
		B[2] = 5;
		B[3] = 7;
	}
	games(A, B, jk);
    for (i = 0; i < jk; i++) free (A[i]);
	free (A);
    free (B);
	return;
}
