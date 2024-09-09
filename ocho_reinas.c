#include <stdio.h>
#include <stdbool.h>

#define N 8

// Función para imprimir el tablero
void printBoard(int board[N][N]) {
	int i = 0;
	int j = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (board[i][j] == 1)
                printf("* ");
            else
                printf("- ");
        }
        printf("\n");
    }
}

// Función para verificar si es seguro colocar una reina en la posición (row, col)
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Verifica la fila en el lado izquierdo
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Verifica la diagonal superior izquierda
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Verifica la diagonal inferior izquierda
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Función recursiva para resolver el problema de las N reinas
bool solveNQueensUtil(int board[N][N], int col) {
    // Si todas las reinas están colocadas, retorna true
    if (col >= N)
        return true;

	int i = 0;
    // Intenta colocar una reina en cada fila de la columna actual
    for (i = 0; i < N; i++) {
        // Verifica si es seguro colocar una reina en la posición (i, col)
        if (isSafe(board, i, col)) {
            // Coloca la reina
            board[i][col] = 1;

            // Recursivamente coloca las reinas en el resto del tablero
            if (solveNQueensUtil(board, col + 1))
                return true;

            // Si colocar la reina en (i, col) no conduce a una solución, retírala
            board[i][col] = 0;
        }
    }

    // Si no se puede colocar una reina en ninguna fila de esta columna, retorna false
    return false;
}

// Función para resolver el problema de las N reinas
bool solveNQueens() {
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0)) {
        printf("No existe solución.\n");
        return false;
    }

    printBoard(board);
    return true;
}

int main() {
    solveNQueens();
    return 0;
}

