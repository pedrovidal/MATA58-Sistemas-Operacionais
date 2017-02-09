#ifndef PROCESSINHO_H
#define PROCESSINHO_H
struct processo{
	int chegada, duracao, tempo;
	char nome;
};

bool cmp(processo a, processo b);
#endif
