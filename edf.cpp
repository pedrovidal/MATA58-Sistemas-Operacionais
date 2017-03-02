#include <bits/stdc++.h>
#include "processinho.hpp"
#include "sjf.hpp"
using namespace std;

class Compare {
public:
	bool operator() (processo *a, processo *b){
		return a->duracao > b->duracao;
	}
};

void sjf(processo * vet, int numeroDeProcessos){
	multimap<int, processo> chegada;
	map<char,int> fim;
	priority_queue<processo *, std::vector<processo *>, Compare> fila;
	for (int i = 0; i < numeroDeProcessos; i++) {
		vet[i].tempo = 0;
		chegada.insert(make_pair(vet[i].chegada, vet[i]));
	}
	int time = 0;
	pair<multimap<int, processo>::iterator, multimap<int, processo>::iterator> srch;
	while (!chegada.empty() || !fila.empty()) {
		srch = chegada.equal_range(time);
		for (multimap<int, processo>::iterator it = srch.first; it != srch.second; it++) {
			fila.push(&((*it).second));
			chegada.erase(it);
		}
		if (!fila.empty()) {
			fila.top()->tempo++;
			cout << fila.top()->nome;
			if (fila.top()->tempo == fila.top()->duracao) {
				fim.insert(make_pair(fila.top()->nome, time - fila.top()->chegada + 1));
				fila.pop();
			}
		}
		else {
			cout << '*';
		}
		time++;
	}
	cout << endl;
	int medio = 0;
	for (pair<char,int> x : fim) {
		cout << "Tempo de espera de " << x.first << ": " << x.second << endl;
		medio += x.second;
	}
	cout << "Turnaround time: " << (double) medio / (double) numeroDeProcessos << endl;
}
