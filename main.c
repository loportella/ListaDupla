#include <stdio.h>
#include <stdlib.h>
#include "ld.h"
int main(int argc, char *argv[]) {
	lst *a=NULL;
	a=cria();
	int o,p;
	do{
		printf("\nMENU:\n1-Inserir\n2-Descobrir a posicao\n3-Remover\n4-Tamanho\n5-Mostrar dados \t");scanf("%d",&o);
		switch(o){
			case 1:
				if(vazia(a)==0)printf("So pode inserir na posicao 1\n");
				else printf("Voce tem %d posicoes ou >q/ vai ao fim\n",tamanho(a));
				printf("Inserir na posição: ");
				scanf("%d",&p);
			a=insere(a,p);break;
			case 2:valor(a);break;
			case 3: 
			printf("Remover da posição: ");
			scanf("%d",&p);
			a=remov(a,p);break;
			case 4:
				if(vazia(a)!=0)
				printf("Tem %d valores\n",tamanho(a));
				else printf("Nao ha dados\n");
			break;
			case 5: pr(a);break;
		}
	}while(o!=0);
	
	return 0;
}
