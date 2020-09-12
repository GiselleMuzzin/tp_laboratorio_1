/*
Muzzin Giselle
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
    // Operandos de las operaciones
    float firstOperand = 0;
    float secondOperand = 0;

    // Resultados de las operaciones
    float addResult;
    float subtractionResult;
    float multiplicationResult;
    float divisionResult;
    long long unsigned factorialResultA;
    long long unsigned factorialResultB;

    // Opcion seleccionada por el usuario
    int option;

    // Bandera que indica si los calculos estan actualizados
    // esto es: se hicieron despues de que se diera valor a los operandos
    int flagUpdatedCalculations = 0;

    // Bandera que indica si el primer operando ha sido cargado (si no se carga, no se puede sumar)
    // Ademas no se puede mostrar el valor del operando si no se cargó
    int flagFirstOperandLoaded = 0;
    // Analogo pero para el segundo operando
    int flagSecondOperandLoaded = 0;

    showMenu(flagFirstOperandLoaded, firstOperand, flagSecondOperandLoaded, secondOperand);
    option = askForOption();

    while(option != 5)  //opcion 5 es salir
    {
        switch(option)
        {
        case 1:
            printf("Ingrese el primer operando: ");
            loadOperand(&firstOperand, &flagUpdatedCalculations, &flagFirstOperandLoaded);
            break;
        case 2:
            printf("Ingrese el segundo operando: ");
            loadOperand(&secondOperand, &flagUpdatedCalculations, &flagSecondOperandLoaded);
            break;
        case 3:
            if (flagFirstOperandLoaded == 0 || flagSecondOperandLoaded == 0) // Falta cargar algun operando, no podemos operar
            {
                printf("Para hacer los calculos se deben ingresar dos operandos mediante las opciones 1 y 2 del menu\n");
            }
            else
            {
                performCalculations(firstOperand, secondOperand, &addResult, &subtractionResult, &multiplicationResult,
                                    &divisionResult,&factorialResultA, &factorialResultB, &flagUpdatedCalculations);
            }
            break;
        case 4:
            if(flagUpdatedCalculations == 0) // Los calculos no se han hecho desde que se cargaron los operandos
            {
                printf("Los calculos no estan listos para ser mostrados, calculelos con la opcion 3\n");
            }
            else
            {
                displayAllTheResults(addResult, subtractionResult, multiplicationResult, divisionResult, firstOperand, secondOperand, factorialResultA, factorialResultB);
            }
            break;
        }
        showMenu(flagFirstOperandLoaded, firstOperand, flagSecondOperandLoaded, secondOperand);
        option = askForOption();
    }
    return 0;
}
