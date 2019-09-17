#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void binaryParser(int decimalNumber);
void hexaParser(int decimalNumber);
void complement(int binaryNumber[4]);
void complement2(int binaryNumber[4]);
void binarySumAB(int binaryNumberA[4], int binaryNumberB[4]);

int binaryNumber[4];

int binaryNumberA[4] = {0, 1, 1, 0};
int binaryNumberB[4] = {0, 1, 0, 1};
int binaryNumberSum[4];

int binaryNumberComplement[4];
int binaryNumberComplement2[4];
char hexaNumber[4];

int main()
{
    // binaryParser(15);
    // for (int i = 0; i < 4; i++)
    //     printf("%i", binaryNumber[i]);
    // printf("\n");
    // complement(binaryNumber);
    // for (int i = 0; i < 4; i++)
    //     printf("%i", binaryNumberComplement[i]);
    // printf("\n");
    // complement2(binaryNumberComplement);
    // for (int i = 0; i < 4; i++)
    //     printf("%i", binaryNumberComplement2[i]);
    // printf("\n");
    binarySumAB(binaryNumberA, binaryNumberB);
    for (int i = 0; i < 4; i++)
        printf("%i", binaryNumberSum[i]);

    system("pause");
    return 0;
}

void hexaParser(int decimalNumber)
{
    int i = 3, rest = 0;
    char letter;
    while (decimalNumber > 0)
    {
        rest = decimalNumber % 16;
        switch (rest)
        {
        case 10:
            letter = 'A';
            break;
        case 11:
            letter = 'B';
            break;
        case 12:
            letter = 'C';
            break;
        case 13:
            letter = 'D';
            break;
        case 14:
            letter = 'E';
            break;
        case 15:
            letter = 'F';
            break;
        }
        if (rest >= 10)
        {
            hexaNumber[i] = letter;
        }
        else
        {
            hexaNumber[i] = rest + '0';
        }
        decimalNumber /= 16;
        i--;
    }
}

void binaryParser(int decimalNumber)
{
    int i = 3;
    while (decimalNumber > 0)
    {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i--;
    }
}

void complement(int binaryNumber[4])
{
    for (int i = 0; i < 4; i++)
    {
        binaryNumberComplement[i] = binaryNumber[i] ? 0 : 1;
    }
}

void complement2(int binaryNumber[4])
{
    int lastPosition = 3;
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        binaryNumberComplement2[i] = binaryNumber[i];
    }
    for (i = lastPosition; i >= 0; i--)
    {
        if (binaryNumber[i] == 1)
        {
            binaryNumberComplement2[i] = 0;
        }
        else
        {
            binaryNumberComplement2[i] = 1;
            break;
        }
    }
}

void binarySumAB(int binaryNumberA[4], int binaryNumberB[4])
{

    int goOne = 0;
    for (int i = 3; i >= 0; i--)
    {
        if ((binaryNumberA[i] == 1 && binaryNumberB[i] == 1) && goOne == 1)
        {
            binaryNumberSum[i] = 1;
            goOne = 0;
        }
        else if ((binaryNumberA[i] == 1 && binaryNumberB[i] == 1) && goOne == 0)
        {
            binaryNumberSum[i] = 0;
            goOne = 0;
        }
        else if (((binaryNumberA[i] == 0 && binaryNumberB[i] == 1) || (binaryNumberA[i] == 1 && binaryNumberB[i] == 0)) && goOne == 1)
        {
            binaryNumberSum[i] = 0;
            goOne = 1;
        }
        else if (((binaryNumberA[i] == 0 && binaryNumberB[i] == 1) || (binaryNumberA[i] == 1 && binaryNumberB[i] == 0)) && goOne == 0)
        {
            binaryNumberSum[i] = 1;
            goOne = 0;
        }
        else if ((binaryNumberA[i] == 0 && binaryNumberB[i] == 0) && goOne == 1)
        {
            binaryNumberSum[i] = 1;
            goOne = 0;
        }
        else if ((binaryNumberA[i] == 0 && binaryNumberB[i] == 0) && goOne == 0)
        {
            binaryNumberSum[i] = 0;
        }
    }
}