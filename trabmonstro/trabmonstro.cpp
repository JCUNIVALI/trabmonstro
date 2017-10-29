#include "stdafx.h"
#include <iostream>
#include <time.h>
#define TAMANHOMATRIZ 5
using namespace std;


void MoveMonstro(int MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ], int LinhaMonstro, int ColunaMonstro, int LinhaPersonagem, int ColunaPersonagem, int aux) {
	if (LinhaMonstro > LinhaPersonagem) {
		if (aux == 0) {
			MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
			LinhaMonstro--;
			MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
		}
		else {
			MatrizMonstro[LinhaPersonagem][ColunaPersonagem] = 0;
			LinhaPersonagem++;
			MatrizMonstro[LinhaPersonagem][ColunaPersonagem] = 1;
		}
	}
	if (ColunaMonstro < ColunaPersonagem) {
		if (aux == 0) {
			MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
			ColunaMonstro++;
			MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
		}
		else {
			MatrizMonstro[LinhaPersonagem][ColunaPersonagem] = 0;
			ColunaMonstro--;
			MatrizMonstro[LinhaPersonagem][ColunaPersonagem] = 1;
		}
	}
	if (aux == 0) {
		MoveMonstro(MatrizMonstro, LinhaPersonagem, ColunaPersonagem, LinhaMonstro, ColunaMonstro, aux++);
	}
}
int main(){
	int MatrizPesonagem[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 };
	MatrizPesonagem[2][2] = 1;
	MatrizMonstro[0][1] = 1;
	MatrizMonstro[3][4] = 1;
	MatrizMonstro[4][0] = 1;
	MatrizMonstro[4][2] = 1;
	MoveMonstro(MatrizMonstro, 4, 0, 2, 2, 0);
	for (int linha = 0; linha < TAMANHOMATRIZ; linha++) {
		for (int coluna = 0; coluna < TAMANHOMATRIZ; coluna++) {
			cout << MatrizMonstro[linha][coluna] << "\t";
	}
		cout<< endl;
	}
	system("pause");
    return 0;
}