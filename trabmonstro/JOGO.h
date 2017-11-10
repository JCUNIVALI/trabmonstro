#ifndef JOGO_H
#define JOGO_H
#include <iostream>
#include <time.h>
#include <string>
#include "conio.h"
#define TAMANHOMATRIZ 5

using namespace std;

struct ATAQUE {
	bool rapido;
	int dano;
};
struct MONSTRO {
	int vida;
	int level;
	string nome;
	ATAQUE ataque[4];
};
struct OPONENTE {
	MONSTRO monstros[2];
	int linha;
	int coluna;
};
void jogo(OPONENTE Arauto, OPONENTE Pedras, OPONENTE Lobos, OPONENTE Baron, OPONENTE JOGADOR);

void batalha(OPONENTE &Monstro, int LinhaMonstro, int ColunaMonstro, OPONENTE JOGADOR, int LinhaJogador, int ColunaJogador, int MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ]) {
	srand(time(NULL));
	int morto = 0, contador = 0, jogadormove = 0, aplicadanojogador[3] = { 0 }, aplicadanomonstro[3] = { 0 }, opcao, ataqueQ = 0, ataqueW = 0, ataqueE = 0;
	int danojogador[3] = { 0 }, danomonstro[3] = { 0 }, monstro = 0;
	MONSTRO player;
	cout << "INICIO DA BATALHA!!!!!!!!!!!!!!!!!!!!!!";
	while (morto == 0) {
		if (contador == 0) {
			do {
				cout << "Escolha seu champ: " << endl << "Ashe [0]" << endl << "Garen [1]" << endl;
				opcao=_getch()-48;
				player = JOGADOR.monstros[opcao];
				system("cls");
			} while (opcao != 0 && opcao != 1);
			contador++;
		}
		cout << "JOGADOR:\t" << player.nome<<"\t\t\tVida: "<<player.vida << endl;
		cout << "OPONENTE:\t"<< Monstro.monstros[monstro].nome << "\t\tVida: " << Monstro.monstros[monstro].vida << endl;
		cout << "Ecolha seu ataque: " << endl << "A : Auto-Ataque\t\t\tDano : " << player.ataque[0].dano << endl;
		cout <<  "Q : Acerto Decisivo\t\tDano : " << player.ataque[1].dano << endl;
		cout <<  "W : Julgamento\t\t\tDano : " << player.ataque[2].dano << endl;
		cout <<  "E : Poder do Grao-Mestre\tDano : " << player.ataque[3].dano << endl;
		int tecla = 0;
		if (jogadormove==0) {
			tecla = _getch();
			if (tecla == 97) {//tecla a
				Monstro.monstros[monstro].vida -= player.ataque[0].dano;
				jogadormove++;
			}
			if (tecla == 113 && ataqueQ < 4) {//tecla q
				Monstro.monstros[monstro].vida -= (player.ataque[1].dano) / 2;
				aplicadanojogador[0] += (player.ataque[1].dano) / 2;
				danojogador[0]++;
				jogadormove++;
			}
			if (tecla == 119 && ataqueW < 4) {//tecla w
				Monstro.monstros[monstro].vida -= (player.ataque[2].dano) / 2;
				aplicadanojogador[1] += (player.ataque[2].dano) / 2;
				danojogador[1]++;
				jogadormove++;
			}
			if (tecla == 101 && ataqueE < 4) {//tecla e
				Monstro.monstros[monstro].vida -= (player.ataque[3].dano) / 2;
				aplicadanojogador[2] += (player.ataque[3].dano) / 2;
				danojogador[2]++;
				jogadormove++;
			}
		}
		for (int x = 0; x < 3; x++) {
			if (danomonstro[x] == 1) {
				danomonstro[x]++;
			}
		}
		if (jogadormove >= 1) {
			for (int x = 0; x < 3; x++) {
				if (aplicadanojogador[x] > 0 && danojogador[x]>=2) {
					Monstro.monstros[monstro].vida -= aplicadanojogador[x];
					aplicadanojogador[x]--;
				}
			}
			jogadormove--;
			int ataquemonstro=rand() % 4;
			cout << ataquemonstro << "ATAQUE DO MONSTRO"<<endl;
			if (ataquemonstro == 0) {
				cout << "entoru 0" << endl;
				player.vida -= Monstro.monstros[monstro].ataque[0].dano;
			}
			if (ataquemonstro == 1) {
				cout << "entoru 1" << endl;
				player.vida -= (Monstro.monstros[monstro].ataque[1].dano)/2;
				aplicadanomonstro[0] += (Monstro.monstros[monstro].ataque[1].dano) / 2;
				danomonstro[0]++;
			}
			if (ataquemonstro == 2) {
				cout << "entoru 2" << endl;
				player.vida -= (Monstro.monstros[monstro].ataque[2].dano)/2;
				aplicadanomonstro[1] += (Monstro.monstros[monstro].ataque[2].dano) / 2;
				danomonstro[1]++;
			}
			if (ataquemonstro == 3) {
				cout << "entoru 3" << endl;
				player.vida -= (Monstro.monstros[monstro].ataque[3].dano)/2;
				aplicadanomonstro[2] += (Monstro.monstros[monstro].ataque[3].dano) / 2;
				danomonstro[2]++;
			}

			//fazer a batalha em si aki..
		}
		if (player.vida <= 0) {
			if (opcao==0 && JOGADOR.monstros[1].vida>0)
				opcao++;
			if (opcao == 1 && JOGADOR.monstros[0].vida>0)
				opcao--;
			else {
				cout << "-------------------------GAMEOVER--------------";
				getchar();
			}
		}
		if (Monstro.monstros[monstro].vida <= 0) {
			if (monstro==0)
				monstro++;
			else {
				morto = 1;

			}
		}
		for (int x = 0; x < 3; x++) {
			if (danojogador[x] == 1) {
				danojogador[x]++;
			}
		}
		//system("cls");
	}
}
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
			retornox = Linha;
			retornoy = Coluna;
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
			retornox = Linha;
			retornoy = Coluna;
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
			retornox = Linha;
			retornoy = Coluna;
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
			retornox = Linha;
			retornoy = Coluna;
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
			retornox = Linha;
			retornoy = Coluna;
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
			retornox = Linha;
			retornoy = Coluna;
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
			retornox = Linha;
			retornoy = Coluna;
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
			retornox = Linha;
			retornoy = Coluna;
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



void inicia() {
	ATAQUE aa, q, w, e;
	aa.dano = 10;
	aa.rapido = true;
	q.dano = 15;
	q.rapido = false;
	w.dano = 20;
	w.rapido = false;
	e.dano = 25;
	e.rapido = false;

	MONSTRO arauto, arungueijo, krugueanciao, krugue, lobomaior, lobo, baron, dragon, ashe, garen;

	arauto.nome = "arauto";
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

	arungueijo.nome = "arungueijo";
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

	krugueanciao.nome = "Krugue Anciao";
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

	krugue.nome = "Krugue";
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

	lobomaior.nome = "Lobo Alfa";
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

	lobo.nome = "Lobo";
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

	baron.nome = "Baron";
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

	dragon.nome = "Dragon";
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

	ashe.nome = "Ashe";
	ashe.level = 50;
	ashe.vida = 60 * ashe.level;
	ashe.ataque[0] = aa;
	ashe.ataque[0].dano *= ashe.level * 3;
	ashe.ataque[1] = q;
	ashe.ataque[1].dano *= ashe.level * 3;
	ashe.ataque[2] = w;
	ashe.ataque[2].dano *= ashe.level * 4;
	ashe.ataque[3] = e;
	ashe.ataque[3].dano *= ashe.level * 5;

	garen.nome = "Garen";
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

	OPONENTE Arauto, Pedras, Lobos, Baron, JOGADOR;

	Arauto.linha = 0;
	Arauto.coluna = 0;
	Arauto.monstros[0] = arauto;
	Arauto.monstros[1] = arungueijo;

	Pedras.linha = 1;
	Pedras.coluna = 3;
	Pedras.monstros[0] = krugueanciao;
	Pedras.monstros[1] = krugue;

	Lobos.linha = 4;
	Lobos.coluna = 0;
	Lobos.monstros[0] = lobomaior;
	Lobos.monstros[1] = lobo;

	Baron.linha = 4;
	Baron.coluna = 4;
	Baron.monstros[0] = baron;
	Baron.monstros[1] = dragon;

	JOGADOR.linha = 2;
	JOGADOR.coluna = 2;
	JOGADOR.monstros[0] = ashe;
	JOGADOR.monstros[1] = garen;

	jogo(Arauto, Pedras, Lobos, Baron, JOGADOR);
}

void jogo(OPONENTE Arauto, OPONENTE Pedras, OPONENTE Lobos, OPONENTE Baron, OPONENTE JOGADOR) {
	int MatrizPersonagem[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 }, MatrizMonstro[TAMANHOMATRIZ][TAMANHOMATRIZ] = { 0 };
	MatrizMonstro[Arauto.linha][Arauto.coluna] = 1;
	MatrizMonstro[Pedras.linha][Pedras.coluna] = 1;
	MatrizMonstro[Lobos.linha][Lobos.coluna] = 1;
	MatrizMonstro[Baron.linha][Baron.coluna] = 1;
	MatrizPersonagem[JOGADOR.linha][JOGADOR.coluna] = 1;

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
			int monstro = 0, lobosmorto = 0, baronmorto = 0, arautomorto = 0, pedrasmorto = 0;
			do{
				int contadorexterno = 0, validamove = 0;
				switch (monstro)
				{
				case 0 :
					if (Lobos.monstros[1].vida > 0) {
						contadordemovimento(MatrizMonstro, Lobos.linha, Lobos.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Lobos.linha, Lobos.coluna); //baixo esquerda
						contadordemovimento(MatrizMonstro, Lobos.linha, Lobos.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Lobos.linha, Lobos.coluna);
						cout << ".";
					}
					else {
						lobosmorto++;
						MatrizMonstro[Lobos.linha][Lobos.coluna] = 0;
					}
					break;
				case 1:
					if (Baron.monstros[1].vida > 0) {
						contadordemovimento(MatrizMonstro, Baron.linha, Baron.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Baron.linha, Baron.coluna);
						contadordemovimento(MatrizMonstro, Baron.linha, Baron.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Baron.linha, Baron.coluna);
						cout << ".";
					}
					else {
						baronmorto++;
						MatrizMonstro[Baron.linha][Baron.coluna] = 0;
					}
					break;
				case 2:
					if (Arauto.monstros[1].vida > 0) {
						contadordemovimento(MatrizMonstro, Arauto.linha, Arauto.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Arauto.linha, Arauto.coluna); //cima esquerda
						contadordemovimento(MatrizMonstro, Arauto.linha, Arauto.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Arauto.linha, Arauto.coluna);
						cout << ".";
					}
					else {
						arautomorto++;
						MatrizMonstro[Arauto.linha][Arauto.coluna] = 0;
					}
					break;
				case 3:
					if (Pedras.monstros[1].vida > 0) {
						contadordemovimento(MatrizMonstro, Pedras.linha, Pedras.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, false, validamove, Pedras.linha, Pedras.coluna); //direita cima
						contadordemovimento(MatrizMonstro, Pedras.linha, Pedras.coluna, 0, contadorexterno, JOGADOR.linha, JOGADOR.coluna, true, validamove, Pedras.linha, Pedras.coluna);
						cout << ".";
					}
					else {
						pedrasmorto++;
						MatrizMonstro[Pedras.linha][Pedras.coluna] = 0;
					}
					break;
				default:
					break;
				}
				monstro++;
			} while (monstro < 4);
			if (Lobos.linha == JOGADOR.linha && Lobos.coluna == JOGADOR.coluna && lobosmorto==0) {
				batalha(Lobos, Lobos.linha, Lobos.coluna, JOGADOR, JOGADOR.linha, JOGADOR.coluna,MatrizMonstro);
			}
			if (Baron.linha == JOGADOR.linha && Baron.coluna == JOGADOR.coluna && baronmorto==0) {
				batalha(Baron, Baron.linha, Baron.coluna, JOGADOR, JOGADOR.linha, JOGADOR.coluna, MatrizMonstro);
			}
			if (Arauto.linha == JOGADOR.linha && Arauto.coluna == JOGADOR.coluna && arautomorto==0) {
				batalha(Arauto, Arauto.linha, Arauto.coluna, JOGADOR, JOGADOR.linha, JOGADOR.coluna, MatrizMonstro);
			}
			if (Pedras.linha == JOGADOR.linha && Pedras.coluna == JOGADOR.coluna && pedrasmorto==0) {
				batalha(Pedras, Pedras.linha, Pedras.coluna, JOGADOR, JOGADOR.linha, JOGADOR.coluna, MatrizMonstro);
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