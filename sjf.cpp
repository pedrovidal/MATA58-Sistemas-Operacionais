#include <bits/stdc++.h>
#include "processinho.h"
using namespace std;

bool cmp2(processo a, processo b){
	return a.duracao < b.duracao;
}

void sjf(processo * vet, int numeroDeProcessos){
	processo chegaram[numeroDeProcessos];
	int tempo=vet[0].chegada, cont=0, n=numeroDeProcessos;
	float turnaround=0;
	string res;
	for (int j=0; j<tempo; j++)
		res+="_";
	while(n){
		while(vet[cont].chegada<=tempo){
			chegaram[cont]=vet[cont];
			cont++;		
		}
		sort(chegaram, chegaram+cont, cmp2);
		cout << vet[numeroDeProcessos-n].nome;		
		for (int j=0; j<vet[numeroDeProcessos-n].duracao; j++)			
			res+="|";
		for (int j=0; j<res.size(); j++)
			if (numeroDeProcessos-n>0 && j==vet[numeroDeProcessos-n].chegada && res[j]=='_') res[j]='*';
		cout << ": " << res << endl;
		vet[numeroDeProcessos-n].tempo=res.size()-vet[numeroDeProcessos-n].chegada;
		tempo=vet[numeroDeProcessos-n].tempo;
		turnaround+=tempo;
		for (int j=0; j<res.size(); j++)
			res[j]='_';
		n--;	
	}
	for (int i=0; i<numeroDeProcessos; i++)
		cout << "Tempo de espera de " << vet[i].nome << " " << vet[i].tempo << endl;
	cout << "Turnaround medio " << turnaround/numeroDeProcessos << endl;
}
