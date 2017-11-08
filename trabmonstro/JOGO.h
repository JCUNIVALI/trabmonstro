#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#include "conio.h"
#include <time.h>
#define TAMANHOMATRIZ 5

using namespace std;


bool contadordemovimento(int MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ], int Linha, int Coluna, int contador, int &contadorexterno, int xperson, int yperson, bool move, int &validamove,int &retornox,int &retornoy) {
	if (Linha == xperson && Coluna == yperson) {
		if (contadorexterno == 0 && move == false) {
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
		if (Linha + 1==xperson && Coluna ==yperson && move == true && contadorexterno==1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Linha++;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha + 1][Coluna] == 0) {
			Linha++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove,retornox,retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
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
		if (Linha + 1 == xperson && Coluna + 1 == yperson && move == true && contadorexterno == 1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Linha++;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha + 1][Coluna + 1] == 0) {
			Linha++;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove, retornox, retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
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
		if (Linha + 1 == xperson && Coluna - 1 == yperson && move == true && contadorexterno == 1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Linha++;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha + 1][Coluna - 1] == 0) {
			Linha++;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove, retornox, retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
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
		if (Linha == xperson && Coluna + 1 == yperson && move == true && contadorexterno == 1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha][Coluna + 1] == 0) {
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove, retornox, retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
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
		if (Linha == xperson && Coluna - 1 == yperson && move == true && contadorexterno == 1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha][Coluna - 1] == 0) {
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove, retornox, retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
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
		if (Linha - 1 == xperson && Coluna == yperson && move == true && contadorexterno == 1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Linha--;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha - 1][Coluna] == 0) {
			Linha--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove, retornox, retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
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
		if (Linha - 1 == xperson && Coluna + 1 == yperson && move == true && contadorexterno == 1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Linha--;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha - 1][Coluna + 1] == 0) {
			Linha--;
			Coluna++;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove, retornox, retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
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
		if (Linha - 1 == xperson && Coluna - 1 == yperson && move == true && contadorexterno == 1) {
			MatrizMonstro[Linha][Coluna] = 0;
			Linha--;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			return false;
		}
		else if (MatrizMonstro[Linha - 1][Coluna - 1] == 0) {
			Linha--;
			Coluna--;
			MatrizMonstro[Linha][Coluna] = 1;
			contador++;
			contadordemovimento(MatrizMonstro, Linha, Coluna, contador, contadorexterno, xperson, yperson, move, validamove, retornox, retornoy);
			if (validamove == 1 && contador == 1) {
				retornox = Linha;
				retornoy = Coluna;
				Linha++;
				Coluna++;
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

struct ATAQUE {
	bool rapido;
	int dano;
};
struct MONSTRO {
	int vida;
	int level;
	ATAQUE ataque[4];
};
struct OPONENTE {
	MONSTRO monstros[2];
	int linha;
	int coluna;
};


void jogo() {
	int MatrizPersonagem[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 };
	
	ATAQUE aa, q, w, e;
	aa.dano = 10;
	aa.rapido = true;
	q.dano = 15;
	q.rapido = false;
	w.dano = 20;
	w.rapido = false;
	e.dano = 25;
	e.rapido = false;

	MONSTRO arauto, arungueijo, krugueanciao, krugue, lobomaior, lobo, baron, dragon,ashe,garen;

	arauto.level = 50;
	arauto.vida = 400 * arauto.level;
	arauto.ataque[0] = aa;
	arauto.ataque[0].dano *= arauto.level;
	arauto.ataque[1] = q;
	arauto.ataque[1].dano *= arauto.level;
	arauto.ataque[2] = w;
	arauto.ataque[2].dano *= arauto.level;
	arauto.ataque[3] = e;
	arauto.ataque[3].dano *= arauto.level;

	arungueijo.level = 50;
	arungueijo.vida = 10 * arungueijo.level;
	arungueijo.ataque[0] = aa;
	arungueijo.ataque[0].dano *= arungueijo.level / 2;
	arungueijo.ataque[1] = q;
	arungueijo.ataque[1].dano *= arungueijo.level / 2;
	arungueijo.ataque[2] = w;
	arungueijo.ataque[2].dano *= arungueijo.level / 2;
	arungueijo.ataque[3] = e;
	arungueijo.ataque[3].dano *= arungueijo.level / 2;

	krugueanciao.level = 50;
	krugueanciao.vida = 25 * krugueanciao.level;
	krugueanciao.ataque[0] = aa;
	krugueanciao.ataque[0].dano *= krugueanciao.level / 3;
	krugueanciao.ataque[1] = q;
	krugueanciao.ataque[1].dano *= krugueanciao.level / 3;
	krugueanciao.ataque[2] = w;
	krugueanciao.ataque[2].dano *= krugueanciao.level / 3;
	krugueanciao.ataque[3] = e;
	krugueanciao.ataque[3].dano *= krugueanciao.level / 3;

	krugue.level = 50;
	krugue.vida = 10 * krugue.level;
	krugue.ataque[0] = aa;
	krugue.ataque[0].dano *= krugue.level / 4;
	krugue.ataque[1] = q;
	krugue.ataque[1].dano *= krugue.level / 4;
	krugue.ataque[2] = w;
	krugue.ataque[2].dano *= krugue.level / 4;
	krugue.ataque[3] = e;
	krugue.ataque[3].dano *= krugue.level / 4;

	lobomaior.level = 50;
	lobomaior.vida = 16 * lobomaior.level;
	lobomaior.ataque[0] = aa;
	lobomaior.ataque[0].dano *= lobomaior.level / 3;
	lobomaior.ataque[1] = q;
	lobomaior.ataque[1].dano *= lobomaior.level / 3;
	lobomaior.ataque[2] = w;
	lobomaior.ataque[2].dano *= lobomaior.level / 3;
	lobomaior.ataque[3] = e;
	lobomaior.ataque[3].dano *= lobomaior.level / 3;

	lobo.level = 50;
	lobo.vida = 12 * lobo.level;
	lobo.ataque[0] = aa;
	lobo.ataque[0].dano *= lobo.level / 4;
	lobo.ataque[1] = q;
	lobo.ataque[1].dano *= lobo.level / 4;
	lobo.ataque[2] = w;
	lobo.ataque[2].dano *= lobo.level / 4;
	lobo.ataque[3] = e;
	lobo.ataque[3].dano *= lobo.level / 4;

	baron.level = 50;
	baron.vida = 500 * baron.level;
	baron.ataque[0] = aa;
	baron.ataque[0].dano *= baron.level * 2;
	baron.ataque[1] = q;
	baron.ataque[1].dano *= baron.level * 2;
	baron.ataque[2] = w;
	baron.ataque[2].dano *= baron.level * 2;
	baron.ataque[3] = e;
	baron.ataque[3].dano *= baron.level * 2;

	dragon.level = 50;
	dragon.vida = 14 * dragon.level;
	dragon.ataque[0] = aa;
	dragon.ataque[0].dano *= dragon.level / 3;
	dragon.ataque[1] = q;
	dragon.ataque[1].dano *= dragon.level / 3;
	dragon.ataque[2] = w;
	dragon.ataque[2].dano *= dragon.level / 3;
	dragon.ataque[3] = e;
	dragon.ataque[3].dano *= dragon.level / 3;

	ashe.level = 50;
	ashe.vida = 60 * ashe.level;
	ashe.ataque[0] = aa;
	ashe.ataque[0].dano *= ashe.level*3;
	ashe.ataque[1] = q;
	ashe.ataque[1].dano *= ashe.level*3;
	ashe.ataque[2] = w;
	ashe.ataque[2].dano *= ashe.level*4;
	ashe.ataque[3] = e;
	ashe.ataque[3].dano *= ashe.level*5;

	garen.level = 50;
	garen.vida = 200 * garen.level;
	garen.ataque[0] = aa;
	garen.ataque[0].dano *= garen.level * 2;
	garen.ataque[1] = q;
	garen.ataque[1].dano *= garen.level * 2;
	garen.ataque[2] = w;
	garen.ataque[2].dano *= garen.level * 3;
	garen.ataque[3] = e;
	garen.ataque[3].dano *= garen.level * 3;

	OPONENTE Arauto, Pedras, Lobos, Baron,JOGADOR;

	Arauto.linha = 0;
	Arauto.coluna = 0;
	MatrizMonstro[Arauto.linha][Arauto.coluna] = 1;
	Arauto.monstros[0] = arauto;
	Arauto.monstros[1] = arungueijo;

	Pedras.linha = 1;
	Pedras.coluna = 3;
	MatrizMonstro[Pedras.linha][Pedras.coluna] = 1;
	Pedras.monstros[0] = krugueanciao;
	Pedras.monstros[1] = krugue;

	Lobos.linha = 4;
	Lobos.coluna = 0;
	MatrizMonstro[Lobos.linha][Lobos.coluna] = 1;
	Lobos.monstros[0] = lobomaior;
	Lobos.monstros[1] = lobo;

	Baron.linha = 4;
	Baron.coluna = 4;
	MatrizMonstro[Baron.linha][Baron.coluna] = 1;
	Baron.monstros[0] = baron;
	Baron.monstros[1] = dragon;

	JOGADOR.linha = 2;
	JOGADOR.coluna = 2;
	MatrizPersonagem[JOGADOR.linha][JOGADOR.coluna] = 1;
	JOGADOR.monstros[0] = ashe;
	JOGADOR.monstros[1] = garen;

	cout << "Round 0" << endl;
	for (int l = 0; l < TAMANHOMATRIZ; l++) {
		for (int c = 0; c < TAMANHOMATRIZ; c++) {
			if (l == JOGADOR.linha && c == JOGADOR.coluna)
				cout << "P1" << "\t";
			else {
				if (MatrizMonstro[l][c] == 1)
					cout << "NPC" << "\t";
				else
					cout << "----" << "\t";
			}
		}
		cout << endl;
	}
	int round = 0, controlederound = 0;
	while (true) {						//O JOGO COMECA AQUI!!!!!!!!!
		if (getchar() == 10)
			round++;
		if (controlederound != round) {
			cout << "Processando...Aguarde.";
			int monstro = 0;
			do{
				int contadorexterno = 0, validamove = 0;
				switch (monstro)
				{
				case 0 :
					contadordemovimento(MatrizMonstro, Lobos.linha, Lobos.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Lobos.linha, Lobos.coluna); //baixo esquerda
					contadordemovimento(MatrizMonstro, Lobos.linha, Lobos.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Lobos.linha, Lobos.coluna);
					cout << ".";
					break;
				case 1:
					contadordemovimento(MatrizMonstro, Baron.linha, Baron.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Baron.linha, Baron.coluna);
					contadordemovimento(MatrizMonstro, Baron.linha, Baron.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Baron.linha, Baron.coluna);
					cout << ".";
					break;
				case 2:
					contadordemovimento(MatrizMonstro, Arauto.linha, Arauto.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Arauto.linha, Arauto.coluna); //cima esquerda
					contadordemovimento(MatrizMonstro, Arauto.linha, Arauto.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Arauto.linha, Arauto.coluna);
					cout << ".";
					break;
				case 3:
					contadordemovimento(MatrizMonstro, Pedras.linha, Pedras.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Pedras.linha, Pedras.coluna); //direita cima
					contadordemovimento(MatrizMonstro, Pedras.linha, Pedras.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Pedras.linha, Pedras.coluna);
					cout << ".";
					break;
				default:
					break;
				}
				monstro++;
			} while (monstro < 4);
			if (Lobos.linha == JOGADOR.linha && Lobos.coluna == JOGADOR.coluna) {
				// chama uma batalha passando os monstros que tao no "Lobos" contra o jogador
			}
			if (Baron.linha == JOGADOR.linha && Baron.coluna == JOGADOR.coluna) {
				// chama uma batalha passando os monstros que tao no "Baron" contra o jogador
			}
			if (Arauto.linha == JOGADOR.linha && Arauto.coluna == JOGADOR.coluna) {
				// chama uma batalha passando os monstros que tao no "Arauto" contra o jogador
			}
			if (Pedras.linha == JOGADOR.linha && Pedras.coluna == JOGADOR.coluna) {
				// chama uma batalha passando os monstros que tao no "Pedras" contra o jogador
			}
			system("cls");
			cout << "Round " <<round<< endl;
			for (int l = 0; l < TAMANHOMATRIZ; l++) {
				for (int c = 0; c < TAMANHOMATRIZ; c++) {
					if (l == JOGADOR.linha && c == JOGADOR.coluna)
						cout << "P1" << "\t";
					else {
						if (MatrizMonstro[l][c] == 1)
							cout << "NPC" << "\t";
						else
							cout << "----" << "\t";
					}
				}
				cout << endl;
			}
		}
		controlederound = round;
	}
	
	
	




	system("pause");
	



}







#endif