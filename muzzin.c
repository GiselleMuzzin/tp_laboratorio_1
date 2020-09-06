#include "muzzin.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int addOperation (int a, int b)
{
    int addition;
    addition = a + b;
    return addition;
}

int subtractOperation (int a, int b)
{
    int subtraction;
    subtraction = a - b;
    return subtraction;
}

int multiplyOperation(int a, int b)
{
    int multiplication;
    multiplication = a * b;
    return multiplication;
}

// requiere que b no sea 0
float divideOperation(int a, int b)
{
    float division;
    division = (float) a / b;
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


void displayIntResult(char operatorChar, int result)
{
    printf("El resultado de A%cB es: %d\n", operatorChar, result);
}

void displayFloatResult(char operatorChar, float result)
{
    printf("El resultado de A%cB es: %.2f\n", operatorChar, result);
}

void displayFactorialResult(int resultA, int resultB)
{
    printf("El factorial de A es: %d y El factorial de B es: %d\n", resultA, resultB);
}

void displayFactorialResultA(int result)
{
    printf("El factorial de A es: %d y El factorial de B no se pudo calcular porque es menor a 1\n", result);
}

void displayFactorialResultB(int result)
{
    printf("El factorial de A no se pudo calcular porque es menor a 1 y El factorial de B es: %d\n", result);
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

void showMenu(int firstOperandLoaded, int firstOperand, int secondOperandLoaded, int secondOperand)
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
        printf("El primer operando es %d\n", firstOperand);
    }
    else
    {
        printf("El primer operando no ha sido cargado\n");
    }
    if(secondOperandLoaded == 1)
    {
        printf("El segundo operando es %d\n", secondOperand);
    }
    else
    {
        printf("El segundo operando no ha sido cargado\n");
    }

}
