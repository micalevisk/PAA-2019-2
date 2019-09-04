// clear;gcc -o t *.c && ./t 1 2 3 4 5 6;rm t*

#include "heapDG.h"
#include <stdio.h>
#include <stdlib.h>


// (sinal da comparação) define se é heap de máxima ou mínima
#define SINAL >

#define TIPO int
#define IMPRESSAO		printf("\e[45m%d\e[m ", *aux)
#define COMPARACAO	(*aux1 SINAL *aux2)


void imprimir(void* elemento){
	TIPO* aux = elemento;
	if(elemento!=NULL) IMPRESSAO;
}


// A FUNÇÃO DE COMPARAÇÃO DEFINE O TIPO DE HEAP
// retorna = 0 se 'a' maior/menor que 'b' (de acordo com SINAL)
short comparacao(void* a, void* b){
	TIPO* aux1 = a;
	TIPO* aux2 = b;
	return COMPARACAO;
}


// ===================== [AUXILIARES] ==================== //

void imprimirVetorGenerico(void** v, unsigned tam){
	if(!v) printf("<vazio>\n");
	else{
		int i;
		for(i=0; i < tam; i++) imprimir(v[i]);
	}
	printf("\n");
}

void imprimirVetorGenerico2(void** v, unsigned tam){
	if(!v) printf("<vazio>\n");
	else{
		unsigned pai, esq, dir;
		for(pai=0; pai < tam; ++pai){
			esq = 2*pai+1;
			dir = esq+1;
			imprimir(v[pai]);
			if(esq < tam) imprimir(v[esq]);
			if(dir < tam) imprimir(v[dir]);
			printf("\n");
		}
	}
	printf("\n");
}

// ======================================================= //



int main(int argc, char* argv[]){
	if(argc < 1) return 1;

/*
	THeap* estrutura = criarHeap(comparacao);
	int i;
	for(i=1; i < argc; i++){
		TIPO* aux = malloc(sizeof(TIPO));
		*aux = atoi(argv[i]);

		estrutura->inserir(estrutura, aux);
	}
	percorrer(estrutura, imprimir);

	while( getchar()!=27 && (!estrutura->vazia(estrutura)) ){
		printf("\nRAIZ REMOVIDA: ");
		imprimir(estrutura->raiz(estrutura));
		estrutura->remover(estrutura);
		printf("\nNOVO VETOR: ");
		percorrer(estrutura, imprimir);
	}
*/


	unsigned tam = argc-1;
	int* v = calloc(tam, sizeof(int));
	int i;
	for(i=0; i < tam; i++) v[i] = atoi(argv[i+1]); // ler argumentos da linha de comando.
	void** vetor = malloc(sizeof(void*)*tam); // armazena os endereços dos elementos lidos.
	for(i=0; i < tam; i++) vetor[i] = &v[i];

	printf("\nVETOR LIDO:\n");
	imprimirVetorGenerico(vetor, tam);

	printf("\n\nAPÓS O MAX BUILD-HEAP: (pai filho_esq filho_dir)\n");
	transformarEmHeap(vetor, tam, comparacao);
	imprimirVetorGenerico2(vetor, tam);




	return 0;
}

/*
HEAP SORT O(nlog n):
1) Construir heap a partir da entrada => build_maxHeap(A, n)
2) Para i de n-1 até 1, Trocar(A[0], A[i]) & heapify_maxHeap(A, 0, i-1)
*/
