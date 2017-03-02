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
	processo * atual =  NULL;
	pair<multimap<int, processo>::iterator, multimap<int, processo>::iterator> srch;
	while (!chegada.empty() || !fila.empty() || atual != NULL) {
		srch = chegada.equal_range(time);
		for (multimap<int, processo>::iterator it = srch.first; it != srch.second; it++) {
			fila.push(&((*it).second));
			chegada.erase(it);
		}
		if (atual != NULL) {
			atual->tempo++;
			cout << atual->nome;
			if (atual->tempo == atual->duracao) {
				fim.insert(make_pair(atual->nome, time - atual->chegada + 1));
				atual = NULL;
			}
		}
		else if (!fila.empty()) {
			atual = fila.top();
			fila.pop();
			atual->tempo++;
			cout << atual->nome;
			if (atual->tempo == atual->duracao) {
				fim.insert(make_pair(atual->nome, time - atual->chegada + 1));
				atual = NULL;
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
