//Gabriel Carneiro Gonçalves
//11611ECP013



#include <stdio.h>
#define decimal 1
#define hexa 2


int clear(void){
}

int numBin(int);
int menu(void);
int decBin(void);
int hexBin(void);
int converter(void);
long long convertoct(void);
long long hexadecimal2decimal(void);
int decPhexa(void);


long long convertOctalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0;

    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }

    i = 1;

    return decimalNumber;
}
int convertDecimalToOctal(int decimalNumber)
{
    int octalNumber = 0, i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    return octalNumber;
}


int binNum(char bin[], int type){
    int i;
    int j;
    int num=0;
    for(i=0;i<8;i++){
        if(bin[i] == '1')
                num = (num*2)+1;
        if(bin[i] == '0')
                num = (num*2);
    }
    if(type==1) printf("Decimal: %d", num);
    if(type==2) printf("Hexadecimal: %x", num);
    
}


int numBin(int numero){
    int i;
    int result=numero;
    int bin[8];
    for(i=0;i<8;i++)
        bin[i]=0;
    for(i=0;result!=0;i++){
        bin[i]=result%2;
        result=(result - bin[i])/2;
    }
    printf("Binario: ");
    for(i=7;i>=0;i--)
        printf("%d", bin[i]);
}

int menu(void){
    char opcao[10];
    int op;
    printf("\n");
    printf("\t1. Binario para Decimal\n");
    printf("\t2. Binario para Hexadecimal\n");
    printf("\t3. Hexadecimal para Decimal\n");
    printf("\t4. Hexadecimal para Binario\n");
    printf("\t5. Decimal para Binario\n");
    printf("\t6. Decimal para Hexadecimal\n");
    printf("\t7. Octal para Decimal\n");
    printf("\t8. Decimal para Octal\n\n");
    printf("\t9. Sair\n\n");
    do{
        inicio:
        printf("\tDigite sua opcao: ");
        gets(opcao);
        op = atoi(opcao);
        switch(op){
        	    case 1:			binDecimal();
                                break;
                                
                case 2:			binHexa();
                                break;

                case 3:			hexadecimal2decimal();
                                break;
                case 4:
                                hexBin();
                                break;
                                
                case 5: 		decBin();  
                				break;
                		
                case 6:			decPhexa();
                				break;
                
                case 7: 		convertoct();
                				break;
                				
                case 8:			converter();
                				break;

                case 9:
                                exit(0);
                default:
                                printf("Opcao Invalida\n");
                                goto inicio;
        }
    }while(1);
}

int binDecimal(void){
    int i;
    char bin[8];
    char espera;
    clear();
    printf("Digite o numero binario: ");
    gets(bin);
    binNum(bin, decimal);
    fflush(stdin);
    espera = getchar();
    if(espera) menu();
}
int binHexa(void){
    int i;
    char bin[8];
    char espera;
    clear();
    printf("Digite o numero binario: ");
    gets(bin);
    binNum(bin, hexa);
    fflush(stdin);
    espera = getchar();
    if(espera) menu();
}
int decBin(void){
    int num;
    char espera;
    system("clear");
    printf("Digite o numero: ");
    scanf("%d", &num);
    numBin(num);
    fflush(stdin);
    espera = getchar();
    if(espera) menu();
}
int hexBin(void){
    int num;
    char espera;
    printf("Digite o numero: ");
    scanf("%x", &num);
    numBin(num);
    fflush(stdin);
    espera = getchar();
    if(espera) menu();
}
int converter(void){
    int decimalNumber;

    printf("Digite um numero decimal: ");
    scanf("%d", &decimalNumber);

    printf("%d <- seu numero = %d <-Em Octal", decimalNumber, convertDecimalToOctal(decimalNumber));

    return 0;
}
long long convertoct(void){
	int octalNumber;

    printf("Digite um numero octal: ");
    scanf("%d", &octalNumber);

    printf("%d <- seu numero = %lld <-Em decimal\n\n", octalNumber, convertOctalToDecimal(octalNumber));

    return 0;
}
long long hexadecimal2decimal () {
    int h; 
    printf ("\tEntre com um numero hexadecimal: ");
    scanf ("%X",&h);
    printf ("\tA conversao do numero %X em decimal e %d :\n",h,h); 
}



int decPhexa(void){
	int num;
	char numEmHexa[10];

	printf("Entre com um numero decimal: ");
	scanf("%d", &num);
	sprintf(numEmHexa, "%x", num);
	printf("Seu numero em Hexadecimal eh: %s\n", numEmHexa);
 
}




int main(){
    menu();
    return 0;
}
