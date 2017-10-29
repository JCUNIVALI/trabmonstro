// trabmonstro.cpp: Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include <iostream>
#define TAMANHOMATRIZ 5
using namespace std;


void movemostro(int MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ], int LinhaMonstro, int ColunaMonstro, int LinhaPersonagem, int ColunaPersonagem) {
	if(LinhaMonstro<LinhaPersonagem && ColunaMonstro == ColunaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		LinhaMonstro++;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
	if(ColunaMonstro<ColunaPersonagem && LinhaMonstro == LinhaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		ColunaMonstro++;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
	if(LinhaMonstro>LinhaPersonagem && ColunaMonstro == ColunaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		LinhaMonstro--;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
	if(ColunaMonstro>ColunaPersonagem && LinhaMonstro == LinhaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		ColunaMonstro--;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
	if(LinhaMonstro<LinhaPersonagem && ColunaMonstro<ColunaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		LinhaMonstro++;
		ColunaMonstro++;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
	if(LinhaMonstro>LinhaPersonagem && ColunaMonstro<ColunaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		LinhaMonstro--;
		ColunaMonstro++;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
	if(LinhaMonstro<LinhaPersonagem && ColunaMonstro>ColunaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		LinhaMonstro++;
		ColunaMonstro--;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
	if(LinhaMonstro>LinhaPersonagem && ColunaMonstro>ColunaPersonagem) {
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 0;
		LinhaMonstro--;
		ColunaMonstro--;
		MatrizMonstro[LinhaMonstro][ColunaMonstro] = 1;
	}
}
int main()
{
	int MatrizPesonagem[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 };
	MatrizPesonagem[2][2] = 1;
	MatrizMonstro[0][1] = 1;
	MatrizMonstro[3][4] = 1;
	MatrizMonstro[4][0] = 1;
	MatrizMonstro[4][2] = 1;

    return 0;
}

