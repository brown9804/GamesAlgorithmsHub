#include<funciones.h>

int main(int argc, char** argv)
{
	int z;
	int n;
	int p;
	printf("Digite la base del número que desea calcular su n-ésima potencia\n");
	scanf("%d",&z);
	printf("Digite el exponente de su potencia\n");
	scanf("%d",&n);
	p = pote(z, n);
	printf("La potencia es: %d\n", p);
	return 0;
}
