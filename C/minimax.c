#include <stdio.h>


int minimax(int* matrix, int line, int column);
/* ----------------------------- Main function ----------------------------- */
int main () {
	int mtz[3][3] = {{1,2,3},
					 {4,5,6},
					 {7,8,9}};
	printf("The Minimax is: %d\n", minimax((int*)mtz,3,3));
	return 0;
}
/* --------------------------- Minimax function ---------------------------- */
int minimax(int* matrix, int line, int column) {
	int i, linha_minimax, minimax, max = 0;
	for (i = 0; i < line*column; i++) {
		if (max < matrix[i]) {
			max = matrix[i];
			linha_minimax = i/column;
		}
	}
	minimax = max;
	for (i = linha_minimax*column; i < (linha_minimax*column+column); i++) {
		if (minimax > matrix[i]) {
			minimax = matrix[i];
		}
	}
	return minimax;
}
