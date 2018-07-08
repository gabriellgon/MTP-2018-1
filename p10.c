//Gabriel Carneiro Gonçalves
//11611ECP013

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NCHAR_NOME 64

typedef struct Dimensoes{
    float largura;
    float profundidade;
    float altura;
}Dimensoes;

typedef struct Produto{
    char nome[NCHAR_NOME];
    float preco;
    struct Dimensoes d;
}Produto;

void cadastrar(Produto **p, int n_produtos);
void consultar(Produto *p, int codigo);
void carregar(Produto **p, int *NProd);
void salvar(Produto *p, int NProd);
int sizeofFile(char nomearquivo[NCHAR_NOME]);

int main(void)
{
    Dimensoes d; 
    Produto* p = NULL; 

    int opc, codigo, nprodutos=0, sof;
    char nomearquivo[NCHAR_NOME];

    FILE *arquivo, *leitura;
    arquivo = fopen("produtos.dat","wb");
    if(arquivo==NULL){
        printf("Problemas ao criar arquivo\n");
        return 0;
    }


   do{
        printf("\n---------- MENU -----------\n\n\n");
        printf("Produtos em memoria: %d", nprodutos);
        printf("\n1- Consultar produtos \n");
        printf("2- Cadastrar novo produto \n");
        printf("3- Carregar arquivo para memoria \n");
        printf("4- Salvar memoria em arquivo \n");
        printf("0- Encerrar \n");
        printf("Escolha sua opc: ");
        scanf("%d",&opc);
        getchar();

        switch(opc){
        case 1:
            printf("\nProdutos em memoria: %d\n\n",nprodutos);
            

            if(nprodutos > 0) {
                printf("\n0- Voltar");
                int i;
                for(i=0;i<nprodutos;i++) {
                    printf("\n%d %s", i+1, p[i].nome);
                }
                printf("\nEscolha sua opc: ");
                scanf("%d",&codigo);
                getchar();

                consultar(p,codigo-1);
            } else {
                printf("Pressione qualquer tecla para voltar ...");
                getchar();
            }           
                
            break;

        case 2:
            cadastrar(&p,nprodutos);
            nprodutos++;
            break;
        case 3:

            carregar(&p , &nprodutos);
            break;
        case 4:

            salvar(p, nprodutos);
            break;
        case 0:
            exit(1);
            break;
        }
    } while(opc!=0);

    free(p);
}

void cadastrar(Produto **p, int n_produtos){

    Produto p_novo;

    printf("Nome do produto: ");
    fflush(stdin);
    fgets(p_novo.nome, 64, stdin);
    p_novo.nome[strlen(p_novo.nome)-1] = '\0';

    printf("Preco do produto: ");
    scanf("%f", &p_novo.preco);

    printf("Dimensoes do produto\n");
    printf("Largura: ");
    scanf("%f", &p_novo.d.largura);

    printf("Profundidade: ");
    scanf("%f", &p_novo.d.profundidade);

    printf("Altura: ");
    scanf("%f", &p_novo.d.altura);

    *p = (Produto *) realloc(*p, (n_produtos + 1) * sizeof(Produto) );

    (*p)[n_produtos] = p_novo;
    
    printf("Produto cadastrado com sucesso! \n");

}

void consultar(Produto *p, int codigo){
    printf("%s, R$ %.3f, L: %.3fm, x P: %.3fm x A: %.3fm", p[codigo].nome,p[codigo].preco, p[codigo].d.largura, p[codigo].d.profundidade, p[codigo].d.altura);
}

void carregar(Produto **p, int *NProd) {
    char nomearquivo[NCHAR_NOME];
    FILE *arquivo;
    printf("Digite o nome do arquivo para carregar :\n");
    scanf("%s", nomearquivo);
    int sof = sizeofFile(nomearquivo);
    if (sof > 0) {
        arquivo = fopen(nomearquivo, "rb");
        *NProd = sof/sizeof(Produto);
        printf("Arquivo contem %d produto(s).\n", *NProd);
        *p = (Produto *) realloc(*p, sizeof(Produto)*(*NProd));
        if(*p)
            fread(*p, sizeof(Produto), *NProd, arquivo);
        else {
            fprintf(stderr, ">>> Problema de realocacao da memoria!\n");
            *NProd = 0;
        }
        fclose(arquivo);
    } else
        fprintf(stderr, ">>> Carregamento nao efetuado!\n");
}

void salvar(Produto *p, int NProd) {
    char nomearquivo[NCHAR_NOME];
    FILE *arquivo;
    printf("Digite o nome do arquivo para salvar (sera sobrescrito caso exista):\n");
    scanf("%s", nomearquivo);
    int sof = sizeofFile(nomearquivo);
    if(arquivo = fopen(nomearquivo, "wb")) {
        fwrite(p, sizeof(Produto), NProd, arquivo);
        fclose(arquivo);
    } else
        fprintf(stderr, ">>> Salvamento nao efetuado!\n");
}

int sizeofFile(char nomearquivo[NCHAR_NOME]) {
    int sof = 0;
    FILE* arquivo = fopen(nomearquivo, "rb");
    if (arquivo) {
        fseek(arquivo, 0, SEEK_END);
        sof = ftell(arquivo);
        fclose(arquivo);
    } else {
        fprintf(stderr, ">>> Arquivo nao encontrado!\n");
        sof = -1;
    }
    return sof;
}
