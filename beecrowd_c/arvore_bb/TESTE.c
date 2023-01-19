#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //Biblioteca para usar strings
#include <stdbool.h> //biblioteca para usar Booleanos em C

typedef struct no{ //estrutura do nó, tendo elementos menores a esquerda e elementos maiores a direita
  char elem;       //valor do elemento que está na arvore
  struct no *esq; //ponteiro para a subarvore a esquerda(filho menor)
  struct no *dir; //ponteiro para a subarvore a direita(filho maior)
}noArvBB;          //nome dado para a estrutura de no da arvore usada

noArvBB *raiz = NULL; //raiz inicial da arvore é nula(arvore está vazia), mas o primeiro nó foi criado já

bool insereArvBB(char *valor){ 
  noArvBB *ant = NULL;       
  noArvBB *atual = raiz;      
  noArvBB *novo = (noArvBB *) malloc(sizeof(noArvBB));

  int auxant,auxatual,auxelem;

  novo->elem = valor; 
  novo->esq = NULL;   
  novo->dir = NULL;
  printf("VALOR DO NOVO: %s \n", &novo->elem);   

  while((atual != NULL) && (valor != atual->elem)){ 
    ant = atual;

    auxant=ant->elem;
    auxatual=atual->elem;
    auxelem=valor;

    if(auxelem <auxatual){ 
      atual = atual->esq;
    }
    else{ 
      atual = atual->dir;
    }
  }
  if(ant == NULL){ 
    raiz = novo;
  }
  else{
    if(atual == NULL){  

                           

      if(auxelem < auxant){
        ant->esq = novo;
      }
      else{               
        ant->dir = novo;
      }
    }
    else{
      return false; 
    }
  }
    printf("INSERIDO\n");
  return true;
}

bool buscaArvBB(char valor){ 
  noArvBB *atual = raiz;   //inicializa uma instancia na raiz para usar no começo da busca
  while((atual!= NULL) && (valor != atual-> elem)){ //fica em loop percorrendo a arvore
    if(valor < atual->esq){ //compara o valor se é menor para ir a esquerda
            atual = atual->esq;
  }
  else                      //se nao for para esquerda entao ele percorre para a direita
    atual = atual->dir;
}
if ((atual != NULL) && (valor == atual->elem)) //quando ele sai do loop da linha 65, compara para ver se achou o valor na posição atual
  return true;                                 //retorna TRUE se o valor foi achado
else
return false;                                 //retorna FALSE, caso em que foi prercorrido a arvore toda e nao foi achado o valor
}

void imprimePreOrdemArvBB(noArvBB *n){
  if(n != NULL){
    printf(" %s ", n->elem);
    imprimePreOrdemArvBB(n->esq);
    imprimePreOrdemArvBB(n->dir);
  }
}
void imprimeEmOrdemArvBB (noArvBB *n){
	if (n != NULL){
		imprimeEmOrdemArvBB(n->esq);
		printf(" %s ", n->elem);
		imprimeEmOrdemArvBB(n->dir);
	}
}
void imprimePosArvBB (noArvBB *n){
	if (n != NULL){
		imprimePosArvBB(n->esq);
		imprimePosArvBB(n->dir);
		printf(" %s ", n->elem);
	}
}

int main(int argc, char *argv[]){


    char op[7];
    while(op[0]!='E'&&op[1]!='O'&&op[2]!='F'){
    scanf(" %s", &op);
    if(op[0]=='I'&& op[3]!='I'){
            printf("testando\n");
        insereArvBB(op[2]);
        printf(" %s", &raiz->elem);
    
    }else if (op[1] == 'N'){
        printf("testando infixo\n");
        imprimeEmOrdemArvBB(raiz);
    }else if(op[0]=='P' && op[1]=='R'){
        printf("testando PREORDEM\n");
        imprimePreOrdemArvBB(raiz);
    }else if(op[0]=='P' && op[1]=='O'){
        printf("Testando POSORDEM\n");
        imprimePosArvBB(raiz);
    }else if(op[0]=='P'){
        printf("tetando busca\n");
        buscaArvBB(op[2]);
    }
    }

  return 0;
}
