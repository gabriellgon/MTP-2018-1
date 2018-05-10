//Gabriel Carneiro Gonçalves
//11611ECP013


#include <stdio.h>

int main()
{
	int estado=0, i=0;
	char bits[256];
	
	printf("Entre com o numero binario para verificar se e multiplo de 3: ");
	scanf("%s",bits);
	
	while(bits[i]!='\0')
	{
		if(bits[i]=='0')
		{
			if(estado==0)
				estado=0;
			else
			{
				if(estado==1)
					estado=2;
				else
				{
					if(estado==2)
					estado=1;
				}
			}
		}
		
		if(bits[i]=='1')
		{
			if(estado==0)
				estado=1;
			else
			{
				if(estado==1)
					estado=0;
				else
				{
					if(estado==2)
					estado=2;
				}
					
			}
		}
		
		i++;
	}
	
	printf("%i\n",estado);
	if(estado==0)
		printf("%s e multiplo de 3",bits);
	if(estado!=0)
		printf("%s nao e multiplo de 3",bits);
	return 0;
}
