#include<stdio.h>
int main()
{
	int naci;
	int edad;
	printf("Ingrese su año de nacimiento\n");
	scanf("%d",&naci);
	edad = 2017-naci;
	if (edad>=18)
	{ 
		printf("Usted es mayor de edad y su edad es %d\n",edad);
	}
	else 
	{
		printf("Usted es menor de edad y su edad es %d\n",edad);
	}
}	
