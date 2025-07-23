#include <iostream>
using namespace std;

// Function to display the game board
void displayBoard(char board[3][3]) {
    cout << "Current Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check for a win
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Columns
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // If there's an empty space, it's not a draw
            }
        }
    }
    return true; // No empty spaces, it's a draw
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char currentPlayer = 'X';
    char playAgain;

    do {
        // Reset the board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }

        bool gameWon = false;

        while (!gameWon) {
            displayBoard(board);
            int row, col;

            // Get player input
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Validate input
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            // Update the board
            board[row][col] = currentPlayer;

            // Check for win or draw
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameWon = true;
            } else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                gameWon = true;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
