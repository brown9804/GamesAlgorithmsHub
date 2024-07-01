#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<stdio.h>
int aleatorio(int min,int max)
{
	int number;
	number= (rand()%(max-min))+min;
	return number;
}
int main ()
{
	int cond;
	int mnum;
	int i;
	int max=100;
	int min=0;
	int number;
	i=0;
	srand(time(NULL));
	mnum=rand() % 101;
	number=aleatorio(min,max);
	printf("Piense en un numero que se encuentre entre 0-100\n");	
	sleep(3);
	printf("Creo que el numero es %d\n", mnum);
	printf("Digite 1 si el numero que usted penso es igual al que yo le proyecte, 2 si es mayor y 3 si es menor\n");
	while (1)
	{	
		scanf("%d",& cond);
		i++;	
		if (cond==1)	
		{
			printf("He adivinado el numero, el numero es %d\n", mnum);
		break;
		}	
		if (cond==2)	
		{
			min=mnum;
			mnum=aleatorio(min,max);
			printf("El numero es %d?\n",mnum);			
			printf("Digite 1 si el numero que usted penso es igual al que yo le proyecte, 2 si es mayor y 3 si es menor\n");
		}
		if (cond==3) 
		{;
			max=mnum;
			mnum=aleatorio(min,max);
			printf("El numero es %d?\n", mnum);
			printf("Digite 1 si el numero que usted penso es igual al que yo le proyecte, 2 si es mayor y 3 si es menor\n");;
		}
	}
	printf("Lo he intentado  %d veces\n", i);
	return  0;
}
