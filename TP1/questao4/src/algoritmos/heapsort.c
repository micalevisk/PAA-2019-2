#include "algorithms.h"

/*
ALGORITMO PARA ORDENAÇÃO CRESCENTE O(nlogn) ou O(nlogn):
// COMPARAÇÕES  = 2*n*logn+2*n
-------------------------------------------------------------------------
______________
Rotina_Heapify
	Recebe:
	- um array 'vetor'
	- números 'pai' e 'posUltimo'

	eqs := 2 * pai + 1
	dir := esq + 1
	posMaior := pai

	Se esq < posUltimo, então
		Se vetor[esq] > vetor[pai], então
			posMaior := esq
		Se dir <= posUltimo e vetor[dir] > vetor[posMaior], então
			posMaior := dir
	Se posMaior != pai, então
		Swap(vetor[posMaior], vetor[pai])
		Rotina_Heapify(vetor, posMaior, posUltimo)

________________
Rotina_BuildHeap
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Para i de (N-1)/2 até 0, faça
		Rotina_Heapify(vetor, i, n-1)

_______________
Rotina_Heapsort
	Recebe:
	- um array 'vetor'
	- quantidade 'N' de elementos nesse array

	Rotina_BuildHeap(vetor, N)
	Para i de N-1 até 1, faça
		Swap(vetor[i], vetor[0])
		i := i - 1
		Rotina_Heapify(vetor, 0, i)
-------------------------------------------------------------------------
*/

	

void heapify(int64* v, uint64 pai, int64 posUltimo) {
	uint64 esq, dir, posMaior;
	esq = 2*pai + 1;
	dir = esq + 1;
	posMaior = pai;

	if ((esq <= posUltimo) && (v[esq] > v[posMaior])) {
		posMaior = esq;
	}
	if ((dir <= posUltimo) && (v[dir] > v[posMaior])) {
		posMaior = dir;
	}

	if (posMaior != pai) {
		swap(&v[pai], &v[posMaior]);
		heapify(v, posMaior, posUltimo);
	}

}

void buildHeap(int64* v, uint64 n) {
	for (int64 i=(n-1)/2; i >= 0; --i)
		heapify(v, i, n-1);
}


void heapsort(int64* v, uint64 n) {
	buildHeap(v, n);
	for (int64 i=n-1; i > 0; ){
		swap(&v[i], &v[0]);
		--i;
		heapify(v, 0, i);
	}
}


// Analytics OrdenacaoAnalytics::analytics_heapsort(){
// 	int* dadosLidos = readArray();

// 	Analytics analise = Analytics("heap", tamanho);
// 	analise.iniciarTempo();
// 	heapsort(dadosLidos, tamanho);
// 	analise.pararTempo();

// 	#ifdef VERBOSE
// 		cout << "{depois do heap}: ";
// 		Extras::imprimirElementos(dadosLidos, tamanho);//resultado interno
// 	#endif
// 	#ifdef DEBUG
// 		vector<int> copiaDados(dadosLidos, dadosLidos + sizeof(dadosLidos)/sizeof(int));
// 		UnitTest::isSorted<int>(copiaDados);
// 	#endif

// 	delete[] dadosLidos;

// 	return analise;
// }
