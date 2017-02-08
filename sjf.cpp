#include <bits/stdc++.h>
using namespace std;

struct processo{
	int chegada, duracao, tempo;
	char nome;
};

bool cmp(processo a, processo b){
	if (a.chegada==b.chegada)
		return a.duracao < b.duracao;
	return a.chegada < b.chegada;
}

bool cmp2(processo a, processo b){
	return a.duracao < b.duracao;
}

int main(){
	int numeroDeProcessos;
	cout << "Digite o numero de processos:\n";
	cin >> numeroDeProcessos;
	processo vet[numeroDeProcessos], chegaram[numeroDeProcessos];
	for (int i=0; i<numeroDeProcessos; i++){
		cout << "Digite o tempo de chegada do processo " << (char)(i+'A') << endl;
		cin >> vet[i].chegada;
		cout << "Digite a duracao do processo " << (char)(i+'A') << endl;
		cin >> vet[i].duracao;
		vet[i].nome='A'+i;
	}
	sort(vet, vet+numeroDeProcessos, cmp);
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
