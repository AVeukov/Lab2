#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "functions.h"

int binToDec(char *binaryString, int count) 
{
    int decimal = 0;
    int len = strlen(binaryString);
    int power = 1;
    int check = 0;
    if (binaryString[0] == '-')
    	check = 1;
    for (int i = len - 1 - count; i >= check; i--) 
    {
        if (binaryString[i] == '1')
            decimal += power;
        power *= 2;
    }
    if (check == 1)
    	decimal = -decimal;
	
    return decimal;
}
int isBinNum(const char *s, int count)
{
	int len = strlen(s)-count;
	int i = 0;
	
	if (s[0] == '-')
		i=1;
    	
	if (len == 0) 
        	return 0;

    	for (; i < len; i++) {
        	if (s[i] != '0' && s[i] != '1')
            		return 0;
    	}
    	
	return 1;
}
bool isOctal(const char* str, int count) {
    	int i = 0;
	
	if (str[0] == '-')
		i = 1;
    	
	if (str[i] != '0')
        	return false;
    	
	for (; i < strlen(str)-count; i++) 
	{
        	if (str[i] < '0' || str[i] > '7') 
			return false;
        	
    	}
    	return true;
}
int isHexDec(const char *s,int count)
{
	int j = 0;
	if (s[0] == '-')
		j = 1;
	
	int len = strlen(s) - count;
	
	if (len < 3)
		return 0;
 	
	if (s[0+j] != '0' || (s[1+j] != 'x' && s[1+j] != 'X'))
 		return 0;
	
	for (int i = 2 + j; i < len - count; i++) 
	{
		
		if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))) 
		{
            		return 0;
        	}
    	}
    	
	return 1;
}
void printBinary(int number) 
{
	if (number > 1)
        	printBinary(number / 2);
    
    	printf("%d", number % 2);
}
int operation(char* num1, char* proc, char* num2, int base)
{
	int res,inum1,inum2;
	if (base == 16){
		sscanf(num1, "%x", &inum1);
		sscanf(num2, "%x", &inum2);
	}
	else if (base == 8){
		sscanf(num1, "%o", &inum1);
		sscanf(num2, "%o", &inum2);
	}
	else if (base == 2){
		inum1 = binToDec(num1, 0);
		inum2 = binToDec(num2, 1);
	}
	if (num1[0] == '0' && num1[1] == '\0')
		inum1 = 0;
	
	if (num2[0] == '0' && num2[1] == '\0')
		inum2 = 0;
	
	char* bit_oper = "&|^";
	
	if (strchr(bit_oper, proc[0]) && (inum1<0 || inum2<0)){
		printf("Mistake\n");
		exit(-1);
	}
	if (proc[0] == '+')
		res = inum1 + inum2;
	
	else if (proc[0] == '-')
    		res = inum1 - inum2;
	
	else if (proc[0] == '*')
 		res = inum1 * inum2;
	
	else if (proc[0] == '%')
		res = inum1 % inum2;
	
	else if (proc[0] == '&')
		res = inum1 & inum2;
	
	else if (proc[0] == '|')
		res = inum1 | inum2;
	
	else if (proc[0] == '^')
		res = inum1 ^ inum2;
	
	return res;
}
void removeCharacter(char *str, char c) {
	int j, n = strlen(str);
    
    	for (int i = j = 0; i < n; i++) {
        	if (str[i] != c)
            		str[j++] = str[i];
    		}
    
    	str[j] = '\0';
}
int findBase(char* str, int count)
{
	if (isHexDec(str, count))
		return 16;
	
	if (isOctal(str, count))
		return 8;
	
	if (isBinNum(str, count))
		return 2;
	
	return 0;
}
void printRes(int res, int base)
{
	if (base == 16){
		if (res < 0)
			printf("-0x%x (%i)\n", abs(res), res);
		else
			printf("0x%x (%i)\n", res, res);
	}
	else if (base == 2)
	{
		if (res >= 0)
		{
			printBinary(res);
			printf(" (%i)\n", res);
		}
		else{
			printf("-");
			printBinary(abs(res));
			printf(" (%i)\n", res);
		}
	}
	else if (base == 8)
	{
		if (res < 0)
			printf("-0%o (%i)\n", abs(res), res);
		
		else if (res > 0)
			printf("0%o (%i)\n",res,res);
		
		else 
			printf("0 (%i)\n", res);
	}
}
void findRes(char* str, int res, int base, char* num1, char* num2, char* proc){
	if (strchr(str, ' '))
	{
		char* num1 = strtok(str," ");
		char* proc = strtok(NULL," ");
		char* num2;
		
		if (proc != NULL)
		{
			num2 = strtok(NULL," ");
			
			if (strtok(NULL, " ") != NULL)
			{
				printf("строка введена некорректно\n");
				exit(-1);
			}
			int base1, base2;
			base1 = findBase(num1, 0);
			base2 = findBase(num2, 1);
			
			if (num1[0] == '0' && num1[1] == '\0')
				base1 = 2;
			
			if (num2[0] == '0' && num2[2] == '\0')
				base2 = 2;
			
			if (base1 == base2)
			{
				base = base1;
				
				if (base == 0)
				{
					printf("Ошибка: строка введена некорректно\n");
					exit(-1);
				}
			}
			else
			{
				printf("Ошибка: системы счисления не совпадают\n");
				exit(-1);
			}
			res = operation(num1, proc, num2, base);
		}
		else
		{
			printf("Ошибка: строка введена некорректно");
			exit(-1);
		}
		printRes(res, base);
		exit(-1);
	}
	else
	{
		num1 = str;
		if (num1[0] == '~')
		{
			int inum1;
			removeCharacter(num1, '~');
			base = findBase(num1, 1);
			if (num1[0] == '0' && num1[2] == '\0')
				base = 2;
			
			if (base == 16)
				sscanf(num1, "%x", &inum1);
			
			else if (base == 8)
				sscanf(num1, "%o", &inum1);
			
			else if (base == 2)
				inum1 = binToDec(num1,1);
			
			else
			{
				printf("строка введена некорректно");
				exit(-1);
			}
			if (inum1 < 0)
			{
				printf("строка введена некорректно");
				exit(-1);
			}
			res = ~inum1;
			printRes(res, base);
			exit(-1);
		}
		else
		{
			printf("строка введена некорректно");
			exit(-1);
		}
	}
}






