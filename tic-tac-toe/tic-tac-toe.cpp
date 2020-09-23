#include <iostream>
using namespace std;

void getAICoordinates(int xy[2]);
void getUserCoordinates(int xy[2], char matrix[3][3]);

void enterUserCoordinates(int xy[2]);
bool isUserCorrectCoordinates(int xy[2]);
bool isCoordinatesClear(int xy[2], char matrix[3][3]);

void writeCoordinates(int xy[2], char matrix[3][3], char symbol);


void printfMatrix(char matrix[3][3]);
void getClearMatrix(char matrix[3][3]);

int main()
{
    int xyAI[2], xyUser[2];
    char matrix[3][3];

    getClearMatrix(matrix);
    printfMatrix(matrix);

    getUserCoordinates(xyUser, matrix);
    writeCoordinates(xyUser, matrix, 'x');
    printfMatrix(matrix);

       

    getAICoordinates(xyAI);

    return 0;
}

void writeCoordinates(int xy[2], char matrix[3][3], char symbol)
{
    matrix[xy[0]][xy[1]] = symbol;
}

bool isCoordinatesClear(int xy[2], char matrix[3][3])
{
    if (matrix[xy[0]][xy[1]] == ' ')
        return true;
    return false;
}

void getAICoordinates(int xy[2])
{
    xy[0] = rand() % 3;
    xy[1] = rand() % 3;
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

void getUserCoordinates(int xy[2], char matrix[3][3])
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

void printfMatrix(char matrix[3][3])
{
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i;
        for (int j = 0; j < 3; j++)
        {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}

void getClearMatrix(char matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}