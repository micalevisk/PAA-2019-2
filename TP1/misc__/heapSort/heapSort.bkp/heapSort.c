//
//	[heapSort.c]
//	Created by Micael Levi on 08/18/2016
//	Copyright (c) 2016 mllc@icomp.ufam.edu.br; All rights reserved.
//


#include "heapSort.h"


#define SWAP(arr, a, b) \
{ \
  void* tmp = arr[a]; \
  arr[a] = arr[b]; \
  arr[b] = tmp; \
}


typedef struct dadosHeap{
	int ocupacao;
	unsigned tamanho;
	void** vetor;
}TDadosHeap;


/*================ FUNÇÕES AUXILIARES ==================*/

static void ajustarVetor(THeap* heap, unsigned novoTamanho){
	TDadosHeap* d = heap->dados;
	size_t bytes = sizeof(void*); // 4 bytes
	void** novoVetor = malloc(bytes*novoTamanho);

	memcpy(novoVetor, d->vetor, bytes*novoTamanho);
	d->tamanho = novoTamanho;

	free(d->vetor);
	d->vetor = novoVetor;
}



// Heapify:
// Garante a manutenção da propriedade ordem do Heap. O(log n)
void ajustarHeap(void** vetor, unsigned pai, int posUltimo, TComparacao comparar){
	unsigned esq, dir, posMaior;

	esq = 2*pai + 1;
	dir = esq + 1;
	posMaior = pai;
	if((esq <= posUltimo) && comparar(vetor[esq],vetor[posMaior]))	posMaior = esq;
	if((dir <= posUltimo) && comparar(vetor[dir],vetor[posMaior]))	posMaior = dir;

	if(posMaior != pai){
		SWAP(vetor, pai, posMaior);
		ajustarHeap(vetor, posMaior, posUltimo, comparar);
	}
}


// Build-Heap:
// Produz um heap a partir de um vetor não ordenado. O(n)
void transformarEmHeap(void** vetor, unsigned tamanho, TComparacao comparar){
	int i;
	for(i=(tamanho-1)/2; i >= 0; --i)
		ajustarHeap(vetor, i, tamanho-1, comparar);
}





/*================ IMPLEMENTAÇÃO DOS MÉTODOS ==================*/

static int _vazia(THeap* heap){ // retorna 1 se o vetor estiver "vazio".
	return !( ((TDadosHeap*)heap->dados)->ocupacao );
	;
}


static short _inserir(THeap* heap, void* elemento){
	TDadosHeap* d = heap->dados;
	int i = d->ocupacao, posAncestral;
	void *aux, *atual;

	if(i >= d->tamanho){
		unsigned novoTam = pow(2.0, floor(log2(i))+1);
		ajustarVetor(heap, novoTam);
	}

	d->vetor[i] = elemento;

	posAncestral = (i-1)/2;
	//atual > d->vetor[posAncestral]
	for(atual = elemento; (i>0) && (heap->comparar(atual, d->vetor[posAncestral])); ){
		aux											= d->vetor[posAncestral];
		d->vetor[posAncestral]	= atual;
		d->vetor[i]							= aux;
		i												= posAncestral;
		posAncestral = (i-1)/2;
	}
	d->ocupacao++;

	return 1;
}


static void* _raiz(THeap* heap){
	if(_vazia(heap)) return NULL;
	return ((TDadosHeap*)heap->dados)->vetor[0];
}


static void* _acessar(THeap* heap, unsigned pos){
	TDadosHeap* d = heap->dados;
	if(pos < d->ocupacao)	return d->vetor[pos];
	return NULL;
}


static void _remover(THeap* heap){
	TDadosHeap* d = heap->dados;
	void* raiz;
	int posUltimo = d->ocupacao - 1;
	void** vet = d->vetor;

	if(posUltimo >= 0){
		SWAP(vet, 0, posUltimo);
		// raiz 						= vet[0];
		// vet[0] 			  	= vet[posUltimo];
		// vet[posUltimo] 	= raiz;

		d->ocupacao--;
		posUltimo = d->ocupacao - 1;

		if(posUltimo > 0)
			ajustarHeap(vet, 0, posUltimo, heap->comparar);
	}
}

static unsigned _altura(THeap* heap){

}



/*================ IMPLEMENTAÇÃO DAS FUNÇÕES ==================*/

unsigned tamanho(THeap* heap){
	return ((TDadosHeap*)heap->dados)->tamanho;
	;
}


void percorrer(THeap* heap, void (*acao)(void*)){
	TDadosHeap* dados = heap->dados;
	if(_vazia(heap)) printf("<vazio>\n");
	else{
		int i, limite = dados->ocupacao;
		void** v = dados->vetor;
		for(i=0; i < limite; i++) acao(v[i]);
	}
	printf("\n");
}

TDadosHeap* criarDados(){
	TDadosHeap* dados = malloc(sizeof(TDadosHeap));

	dados->ocupacao	= 0;
	dados->tamanho  = 2;
	dados->vetor = malloc(sizeof(void*) * dados->tamanho);
	return dados;
}

THeap* criarHeap(short (*cmp)(void*,void*)){
	THeap* heap = malloc(sizeof(THeap));
	TDadosHeap* dados = criarDados();

	heap->dados 	= dados;
	heap->inserir = _inserir;
	heap->raiz	  = _raiz;
	heap->remover	= _remover;
	heap->acessar = _acessar;
	heap->vazia		= _vazia;
	heap->comparar= cmp;

	return heap;
}


void destruirHeap(THeap* heap){
	TDadosHeap* d = heap->dados;
	free(d->vetor);
	free(d);
	free(heap);
}


// ORDENAÇÃO POR HEAP: [INSTÁVEL]
// melhor: O(n logn) | pior: O(n logn)  
void heapSort(void** vetor, unsigned tamanho, TComparacao comparar){
	transformarEmHeap(vetor, tamanho, comparar); // build_heapMax
	unsigned i;
	for(i=tamanho-1; i > 0; ){
		SWAP(vetor, i, 0);
		ajustarHeap(vetor, 0, --i, comparar);
	}

}






// Manutenção HEAP MÁXIMO:
// Ordena parcialmente de forma que a raiz seja o maior valor da estrutura.
/*
 *	i 				<- posição do pai inicial = 0
 *	esq 			<- posição filho esquerdo(i) = 2i+1
 *	dir 			<- posição filho direito(i)  = 2i+2
 *	posUltimo <- ocupacao - 1
 *	posMaior	<- i
 *
 * Se esq <= posUltimo & V(esq) > V(pai), então posMaior <- esq
 * Se dir <= posUltimo & V(dir) > V(posMaior), então posMaior <- dir
 *
 * Se V(posMaior) for diferente de V(pai), então
 * 	TROCA(i, posMaior)
 * 	HEAP_MAXIMO(V, posMaior)
*/
