#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int BOARD_SIZE = 10;
const char EMPTY = ' ';
const char BALL = 'O';
const char PLAYER = 'P';

void playCatchTheBall() {
    srand(time(0));
    char board[BOARD_SIZE][BOARD_SIZE];
    int playerRow = BOARD_SIZE - 1;
    int playerCol = BOARD_SIZE / 2;
    int ballRow = 0;
    int ballCol = rand() % BOARD_SIZE;

    for (int row = 0; row < BOARD_SIZE; ++row)
        for (int col = 0; col < BOARD_SIZE; ++col)
            board[row][col] = EMPTY;

    board[playerRow][playerCol] = PLAYER;
    board[ballRow][ballCol] = BALL;

    bool gameRunning = true;
    int score = 0;

    while (gameRunning) {
        system("cls");

        for (int row = 0; row < BOARD_SIZE; ++row) {
            for (int col = 0; col < BOARD_SIZE; ++col) {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }

        char move;
        cout << "Move (a=left, d=right): ";
        cin >> move;

        board[playerRow][playerCol] = EMPTY;

        if (move == 'a' && playerCol > 0) --playerCol;
        else if (move == 'd' && playerCol < BOARD_SIZE - 1) ++playerCol;

        board[playerRow][playerCol] = PLAYER;
        board[ballRow][ballCol] = EMPTY;

        if (ballRow < playerRow) {
            ++ballRow;
        } else {
            if (rand() % 2 == 0 && ballCol > 0) --ballCol;
            else if (ballCol < BOARD_SIZE - 1) ++ballCol;
            ++ballRow;
        }

        if (ballRow == playerRow && ballCol == playerCol) {
            ++score;
            ballRow = 0;
            ballCol = rand() % BOARD_SIZE;
        }

        board[ballRow][ballCol] = BALL;

        if (ballRow == BOARD_SIZE - 1) gameRunning = false;
    }

    cout << "Game Over! Your score: " << score << endl;
}

