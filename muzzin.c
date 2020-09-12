#include "muzzin.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


float addOperation (float a, float b)
{
    float addition;
    addition = a + b;
    return addition;
}

float subtractOperation (float a, float b)
{
    float subtraction;
    subtraction = a - b;
    return subtraction;
}

float multiplyOperation(float a, float b)
{
    float multiplication;
    multiplication = a * b;
    return multiplication;
}

// requiere que b no sea 0
float divideOperation(float a, float b)
{
    float division;
    division = a / b;
    return division;
}

int factorialOperation(int a)
{
    if(a == 1)
    {
        return 1;
    }
    else
    {
        int factorialize;
        factorialize = a * factorialOperation(a - 1);
        return factorialize;
    }
}


void displayOperationResult(char operatorChar, float result)
{
    printf("El resultado de A%cB es: %.2f\n", operatorChar, result);
}

void displayFactorialResult(int resultA, int resultB)
{
    printf("El factorial de A es: %d y El factorial de B es: %d\n", resultA, resultB);
}

void displayFactorialResultA(int result)
{
    printf("El factorial de A es: %d y El factorial de B no se pudo calcular\n", result);
}

void displayFactorialResultB(int result)
{
    printf("El factorial de A no se pudo calcular y El factorial de B es: %d\n", result);
}

int askForOption()
{
    int option;
    printf("Ingrese opcion\n");
    __fpurge(stdin);
    scanf("%d", &option);
    while(option < 1 || option > 5)
    {
        printf("Opcion invalida, Ingrese opcion\n");
        scanf("%d", &option);
    }
    return option;
}

void showMenu(int firstOperandLoaded, float firstOperand, int secondOperandLoaded, float secondOperand)
{
    printf("Calculadora\n");
    printf("Menu\n");
    printf("1 - Cargar primer operando\n");
    printf("2 - Cargar segundo operando\n");
    printf("3 - Realizar calculos\n");
    printf("4 - Mostrar resultados\n");
    printf("5 - Salir\n");
    if(firstOperandLoaded == 1)
    {
        printf("El primer operando es %.2f\n", firstOperand);
    }
    else
    {
        printf("El primer operando no ha sido cargado\n");
    }
    if(secondOperandLoaded == 1)
    {
        printf("El segundo operando es %.2f\n", secondOperand);
    }
    else
    {
        printf("El segundo operando no ha sido cargado\n");
    }

}

int checkIfFloatIsInt(float number)
{
    int intVersionOfNumber = (int) number;
    if(intVersionOfNumber == number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int canCalculateFactorial(float number)
{
    return number >= 1 && checkIfFloatIsInt(number);
}

void loadOperand(float* operand, int* flagUpdatedCalculations, int* flagOperandLoaded)
{
    scanf("%f", operand);
    (*flagUpdatedCalculations) = 0;
    (*flagOperandLoaded) = 1;
}


void displayAllTheResults(float addResult, float substractionResult, float multiplicationResult, float divisionResult, float firstOperand, float secondOperand, int factorialResultA, int factorialResultB)
{
    displayOperationResult('+', addResult);
    displayOperationResult('-', substractionResult);
    displayOperationResult('*', multiplicationResult);
    if(secondOperand == 0)
    {
        printf("No se puede dividir por cero.\n");
    }
    else
    {
        displayOperationResult('/', divisionResult);
    }
    if(canCalculateFactorial(firstOperand) && canCalculateFactorial(secondOperand))
    {
        displayFactorialResult(factorialResultA, factorialResultB);
    }
    else
    {
        if( ! canCalculateFactorial(firstOperand) && canCalculateFactorial(secondOperand))
        {
            displayFactorialResultB((int)factorialResultB);
        }
        else
        {
            if(canCalculateFactorial(firstOperand) && !canCalculateFactorial(secondOperand))
            {
                displayFactorialResultA((int)factorialResultA);
            }
            else
            {
                printf("El factorial de A no se pudo calcular y El factorial de B tampoco\n");
            }
        }

    }
}

void performCalculations(float firstOperand, float secondOperand, float* pAddResult, float* pSubtractionResult, float* pMultiplicationResult,
                        float* pDivisionResult, int* pFactorialResultA, int* pFactorialResultB, int* pFlagUpdatedCalculations)
{
    (*pAddResult) = addOperation(firstOperand,secondOperand);
    (*pSubtractionResult) = subtractOperation(firstOperand,secondOperand);
    (*pMultiplicationResult) = multiplyOperation(firstOperand,secondOperand);
    if(secondOperand != 0)
    {
        (*pDivisionResult) = divideOperation(firstOperand,secondOperand);
    }
    if(canCalculateFactorial(firstOperand))
    {
        (*pFactorialResultA) = factorialOperation((int)firstOperand);
    }
    if(canCalculateFactorial(secondOperand))
    {
        (*pFactorialResultB) = factorialOperation((int)secondOperand);

    }
    (*pFlagUpdatedCalculations) = 1;
}
