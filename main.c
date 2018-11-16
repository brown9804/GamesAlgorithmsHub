#include "floodfill.h"
#include <stdio.h>
#include <stdlib.h>
#include
void floodfill(int f, int c){

	char sim=i[f][c];

	if ((i[f][c]) == '|' && (i[f][c]) == '-'){
		
		i[f][c]= i[f][c];
	}
	else
	{
		i[f][c] = '@';
	}

	if (i[f+1][c]==sim){
			floodfill(f+1,c);
		}
		
	if (i[f][c-1]==sim){
			floodfill(f,c-1);
		}

	if (i[f-1][c]==sim){
			floodfill(f-1,c);
	
		}

	if (i[f][c+1]==sim)
		{
			floodfill(f,c+1);
		}


	

}

void imprimir(){
	for (int n = 0; n < 12; ++n)
	{
		for (int m = 0; m < 25; ++m)
		{
			printf("%c ",i[n][m]);
		}
		printf("\n");
	}
}


int main(int argc, char const *argv[])
{
	int fila;
	int columna;

	imprimir();
	printf("Digite (fila,columna) : \n");
	scanf("%i,%i",&fila, &columna);

	floodfill(fila, columna);
	imprimir();

	return 0;
}
