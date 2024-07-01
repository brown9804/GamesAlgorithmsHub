#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main (int argc, char *argv[])
{
	system("clear");
	int **m;
	int z,filas,columnas;
	printf("El juego funciona de la siguiente manera: Se le va a solicitar la dimensión cuadrada del gato o tic tac toe que desee utilizar, después, debe seleccionar la posición por coordenadas dándole enter a cada coordenada en orden de filas por columnas y así sucesivamente\n");
	printf("\n\n");
	printf("Dimension del tablero NxN:\n");
	scanf("%d",&filas);
	system("clear");
	columnas=filas;
	m=calloc(filas, sizeof(int *));
	for (z = 0; z < filas; z += 1)
	{
		m[z]=calloc(columnas, sizeof(int));
	}
	int tope=pow(filas,2);
	int turnos=1;
	int f,c,a,b;
	int temp=filas;
	int fil,col,col2,gana;
	int diag;
	printf("  ");
	for (z = 1; z <= filas; z += 1)
	{
		printf("%d ",z);
	}
	printf("\n");
	for (f = 0; f < filas; f += 1)
	{
		printf("%d ",f+1);
		for (c = 0; c < columnas; c += 1)
		{
			if (m[f][c]==0)
			{
				printf("^ ");
			}
			
		}
		printf("\n");
	}
	do
	{
		printf("Turno numero: %d\n",turnos);
		printf("Turno Jugador X:\n");
		scanf("%d %d",&a,&b);
		while (a>filas || b>filas || a<1 || b<1 || m[a-1][b-1]==1 || m[a-1][b-1]==2)
		{
			if (a>filas || b>filas || a<1 || b<1)
			{
				printf("Sobrepasa la dimensión\n");
			        printf("Debe ingresar otra coordenada ya que la anterior no existe\n");
				scanf("%d %d",&a,&b);
			}
			else if (m[a-1][b-1]==1 || m[a-1][b-1]==2)
			{
				printf("Este espacio está ocupado\n");
				printf("Intente con otra posición\n");
				scanf("%d %d",&a,&b);
			}
			
		}
		system("clear");
		m[a-1][b-1]=1;
		printf("  ");
		for (z = 1; z <= filas; z += 1)
		{
			printf("%d ",z);
		}
		printf("\n");
		for (f = 0; f < filas; f += 1)
		{
			printf("%d ",f+1);
			for (c = 0; c < columnas; c += 1)
			{
			if (m[f][c]==0)
			{
				printf(". ");
			}
			if (m[f][c]==1)
			{
				printf("X ");
			}
			if (m[f][c]==2)
			{
				printf("O ");
			}
			}
		printf("\n");
		}
	       		
		fil=0;
		for (f = 0; f < filas; f += 1)
		{
			fil=0;
			for (c = 0; c < columnas; c += 1)
			{
				if (m[f][c]==1)
				{
					fil++;
				}
				
			}
			if (fil==columnas)
			{
				printf("El jugador X ha ganado\n");
				return 0;
			}
		}

		col=0;
		for (c = 0; c < columnas; c += 1)
		{
			col=0;
			for (f = 0; f < filas; f += 1)
			{
				if (m[f][c]==1)
				{
					col++;
				}
				
			}
			if (col==columnas)
			{
				printf("El jugador X ha ganado \n");
				return 0;
			}
		}
	
		for (f = 0; f < filas; f += 1)
		{
			fil=0;
			for (c = 0; c < columnas; c += 1)
			{
				if (m[0+c][0+c]==1)
				{
					fil++;
				}
				
			}
			if (fil==columnas)
			{
				printf("El jugador X ha ganado\n");
				return 0;
			}
		}
		temp=filas;
		diag=0;
		for (f = 0; f < filas; f += 1)
		{
			
			for (c = 0; c < columnas; c += 1)
			{
				if (m[f][temp-1]==1)
				{
					diag++;
					temp=temp-1;
				}
				
			}
			if (diag==columnas)
			{
				printf("El jugador X ha ganado \n");
				return 0;
			}
		}		
		
		
		
		if (turnos==tope)
		{
			break;
		}
		turnos++;
		
		printf("Este es el turno número: %d\n",turnos);
		printf("Turno del jugador O:\n");
		scanf("%d %d",&a,&b);
		while (a>filas || b>filas || a<1 || b<1 || m[a-1][b-1]==1 || m[a-1][b-1]==2)
		{
			if (a>filas || b>filas || a<1 || b<1)
			{
				printf("Sobrepasa la dimensión\n");
                                printf("Debe ingresar otra coordenada ya que la anterior no existe\n");
				scanf("%d %d",&a,&b);
			}
			else if (m[a-1][b-1]==1 || m[a-1][b-1]==2)
			{
				printf("Este espacio está ocupado\n");
                                printf("Intente con otra posición\n");
				scanf("%d %d",&a,&b);
			}
			
		}
		system("clear");
		m[a-1][b-1]=2;
		printf("  ");
		for (z = 1; z <= filas; z += 1)
		{
			printf("%d ",z);
		}
		printf("\n");
		for (f = 0; f < filas; f += 1)
		{
		printf("%d ",f+1);
		for (c = 0; c < columnas; c += 1)
		{
			if (m[f][c]==0)
			{
				printf("^ ");
			}
			if (m[f][c]==1)
			{
				printf("X ");
			}
			if (m[f][c]==2)
			{
				printf("O ");
			}
		}
		printf("\n");
	}
			
		fil=0;
		for (f = 0; f < filas; f += 1)
		{
			fil=0;
			for (c = 0; c < columnas; c += 1)
			{
				if (m[f][c]==2)
				{
					fil++;
				}
				
			}
			if (fil==columnas)
			{
				printf("El jugador de O ha ganado\n");
				return 0;
			}
		}

		col=0;
		for (c = 0; c < columnas; c += 1)
		{
			col=0;
			for (f = 0; f < filas; f += 1)
			{
				if (m[f][c]==2)
				{
					col++;
				}
				
			}
			if (col==columnas)
			{
				printf("El jugador de O ha ganado\n");
				return 0;
			}
		}
		for (f = 0; f < filas; f += 1)
		{
			fil=0;
			for (c = 0; c < columnas; c += 1)
			{
				if (m[0+c][0+c]==2)
				{
					fil++;
				}
				
			}
			if (fil==columnas)
			{
				printf("El jugador de O ha ganado\n");
				return 0;
			}
		}
		temp=filas;
		diag=0;
		for (f = 0; f < filas; f += 1)
		{
			
			for (c = 0; c < columnas; c += 1)
			{
				if (m[f][temp-1]==2)
				{
					diag++;
					temp=temp-1;
				}
				
			}
			if (diag==columnas)
			{
				printf("El jugador de O ha ganado\n");
				return 0;
			}
		}		
		turnos++;
	} while (tope>=turnos); 
	
	printf("Esto ha sido un empate\n");







	for (z = 0; z < filas; z += 1)
	{
		free(m[z]);
	}
	free(m);
	
	return 0;
}
