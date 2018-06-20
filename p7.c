//Gabriel Carneiro Gonçalves
//11611ECP013


#include <stdio.h>


int A(int m, int n)
{
	if(m == 0)
		return n + 1;
	
	if( m > 0 && n == 0)
		return A(m - 1, 1);
		
	if(m > 0 && n > 0)
		return A(m - 1, A(m, n - 1));
	
}

int main()
{
	int m, n;
	
	printf("\t\t## Funcao de Ackermann ##\n\n");
	printf("Entre com dois valores 'm' e 'n' respectivamente:");
	scanf("%d %d", &m,&n);
	getchar();
	
	printf("\t%d",A(m,n));

    return 0;
}
