#include<bits/stdc++.h>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char human, ai;

void printBoard() {
    cout << "---------\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << "---------\n";
}

bool isMovesLeft() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;
    return false;
}

int evaluate() {
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == ai)
                return +10;
            else if (board[row][0] == human)
                return -10;
        }
    }

    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == ai)
                return +10;
            else if (board[0][col] == human)
                return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == ai)
            return +10;
        else if (board[0][0] == human)
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == ai)
            return +10;
        else if (board[0][2] == human)
            return -10;
    }

    return 0;
}

int minimax(int depth, bool isMax, int alpha, int beta) {
    int score = evaluate();

    if (score == 10)
        return score - depth;
    if (score == -10)
        return score + depth;
    if (!isMovesLeft())
        return 0;

    if (isMax) {
        int best = numeric_limits<int>::min();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = ai;
                    best = max(best, minimax(depth + 1, false, alpha, beta));
                    alpha = max(alpha, best);
                    board[i][j] = backup;

                    if (beta <= alpha)
                        return best;
                }
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = human;
                    best = min(best, minimax(depth + 1, true, alpha, beta));
                    beta = min(beta, best);
                    board[i][j] = backup;

                    if (beta <= alpha)
                        return best;
                }
            }
        }
        return best;
    }
}

pair<int, int> findBestMove() {
    int bestVal = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = ai;
                int moveVal = minimax(0, false, numeric_limits<int>::min(), numeric_limits<int>::max());
                board[i][j] = backup;

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}

void humanMove() {
    int move;
    cout << "Enter the number for your move: ";
    cin >> move;

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = human;
    } else {
        cout << "Invalid move. Try again.\n";
        humanMove();
    }
}

int main() {
    cout<<"enter the human character(X or O)"<<endl;\
    cin>>human;
    if(human=='X') ai='O';
    else ai='X';
    printBoard();
    while (isMovesLeft() && evaluate() == 0) {
        humanMove();
        printBoard();

        if (!isMovesLeft() || evaluate() != 0)
            break;

        cout << "AI is making a move...\n";
        pair<int, int> bestMove = findBestMove();
        board[bestMove.first][bestMove.second] = ai;
        printBoard();
    }

    int score = evaluate();
    if (score == 10)
        cout << "AI wins!\n";
    else if (score == -10)
        cout << "Human wins!\n";
    else
        cout << "It's a draw!\n";

    return 0;
}
