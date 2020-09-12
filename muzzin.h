#ifndef MUZZIN_H_INCLUDED
#define MUZZIN_H_INCLUDED

// math operations

/** \brief calcula la suma de los operandos
*   \param a float primer operando de la suma
*   \param b float segundo operando de la suma
*   \return el resultado de la suma de a y b
*
*/
float addOperation (float a, float b);
float subtractOperation (float a, float b);
float multiplyOperation (float a, float b);
float divideOperation (float a, float b);
int factorialOperation (int a);
int checkIfFloatIsInt(float number);
int canCalculateFactorial(float number);
void loadOperand(float* pOperand, int* pFlagUpdatedCalculations, int* pFlagOperandLoaded);
void displayOperationResult(char operatorChar, float result);
void displayFactorialResult(int resultaA, int resultB);
void displayFactorialResultA(int result);
void displayFactorialResultB(int result);
void performCalculations(float firstOperand, float secondOperand, float* pAddResult, float* pSubtractionResult,
                        float* pMultiplicationResult, float* pDivisionResult,
                        int* pFactorialResultA, int* pFactorialResultB, int* pFlagUpdatedCalculations);

int askForOption();

void showMenu(int firstOperandLoaded, float firstOperand, int secondOperandLoaded, float secondOperand);
void displayAllTheResults(float addResult, float substractionResult, float multiplicationResult, float divisionResult, float firstOperand, float secondOperand, int factorialResultA, int factorialResultB);


#endif // MUZZIN_H_INCLUDED
