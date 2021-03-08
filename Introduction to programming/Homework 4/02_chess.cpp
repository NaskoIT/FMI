/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Atanas Vasilev
* @idnumber 62577
* @task 2
* @compiler GCC
*
*/


#include <iostream>
#include <vector>

using namespace std;

const int SUCCESS_EXIT_CODE = 0;
const int ERROR_EXIT_CODE = -1;
const int POSSIBLE_TURNS = 8;
const int BOARD_MIN_SIZE = 4;
const int BOARD_MAX_SIZE = 200;
const int NOT_VISITED_CELL = -1;
const int KNIGHT_DIRECTIONS[POSSIBLE_TURNS][2] = {
        {-2, -1},
        {-1, -2},
        {-2, 1},
        {-1, 2},
        {2,  -1},
        {1,  -2},
        {2,  1},
        {1,  2}
};

bool canMoveKnightToTargetPosition(int rows, int cols, int row, int col, int targetRow, int targetCol, int maxTurns);

bool isValidBoardSize(int size);

bool isValidRow(int row, int totalRows);

bool isValidCol(int col, int totalCols);

int main() {
    int rows;
    cin >> rows;
    if (!isValidBoardSize(rows)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    int cols;
    cin >> cols;
    if (!isValidBoardSize(cols)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    int initialRow;
    cin >> initialRow;
    if (!isValidRow(initialRow, rows)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    int initialCol;
    cin >> initialCol;
    if (!isValidCol(initialCol, cols)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    int targetRow;
    cin >> targetRow;
    if (!isValidRow(targetRow, rows)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }
    int targetCol;
    cin >> targetCol;
    if (!isValidCol(targetCol, cols)) {
        cout << ERROR_EXIT_CODE << endl;
        return SUCCESS_EXIT_CODE;
    }

    int maxTurns;
    cin >> maxTurns;
    if (maxTurns <= 0 || maxTurns > 30) {
        cout << ERROR_EXIT_CODE;
        return SUCCESS_EXIT_CODE;
    }

    cout << canMoveKnightToTargetPosition(rows, cols, initialRow, initialCol, targetRow, targetCol, maxTurns);
}

bool isInside(int rows, int cols, int row, int col) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void move(vector<vector<int>> &board, int rows, int cols, int row, int col, int targetRow, int targetCol, int currentTurn, int maxTurns) {
    if (!isInside(rows, cols, row, col)) {
        return;
    } else if (row == targetRow && col == targetCol && board[row][col] <= maxTurns) {
        return;
    }

    if (currentTurn < maxTurns) {
        for (int i = 0; i < POSSIBLE_TURNS; i++) {
            int nextRow = row + KNIGHT_DIRECTIONS[i][0];
            int nextCol = col + KNIGHT_DIRECTIONS[i][1];
            if(isInside(rows, cols, nextRow, nextCol) &&
               (board[nextRow][nextCol] == NOT_VISITED_CELL ||
                board[nextRow][nextCol] > currentTurn + 1)) {
                board[nextRow][nextCol] = currentTurn + 1;
                move(board, rows, cols, nextRow, nextCol, targetRow, targetCol, currentTurn + 1, maxTurns);
            }
        }
    }
}

bool canMoveKnightToTargetPosition(int rows, int cols, int row, int col, int targetRow, int targetCol, int maxTurns) {
    if (!isInside(rows, cols, row, col)) {
        return false;
    }

    vector<vector<int>> board(rows);
    for (int i = 0; i < rows; i++) {
        board[i] = vector<int>(cols);
        for (int j = 0; j < cols; j++) {
            board[i][j] = NOT_VISITED_CELL;
        }
    }

    board[row][col] = 0;
    move(board, rows, cols, row, col, targetRow, targetCol, 0, maxTurns);

    return board[targetRow][targetCol] >= 0;
}

bool isValidBoardSize(int size) {
    return size >= BOARD_MIN_SIZE && size <= BOARD_MAX_SIZE;
}

bool isValidRow(int row, int totalRows) {
    return row >= 0 && row < totalRows;
}

bool isValidCol(int col, int totalCols) {
    return col >= 0 && col < totalCols;
}