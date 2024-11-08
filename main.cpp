#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'X';
        resetBoard();
    }

    // Function to reset the board
    void resetBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    // Function to print the board
    void printBoard() {
        cout << "   0   1   2\n";
        for (int i = 0; i < 3; i++) {
            cout << i << "  ";
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "  ---|---|---\n";
        }
    }

    // Function to make a move
    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    // Function to switch players
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Function to check for a win
    bool checkWin() {
        // Check rows, columns, and diagonals
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    // Function to check if the board is full (i.e., draw)
    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    // Function to start the game
    void playGame() {
        int row, col;
        bool gameEnded = false;

        while (!gameEnded) {
            printBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (makeMove(row, col)) {
                if (checkWin()) {
                    printBoard();
                    cout << "Player " << currentPlayer << " wins!\n";
                    gameEnded = true;
                } else if (checkDraw()) {
                    printBoard();
                    cout << "The game is a draw!\n";
                    gameEnded = true;
                } else {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move! Try again.\n";
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
 return 0;
}
