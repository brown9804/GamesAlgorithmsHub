#include <stdio.h>


int main(void)
{
    int i = 0;
    int p = 0;
    int dele = 0;
    int fila = 0; 
    int columna = 0;
    int lineawin = 0;
    int win = 0;
    char tablero[3][3] = 
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    
    for( i = 0; i<9 && win==0; i++)
    
    {
        printf("\n\n");
        printf(" %c | %c | %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
printf("-----------\n");
        printf(" %c | %c | %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);
        
        p = i%2 + 1;
        
        do
        {
printf("\nHola, jugador  %d, Digite la casilla donde quiere realizar su jugada %c: ", p,(p==1)?'X':'O');
            scanf("%d", &dele);
            
            fila = --dele/3;
            columna = dele%3;
        }
        while(dele<0 || dele>9 || tablero[fila][columna]>'9');
        
        tablero[fila][columna] = (p == 1) ? 'X' : 'O';
        
	if((tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]) ||
           (tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])){
	       	win = p;
		printf("\n\n");
		printf("Ganó por diagonal\n");
	}
	else
            
            for(lineawin = 0; lineawin <= 2; lineawin ++)
                
                if((tablero[lineawin][0] == tablero[lineawin][1] && tablero[lineawin][0] == tablero[lineawin][2])||
                   (tablero[0][lineawin] == tablero[1][lineawin] && tablero[0][lineawin] == tablero[2][lineawin])){
		       	win = p;
			printf("\n\n");
			printf("Ganó por línea\n");
		}
        
    }
    printf("\n\n");
    printf(" %c | %c | %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
printf("_____________\n");
    printf(" %c | %c | %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
printf("_____________\n");
    printf(" %c | %c | %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);
    
    if(win == 0)
        printf("\nEmpate\n");
    else
printf("\nHey  %d, felicidades!\n", win);
}
