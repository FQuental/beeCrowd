#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct noArvBB{

	char elem;
	struct noArvBB *dir;
	struct noArvBB *esq;

} noArvBB;

noArvBB* novoNo(char valor)
{

	noArvBB *no = (noArvBB *) malloc(sizeof(noArvBB));
	no->elem = valor;
	no->esq = no->dir = NULL;

	return no;
}

int src(char *str, int inicio, int fim, char elem)
{

	short i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == elem)
			return i;

	return -1;

}

short indice;

noArvBB* tree(char *infixa, char *prefixa, int inInicio, int inFim){
	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	noArvBB *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(infixa, inInicio, inFim, no->elem);
	no->esq = tree(infixa, prefixa, inInicio, infixaIndice - 1);
	no->dir = tree(infixa, prefixa, infixaIndice + 1, inFim);
	return no;
}

void imprimePosArvBB (noArvBB *n){ //imprime em pos ordem
	if (n != NULL){
		imprimePosArvBB(n->esq);
		imprimePosArvBB(n->dir);
		printf("%c", n->elem);
	}
}


int main (){

	short quantCasos;
	short quantNos, i;
	char prefixa[MAX], infixa[MAX];

	scanf("%hu", &quantCasos);

	while (quantCasos--)
	{

		scanf("%hu %s %s%*c", &quantNos, prefixa, infixa);
		indice = 0;
		noArvBB *raiz = tree(infixa, prefixa, 0, quantNos - 1);
		imprimePosArvBB(raiz);
		printf("\n");
	}
return 0;
}