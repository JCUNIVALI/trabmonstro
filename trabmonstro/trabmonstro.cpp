#include "stdafx.h"
#include <iostream>
#include <time.h>
#define TAMANHOMATRIZ 5
using namespace std;


bool contadordemovimento(int MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ], int Linha, int Coluna, int contador, int &contadorexterno, int xperson,int yperson, bool move, int &validamove) {
	if(Linha == xperson && Coluna == yperson) {
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
		if (contador == contadorexterno && move == true) {
			validamove = 1;
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			move = false;
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
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno,xperson,yperson,move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha--;
				MatrizMonstro[Linha][Coluna] = 0;
				return false;
			}
			if (validamove == 1 && contador == 0) {
				Linha--;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha--;
			}
		}
	}
	if(Linha<TAMANHOMATRIZ - 1 && Coluna<TAMANHOMATRIZ - 1) {
		if(MatrizMonstro[Linha + 1][Coluna + 1] == 0) {
			Linha++;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson,move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha--;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			if (validamove == 1 && contador == 0) {
				Linha--;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha--;
				Coluna--;
			}
		}
	}
	if(Linha<TAMANHOMATRIZ - 1 && Coluna>0) {
		if(MatrizMonstro[Linha + 1][Coluna - 1] == 0) {
			Linha++;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson,move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha--;
				Coluna++;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			if (validamove == 1 && contador == 0) {
				Linha--;
				Coluna++;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha--;
				Coluna++;
			}
		}
	}
	if(Coluna<TAMANHOMATRIZ - 1) {
		if(MatrizMonstro[Linha][Coluna + 1] == 0) {
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson,move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			if (validamove == 1 && contador == 0) {
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Coluna--;
			}
		}
	}
	if(Coluna>0) {
		if(MatrizMonstro[Linha][Coluna - 1] == 0) {
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson,move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Coluna++;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			if (validamove == 1 && contador == 0) {
				Coluna++;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Coluna++;
			}
		}
	}
	if(Linha>0) {
		if(MatrizMonstro[Linha - 1][Coluna] == 0) {
			Linha--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha++;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			if (validamove == 1 && contador == 0) {
				Linha++;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha++;
			}
		}
	}
	if(Linha>0 && Coluna<TAMANHOMATRIZ - 1) {
		if(MatrizMonstro[Linha - 1][Coluna + 1] == 0) {
			Linha--;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson,move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha++;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			if (validamove == 1 && contador == 0) {
				Linha++;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha++;
				Coluna--;
			}
		}
	}
	if(Linha>0 && Coluna>0) {
		if (MatrizMonstro[Linha - 1][Coluna - 1] == 0) {
			Linha--;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson,move, validamove);
			if (validamove == 1 && contador == 1) {
				Linha--;
				Coluna--;
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			if (validamove == 1 && contador == 0) {
				Linha++;
				Coluna++;
				MatrizMonstro[Linha][Coluna] = 0;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha++;
				Coluna++;
			}
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
	
	for (int linha = 0; linha < TAMANHOMATRIZ; linha++) {
		for (int coluna = 0; coluna < TAMANHOMATRIZ; coluna++) {
			cout << MatrizMonstro[linha][coluna] << "\t";
	}
		cout<< endl;
	}
	int validamove = 0;
	contadordemovimento(MatrizMonstro, 4, 0, 0, contadorexterno, 2, 2,false,validamove);
	cout << endl<<contadorexterno<<endl<<endl;
	contadordemovimento(MatrizMonstro, 4, 0, 0, contadorexterno, 2, 2,true,validamove);
	for (int linha = 0; linha < TAMANHOMATRIZ; linha++) {
		for (int coluna = 0; coluna < TAMANHOMATRIZ; coluna++) {
			cout << MatrizMonstro[linha][coluna] << "\t";
		}
		cout << endl;
	}

	system("pause");
    return 0;
}