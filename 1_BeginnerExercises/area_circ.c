#include<stdio.h>
#include<stdlib.h>

int main()
{
	float area;
	int radio;
	printf("Digite el radio del círculo para calcular su área ");
	scanf("%d",&radio);
	area = radio*radio*3.14;
	printf("El área del círculo es de: %f\n",area);
}
