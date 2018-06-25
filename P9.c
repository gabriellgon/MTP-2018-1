//Gabriel Carneiro Gonçalves
//11611ECP013

#include <stdio.h>
#include <string.h>
#define ESTOQUE_MAX 100

int n=0;

struct Dimensoes
{
	float largura;
	float profundidade;
	float altura;
};

struct Produto
{
	char nome [63];
	float preco;
	float dimensoes;
	struct Dimensoes end;	
};

struct Produto produtos[ESTOQUE_MAX];

void preencher (void)
{
	int i;

	printf("\nDigite quantos produtos deseja cadastrar: ");
	scanf("%d",&n);

	for( i = 0;  i < n ; i++ )
	{
		printf("\nNome: ");
		scanf("%s", produtos[i].nome);
		getchar();
		printf("Preco: ");
		scanf("%f",&produtos[i].preco);
		getchar();
		printf("Dimensoes: ");
		scanf("%f",&produtos[i].dimensoes);
		getchar();
		printf("largura: ");
		scanf("%f",&produtos[i].end.largura);
		getchar();
		printf("Profundidade: ");
		scanf("%f",&produtos[i].end.profundidade);
		getchar();
		printf("Altura: ");
		scanf("%f", &produtos[i].end.altura);
		getchar();
	}
}

void mostrar(int n)
{
	int i;

	for (i = 0 ; i < n ; i++)
	{
		printf("\nNome: %s\n", produtos[i].nome);
		printf("Preco: %.2f\n", produtos[i].preco);
		printf("Dimensoes: %.2f\n", produtos[i].dimensoes);
		printf("Largura: %.2f\n", produtos[i].end.largura);
		printf("Profundidade: %.2f\n", produtos[i].end.profundidade);
		printf("Altura: %.2f\n", produtos[i].end.altura);
	}
}

void buscar()
{
	int i=0, j=0;
	char str[63];
	
	printf("\nDigite o nome do produto que deseja buscar:  ");
	getchar ();
	scanf("%[^\n]s",str);
	printf ("\n");
		
	while(1)
	{
		if (i == n)
		{
			printf ("\nProduto nao cadastrado.\n\n");
			break;		
		}
		if(strcmp(str,produtos[i].nome)!=0)
			i++;
	
		if (strcmp(str, produtos[i].nome) == 0)
		{
			printf("\nNome: %s\n", produtos[i].nome);
			printf("Preco: %.2f\n", produtos[i].preco);
			printf("Dimensoes: %.2f\n", produtos[i].dimensoes);
			printf("Largura: %.2f\n", produtos[i].end.largura);
			printf("Profundidade: %.2f\n", produtos[i].end.profundidade);
			printf("Altura: %.2f\n", produtos[i].end.altura);
			break;
		}
	}
}

int main()
{
	int a=0;
	struct Produto produtos;
	
	do
	{
		printf("\n\t [1] - Para cadastrar\n");
		printf("\t [2] - Mostar os produtos\n");
		printf("\t [3] - Buscar o produto\n");
		printf("\t [4] - Sair do programa\n");
		printf("\t Digite sua opcao: ");
		scanf("%d",&a);
		
		switch(a)
		{
			case 1:
				preencher();
				break;
			case 2:
				mostrar(n);
				break;
			case 3:
				buscar();
				break;
		}
		
	}while (a != 4);
	
	return 0;
}
