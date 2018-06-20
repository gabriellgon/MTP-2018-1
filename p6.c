//Gabriel Carneiro Gonçalves
//11611ECP013

#include <stdio.h>

void soma ( )
{
	int vet[20]={0}, quant, i=0, j=0, somar=0;
	
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
		somar=somar+vet[j];
	}
	divide(somar,quant);
}

int divide(int somar, int quanti)
{
	float media;
	
	media=(float)somar/(float)quanti;
	printf("\nA media dos numeros informados e: %.2f",media);
	
	return 0;
}

int main ( )
{
	soma( );

	return 0;
}
