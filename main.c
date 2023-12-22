#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
		
int main()
{
	char* str = NULL;
	size_t len = 0;
	ssize_t read = getline(&str,&len,stdin);
	if (read == -1)
	{
		return -1;
	}
	int base;
	int res;
	char* num1;
	char* num2;
	char* proc;
	findRes(str,res, base, num1, num2, proc);
	return 0;
}





