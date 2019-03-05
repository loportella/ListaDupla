#include <stdio.h>
#include <stdlib.h>
#include "ld.h"
struct lista{
	int elemento;
	struct lista *ant;
	struct lista *prox;
};
lst *cria(){
	return NULL;
}
int vazia(lst *l){
	if(l==NULL) return 0;
	else if(l->prox==NULL)return 1;
	else return 2;
}
int tamanho(lst *l){
	int t=0;lst *p=NULL;
	if(vazia(l)==0)return 0;
	else if(vazia(l)==1)return 1;
	else{
	for(p=l;p!=NULL;p=p->prox){
		t++;
	}return t;}
}
void valor(lst *l){
	if(vazia(l)==0){
		printf("Lista vazia\n");return ;
	}int p=1,val,i=0;
	printf("Valor para procurar: ");scanf("%d",&val);
	while(l!=NULL){
		if(l->elemento==val){
			printf("%d esta na posição %d\n",val,p);i++;
		}
		l=l->prox;p++;
	}if(i==0)printf("Valor nao foi encontrado");
}
lst *insere(lst* l,int p){
	if(p<=0){
		printf("Posicao indisponivel\n");return l;
	}
	lst *no=(lst*)malloc(sizeof(lst));
	int val;
	printf("Valor: ");scanf("%d",&val);
	if(p==1||vazia(l)==0){
		if(vazia(l)==0){
			no->elemento=val;
			no->prox=NULL;
			no->ant=NULL;
			if(p>1)printf("Valor colocado na posicao 1");
			return no;
		}else{
			no->elemento=val;
			no->prox=l;
			no->ant=NULL;
			return no;
		}
	}else if(p>tamanho(l)){
		lst *a=l;
		no->elemento=val;
		no->prox=NULL;
		while(a->prox!=NULL){
			a=a->prox;
		}a->prox=no;
		no->ant=a;
		printf("Esse elemento foi inserido na %d posicao\n",tamanho(l));
		return l;
	}else{
		lst *a=l,*b;int c=0;
		while(p-1!=c){
			b=a;
			a=a->prox;c++;
		}no->elemento=val;
		no->prox=b->prox;
		no->ant=b;
		b->prox=no;
		a->ant=no;
		return l;
	}
}
void pr(lst *l){
	lst *p;
	for(p=l;p!=NULL;p=p->prox){
		printf("%d\t",p->elemento);
	}
}
lst *remov(lst *l,int p){
	if(vazia(l)==0){
		printf("Nao ha dados\n");return l;
	}else if(p>tamanho(l)||p<=0){
		printf("Posicao indisponivel\n");return l;
	}else{
		lst *a=l,*b;int c=1;
		while(p-1!=c){
			b=a;
			a=a->prox;
			c++;
		}if(p==1){
			if(vazia(l)==1){
				return NULL;
			}
			l=l->prox;
			l->ant=NULL;
			return l;
		}else if(a->prox->prox==NULL){
			a->prox=NULL;
			return l;
		}else{
			printf("aqui");
			a->prox=a->prox->prox;
			return l;
		}
	}
}
