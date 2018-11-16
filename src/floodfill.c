#include<floodfill.h>

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

