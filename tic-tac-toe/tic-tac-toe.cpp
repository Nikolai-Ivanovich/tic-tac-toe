#include <iostream>
//#include <windows.h>
using namespace std;
#define SIZE 3

void printfMatrix(char matrix[SIZE][SIZE]);
void getClearMatrix(char matrix[SIZE][SIZE]);
void writeCoordinates(int xy[2], char matrix[SIZE][SIZE], char symbol);
bool isCoordinatesClear(int xy[2], char matrix[SIZE][SIZE]);
bool isWinnerDetermined(char matrix[SIZE][SIZE]);  // определение победителя и выход из бесконечного цикла
bool isWinnerDeterminedHorisontal(char matrix[SIZE][SIZE]);
bool isWinnerDeterminedVertical(char matrix[SIZE][SIZE]);
bool isWinnerDeterminedSlantingLeftToRight(char matrix[SIZE][SIZE]);
bool isWinnerDeterminedSlantingRightToLeft(char matrix[SIZE][SIZE]);

void clearDisplay();

// User
void getUserCoordinates(int xy[2], char matrix[SIZE][SIZE]);
void enterUserCoordinates(int xy[2]);
bool isUserCorrectCoordinates(int xy[2]);

// Ai
void checkMatrixAttackAI(char matrix[SIZE][SIZE]);
void checkMatrixDefAI(char matrix[SIZE][SIZE]);
void searchClearCoordinatesAi(char matrix[SIZE][SIZE]);

void getAICoordinates(int xy[2]);


int main()
{
    int xyAI[2], xyUser[2];
    char matrix[SIZE][SIZE];

    getClearMatrix(matrix);
    printfMatrix(matrix);


    while (true)
    {
        
        getUserCoordinates(xyUser, matrix);
        writeCoordinates(xyUser, matrix, 'x');
        clearDisplay();
        printfMatrix(matrix);

        if (isWinnerDetermined(matrix))
        {
            cout << "you win";
            break;
        }
    }
    clearDisplay();
    cout << "you win";

       

    getAICoordinates(xyAI);

    return 0;
}


bool isWinnerDeterminedHorisontal(char matrix[SIZE][SIZE])
{
    int consistency = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (matrix[i][0] == matrix[i][j] and matrix[i][0] != ' ')
                consistency++;
            else
            {
                break;
            }
        }
        if (consistency == SIZE - 1)
            return true;
    }
    return false;
}

bool isWinnerDeterminedVertical(char matrix[SIZE][SIZE])
{
    int consistency = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 1; j < SIZE; j++)
        {
            if (matrix[0][i] == matrix[j][i] and matrix[0][i] != ' ')
                consistency++;
            else
            {
                break;              
            }
        }
        if (consistency == SIZE - 1)
            return true;
    }
    return false;
}

bool isWinnerDeterminedSlantingLeftToRight(char matrix[SIZE][SIZE])
{
    int consistencyLeftToRight = 0;
    for (int i = 1; i < SIZE; i++)
    {
        if (matrix[0][0] == matrix[i][i] and matrix[0][0] != ' ')
            consistencyLeftToRight++;
        else
        {
            break;
        }
    }
    if (consistencyLeftToRight == SIZE - 1)
    {
        return true;
    }
    return false;
}
bool isWinnerDeterminedSlantingRightToLeft(char matrix[SIZE][SIZE])
{
    int consistencyRightToLeft = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i + j == SIZE - 1)
            {
                if (matrix[0][SIZE - 1] == matrix[i][j] and matrix[i][j] != ' ')
                    consistencyRightToLeft++;
                else
                {
                    break;
                }
            }
        }
    }
    if (consistencyRightToLeft == SIZE)
    {
        return true;
    }
    return false;
}

bool isWinnerDetermined(char matrix[SIZE][SIZE])
{
    if (isWinnerDeterminedHorisontal(matrix))
        return true;
    else if (isWinnerDeterminedVertical(matrix))
        return true;
    else if (isWinnerDeterminedSlantingLeftToRight(matrix))
        return true;
    else if (isWinnerDeterminedSlantingRightToLeft(matrix))
        return true;
    return false;
}

void checkMatrixAttackAI(char matrix[SIZE][SIZE])
{
    // 1. должна проверить есть ли совпадения когда 2 ячейка O и одна свободна
}

void checkMatrixDefAI(char matrix[SIZE][SIZE])
{
    // 2. перекрытие выигрышных вариантов пользователя  когда 2 ячейка X и одна свободна
}

void searchClearCoordinatesAi(char matrix[SIZE][SIZE])
{
    // 3. Поиск свободных координат-ходов
}

void writeCoordinates(int xy[2], char matrix[SIZE][SIZE], char symbol)
{
    matrix[xy[0]][xy[1]] = symbol;
}

bool isCoordinatesClear(int xy[2], char matrix[SIZE][SIZE])
{
    if (matrix[xy[0]][xy[1]] == ' ')
        return true;
    return false;
}

void getAICoordinates(int xy[2])
{
    xy[0] = rand() % SIZE;
    xy[1] = rand() % SIZE;
}

void enterUserCoordinates(int xy[2])
{
    cout << endl << "Please, enter you coordinates. X: [0;2], Y: [0,2]" << endl;
    cout << "X: ";
    cin >> xy[0];
    cout << "Y: ";
    cin >> xy[1];
}

bool isUserCorrectCoordinates(int xy[2])
{
     if (xy[0] >= 0 and xy[0] <= 2 and xy[1] >= 0 && xy[1] <= 2)
         return true;
     return false;
}

void getUserCoordinates(int xy[2], char matrix[SIZE][SIZE])
{
    bool userCorrectCoordinates = false;
    bool coordinatesClear = false;

    while (userCorrectCoordinates == false or coordinatesClear == false)
    {
        enterUserCoordinates(xy);

        userCorrectCoordinates = isUserCorrectCoordinates(xy);
        if (userCorrectCoordinates == false)
        {
            cout << "Incorrect coordinates.";
            continue;
        }
        coordinatesClear = isCoordinatesClear(xy, matrix);
        if (coordinatesClear == false)
        {
            cout << "These coordinates are already taken.";
            continue;
        }
    }
}

void printfMatrix(char matrix[SIZE][SIZE])
{
    cout << "  0 1 2" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i;
        for (int j = 0; j < SIZE; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

void getClearMatrix(char matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}

void clearDisplay() {
    system("cls");
}