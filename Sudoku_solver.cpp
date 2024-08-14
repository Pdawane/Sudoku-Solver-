#include <iostream>
#include<time.h>
using namespace std;

const int N = 9; // Size of the Sudoku grid

// Function to print the Sudoku grid
// void printGrid(int grid[N][N]) {
//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++) {
//             cout << grid[row][col] << " ";
//         }
//     }
// }

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0 && row != 0) {
            cout << "------+------+------\n";
        }
        for (int col = 0; col < N; col++) {
            if (col % 3 == 0 && col != 0) {
                cout << "| ";
            }
            if (grid[row][col] == 0) {
                cout << "  ";
            } else {
                cout << grid[row][col] << " ";
            }
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in a particular cell
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is already present in the current row or column
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    // If the number is not present anywhere in the row, column, or subgrid, it's safe to place
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    int row, col;

    // Find an empty cell (if any)
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    // If no empty cell is found, the puzzle is solved
    if (!isEmpty) {
        return true;
    }

    // Try placing numbers from 1 to 9 in the empty cell
    for (int num = 1; num <= 9; num++) {
        // Check if it's safe to place 'num' in the empty cell
        if (isSafe(grid, row, col, num)) {
            // Place the number in the empty cell
            grid[row][col] = num;

            // Recursively try to solve the Sudoku puzzle
            if (solveSudoku(grid)) {
                return true; // If solved, return true
            }

            // If not solved, backtrack and try the next number
            grid[row][col] = 0;
        }
    }

    // If no number can be placed in the current cell, backtrack
    return false;
}

bool SolveSudoku(int grid[N][N]) {
    if (solveSudoku(grid)) {
        return true;
    }
    return false;
}


void takeInput(int grid[N][N]) {
    cout << "Enter the Sudoku grid (9x9, use 0 for blank cells):\n";
    for (int row = 0; row < N; row++) {
        cout << "Row " << row + 1 << ": ";
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }
}



int main() {
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // int grid[N][N];
    // takeInput(grid);

    // // // Print the Sudoku grid
    // // cout << "\nInput Sudoku grid:\n";
    // // printGrid(grid);






    if (SolveSudoku(grid)) {
        printGrid(grid);
    } else {
        cout << "No solution exists!";
    }

    return 0;
}
