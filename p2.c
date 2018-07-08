#include<stdio.h>

void bin(unsigned int num)
{
	int nb, i;
	
	for(nb = 0; num >= (1 << nb); nb++){}	
	
	char bits1[nb];
	
	for(i=0; i<nb; i++){
		if(num%2==0)
			bits1[i]=0;
		else
			bits1[i]=1;	
		num=num/2;
	}
	
	for(i=nb-1; i>=0; i--)
		printf("%i", bits1[i]);
}

int main ()
{
	
	char bits[256], comando;
	int i=0;
	unsigned int num=0;
	
	printf("Conversao de Bases, digite: \n1. Binario para Decimal;\n2. Binario para Hexadecimal;\n3. Hexadecimal para Decimal;\n4. Hexadecimal para Binario;");
	printf("\n5. Decimal para Binario;\n6. Decimal para Hexadecimal;\n7. Octal para Decimal;\n8. Decimal para Octal.\n");
	scanf("%c", &comando);	getchar();
	
	switch(comando)
	{
		case '1':
			scanf("%s", bits); getchar();
			for(i=0; bits[i] != '\0'; i++)
				num = num*2 + (bits[i] - '0');	
			printf("%d", num);
			break;
		case '2':
			scanf("%s", bits); getchar();
			for(i=0; bits[i] != '\0'; i++)
				num = num*2 + (bits[i] - '0');	
			printf("%X", num);
			break;
		case '3':
			scanf("%X", &num); getchar();
			printf("%d", num);
			break;
		case '4':
			scanf("%X", &num); getchar();
			bin(num);
			break;
		case '5':
			scanf("%d", &num); getchar();
			bin(num);
			break;
		case '6':
			scanf("%d", &num); getchar();
			printf("%X", num);
			break;	
		case '7':
			scanf("%o", &num); getchar();
			printf("%d", num);
			break;
		case '8':
			scanf("%d", &num); getchar();
			printf("%o", num);
			break;
		default:
			printf("Opcao invalida");
	}

	return 0;
}
