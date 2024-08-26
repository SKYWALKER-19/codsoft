#include <iostream>
#include <vector>

const char EMPTY = ' ';
const int SIZE = 3;

// Function prototypes
void displayBoard(const std::vector<std::vector<char>>& board);
bool isWin(const std::vector<std::vector<char>>& board, char player);
bool isDraw(const std::vector<std::vector<char>>& board);
bool isBoardFull(const std::vector<std::vector<char>>& board);
void makeMove(std::vector<std::vector<char>>& board, int row, int col, char player);

int main() {
    char playAgain;
    do {
        // Initialize the game board
        std::vector<std::vector<char>> board(SIZE, std::vector<char>(SIZE, EMPTY));
        char currentPlayer = 'X';
        bool gameWon = false;

        while (!isBoardFull(board) && !gameWon) {
            displayBoard(board);

            // Get the current player's move
            int row, col;
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            // Validate input
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != EMPTY) {
                std::cout << "Invalid move. Try again.\n";
                continue;
            }

            // Make the move
            makeMove(board, row, col, currentPlayer);

            // Check for a win
            if (isWin(board, currentPlayer)) {
                displayBoard(board);
                std::cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
            } else if (isDraw(board)) {
                displayBoard(board);
                std::cout << "The game is a draw!\n";
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask if players want to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

// Function to display the game board
void displayBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < SIZE - 1) std::cout << "|";
        }
        std::cout << "\n";
        if (i < SIZE - 1) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

// Function to check if the current player has won
bool isWin(const std::vector<std::vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Check columns
    for (int i = 0; i < SIZE; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool isDraw(const std::vector<std::vector<char>>& board) {
    return isBoardFull(board) && !isWin(board, 'X') && !isWin(board, 'O');
}

// Function to check if the board is full
bool isBoardFull(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}

// Function to make a move on the board
void makeMove(std::vector<std::vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}
