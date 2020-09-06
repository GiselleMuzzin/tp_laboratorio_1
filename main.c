/*
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "muzzin.h"


int main(void)
{
    int firstOperand=0;
    int secondOperand=0;
    int addResult;
    int subtractionResult;
    int multiplicationResult;;
    int factorialResultA;
    int factorialResultB;
    int option;
    float divisionResult;
    int updatedCalculations = 0;
    int firstOperandLoaded = 0;
    int secondOperandLoaded = 0;


    showMenu(firstOperandLoaded, firstOperand, secondOperandLoaded, secondOperand);
    option = askForOption();


    while(option != 5)  //opcion 5 es salir
    {
        switch(option)
        {
        case 1:
            printf("Ingrese el primer operando: ");
            scanf("%d", &firstOperand);
            updatedCalculations = 0;
            firstOperandLoaded = 1;
            break;
        case 2:
            printf("Ingrese el segundo operando: ");
            scanf("%d", &secondOperand);
            updatedCalculations = 0;
            secondOperandLoaded = 1;
            break;
        case 3:
            if (firstOperandLoaded == 0 || secondOperandLoaded == 0)
            {
                printf("Para hacer los calculos se deben ingresar dos operandos mediante las opciones 1 y 2 del menu\n");
            }
            else
            {
                addResult= addOperation(firstOperand,secondOperand);
                subtractionResult = subtractOperation(firstOperand,secondOperand);
                multiplicationResult = multiplyOperation(firstOperand,secondOperand);
                if(secondOperand != 0)
                {
                    divisionResult = divideOperation(firstOperand,secondOperand);
                }
                if(firstOperand >= 1)
                {
                    factorialResultA = factorialOperation(firstOperand);
                }
                if(secondOperand >= 1)
                {
                    factorialResultB = factorialOperation(secondOperand);

                }
                updatedCalculations = 1;
            }
            break;
        case 4:
            if(updatedCalculations == 0)
            {
                printf("Los calculos no estan listos para ser mostrados, calculelos con la opcion 3\n");
            }
            else
            {
                displayIntResult('+', addResult);
                displayIntResult('-', subtractionResult);
                displayIntResult('*', multiplicationResult);
                if(secondOperand == 0)
                {
                    printf("No se puede dividir por cero.\n");
                }
                else
                {
                    displayFloatResult('/', divisionResult);
                }
                if(firstOperand >= 1 && secondOperand >= 1 )
                {
                    displayFactorialResult(factorialResultA, factorialResultB);
                }
                else
                {
                    if(firstOperand < 1 && secondOperand >= 1)
                    {
                        displayFactorialResultB(factorialResultB);
                    }
                    else
                    {
                        if(firstOperand >= 1 && secondOperand < 1)
                        {
                            displayFactorialResultA(factorialResultA);
                        }
                        else
                        {
                            printf("El factorial de A no se pudo calcular porque es menor a 1 y El factorial de B tampoco\n");
                        }
                    }

                }
            }
            break;

        }
        showMenu(firstOperandLoaded, firstOperand, secondOperandLoaded, secondOperand);
        option = askForOption();

    }


    return 0;
}

