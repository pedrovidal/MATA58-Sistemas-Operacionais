#include <bits/stdc++.h>
#include "processinho.hpp"
#include "edf.hpp"
using namespace std;

class Comparemos {
public:
	bool operator() (processo *a, processo *b){
		return a->deadline > b->deadline;
	}
};

void edf(processo * vet, int numeroDeProcessos){
	cout << "EARLIEST DEADLINE FIRST" << endl;
	multimap<int, processo> chegada;
	map<char,int> fim;
	priority_queue<processo *, std::vector<processo *>, Comparemos> fila, bkp;
	for (int i = 0; i < numeroDeProcessos; i++) {
		vet[i].tempo = 0;
		chegada.insert(make_pair(vet[i].chegada, vet[i]));
	}
	vector<processo *> db;
	for (multimap<int, processo>::iterator it = chegada.begin(); it != chegada.end(); it++) {
		db.push_back(&((*it).second));
	}
	int time = 0;
	pair<multimap<int, processo>::iterator, multimap<int, processo>::iterator> srch;
	while (!chegada.empty() || !fila.empty()) {
		srch = chegada.equal_range(time);
		for (multimap<int, processo>::iterator it = srch.first; it != srch.second; it++) {
			((*it).second).exec += "*";
			fila.push(&((*it).second));
			chegada.erase(it);
		}
		for (multimap<int, processo>::iterator it = chegada.begin(); it != chegada.end(); it++) {
			((*it).second).exec += "_";
		}
		if (!fila.empty()) {
			bkp.push(fila.top());
			fila.pop();
		}
		while (!fila.empty()) {
			fila.top()->exec += "_";
			bkp.push(fila.top());
			fila.pop();
		}
		while (!bkp.empty()) {
			fila.push(bkp.top());
			bkp.pop();
		}
		
		if (!fila.empty()) {
			fila.top()->tempo++;
			if (fila.top()->chegada == time)
				fila.top()->exec = fila.top()->exec.substr(0, fila.top()->exec.size() - 1);
			fila.top()->exec += "|";
			if (fila.top()->tempo == fila.top()->duracao) {
				fim.insert(make_pair(fila.top()->nome, time - fila.top()->chegada + 1));
				fila.pop();
			}
			else if (fila.top()->deadline == time) {
				fila.top()->exec += "X";
				fim.insert(make_pair(fila.top()->nome, 0));
				fila.pop();
			}
		}
		time++;
	}
	cout << endl;
	int medio = 0;
	for (processo *a : db)
		cout << a->exec << endl;
	for (pair<char,int> x : fim) {
		if (x.second == 0) {
			cout << "Tempo de espera de " << x.first << ": DEAD" << endl;
			numeroDeProcessos--;
		}
		else
			cout << "Tempo de espera de " << x.first << ": " << x.second << endl;
		medio += x.second;
	}
	cout << "Turnaround time: " << (double) medio / (double) numeroDeProcessos << endl;
}
