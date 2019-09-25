#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int isSymbolInDictionary(char symbol);
int isValidExpression(char *expression);
void writeExpression(char *expression);
int execute(char *firstExpression);

int main(int argc, char **argv)
{
    if (isValidExpression(argv[1]) == TRUE)
    {
        execute(argv[1]);
    }
    else
    {
        system("cls");
        printf("Expressao invalida");
    }
}

int execute(char *expression)
{
    char firstOperator, secondOperator, middleOperator;
    int right = expression[1], left = expression[3], firstResult, secondResult;
    firstOperator = expression[2];
    secondOperator = expression[8];
    middleOperator = expression[5];
    switch (firstOperator)
    {
    case '<':
        if (right < left)
            firstResult = TRUE;
        else
            firstResult = FALSE;
        break;
    case '>':
        if (right > left)
            firstResult = TRUE;
        else
            firstResult = FALSE;
        break;
    default:
        break;
    }
    if (firstResult)
        printf("( V %c", middleOperator);
    else
        printf("( F %c", middleOperator);

    right = expression[7];
    left = expression[9];
    switch (secondOperator)
    {
    case '<':
        if (right < left)
            secondResult = TRUE;
        else
            secondResult = FALSE;
        break;
    case '>':
        if (right > left)
            secondResult = TRUE;
        else
            secondResult = FALSE;
        break;
    default:
        break;
    }
    if (secondResult)
        printf(" V )");
    else
        printf(" F )");
    if (middleOperator == '^' && firstResult && secondResult)
    {
        printf(" = V\n\n");
        return 1;
    }

    if (middleOperator == 'U' && (firstResult == TRUE || secondResult == TRUE))
    {
        printf(" = V\n\n");
        return 1;
    }

    if (middleOperator == 'O' && ((firstResult && !secondResult) || (!firstResult && secondResult)))
    {
        printf(" = V\n\n");
        return 1;
    }

    printf(" = F\n\n");
    return 0;
}

int isSymbolInDictionary(char symbol)
{
    char dictionary[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '(', ')', '<', '>', '^', 'U', 'O', 'o'};
    int found = 0;
    for (int i = 0; i < sizeof(dictionary) - 1; i++)
    {
        if (symbol == dictionary[i])
            found = 1;
    }
    return found;
}

int isValidExpression(char *expression)
{
    int i = 0, parenthesesCount = 0;
    do
    {
        if (!isSymbolInDictionary(expression[i]))
        {
            return 0;
        }
        if (expression[i] == '(' || expression[i] == ')')
        {
            parenthesesCount++;
        }
        i++;
    } while (expression[i] != '\0');
    if (parenthesesCount != 4)
        return 0;
    else
        return 1;
}