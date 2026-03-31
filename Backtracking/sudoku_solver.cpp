#include <iostream>
using namespace std;

void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if placing 'dig' at sudoku[row][col] is valid
bool isSafe(int sudoku[9][9], int row, int col, int dig) {
    // horizontal
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == dig) return false;
    }

    // vertical
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == dig) return false;
    }

    // 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (sudoku[i][j] == dig) return false;
        }
    }

    return true;
}

// Sudoku solver using backtracking
bool sudoku_solver(int sudoku[9][9], int row, int col) {
    if (row == 9) {
        printSudoku(sudoku);
        return true;  // ✅ Stop after one solution is found
    }

    int nextRow = row;
    int nextCol = col + 1;
    if (col + 1 == 9) {
        nextRow = row + 1;
        nextCol = 0;
    }

    if (sudoku[row][col] != 0) {
        return sudoku_solver(sudoku, nextRow, nextCol);
    }

    for (int dig = 1; dig <= 9; dig++) {
        if (isSafe(sudoku, row, col, dig)) {
            sudoku[row][col] = dig;
            if (sudoku_solver(sudoku, nextRow, nextCol)) {
                return true; // ✅ stop recursion once solved
            }
            sudoku[row][col] = 0; // backtrack
        }
    }

    return false; // trigger backtracking
}

int main() {
    int sudoku[9][9] = {
        {0, 0, 8, 0, 0, 0, 0, 0, 0},
        {4, 9, 0, 1, 5, 7, 0, 0, 2},
        {0, 0, 3, 0, 0, 4, 1, 9, 0},
        {1, 8, 5, 0, 6, 0, 0, 2, 0},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {9, 6, 0, 4, 0, 5, 3, 0, 0},
        {0, 3, 0, 0, 7, 2, 0, 0, 4},
        {0, 4, 9, 0, 3, 0, 0, 5, 7},
        {8, 2, 7, 0, 0, 9, 0, 1, 3}
    };

    if (!sudoku_solver(sudoku, 0, 0)) {
        cout << "No solution exists." << endl;
    }

    return 0;
}
