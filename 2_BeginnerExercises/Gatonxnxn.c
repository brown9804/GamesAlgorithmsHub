#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check(int ***matrix,int n, int filas,int v){
	for (int r = 0;r <= n; r=r+1)
	{
		for (int p = 0;p <= n; p=p+1)
		{
			for (int q = 0;q <= n;q=q+1)
			{
				if(matrix[p][n][r] == matrix[p][n-q][r] && matrix[p][n-q][r] != 0)
				{
					filas = filas +1;
				}
			}
			if(filas == n+1)
			{
				v=0;
				filas=0;
			}
			else
			{
				filas=0;
			}
		}
	}			
	for (int r = 0;r <= n; r=r+1)
	{
		for (int p = 0;p <= n; p=p+1)
		{
			for (int q = 0;q <= n; q=q+1)
			{
           		if(matrix[n][p][r] == matrix[n-q][p][r] && matrix[n-q][p][r] != 0)
           	                {
					filas=filas+1;
				}
			}
			if(filas == n+1)
			{
				v=0;
				filas=0;
			}
			else
			{
				filas=0;
			}
		}
	}
	for(int r = 0;r <= n;r=r+1)
	{
		for(int s = 0;s <= n;s=s+1)
		{
			if(matrix[0][0][r] == matrix[s][s][r] && matrix[s][s][r] != 0)
			{
				filas=filas+1;
			}
		}
		if(filas == n+1)
		{
			v=0;
			filas=0;
		}
		else
		{
			filas=0;
		}
	}
	for(int r = 0;r <= n;r=r+1)
	{
		for(int t = 0;t <= n;t=t+1)
		{
			if(matrix[n][0][r] == matrix[n-t][t][r] && matrix[n-t][t][r] != 0)
			{
				filas=filas+1;
			}
		}
		if(filas == n+1)
		{
			v=0;
			filas=0;
		}
		else
		{
			filas=0;
		}
	}
	for (int r = 0;r <= n; r=r+1)
	{
		for (int p = 0;p <= n; p=p+1)
		{
			for (int q = 0;q <= n;q=q+1)
			{
				if(matrix[r][p][q] == matrix[r][p][n-q] && matrix[r][p][n-q] != 0)
				{
					filas = filas+1;
				}
			}
			if(filas == n+1)
			{
				v=0;
				filas=0;
			}
			else
			{
				filas=0;
			}
		}
	}
	for(int r = 0;r <= n;r=r+1)
	{
		for(int s = 0;s <= n;s=s+1)
		{
			if(matrix[r][0][0] == matrix[r][s][s] && matrix[r][s][s] != 0)
			{
				filas=filas+1;
			}
		}
		if(filas == n+1)
		{
			v=0;
			filas=0;
		}
		else
		{
			filas=0;
		}
	}
	for(int r = 0;r <= n;r=r+1)
	{
		for(int t = 0;t <= n;t=t+1)
		{
			if(matrix[r][n][0] == matrix[r][n-t][t] && matrix[r][n-t][t] != 0)
			{
				filas=filas+1;
			}
		}
		if(filas == n+1)
		{
			v=0;
			filas=0;
		}
		else
		{
			filas=0;
		}
	}
	for(int r = 0;r <= n;r=r+1)
	{
		for(int s = 0;s <= n;s=s+1)
		{
			if(matrix[0][r][0] == matrix[s][r][s] && matrix[s][r][s] != 0)
			{
				filas=filas+1;
			}
		}
		if(filas == n+1)
		{
			v=0;
			filas=0;
		}
		else
		{
			filas=0;
		}
	}
	for(int r = 0;r <= n;r=r+1)
	{
		for(int t = 0;t <= n;t=t+1)
		{
			if(matrix[0][r][n] == matrix[t][r][n-t] && matrix[t][r][n-t] != 0)
			{
				filas=filas+1;
			}
		}
		if(filas == n+1)
		{
			v=0;
			filas=0;
		}
		else
		{
			filas=0;
		}
	}
	for(int t = 0;t <= n;t=t+1)
	{
		if(matrix[0][0][0] == matrix[t][t][t] && matrix[t][t][t] != 0)
		{
			filas=filas+1;
		}
	}
	if(filas == n+1)
	{
		v=0;
		filas=0;
	}
	else
	{
		filas=0;
	}
	for(int t = 0;t <= n;t=t+1)
	{
		if(matrix[0][n][0] == matrix[t][n-t][t] && matrix[t][n-t][t] != 0)
		{
			filas=filas+1;
		}
	}
	if(filas == n+1)
	{
		v=0;
		filas=0;
	}
	else
	{
		filas=0;
	}
	for(int t = 0;t <= n;t=t+1)
	{
		if(matrix[n][n][0] == matrix[n-t][n-t][t] && matrix[n-t][n-t][t] != 0)
		{
			filas=filas+1;
		}
	}
	if(filas == n+1)
	{
		v=0;
		filas=0;
	}
	else
	{
		filas=0;
	}
	for(int t = 0;t <= n;t=t+1)
	{
		if(matrix[n][0][0] == matrix[n-t][t][t] && matrix[n-t][t][t] != 0)
		{
			filas=filas+1;
		}
	}
	if(filas == n+1)
	{
		v=0;
		filas=0;
	}
	else
	{
		filas=0;
	}
	return v;
}
int checker(int ***matrix,int filas,int c2,int c,int n){
	for (int p = 0;p <= n; p=p+1)
	{
		for (int q = 0;q <= n;q=q+1)
		{
			if(*matrix[p][n-q]== 'O')
			{
				filas = 1;
			}
			if(*matrix[p][n-q]=='X')
			{
				c = 1;
			}
		}
		if(c + filas==2)
		{
            		filas = 0;
			c2 = c2 +1;
			c = 0;
		}
		else
		{
			c = 0;
			filas = 0;
		}				
	}			
	for (int p = 0;p <= n; p=p+1)
	{
		for (int q = 0;q <= n; q=q+1)
		{
			if(*matrix[n-q][p] == 'O')
               	{
                	filas=1;
               	}
			if(*matrix[n-q][p] == 'X')
			{
				c = 1;
			}
		}
		if(c + filas==2)
		{
			c2 = c2 +1;
			c = 0;
			filas = 0;
		}
		else
		{
			c = 0;
			filas = 0;
		}		
	}
	for(int s = 0;s <= n;s=s+1)
	{
		if(*matrix[s][s]== 'O')
		{
			filas=1;
		}
		if(*matrix[s][s]== 'X')
		{
			c=1;
		}
	}
	if(c + filas==2)
	{
		c2 = c2 +1;
		filas = 0;
        c = 0;
	}
	else
	{
		c = 0;
		filas = 0;
	}		
	for(int t = 0;t <= n;t=t+1)
	{
		if(*matrix[n-t][t]== 'X')
		{
			filas=1;
		}
		if(*matrix[n-t][t]=='O')
		{
			c=1;
		}
	}
	if(c + filas==2)
	{
		c2 = c2 +1;
		c = 0;
		filas = 0;
	}
	else
	{
		c = 0;
		filas = 0;
	}
	return c2;
}
void print(int ***matrix, int n){
    
	for (int p = 0;p <= n; p=p+1)
	{
		for (int q = 0;q <= n;q=q+1)
		{
		    printf("|");;
		    for (int r=0;r<=n;r=r+1)
		    {
			    printf("%c", matrix[p][q][r]);
			    printf("    ");
		    }
		    printf("|");
			printf("\n");		    
		}
	printf("\n");     	
	}
}


int main () {
	int n;
	int x = 1;
	int a;
	int b;
	int v = 1;
	int filas = 0;
	int c = 0;
	int c2 = 0;
	int ***matrix;
	char y = 'X';
	char o = 'O';

	printf("Por favor digite la dimension del gato: \n");
	scanf("%d",&n);
	matrix = malloc(n * sizeof(char **));
	for (int i = 0;i < n;i=i+1)
	{
		matrix[i] = malloc(n * sizeof(char *));
	    for (int m = 0;m < n;m=m+1)
	    {
		    matrix[i][m] = malloc(n * sizeof(char));
	    }
    }    
	n= n-1;
	for (int p = 0;p <= n; p=p+1)
	{
		for (int q = 0;q <= n;q=q+1)
		{
		    for (int r=0;r<=n;r=r+1)
		    {
			    matrix[p][q][c] = 0;
		    }
		}
	}
	while(v==1)
	{
		printf("Player 1 digite debe digitar la posicion de la O: \n");
		scanf("%d %d %d",&a, &b, &c);
		if(matrix[a][b][c] == 'X' || matrix[a][b][c] == 'O' || a > n || b > n || c > n)
	    {
		    x = 0;
	    }
	    while(x==0)
	    {
		    printf("Lo lamento, digite una nueva posicion: \n");
		    scanf("%d %d %d", &a, &b, &c);
		    if(matrix[a][b][c] != 'X' && matrix[a][b][c] != 'O')
		    {
			    x = 1;
		    }
	    }	
		matrix[a][b][c] = (char) o;
		printf("%c \n", matrix[0][0][0]);
		printf("%c \n", matrix[1][0][0]);
		printf("%c \n", matrix[1][1][0]);
		printf("%c \n", matrix[2][0][0]);
		print(matrix,n);
		v = check(matrix,filas,n,v);
		if(v == 0)
		{
			printf("Winner \n");
		}
		else
		{
			c2 = checker(matrix,filas,c,c2,n);
			if(c2==2*(n+1)+2)
			{
				printf("Han empate \n");
			}
		    else
		    {
		        printf("Player 2 digite la posicion de la X: \n");
		        scanf("%d %d %d", &a, &b, &c);
		        if(matrix[a][b][c] == 'X' || matrix[a][b][c] == 'O' || a > n || b > n || c > n)
	            {
		            x = 0;
	            }
	            while(x==0)
	            {
		            printf("Lo siento, digite la nueva posicion: \n");
		            scanf("%d %d %d", &a, &b, &c);
		            if(matrix[a][b][c] != 'X' && matrix[a][b][c] != 'O')
		            {
		    	        x = 1;
		            }
	            }		
		        matrix[a][b][c] = (char) y;
		        print(matrix,n);
		        v = check(matrix,filas,n,v);
		        if(v == 0)
        		{
        			printf("Winner");
        		}
        		else
        		{
        			c2 = checker(matrix,filas,c,c2,n);			
        			if(c2==2*(n+1)+2)
        			{
        				printf("Han empatado");
        			}
        	    }
		    }
		}
	}

}
