//Lab2
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdbool.h>
int binToDec(char *binaryString, int count);
int isBinNum(const char *s, int count);
bool isOctal(const char* str, int count);
int isHexDec(const char *s,int count);
void printBinary(int number);
int operation(char* num1, char* proc, char* num2, int base);
void removeCharacter(char *str, char c);
int findBase(char* str, int count);
void printRes(int res, int base);
void findRes(char* str, int res, int base, char* num1, char* num2, char* proc);

#endif	
