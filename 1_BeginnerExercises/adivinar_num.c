#include<stdlib.h>
#include<time.h>
#include<stdio.h>
int main ()
{
	int num;
	int new;
	int i;
	i=0;
	srand(time(NULL));
	new=rand() % 101;
	printf("Intente adivinar el numero, es entre 0 - 100, digite el numero\n");
	while (1)
	{	
		scanf("%d", &num);
		i++;	
		if (num==new)	
		{
			printf("Correcto ha adivinado, el numero es %d\n", new);
		break;
		}	
		if (new<num)	
		{
			printf("El numero digitado fue %d\n ", num);
			printf("Ese no es el numero, el numero es menor\n");
			printf("Digite otra vez\n");
		}
		if (new>num) 
		{
			printf("El numero digitado fue %d\n ", num);
			printf("Ese no es el numero, el numero es mayor\n");
			printf("Digite otra vez\n");
		}
	}
	printf("Usted lo ha intentado %d veces\n", i);
}
