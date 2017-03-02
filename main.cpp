#include <bits/stdc++.h>
#include "processinho.hpp"
#include "fifo.hpp"
#include "sjf.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
    int numeroDeProcessos;
	cout << "Digite o numero de processos:\n";
	cin >> numeroDeProcessos;
	processo vet[numeroDeProcessos];
	for (int i=0; i<numeroDeProcessos; i++){
		cout << "Digite o tempo de chegada do processo: " << (char)(i+'A') << endl;
		cin >> vet[i].chegada;
		cout << "Digite a duracao do processo: " << (char)(i+'A') << endl;
		cin >> vet[i].duracao;
		vet[i].nome='A'+i;
		vet[i].exec = vet[i].nome;
		vet[i].exec += ": ";
	}
	sort(vet, vet+numeroDeProcessos, cmp);
	cout << endl;
    fifo(vet, numeroDeProcessos);
    sjf(vet, numeroDeProcessos);
    return 0;
}
