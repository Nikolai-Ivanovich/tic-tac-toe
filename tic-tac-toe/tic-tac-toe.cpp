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
int checkMatrixDefAI(int xy[2], char matrix[SIZE][SIZE]);
void searchClearCoordinatesAi(int xy[2], char matrix[SIZE][SIZE]);


void getAICoordinates(int xy[2]);


int main()
{
    int xyAI[2], xyUser[2];
    char matrix[SIZE][SIZE];

    getClearMatrix(matrix); //put in every element of array symbol ' '
    while (true)
    {
        clearDisplay();
        printfMatrix(matrix);
        if (isWinnerDetermined(matrix))
        {
            cout << "AI win";
            break;
        }

        getUserCoordinates(xyUser, matrix);   //check and enter values in array xy

        writeCoordinates(xyUser, matrix, 'x');  // записать в массив matrix символ с координатой ху
        clearDisplay();
        printfMatrix(matrix);

        if (isWinnerDetermined(matrix))
        {
            cout << "you win";
            break;
        }

        if (checkMatrixDefAI(xyAI, matrix) == 0)
        {
            clearDisplay();
            printfMatrix(matrix);
            continue;
        }
        searchClearCoordinatesAi(xyAI, matrix);     

        
    }

    return 0;
}

int checkMatrixDefAI(int xy[2], char matrix[SIZE][SIZE])
{
    // 2. перекрытие выигрышных вариантов пользователя  когда 2 ячейка X и одна свободна
    if (matrix[0][0] == matrix[0][1] and matrix[0][0] != ' ' and matrix[0][2] != 'o') { // 0 line
        xy[0] = 0, xy[1] = 2;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][0] == matrix[0][2] and matrix[0][0] != ' ' and matrix[0][1] != 'o') { // 0 line
        xy[0] = 0, xy[1] = 1;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][1] == matrix[0][2] and matrix[0][1] != ' ' and matrix[0][0] != 'o') { // 0 line
        xy[0] = 0, xy[1] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[1][0] == matrix[1][1] and matrix[1][0] != ' ' and matrix[1][2] != 'o') { // 1 line
        xy[0] = 1, xy[1] = 2;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[1][0] == matrix[1][2] and matrix[1][0] != ' ' and matrix[1][1] != 'o') { // 1 line
        xy[0] = 1, xy[1] = 1;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[1][1] == matrix[1][2] and matrix[1][1] != ' ' and matrix[1][1] != 'o') { // 1 line
        xy[0] = 1, xy[1] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[2][0] == matrix[2][1] and matrix[2][0] != ' ' and matrix[2][1] != 'o') { // 2 line
        xy[0] = 2, xy[1] = 2;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[2][0] == matrix[2][2] and matrix[2][0] != ' ' and matrix[2][1] != 'o') { // 2 line
        xy[0] = 2, xy[1] = 1;
        writeCoordinates(xy, matrix, 'o');
    }
    if (matrix[2][1] == matrix[2][2] and matrix[2][0] != ' ' and matrix[2][0] != 'o') { // 2 line
        xy[0] = 2; xy[1] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][0] == matrix[1][0] and matrix[0][0] != ' ' and matrix[2][0] != 'o') { // column 0
        xy[0] = 2, xy[1] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][0] == matrix[2][0] and matrix[0][0] != ' ' and matrix[1][0] != 'o') { // column 0
        xy[0] = 1, xy[1] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[2][0] == matrix[1][0] and matrix[2][0] != ' ' and matrix[0][0] != 'o') { // column 0
        xy[0] = 0, xy[0] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][1] == matrix[1][1] and matrix[0][1] != ' ' and matrix[2][1] != 'o') { // column 1
        xy[0] = 2, xy[0] = 1;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][1] == matrix[2][1] and matrix[0][1] != ' ' and matrix[1][1] != 'o') { // column 1
        xy[0] = 1, xy[0] = 1;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[1][1] == matrix[2][1] and matrix[1][1] != ' ' and matrix[0][1] != 'o') { // column 1
        xy[0] = 0, xy[0] = 1;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][2] == matrix[1][2] and matrix[0][2] != ' ' and matrix[2][2] != 'o') { // column 2
        xy[0] = 2, xy[0] = 2;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][2] == matrix[2][2] and matrix[0][2] != ' ' and matrix[1][2] != 'o') { // column 2
        xy[0] = 1, xy[0] = 2;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[1][2] == matrix[2][2] and matrix[1][2] != ' ' and matrix[0][0] != 'o') { // column 2
        xy[0] = 0, xy[0] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][0] == matrix[2][2] and matrix[0][0] != ' ' and matrix[1][1] != 'o') { // diagonal 00 -- 22
        xy[0] = 1, xy[1] = 1;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][0] == matrix[1][1] and matrix[0][0] != ' ' and matrix[2][2] != 'o') { //diagonal 00 -- 11
        xy[0] = 2, xy[1] = 2;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[2][2] == matrix[1][1] and matrix[1][1] != ' ' and matrix[0][0] != 'o') { //diagonal 22 -- 11
        xy[0] = 0, xy[1] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[2][0] == matrix[0][2] and matrix[2][0] != ' ' and matrix[1][1] != 'o') { // diagonal 20 -- 02
        xy[0] = 1, xy[1] = 1;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[2][0] == matrix[1][1] and matrix[2][0] != ' ' and matrix[0][2] != 'o') { //diagonal 20 -- 11
        xy[0] = 0, xy[1] = 2;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    if (matrix[0][2] == matrix[1][1] and matrix[0][2] != ' ' and matrix[2][0] != 'o') { //diagonal 02 -- 11
        xy[0] = 2, xy[1] = 0;
        writeCoordinates(xy, matrix, 'o');
        return 0;
    }
    return 1;
}

void writeCoordinates(int xy[2], char matrix[SIZE][SIZE], char symbol) {
    matrix[xy[0]][xy[1]] = symbol;
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
                consistency = 0;
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
                consistency = 0;
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

//void enterCoordinatesAI(int xy[2], char matrix[SIZE][SIZE], char symbol)
//{
//    matrix[1][2] = symbol;
//}



void searchClearCoordinatesAi(int xy[2], char matrix[SIZE][SIZE])
{
    while (true)
    {
        getAICoordinates(xy);
        if (isCoordinatesClear(xy, matrix) == true)
        {
            writeCoordinates(xy, matrix, 'o');
            break;
        }
    }
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

void enterUserCoordinates(int xy[2])    // put in array values from user
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
        enterUserCoordinates(xy);   // put in array values from user

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

void getClearMatrix(char matrix[SIZE][SIZE])    // array of char symbols
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = ' ';
}

void clearDisplay() {
    system("cls");
}
