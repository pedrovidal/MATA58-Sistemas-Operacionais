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
	set<processo *> out, in, db;
	for (multimap<int, processo>::iterator it = chegada.begin(); it != chegada.end(); it++) {
			out.insert(&((*it).second));
			db.insert(&((*it).second));
	}
	pair<multimap<int, processo>::iterator, multimap<int, processo>::iterator> srch;
	while (!chegada.empty() || !fila.empty() || atual != NULL) {
		srch = chegada.equal_range(time);
		for (multimap<int, processo>::iterator it = srch.first; it != srch.second; it++) {
			in.insert(&((*it).second));
			fila.push(&((*it).second));
			chegada.erase(it);
		}
		if (atual != NULL) {
			atual->tempo++;
			atual->exec += "|";
			if (atual->tempo == atual->duracao) {
				fim.insert(make_pair(atual->nome, time - atual->chegada + 1));
				out.erase(atual);
				atual = NULL;
			}
		}
		else if (!fila.empty()) {
			atual = fila.top();
			fila.pop();
			atual->tempo++;
			atual->exec += "|";
			if (atual->tempo == atual->duracao) {
				fim.insert(make_pair(atual->nome, time - atual->chegada + 1));
				out.erase(atual);
				atual = NULL;
			}
		}
		for (processo * a : out)
			if (a != atual && in.find(a) == in.end())
				a->exec += '_';
		for (processo * a : in)
			if (a != atual)
				a->exec += '*';
		in.clear();
		time++;
	}
	
	int medio = 0;
	cout << "SHORTEST JOB FIRST" << endl;
	for (processo *a : db)
		cout << a->exec << endl;
	for (pair<char,int> x : fim) {
		cout << "Tempo de espera de " << x.first << ": " << x.second << endl;
		medio += x.second;
	}
	cout << "Turnaround time: " << (double) medio / (double) numeroDeProcessos << endl;
	cout << endl;
}
