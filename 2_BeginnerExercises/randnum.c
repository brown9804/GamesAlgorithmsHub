#include<stdlib.h>
#include<stdio.h>
#include<time.h>
int main ()
{
	int num;
	int indr;
	srand(time(NULL));
	num= rand() %30;
	indr=num+40;
	printf("El número random es %d\n", indr);
	printf("num es %d\n", num);
return 0;
}

