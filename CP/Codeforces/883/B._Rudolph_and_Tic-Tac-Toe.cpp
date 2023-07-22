
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<string> board(3);
        for (int i = 0; i < 3; i++) {
            cin >> board[i];
        }

        string winner = "DRAW";
        // Check rows
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                winner = board[i][0];
                break;
            }
        }

        // Check columns
        if (winner == "DRAW") {
            for (int j = 0; j < 3; j++) {
                if (board[0][j] != '.' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
                    winner = board[0][j];
                    break;
                }
            }
        }

        // Check diagonals
        if (winner == "DRAW") {
            if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
                winner = board[0][0];
            } else if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
                winner = board[0][2];
            }
        }

        cout << winner << endl;
    }

    return 0;
}
