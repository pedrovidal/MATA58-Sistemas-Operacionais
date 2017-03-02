#include <bits/stdc++.h>
#include "processinho.hpp"
#include "fifo.hpp"
using namespace std;

void fifo(processo * vet, int numeroDeProcessos) {
	cout << "FIRST IN FIRST OUT" << endl;
	int tempo=vet[0].chegada;
	float turnaround=0;
	string res;
	for (int j=0; j<tempo; j++)
		res+="_";
	for (int i=0; i<numeroDeProcessos; i++){
		for (int j=0; j<vet[i].duracao; j++)
			res+="|";
		for (int j=0; j<res.size(); j++)
			if (i>0 && j==vet[i].chegada && res[j]=='_') res[j]='*';
		cout << char(i+'A') << ": " << res << endl;
		vet[i].tempo=res.size()-vet[i].chegada;
		tempo=vet[i].tempo;
		turnaround+=tempo;
		for (int j=0; j<res.size(); j++)
			res[j]='_';
	}
	for (int i=0; i<numeroDeProcessos; i++)
		cout << "Tempo de espera de " << vet[i].nome << " " << vet[i].tempo << endl;
	cout << "Turnaround medio " << turnaround/numeroDeProcessos << endl;
	cout << endl;
}
