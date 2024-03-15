// eval_func.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// eval_func.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

const int size = 9;
int fullyDefCells[9][9] = { {0, 0, 1, 0, 0, 1, 0, 0, 0 },
                            {0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            {1, 0, 1, 0, 0, 0, 1, 0, 1 },
                            {0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            {0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            {0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            {1, 0, 1, 0, 0, 0, 1, 0, 1 },
                            {0, 0, 0, 0, 0, 0, 0, 0, 0 },
                            {0, 0, 1, 0, 0, 0, 1, 0, 0 } };


const int WHITE_SOLDIER = 20;
const int RED_SOLDIER = 20;
const int DEF_BONUS = 5;
const int FULLY_DEF_BONUS = 10;

const char RED_SOLDIER_CH = 'r';
const char WHITE_SOLDIER_CH = 'w';
const char VOID_CELL = 'O';

bool isWhiteSoldier(char soldier) {             //white soldiers
    return WHITE_SOLDIER == soldier;
}

bool isRedSoldier(char soldier) {               //red soldiers
    return RED_SOLDIER == soldier;
}
int isInFullyDef(char matrix[9][9], char ch) {
    int bonus = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == ch && matrix[i][j] == fullyDefCells[i][j]) {
                bonus += FULLY_DEF_BONUS;
            }
        }
    }

    return bonus;
}
int mainDiagonalParallel(char matrix[9][9], char ch) {
    int localBonus = 0;
    int bonus = 0;
    //std::cout<<ch<<" main diagonal" << std::endl;
    for (int i = 1; i < size+1; ++i) {                                //main diagonal
       // std::cout << matrix[i-1][i-1] << " ";
        if(matrix[i-1][i-1] == matrix[i][i] && matrix[i][i] == ch && matrix[i-1][i-1] == ch){
            localBonus += DEF_BONUS;
            //std::cout<<i<<' '<<i-1;
        }
    }
    bonus += localBonus;
    /*std::cout << std::endl;
    std::cout << localBonus;
    std::cout << std::endl;*/

    localBonus = 0;
    for (int i = 1; i < size - 2 + 1; ++i) {                            //higher diagonal
        //std::cout << matrix[i-1][i + 2 - 1] << " ";
        if(matrix[i-1][i+2-1] == matrix[i][i+2] && matrix[i][i + 2] == ch && matrix[i - 1][i + 2 - 1])
            localBonus += DEF_BONUS;
    }
    bonus += localBonus;
   /* std::cout << std::endl;
    std::cout << localBonus;
    std::cout << std::endl;*/
    
    localBonus = 0; 
    for (int i = 3; i < size + 1; ++i) {                                //lower diagonal
        //std::cout << matrix[i - 1][i - 2 - 1] << " ";
        if (matrix[i - 1][i - 2 - 1] == matrix[i][i - 2] && matrix[i - 1][i - 2 - 1] == ch && matrix[i][i - 2] == ch) {
            localBonus += DEF_BONUS;
        }
    }
    bonus += localBonus;
    /*std::cout << std::endl;
    std::cout << localBonus;
    std::cout << std::endl;*/
    return bonus;
}
int sideDiagonalParallel(char matrix[9][9], char ch) {
    int bonus = 0;
    int localBonus = 0;
   /* std::cout << ch;
    std:: cout<<" side diagonal"<<std::endl;*/
    for (int i = 1; i < size + 1; ++i) {                                //side diagonal
        //std::cout << matrix[i - 1][size - i] << " ";
        if (matrix[i][size - i] == matrix[i-1][size - i] && matrix[i - 1][size - i] == ch && matrix[i][size - i]) {
            localBonus += DEF_BONUS;
        }
    }
    bonus += localBonus;
   /* std::cout << std::endl;
    std::cout << localBonus;
    std::cout << std::endl;*/
    

    localBonus=0;
    for (int i = 1; i < size - 2 + 1; ++i) {                            //hegher diagonal
       // std::cout << matrix[i - 1][size - i - 3 + 1] << " ";
        if (matrix[i - 1][size - i - 3 + 1] == matrix[i][size - i - 3] && matrix[i - 1][size - i - 3 + 1] == ch && matrix[i][size - i - 3] == ch) {
            localBonus += DEF_BONUS;
        }
    }
    bonus += localBonus;
    /*std::cout << std::endl;
    std::cout << localBonus;
    std::cout << std::endl;*/
    
    
    localBonus=0;
    for (int i = 3; i < size + 1; ++i) {                                //lower diagonal
        //std::cout << matrix[i - 1][size - i + 3 - 1] << " ";
        if (matrix[i - 1][size - i + 3 - 1] == matrix[i][size - i + 1] && matrix[i - 1][size - i + 3 - 1] == ch && matrix[i][size - i + 1] == ch) {
            localBonus += DEF_BONUS;
        }
    }
    bonus += localBonus;
    /*std::cout << std::endl;
    std::cout << localBonus;
    std::cout << std::endl;*/
      
    return bonus;
}
int columnCalc(char matrix[9][9], char ch) {
    int localBonus = 0;
    int bonus = 0;
   // std:: cout<<ch<<" column" << std::endl;
    for (int j = 0; j < size; ++j) {
        for (int i = 1; i < size + 1; ++i) {
           //std::cout << matrix[i - 1][j] << " ";
            if(i != 2 || i != 7) {
                if (matrix[i - 1][j] == matrix[i][j] && matrix[i - 1][j] == ch && matrix[i][j] == ch) {
                    localBonus+=DEF_BONUS;
                }
            }
            if(j == 0 || j == 8) {
                if (matrix[i - 2][j] == matrix[i][j] && matrix[i - 2][j] == ch && matrix[i][j] == ch) {
                    localBonus += DEF_BONUS;
                }
            }
        }
        //std::cout<<localBonus<<std::endl;
        bonus += localBonus;
        localBonus = 0; 
    }
    return bonus;    
}
int rowCalc(char matrix[9][9], char ch) {
    int localBonus = 0;
    int bonus = 0;
   // std::cout<<ch<<" row" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 1; j < size + 1; ++j) {
           // std::cout<<matrix[i][j-1] << ' ' ;
            if(j != 2 || j != 7) {
                if(matrix[i][j-1] == matrix[i][j] && matrix[i][j-1] == ch && matrix[i][j] == ch){
                    localBonus+=DEF_BONUS;
                }
            }
            if (i == 0 || i == 8) {
                if (matrix[i][j - 2] == matrix[i][j] && matrix[i][j - 2] == ch && matrix[i][j] == ch) {
                    localBonus += DEF_BONUS;
                }
            }
        }
        //std::cout << localBonus << std::endl;
        bonus +=  localBonus;
        localBonus = 0;
    }
    return bonus;
    
}
int calculate(char matrix[9][9]) {
    int white = 0, red = 0;    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == 'r') {
                red += RED_SOLDIER;
            }
            if (matrix[i][j] == 'w') {
                white += WHITE_SOLDIER;
            }
        }
    }
    return white-red;
}
int Evalutate(char matrix[9][9]) {
    int white = 0, red = 0;
    white += rowCalc(matrix, WHITE_SOLDIER_CH);
    white += columnCalc(matrix, WHITE_SOLDIER_CH);
    white += mainDiagonalParallel(matrix, WHITE_SOLDIER_CH);
    white += sideDiagonalParallel(matrix, WHITE_SOLDIER_CH);
    red += rowCalc(matrix, RED_SOLDIER_CH);
    red += columnCalc(matrix, RED_SOLDIER_CH);
    red += mainDiagonalParallel(matrix, RED_SOLDIER_CH);
    red += sideDiagonalParallel(matrix, RED_SOLDIER_CH);
    return  white - red + calculate(matrix) + (isInFullyDef(matrix, WHITE_SOLDIER_CH) - isInFullyDef(matrix, RED_SOLDIER_CH));
}

int main()
{
   
    char matrix[9][9] = {   {'O', 'O', 'r', '-', 'r', '-', 'r', 'O', 'O' },
                            {'O', 'O', 'O', 'r', 'r', 'r', 'O', 'O', 'O' },
                            {'e', 'O', 'r', 'r', 'r', 'r', 'r', 'O', 'e' },
                            {'|', 'e', 'r', 'r', 'e', 'r', 'r', 'e', '|' },
                            {'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e', 'e' },
                            {'|', 'e', 'w', 'w', 'r', 'w', 'w', 'e', '|' },
                            {'e', 'O', 'w', 'w', 'w', 'w', 'w', 'O', 'e' },
                            {'O', 'O', 'O', 'w', 'w', 'w', 'O', 'O', 'O' },
                            {'O', 'O', 'w', '-', 'w', '-', 'w', 'O', 'O' } };
    
   
    int result = Evalutate(matrix);
    if (result < 0) {
        std::cout<<" Red Wins "<< result << std::endl;
    }
    else {
        std::cout<<" White Wins "<< result << std::endl;
    }
    
}



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


