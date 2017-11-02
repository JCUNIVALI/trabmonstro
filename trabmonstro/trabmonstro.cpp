#include "stdafx.h"
#include <iostream>
#include <time.h>
#define TAMANHOMATRIZ 5
using namespace std;


bool contadordemovimento(int MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ], int Linha, int Coluna, int contador, int &contadorexterno) {
	if(Linha == 2 && Coluna == 2) {
		if(contadorexterno == 0) {
			contadorexterno = contador;
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			return false;
		}
		if(contador<contadorexterno) {
			contadorexterno = contador;
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			return false;
		}
		else{
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			return false;
		}

	}
	if(Linha<TAMANHOMATRIZ - 1) {
		if(MatrizMonstro[Linha + 1][Coluna] == 0) {
			Linha++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			Linha--;
		}
	}
	if(Linha<TAMANHOMATRIZ - 1 && Coluna<TAMANHOMATRIZ - 1) {
		if(MatrizMonstro[Linha + 1][Coluna + 1] == 0) {
			Linha++;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			Linha--;
			Coluna--;
		}
	}
	if(Linha<TAMANHOMATRIZ - 1 && Coluna>0) {
		if(MatrizMonstro[Linha + 1][Coluna - 1] == 0) {
			Linha++;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			Linha--;
			Coluna++;
		}
	}
	if(Coluna<TAMANHOMATRIZ - 1) {
		if(MatrizMonstro[Linha][Coluna + 1] == 0) {
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			Coluna--;
		}
	}
	if(Coluna>0) {
		if(MatrizMonstro[Linha][Coluna - 1] == 0) {
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			Coluna++;
		}
	}
	if(Linha>0) {
		if(MatrizMonstro[Linha - 1][Coluna] == 0) {
			Linha--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
				Linha++;
		}
	}
	if(Linha>0 && Coluna<TAMANHOMATRIZ - 1) {
		if(MatrizMonstro[Linha - 1][Coluna + 1] == 0) {
			Linha--;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			Linha++;
			Coluna--;
		}
	}
	if(Linha>0 && Coluna>0) {
		if (MatrizMonstro[Linha - 1][Coluna - 1] == 0) {
			Linha--;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno);
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			Linha++;
			Coluna++;
		}
	}
	else{
		contador--;
		return false;
	}
	return false;
}
int main(){
	int MatrizPesonagem[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, contadorexterno = 0;
	MatrizPesonagem[2][2] = 1;
	MatrizMonstro[0][1] = 1;
	MatrizMonstro[3][4] = 1;
	MatrizMonstro[4][0] = 1;
	MatrizMonstro[4][2] = 1;
	contadordemovimento(MatrizMonstro, 4, 0, 0, contadorexterno);
	for (int linha = 0; linha < TAMANHOMATRIZ; linha++) {
		for (int coluna = 0; coluna < TAMANHOMATRIZ; coluna++) {
			cout << MatrizMonstro[linha][coluna] << "\t";
	}
		cout<< endl;
	}
	cout << contadorexterno;
	system("pause");
    return 0;
}