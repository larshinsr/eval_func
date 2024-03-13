// eval_func.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const int size = 9;
int borderCells[size][size]= { { 0, 0, 1, 0, 1, 0, 1, 0, 0 },
                               { 0, 0, 0, 1, 0, 1, 0, 0, 0 },
                               { 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                               { 0, 1, 1, 0, 0, 0, 1, 1, 0 },
                               { 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                               { 0, 1, 1, 0, 0, 0, 1, 1, 0 },
                               { 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                               { 0, 0, 0, 1, 0, 1, 0, 0, 0 },
                               { 0, 0, 1, 0, 1, 0, 1, 0, 0 } };

int allowedCells[size][size] = { { 0, 0, 1, 0, 1, 0, 1, 0, 0 },
                                { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                                { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
                                { 0, 1, 1, 1, 1, 1, 1, 1, 0 },
                                { 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                                { 0, 1, 1, 1, 1, 1, 1, 1, 0 },
                                { 1, 0, 1, 1, 1, 1, 1, 0, 1 },
                                { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
                                { 0, 0, 1, 0, 1, 0, 1, 0, 0 } };
const int WHITE_SOLDIER = 10;
const int RED_SOLDIER = 10;

const char RED_SOLDIER = 'r';
const char WHITE_SOLDIER = 'w';
const char VOID_CELL = 'O';

bool isWhiteSoldier(char soldier) {             //white soldiers
    return WHITE_SOLDIER == soldier;
}

bool isRedSoldier(char soldier) {               //red soldiers
    return RED_SOLDIER == soldier;
}
bool isInSquare(int x, int y) {
    return (x >= 2 && x <= 6 && y >= 2 && y <= 6);
}

bool isOnBorder(int i, int j) {                 //check is soldier on border
    return borderCells[i][j] == 1;
}
bool isSefePosiotion(char board[size][size], char soldier, int i, int j) {

}
int main()
{
    std::cout << "Hello World!\n";
    char board[9][9] = {{'O', 'O', 'r', 'O', 'r', 'O', 'r', 'O', 'O' },
                        {'O', 'O', 'O', 'r', 'r', 'r', 'O', 'O', 'O' },
                        {'r', 'O', 'r', 'r', 'r', 'r', 'r', 'O', 'O' },
                        {'O', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'O' },
                        {'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r' },
                        {'O', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'O' },
                        {'r', 'O', 'r', 'r', 'r', 'r', 'r', 'O', 'O' },
                        {'O', 'O', 'O', 'r', 'r', 'r', 'O', 'O', 'O' },
                        {'O', 'O', 'r', 'O', 'r', 'O', 'r', 'O', 'O' }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
