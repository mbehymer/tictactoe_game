#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void display(string p[9]) {
    for (int i = 0; i < 3; i++) {
        cout << p[i * 3 + 0] << "|" << p[i * 3 + 1] << "|" << p[i * 3 + 2] << "\n";

    }
}

string manageTurn(int turn) {

    if (turn % 2 == 0) {
        return "X";
    }
    else {
        return "Y";
    }
}

void displayPlayer(int turn) {

    if (turn % 2 == 0) {
        cout << "Player 1, ";
    }
    else {

        cout << "Player 2, ";
    }
}

int askPlayer(int turn) {

    displayPlayer(turn);

    cout << "choose a number 1 through 9 for your position. \n";

    int choice;

    cin >> choice;

    return choice;
}

bool isValidSpot(string grid[], int choice) {
    if (choice < 0 || choice > 8) {
        return false;
    }
    else {
        string spot = grid[choice];
        if (spot == "X" || spot == "Y") {
            return false;
        }
    }
    return true;
}

void updateBoard(string boardPos[], int index, string player) {
    boardPos[index] = player;
}

void winningMsg(int turn) {
    displayPlayer(turn);
    
    cout << "you Won! \n";
}

bool checkFromCenter(string board[], int size, string player) {
    if (board[4] == player) {
        for (int i = 0; i < 4; i++) {
            if (board[i] == player && board[8 - i] == player) {
                return true;
            }
        }
    }

    return false;
}

bool checkFromSide(string board[], int size, string player) {
    for (int i = 1; i < 8; i += 2) {
        if (board[i] == player) {
            if (i == 1 || i == 7) {
                if (board[i - 1] == player && board[i + 1] == player) {
                    return true;
                }
            }
            else {
                if (board[i - 3] == player && board[i + 3] == player) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool isWinner(string board[], int size, string player) {
    
    return (checkFromCenter(board, size, player) || checkFromSide(board, size, player));

}

int main() {
    int x = 0;

    const int boardSize = 9;

    string grid[boardSize] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

    display(grid);

    cout << "\n";

    while (x < 9) {

        int choice = askPlayer(x) - 1;

        if (isValidSpot(grid, choice)) {
            updateBoard(grid, choice, manageTurn(x));

            display(grid);

            cout << "\n";

            if (isWinner(grid, boardSize, manageTurn(x))) {
                winningMsg(x);
                x = 9;
            }

            x += 1;
            if (x == 9) {
                cout << "Cat's game!";
            }
        }
        else {
            cout << "Not a valid move, go again. \n";
        }

    }
    return 0;


}