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

const char RED_SOLDIER_CH = 'r';
const char WHITE_SOLDIER_CH = 'w';
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
bool mainDiagonalParallel(int matrix[9][9]) {
    
    for (int i = 0; i < size; ++i) {                                //main diagonal
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;

   
    for (int i = 0; i < size - 2; ++i) {                            //highук diagonal
        std::cout << matrix[i][i + 2] << " ";
    }
   
    for (int i = 2; i < size; ++i) {                                //lower diagonal
        std::cout << matrix[i][i - 2] << " ";
    }
}
int evalutate(int i, int j) {
    int white = 0, red = 0;
    return  white - red;
}

int main()
{
    std::cout << "Hello World!\n";
    int n = 9;
    char matrix[9][9] = {   {'O', 'O', '1', 'O', '1', 'O', 'r', 'O', 'O' },
                            {'O', 'O', 'O', '1', '1', '1', 'O', 'O', 'O' },
                            {'1', 'O', '1', '1', '1', '1', '1', 'O', '1' },
                            {'O', '1', '1', '1', '1', '1', '1', '1', 'O' },
                            {'1', '1', '1', '1', '1', '1', '1', '1', '1' },
                            {'O', '1', '1', '1', '1', '1', '1', '1', 'O' },
                            {'1', 'O', '1', '1', '1', '1', '1', 'O', '1' },
                            {'O', 'O', 'O', '1', '1', '1', 'O', 'O', 'O' },
                            {'O', 'O', '1', 'O', '1', 'O', '1', 'O', 'O' } };
    // Проход по диагоналям через одну вверх
    std::cout << "Главная диагональ:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i][i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Параллельная диагональ (3, 9, 15):" << std::endl;
    for (int i = 0; i < size - 2; ++i) {
        std::cout << matrix[i][i + 2] << " ";
    }
    std::cout << std::endl;
    // Проход по диагоналям через одну вниз
    std::cout << "Параллельная диагональ (11, 17, 23):" << std::endl;
    for (int i = 2; i < size; ++i) {
        std::cout << matrix[i][i - 2] << " ";
    }
    std::cout << std::endl;

    std::cout << "Главная диагональ:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i][size - i - 1] << " ";
    }
    std::cout << std::endl;
    std::cout << "Побочная диагональ (3, 9, 15):" << std::endl;
    for (int i = 0; i < size - 2; ++i) {
        std::cout << matrix[i][size - i - 3] << " ";
    }
    std::cout << std::endl;
    std::cout << "Побочная диагональ (11, 17, 23):" << std::endl;
    for (int i = 2; i < size; ++i) {
        std::cout << matrix[i][size - i + 3] << " ";
    }
    std::cout << std::endl;


}


