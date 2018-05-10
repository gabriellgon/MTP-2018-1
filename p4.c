//Gabriel Carneiro Gonçalves
//11611ECP013


#include <stdio.h>

int main()
{
	int i=0, j=0;
	char vet[256], vet2[256]={48};
	

	scanf("%s",vet);
	
	while(vet[i]!='\0')
	{
		if(vet[i]>='0')
		{
			if(vet[i]<='9')
			{
				vet2[j]=vet[i];
				j++;
			}
		}
		i++;
	}
	
	printf("%s",vet2);

	return 0;
}
