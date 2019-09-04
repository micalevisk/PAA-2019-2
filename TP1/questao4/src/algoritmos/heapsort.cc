//
//	[heapsort.cc]
//	Created by Micael Levi on 04/10/2017
//	Copyright (c) 2017 mllc@icomp.ufam.edu.br; All rights reserved.
//


///// dependencies
#include "ordenacaoAnalytics.hpp"
using namespace std;


void heapify(int* v, unsigned long pai, int posUltimo, Analytics& analise){
	unsigned long esq, dir, posMaior;
	esq = 2*pai + 1;
	dir = esq + 1;
	posMaior = pai;

	if((esq <= posUltimo) && (v[esq] > v[posMaior])){
		posMaior = esq;
		analise.incrementar_qtdComparacoes();
	}
	if((dir <= posUltimo) && (v[dir] > v[posMaior])){
		posMaior = dir;
		analise.incrementar_qtdComparacoes();
	}

	if(posMaior != pai){
		Extras::trocarElementos<int>(v[pai], v[posMaior]);
		analise.incrementar_qtdTrocas();
		heapify(v, posMaior, posUltimo, analise);
	}

}

void buildHeap(int* v, unsigned n, Analytics& analise){
	for(int i=(n-1)/2; i >= 0; --i)
		heapify(v, i, n-1, analise);
}


void heapsort(int* v, unsigned n, Analytics& analise){
	buildHeap(v, n, analise);
	for(int i=n-1; i > 0; ){
		Extras::trocarElementos<int>(v[i], v[0]);
		analise.incrementar_qtdTrocas();
		--i;
		heapify(v, 0, i, analise);
	}
}


Analytics OrdenacaoAnalytics::analytics_heapsort(){
	int* dadosLidos = readArray();

	Analytics analise = Analytics("heap", tamanho);
	analise.iniciarTempo();
	heapsort(dadosLidos, tamanho, analise);
	analise.pararTempo();

	#ifdef VERBOSE
		cout << "{depois do heap}: ";
		Extras::imprimirElementos(dadosLidos, tamanho);//resultado interno
	#endif
	#ifdef DEBUG
		vector<int> copiaDados(dadosLidos, dadosLidos + sizeof(dadosLidos)/sizeof(int));
		UnitTest::isSorted<int>(copiaDados);
	#endif

	delete[] dadosLidos;

	return analise;
}
