#include <stdio.h>
#include <stdlib.h>
char* tictactoe(int** moves, int movesSize, int* movesColSize);
int main() {
    int movesArray[5][2] = {{1,2}, {2,1}, {1,1}, {2,1}, {2,2}};
    int movesSize = 5;
    int movesColSize[] = {2, 2, 2, 2, 2};
    int** moves = (int**)malloc(movesSize * sizeof(int*));
    for(int i = 0; i < movesSize; i++) {
        moves[i] = (int*)malloc(2 * sizeof(int));
        moves[i][0] = movesArray[i][0];
        moves[i][1] = movesArray[i][1];
    }
    char* result = tictactoe(moves, movesSize, movesColSize);
    printf("Result: %s\n", result);
    for(int i = 0; i < movesSize; i++) {
        free(moves[i]);
    }
    free(moves);
    return 0;
}
char* tictactoe(int** moves, int movesSize, int* movesColSize) {
    char* temp[3][3] = {{"0","0","0"},{"0","0","0"},{"0","0","0"}};
    int i = 0 , j = 0;
    int row, col;
    int cA = 0, cB = 0;
    for(i = 0 ; i < movesSize ; i++) {
        row = moves[i][1];
        col = moves[i][0];
        if(i % 2)
            temp[row][col] = "B";
        else
            temp[row][col] = "A";
    }
    for(int i = 0; i < 3; i++) {
        cA = 0; cB = 0;
        for(int j = 0; j < 3; j++) {
            if(temp[i][j] == "A")
                cA++;
            if(temp[i][j] == "B")
                cB++;
        }
        if(cA == 3)
            return "A";
        if(cB == 3)
            return "B";
    }
    for(int j = 0; j < 3; j++) {
        cA = 0; cB = 0;
        for(int i = 0; i < 3; i++) {
            if(temp[i][j] == "A")
                cA++;
            if(temp[i][j] == "B")
                cB++;
        }
        if(cA == 3)
            return "A";
        if(cB == 3)
            return "B";
    }
    cA = 0; cB = 0;
    for(int j = 0, i = 0; j < 3 && i < 3; j++, i++) {
        if(temp[i][j] == "A")
            cA++;
        if(temp[i][j] == "B")
            cB++;
        if(cA == 3)
            return "A";
        if(cB == 3)
            return "B";
    }
    cA = 0; cB = 0;
    for(int j = 2, i = 0; j >= 0 && i < 3; j--, i++) {
        if(temp[i][j] == "A")
            cA++;
        if(temp[i][j] == "B")
            cB++;
        if(cA == 3)
            return "A";
        if(cB == 3)
            return "B";
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(temp[i][j] == "0")
                return "Pending";
        }
    }
    return "Draw";
}

