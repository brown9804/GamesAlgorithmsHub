#include<stdio.h>
#include<stdlib.h>

int main()
{
	int notas;
	int cant;
	int nota;
	float promedio;
	cant = promedio = notas = 0; 
	while (cant<20) {
		printf("Introduzca una nota ");
		scanf("%d",&nota);
		notas = notas + nota;
		cant = cant +1;
	}
	promedio = notas/20.0;
	printf("El promedio de las notas es de: %f\n",promedio);
}
