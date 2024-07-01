#include<stdio.h>
#include<stdlib.h>

int main()
{
	int largo;
	int ancho;
	int area;
	printf("Digite el ancho del rectángulo para calcular su área ");
	scanf("%d",&ancho);
	printf("Ingrese el largo del rectángulo ");
	scanf("%d",&largo);
	area = largo*ancho;
	printf("EL área del rectángulo es de %d\n",area);
}
