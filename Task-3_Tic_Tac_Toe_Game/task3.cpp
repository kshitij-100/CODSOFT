#include <iostream>
using namespace std;

// Function to initialize the game board
void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

// Function to display the game board
void displayBoard(char board[3][3]) {
    cout << "    0\t   1\t 2\n\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout <<"  "<< board[i][j];
            if (j < 2) cout << "  | ";
        }
        cout << "\n";
        if (i < 2) cout << "  ------------------\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true; // Check columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true; // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true; // Check reverse diagonal
    return false;
}

// Function to check if the game is a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false; // If any empty cell is found, game is not a draw
    return true; // All cells are filled, game is a draw
}

// Function to play the Tic-Tac-Toe game
void playTicTacToe() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameWon = false;

    initializeBoard(board);

    do {
        displayBoard(board);

        // Player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameWon = true;
        } else if (checkDraw(board)) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            gameWon = true;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (!gameWon);

    // Ask if players want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playTicTacToe(); // Restart the game
    } else {
        cout << "Thanks for playing!\n";
    }
}

// Main function
int main() {
    cout << "TIC-TAC-TOE GAME\n";
    playTicTacToe();
    return 0;
}
