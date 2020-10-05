#ifndef MUZZIN_H_INCLUDED
#define MUZZIN_H_INCLUDED

// Grupo de funciones relacionado a operaciones matemáticas

/** \brief calcula la suma de los operandos
*
*   \param a float primer operando de la suma
*   \param b float segundo operando de la suma
*
*   \return el resultado de la suma de a más b
*
*/
float addOperation (float a, float b);

/** \brief calcula la resta de los operandos
*
*   \param a float primer operando de la resta
*   \param b float segundo operando de la resta
*
*   \return el resultado de la resta de a menos b
*
*/
float subtractOperation (float a, float b);

/** \brief calcula la multiplicación de los operandos
*
*   \param a float primer operando de la multiplicación
*   \param b float segundo operando de la multiplicación
*
*   \return el resultado de la multiplicación de a por b
*
*/
float multiplyOperation (float a, float b);

/** \brief calcula la división de los operandos
*
*   \param a float primer operando de la división
*   \param b float segundo operando de la división
*
*   \return el resultado de la división de a dividido b
*
*/
float divideOperation (float a, float b);

/** \brief calcula el factorial del operando
*
*   \param a int operando del factorial
*
*   \return el resultado del factorial
*
*/
long long unsigned factorialOperation (int a);

/** \brief calcula el factorial del operando
*
*   \param firstOperand float primer operando
*   \param secondOperand float segundo operando
*   \param pAddResult float* puntero al resultado de la suma
*   \param pSubtractionResult float* puntero al resultado de la resta
*   \param pMultiplicationResult float* puntero al resultado de la multiplicación
*   \param pDivisionResult float* puntero al resultado de la división
*   \param pFactorialResultA long long unsigned* puntero al resultado del factorial
*   \param pFactorialResultB long long unsigned* puntero al resultado del factorial
*   \param pFlagUpdatedCalculations float* puntero a la bandera de cálculos
*
*   \return void
*
*/
void performCalculations(float firstOperand, float secondOperand, float* pAddResult, float* pSubtractionResult, float* pMultiplicationResult,
                         float* pDivisionResult, long long unsigned* pFactorialResultA, long long unsigned* pFactorialResultB, int* pFlagUpdatedCalculations);


// Grupo de funciones relacionado a validación

/** \brief verifica que el operando sea un entero
*
*   \param number float operando a validar
*
*   \return retorna valor 1 si el operando es un entero o 0 si no lo es
*
*/
int checkIfFloatIsInt(float number);

/** \brief verifica que se pueda resolver el factorial, es decir que sea mayor a 1 y un entero
*
*   \param number float el operando
*
*   \return 1 si es posible calcularle el factorial, 0 si no
*
*/
int canCalculateFactorial(float number);

// Grupo de funciones relacionado a carga de datos por parte del usuario

/** \brief almacena el valor ingresado por el usuario
*
*   \param pOperand float* puntero al operando
*   \param pFlagUpdatedCalculations float* puntero a la bandera que indica si se realizaron las operaciones
*   \param pFlagOperandLoaded float* puntero a la bandera que indica si el operando fue cargado o no
*
*   \return void
*
*/
void loadOperand(float* pOperand, int* pFlagUpdatedCalculations, int* pFlagOperandLoaded);


/** \brief solicita al usuario que ingrese la opción del menú que desea ejecutar
*
*   \param
*
*   \return el número de la opción elegida
*
*/int askForOption();

// Grupo de funciones relacionado a mostrar información

/** \brief muestra el mensaje del resultado de la operación
*
*   \param operatorChar char signo que identifica la operación matemática
*   \param result float resultado de la operación
*
*   \return void
*
*/
void displayOperationResult(char operatorChar, float result);

/** \brief muestra el mensaje del resultado de la operación
*
*   \param resultA long long unsigned resultado del factorial del primer operando
*   \param resultB long long unsigned resultado del factorial del segundo operando
*
*   \return void
*
*/
void displayFactorialResult(long long unsigned resultA, long long unsigned resultB);


/** \brief muestra el mensaje del resultado de la operación, cuando solo se puede calcular el factorial del primer operando
*
*   \param result long long unsigned resultado del factorial del primer operando
*
*   \return void
*
*/
void displayFactorialResultA(long long unsigned result);

/** \brief muestra el mensaje del resultado de la operación, cuando solo se puede calcular el factorial del segundo operando
*
*   \param result long long unsigned resultado del factorial del segundo operando
*
*   \return void
*
*/
void displayFactorialResultB(long long unsigned result);

/** \brief muestra el mensaje del resultado de cada operación
*
*   \param addResult float el resultado de la suma
*   \param subtractionResult float el resultado de la resta
*   \param multiplicationResult float el resultado de la multiplicación
*   \param divisionResult float el resultado de la división
*   \param firstOperand float primer operando
*   \param secondOperand float segundo operando
*   \param factorialResultA long long unsigned el resultado del factorial
*   \param factorialResultB long long unsigned el resultado del factorial
*
*   \return void
*
*/
void displayAllTheResults(float addResult, float subtractionResult, float multiplicationResult, float divisionResult, float firstOperand,
                          float secondOperand, long long unsigned factorialResultA, long long unsigned factorialResultB);

/** \brief muestra el menú por pantalla
*
*   \param flagFirstOperandLoaded bandera que indica si se cargó el primer operando o no
*   \param firstOperand primer operando
*   \param flagSecondOperandLoaded bandera que indica si se cargó el segundo operando o no
*   \param secondOperand segundo operando
*
*   \return void
*
*/
void showMenu(int flagFirstOperandLoaded, float firstOperand, int flagSecondOperandLoaded, float secondOperand);

#endif // MUZZIN_H_INCLUDED
