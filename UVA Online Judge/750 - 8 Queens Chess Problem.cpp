#include <bits/stdc++.h>

int rowOfCol[8];
int counter = 0;

bool valid(int row, int col){
	for(int a = 0; a < col; a++)
		if(rowOfCol[a] == row || abs(rowOfCol[a] - row) == abs(a - col))
			return false;
	return true;
}

void backtrack(int col, int inputRow, int inputCol){
	if(col == 8 && rowOfCol[inputCol] == inputRow){
		printf("%2d      %d", ++counter, rowOfCol[0] + 1);
		for(int a = 1; a < 8; a++)
			printf(" %d", rowOfCol[a] + 1);
		printf("\n");
	}

	for(int a = 0; a < 8; a++){
		if(valid(a, col)){
			rowOfCol[col] = a;
			backtrack(col + 1, inputRow, inputCol);
		}
	}
}

int main(){
	int TC;

	scanf("%d", &TC);

	while(TC--){
		int inputRow;
		int inputCol;

		scanf("%d %d", &inputRow, &inputCol);

		--inputRow;
		--inputCol;

		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");

		counter = 0;
		
		backtrack(0, inputRow, inputCol);

		if(TC) printf("\n");
	}
}