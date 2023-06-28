#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > board(8, vector<char>(8));
int counter = 0;

bool isSafe(int row, int col) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < 8; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void placeQueens(int row) {
    if (row == 8) {
        counter++;
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (board[row][col] == '.' && isSafe(row, col)) {
            board[row][col] = 'Q';
            placeQueens(row + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    placeQueens(0);

    cout << counter << endl;

    return 0;
}
