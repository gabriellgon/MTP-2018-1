//Gabriel Carneiro Gonçalves
//11611ECP013

#include <stdio.h>

void soma ( )
{
	int vet[20]={0}, quant, i=0, j=0, soma=0;
	
	printf("Digite quantos numeros deseja informar: ");
	scanf("%i",&quant);
	getchar( );
	printf("\nDigite os numeros que deseja informar: ");
	for(i=0;i<quant;i++)
	{
		scanf("%i",&vet[i]);
		getchar( );
	}

	for(j=0;j<quant;j++)
	{
		soma=soma+vet[j];
	}
	divide(soma,quant);
}

int divide(int soma, int quanti)
{
	float media;
	
	media=(float)soma/(float)quanti;
	printf("\nA media dos numeros informados e: %.2f",media);
	
	return 0;
}

int main ( )
{
	soma( );

	return 0;
}
