#ifndef MUZZIN_H_INCLUDED
#define MUZZIN_H_INCLUDED

// defino las funciones que necesito
int addOperation (int a, int b);
int subtractOperation (int a, int b);
int multiplyOperation (int a, int b);
float divideOperation (int a, int b);
int factorialOperation (int a);

void displayIntResult(char operatorChar, int result);
void displayFactorialResult(int resultaA, int resultB);
void displayFloatResult(char operatorChar, float result);
void displayFactorialResultA(int result);
void displayFactorialResultB(int result);

int askForOption();

void showMenu(int firstOperandLoaded, int firstOperand, int secondOperandLoaded, int secondOperand);



#endif // MUZZIN_H_INCLUDED
