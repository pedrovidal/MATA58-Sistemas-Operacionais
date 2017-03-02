#include <bits/stdc++.h>
#ifndef PROCESSINHO_H
#define PROCESSINHO_H
struct processo{
	int chegada, duracao, tempo;
	char nome;
	std::string exec;
};

bool cmp(processo a, processo b);
#endif
