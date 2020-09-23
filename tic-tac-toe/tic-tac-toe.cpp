#include <iostream>
using namespace std;
#define SIZE 3

void printfMatrix(char matrix[SIZE][SIZE]);
void getClearMatrix(char matrix[SIZE][SIZE]);
void writeCoordinates(int xy[2], char matrix[SIZE][SIZE], char symbol);
bool isCoordinatesClear(int xy[2], char matrix[SIZE][SIZE]);
bool isWinnerDetermined(char matrix[SIZE][SIZE]);  // определение победителя и выход из бесконечного цикла
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

    getUserCoordinates(xyUser, matrix);
    writeCoordinates(xyUser, matrix, 'x');
    printfMatrix(matrix);

       

    getAICoordinates(xyAI);

    return 0;
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
    cout << "Please, enter you coordinates. X: [0;2], Y: [0,2]" << endl;
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