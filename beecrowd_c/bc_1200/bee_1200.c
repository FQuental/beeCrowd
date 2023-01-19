/*Marcela recebeu como trabalho de Algoritmos a tarefa de fazer um programa que implemente uma Árvore Binária de Pesquisa (ou Busca).
 O Programa deve aceitar os seguintes comandos:

I n: Insere na árvore binária de pesquisa o elemento n.
INFIXA: lista os elementos já cadastrado segundo o percurso infixo
PREFIXA: lista os elementos já cadastrado segundo o percurso prefixo
POSFIXA: lista os elementos já cadastrado segundo o percurso posfixo
P n: pesquisa se o elemento n existe ou não.
A qualquer momento pode-se inserir um elemento, visitar os elementos previamente inseridos na ordem infixa, 
prefixa ou posfixa ou ainda procurar por um elemento na árvore para saber se o elemento existe ou não.

Entrada
A entrada contém N operações utilizando letras (A-Z,a-z) sobre uma árvore binária de Busca,
 que inicialmente se encontra vazia. A primeira linha de entrada contém a inserção de algum elemento. 
 As demais linhas de entrada podem conter quaiquer um dos comandos descritos acima, conforme exemplo abaixo.
  O final da entrada é determinado pelo final de arquivo (EOF).

Obs: Considere que não serão inseridos elementos repetidos na árvore.

Saída
Cada linha de entrada, com exceção das linhas que contém o comando "I", 
deve produzir uma linha de saída. A saída deve ser de acordo com o exemplo fornecido abaixo. 
Não deve haver espaço em branco após o último caractere de cada linha, caso contrário, sua submissão receberá Presentation Error.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore
{
    int dado;
    struct Arvore *dir;
    struct Arvore *esq;
}arvore;

int flag=0;

arvore *reserva();
arvore *inserir(arvore *raiz, arvore *prox, char x);
void preOrdem(arvore *prox);
void  inOrdem(arvore *prox);
void posOrdem(arvore *prox);
arvore *busca(arvore *raiz, char x);

int main()
{
    arvore *raiz=NULL;

    char op[20];

    while(scanf("%[^\n]", op)!=EOF)
    {
        if(op[0]=='I' && op[2]!='F')
        {
            if(!raiz) raiz=inserir(raiz, raiz, op[2]);
                else inserir(raiz, raiz, op[2]);
        }
        if(op[0]=='I' && op[2]=='F')
        {
            flag=0; preOrdem(raiz); printf("\n");
        }
        if(op[0]=='P' && op[2]=='E')
        {
            flag=0; inOrdem(raiz); printf("\n");
        }
        if(op[0]=='P' && op[2]=='S')
        {
            flag=0; posOrdem(raiz); printf("\n");
        }
        if(op[0]=='P' && op[2]!='S' && op[2]!='E')
        {
            if(busca(raiz, op[2])==NULL) printf("%c nao existe\n", op[2]);
                else printf("%c existe\n", op[2]);
        }
        getchar();
    }

    return 0;
}

arvore *reserva()
{
    arvore *p=(arvore *)malloc(sizeof(arvore));
        if(!p){ printf("Nao tem memoria disponivel\n"); exit(0); }
    p->dir=p->esq=NULL; return p;
}

arvore *inserir(arvore *raiz, arvore *prox, char x)
{
    if(!prox)
    {
        prox=reserva(); prox->dado=x;
        if(!raiz) return prox;
        if(x<=raiz->dado) raiz->esq=prox;
            else raiz->dir=prox;
        return prox;
    }
    if(x<=prox->dado) inserir(prox, prox->esq, x);
        else inserir(prox, prox->dir, x);
}

void inOrdem(arvore *prox)
{
    if(!prox) return;
    if(flag==0){printf("%c", prox->dado); flag=1;}
        else printf(" %c", prox->dado);
    inOrdem(prox->esq); inOrdem(prox->dir);
}

void preOrdem(arvore *prox)
{
    if(!prox) return;
    preOrdem(prox->esq);
    if(flag==0){printf("%c", prox->dado); flag=1;}
        else printf(" %c", prox->dado);
    preOrdem(prox->dir);
}

void posOrdem(arvore *prox)
{
    if(!prox) return;
    posOrdem(prox->esq); posOrdem(prox->dir);
    if(flag==0){printf("%c", prox->dado); flag=1;}
        else printf(" %c", prox->dado);
}

arvore *busca(arvore *raiz, char x)
{
    if(raiz==NULL || raiz->dado==x) return raiz;
    if(raiz->dado>x) return busca(raiz->esq, x);
        else return busca(raiz->dir, x);
}