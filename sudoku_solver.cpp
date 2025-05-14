#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> >& board, int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num)
            return false;
        int startRow = 3 * (row / 3) + x / 3;
        int startCol = 3 * (col / 3) + x % 3;
        if (board[startRow][startCol] == num)
            return false;
    }

    return true;
}

bool solve(vector<vector<int> >& board, int row = 0, int col = 0) {
    if (row == 9) return true;
    if (col == 9) return solve(board, row + 1, 0);
    if (board[row][col] != 0) return solve(board, row, col + 1);

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solve(board, row, col + 1)) return true;
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int> > board(9, vector<int>(9));
    cout << "Enter 9 x 9 Sudoku (0 for blanks) :\n";
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cin >> board[i][j];

    if (solve(board)) {
        cout << "\nSolved Sudoku :\n";
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }
}