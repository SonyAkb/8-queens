#include <iostream>
using namespace std;

int board[8][8];

void print_board();  
void setQueen(int i, int j); 
void resetQueen(int i, int j); 
bool tryQueen(int i); 
void print_board_Q(); 
int main() {
    setlocale(LC_ALL, "Russian");


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = 0;
        }
    }
    print_board();

    tryQueen(0);
    print_board();
    print_board_Q();

    return 0;
}

void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void setQueen(int i, int j) {
    int foo;
    for (int x = 0; x < 8; ++x) {
        ++board[x][j];
        ++board[i][x];
        foo = j - i + x;
        if (foo >= 0 && foo < 8) {
            ++board[x][foo];
        }
        foo = j + i - x;
        if (foo >= 0 && foo < 8) {
            ++board[x][foo];
        }
    }
    board[i][j] = -1;
}

void resetQueen(int i, int j) {
    int foo;
    for (int x = 0; x < 8; x++) {
        --board[x][j];
        --board[i][x];
        foo = j - i + x;
        if (foo >= 0 && foo < 8) {
            --board[x][foo];
        }
        foo = j + i - x;
        if (foo >= 0 && foo < 8) {
            --board[x][foo];
        }
    }
    board[i][j] = 0;
}

bool tryQueen(int i) {
    bool result = false;
    for (int j = 0; j < 8; j++) {
        if (board[i][j] == 0) {

            setQueen(i, j);
            cout << "Ферзь поставлен в строку: " << i + 1 << endl;
            print_board_Q();
            if (i == 7) {
                result = true;
            }
            else {
                result = tryQueen(i + 1);
                if (!result) resetQueen(i, j);

            }
        }
    }
    return result;
}

void print_board_Q() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == -1) {
                cout << "Q ";
            }
            else if (board[i][j] > 0) {
                cout << "* ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}