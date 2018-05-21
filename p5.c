//Gabriel Carneiro Gonçalves
//11611ECP013


#include<stdio.h>

void codifica()
{
	char str[256]={'\0'};
	int *ps, i=0;
	
	printf("\nDigite uma mensagem: ");
	gets(str);
	char *pmsg=str;
	printf("Codificada: ");
	for(i=0;str[i];i++)
	{
		ps=(int *)pmsg;
		if(ps[i]!=0)
			printf("%d",ps[i]);
		if(ps[i+1]!=0)
			printf(", ");
	}
}

void decodifica()
{
	char *p;
	int q[64], i=0;
	printf("\nColoque espaco + 0 quando finalizar a entrada de dados!");
	printf("\nDigite uma mensagem para decodificar: ");
	
	for(i=0;i<64;i++)
	{
		scanf("%d",&q[i]);
		getchar();
		p=(char *)q;
		if(q[i]==0)
		break;
	}
	printf("decodificado: ");
	printf("%s",p);
}
 
void menu()
{
	int op,saida=0;
	


	printf("\tMENU\n\n");
    printf("\t1. Codificar\n");
	printf("\t2. Decodificar\n");
	printf("\t3. Sair.");

	do
	{

	    inicio:
		printf ("\n\nDigite sua opcao: ");
		scanf("%d",&op);
		getchar();	
		switch(op)
		{
			case 1:
				codifica();
				saida=1;
				break;
				
			case 2:
				decodifica();
				saida=2;
				break;
				
			case 3:
				printf("\nObrigado!\n");
				saida=3;
				break;	
				
			default: 
			printf("Opcao invalida!");
				goto inicio;				
				
		}
	}while(saida!=3);
}

int main( )
{
	menu();
	return 0;
}
