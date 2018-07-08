//Gabriel Carneiro Gonçalves
//11611ECP013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Dimensao{
    float largura;
    float altura;
    float profundidade;
}
Dimensao;

typedef struct Produto{
    char nomePro[64];
    float preco;
    Dimensao dimensao;
}Produto;

void cadastra(Produto * p){

    printf("\nDigite o nome do produto: ");
    fgets(p->nomePro, 64, stdin);
    p->nomePro[strlen(p->nomePro)-1] = '\0';

    printf("\nDigite o preco: ");
    scanf("%f", &(p->preco));
    getchar();

    printf("\nDigite a largura: ");
    scanf("%f", &(p->dimensao.largura));
    getchar();

    printf("\nDigite a profundidade: ");
    scanf("%f", &(p->dimensao.profundidade));
    getchar();

    printf("\nDigite a altura: ");
    scanf("%f", &(p->dimensao.altura));
}

void consulta(Produto * p){
    char c;

    if(strlen(p->nomePro) == 0){
        printf("\nProduto nao cadastrado!\n");
        while((c=getchar()) != '\n');
        return;
    }

    printf("\n%s, R$ %.2f, L: %.2fm x P: %.2fm x A: %.2fm\n",
    p->nomePro, p->preco,(p->dimensao.largura),(p->dimensao.profundidade), (p->dimensao.altura));
    while((c=getchar())!='\n');
}

int main(){
    int flag=0, flag2;
    Produto * produtos = calloc(2, sizeof(Produto));
    char str[2][16] = {"Cadastro", "Consulta"};

    do{
       printf("\n1 - Cadastrar\n2 - Consulta\n3 - Sair\n-- ");
        scanf("%d", &flag);
        getchar();

        flag2 = 0;

        	if(flag==1){
        		printf("\nRealizar %s\n", str[flag-1]);
         		printf("\n1 - Produto 1\n2 - Produto 2\n3 - Voltar\n-- ");
   	     		scanf("%d", &flag2);
   	     		getchar();

   	     		switch(flag2){

                        case 1:
                            printf("\nProduto %d\n", flag2);
                            cadastra(&produtos[flag2-1]);
                          	break;

                        case 2:
                            printf("\nProduto %d\n", flag2);
                            cadastra(&produtos[flag2-1]);
                          	break;
                    		}

                    	}

			if(flag==2){
        		printf("\nRealizar %s\n", str[flag-1]);
         		printf("\n1 - Produto 1\n2 - Produto 2\n3 - Voltar\n-- ");
   	     		scanf("%d", &flag2);
   	     		getchar();

   	     		switch(flag2){

                        case 1:
                            printf("\nProduto %d\n", flag2);
                            consulta(&produtos[flag2-1]);
                          	break;

                        case 2:
                            printf("\nProduto %d\n", flag2);
                            consulta(&produtos[flag2-1]);
                          	break;
                    		}

						}
	}while(flag!=3);

	free(produtos);

    return 0;
}
