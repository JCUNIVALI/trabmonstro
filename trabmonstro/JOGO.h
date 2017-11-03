#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#define TAMANHOMATRIZ 5

using namespace std;


bool contadordemovimento(int MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ], int Linha, int Coluna, int contador, int &contadorexterno, int xperson, int yperson, bool move, int &validamove) {
	if (Linha == xperson && Coluna == yperson) {
		if (contadorexterno == 0) {
			contadorexterno = contador;
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			return false;
		}
		if (contador<contadorexterno) {
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
		else {
			contador--;
			MatrizMonstro[Linha][Coluna] = 0;
			return false;
		}

	}
	if (Linha<TAMANHOMATRIZ - 1) {
		if (MatrizMonstro[Linha + 1][Coluna] == 0) {
			Linha++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha--;
				MatrizMonstro[Linha][Coluna] = 0;
				return false;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha--;
			}
		}
	}
	if (Linha<TAMANHOMATRIZ - 1 && Coluna<TAMANHOMATRIZ - 1) {
		if (MatrizMonstro[Linha + 1][Coluna + 1] == 0) {
			Linha++;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha--;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha--;
				Coluna--;
			}
		}
	}
	if (Linha<TAMANHOMATRIZ - 1 && Coluna>0) {
		if (MatrizMonstro[Linha + 1][Coluna - 1] == 0) {
			Linha++;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha--;
				Coluna++;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha--;
				Coluna++;
			}
		}
	}
	if (Coluna<TAMANHOMATRIZ - 1) {
		if (MatrizMonstro[Linha][Coluna + 1] == 0) {
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Coluna--;
			}
		}
	}
	if (Coluna>0) {
		if (MatrizMonstro[Linha][Coluna - 1] == 0) {
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Coluna++;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Coluna++;
			}
		}
	}
	if (Linha>0) {
		if (MatrizMonstro[Linha - 1][Coluna] == 0) {
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
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha++;
			}
		}
	}
	if (Linha>0 && Coluna<TAMANHOMATRIZ - 1) {
		if (MatrizMonstro[Linha - 1][Coluna + 1] == 0) {
			Linha--;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				contador--;
				Linha++;
				Coluna--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha++;
				Coluna--;
			}
		}
	}
	if (Linha>0 && Coluna>0) {
		if (MatrizMonstro[Linha - 1][Coluna - 1] == 0) {
			Linha--;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove);
			if (validamove == 1 && contador == 1) {
				Linha--;
				Coluna--;
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				return true;
			}
			else {
				contador--;
				MatrizMonstro[Linha][Coluna] = 0;
				Linha++;
				Coluna++;
			}
		}
	}
	else {
		contador--;
		return false;
	}
	return false;
}
struct OPONENTE {
	MONSTRO monstros[2];
	int linha;
	int coluna;
};
struct MONSTRO {
	int vida;
	ATAQUE ataque[4];
};
struct ATAQUE {
	bool rapido;
	int dano;
};
void geramonstro() {
	ATAQUE aa, q, w, e;
	aa.dano = 100;
	aa.rapido = true;
	q.dano = 100;
	q.rapido = false;
	w.dano = 100;
	w.rapido = false;
	e.dano = 100;
	e.rapido = false;
	MONSTRO arauto, arungueijo, krugueanciao, krugue, lobomaior, lobo, baron, sapo;
	arauto.vida = 10000;
	arungueijo.vida = 500;
	krugueanciao.vida = 1200;
	krugue.vida = 500;
	lobomaior.vida = 800;
	lobo.vida = 600;
	baron.vida = 25000;
	sapo.vida = 700;
	OPONENTE Arauto, Pedras, Lobos, Baron;
	Arauto.linha = 0;
	Arauto.coluna = 1;
	Arauto.monstros[0] = arauto;
	Arauto.monstros[1] = arungueijo;
	Pedras.linha = 3;
	Pedras.coluna = 4;
	Pedras.monstros[0] = krugueanciao;
	Pedras.monstros[1] = krugue;
	Lobos.linha = 4;
	Lobos.coluna = 0;
	Lobos.monstros[0] = lobomaior;
	Lobos.monstros[1] = lobo;
	Baron.linha = 4;
	Baron.coluna = 2;
	Baron.monstros[0] = baron;
	Baron.monstros[1] = sapo;
	
	



}
void jogo() {
	int MatrizPesonagem[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, contadorexterno = 0, validamove = 0;
	MatrizPesonagem[2][2] = 1;
	MatrizMonstro[0][1] = 1;
	MatrizMonstro[3][4] = 1;
	MatrizMonstro[4][0] = 1;
	MatrizMonstro[4][2] = 1;

	for (int linha = 0; linha < TAMANHOMATRIZ; linha++) {
		for (int coluna = 0; coluna < TAMANHOMATRIZ; coluna++) {
			if (linha == 2 && coluna == 2) {
				cout << 'X' << "\t";
			}
			else {
				cout << MatrizMonstro[linha][coluna] << "\t";
			}
		}
		cout << endl;
	}
	contadordemovimento(MatrizMonstro, 4, 0, 0, contadorexterno, 2, 2, false, validamove);
	cout << endl << contadorexterno << endl << endl;
	contadordemovimento(MatrizMonstro, 4, 0, 0, contadorexterno, 2, 2, true, validamove);
	for (int linha = 0; linha < TAMANHOMATRIZ; linha++) {
		for (int coluna = 0; coluna < TAMANHOMATRIZ; coluna++) {
			if (linha == 2 && coluna == 2) {
				cout << 'X' << "\t";
			}
			else {
				cout << MatrizMonstro[linha][coluna] << "\t";
			}
		}
		cout << endl;
	}
	system("pause");
	geramonstro();



}







#endif