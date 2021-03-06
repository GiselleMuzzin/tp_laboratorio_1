#include "muzzin.h"
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

long long unsigned factorialOperation(int a)
{
    if(a == 1)
    {
        return 1;
    }
    else
    {
        long long unsigned factorialize;
        factorialize = a * factorialOperation(a - 1);
        return factorialize;
    }
}

void performCalculations(float firstOperand, float secondOperand, float* pAddResult, float* pSubtractionResult, float* pMultiplicationResult,
                         float* pDivisionResult, long long unsigned* pFactorialResultA, long long unsigned* pFactorialResultB, int* pFlagUpdatedCalculations)
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
    // los calculos han sido actualizados
    (*pFlagUpdatedCalculations) = 1;
}


int checkIfFloatIsInt(float number)
{
    // un float es entero si al pasarlo a int queda igual
    // por ejemplo 2.5 al pasarse a int queda 2 y no es igual a 2.5
    int intVersionOfNumber = (int) number;
    if(intVersionOfNumber == number)
    {
        return 1; // es un int
    }
    else
    {
        return 0; // no es un int
    }
}


int canCalculateFactorial(float number)
{
    // Para poder calcularlo tiene que pasar que:
    // el numero sea mayor o igual que 1 y el numero tiene que ser entero
    if(number >= 1 && checkIfFloatIsInt(number))
    {
        return 1; // se puede
    }
    else
    {
        return 0; // no se puede
    }

}


void loadOperand(float* operand, int* flagUpdatedCalculations, int* flagOperandLoaded)
{
    scanf("%f", operand);
    // Como se cargó un operando, los calculos estan desactualizados
    (*flagUpdatedCalculations) = 0;
    // Indica que el operando fue cargado
    (*flagOperandLoaded) = 1;
}

int askForOption()
{
    int option;
    printf("Ingrese opcion\n");
    __fpurge(stdin);
    scanf("%d", &option);
    while(option < 1 || option > 5)
    {
        printf("Opcion invalida, reingrese opcion\n");
        scanf("%d", &option);
    }
    return option;
}


void displayOperationResult(char operatorChar, float result)
{
    printf("El resultado de A%cB es: %.2f\n", operatorChar, result);
}

void displayFactorialResult(long long unsigned resultA, long long unsigned resultB)
{
    printf("El factorial de A es: %llu y El factorial de B es: %llu\n", resultA, resultB);
}

void displayFactorialResultA(long long unsigned result)
{
    printf("El factorial de A es: %llu y El factorial de B no se pudo calcular\n", result);
}

void displayFactorialResultB(long long unsigned result)
{
    printf("El factorial de A no se pudo calcular y El factorial de B es: %llu\n", result);
}

void displayAllTheResults(float addResult, float subtractionResult, float multiplicationResult, float divisionResult, float firstOperand, float secondOperand, long long unsigned factorialResultA, long long unsigned factorialResultB)
{
    displayOperationResult('+', addResult);
    displayOperationResult('-', subtractionResult);
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
            displayFactorialResultB(factorialResultB);
        }
        else
        {
            if(canCalculateFactorial(firstOperand) && !canCalculateFactorial(secondOperand))
            {
                displayFactorialResultA(factorialResultA);
            }
            else
            {
                printf("El factorial de A no se pudo calcular y El factorial de B tampoco\n");
            }
        }

    }
}

void showMenu(int flagFirstOperandLoaded, float firstOperand, int flagSecondOperandLoaded, float secondOperand)
{
    printf("Calculadora\n");
    printf("Menu\n");
    printf("1 - Cargar primer operando\n");
    printf("2 - Cargar segundo operando\n");
    printf("3 - Realizar calculos\n");
    printf("4 - Mostrar resultados\n");
    printf("5 - Salir\n");
    if(flagFirstOperandLoaded == 1)
    {
        printf("El primer operando es %.2f\n", firstOperand);
    }
    else
    {
        printf("El primer operando no ha sido cargado\n");
    }
    if(flagSecondOperandLoaded == 1)
    {
        printf("El segundo operando es %.2f\n", secondOperand);
    }
    else
    {
        printf("El segundo operando no ha sido cargado\n");
    }

}
