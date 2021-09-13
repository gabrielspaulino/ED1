#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>

using namespace std;

#define LIN 4
#define COL 13
#define BAR 2

int main()
{
	int jogador = 1;
	string naipe;
	string numero;
	int i;
	int j;
	int k;

	int **mat;

	mat = (int**)malloc(LIN * sizeof(int));

	for(i = 0; i < LIN; ++i)
	{
		mat[i] = (int*)malloc(COL * sizeof(int));
	}

	for(i = 0; i < LIN; ++i)
	{
		for(j = 0; j < COL; ++j)
		{
			mat[i][j] = j + 1;
		}
	}

	while(jogador < 5)
	{
		int contador = 1;
		cout << "\n\nCartas do jogador " << jogador << "\n";
		while(contador < 12)
		{
			int random1 = rand();
			int n = random1 % 4;
			int random2 = rand();
			int nc = random2 % 13 + 1;
			int random3 = rand();
			int b = random3 % 2 + 1;

			switch(n)
			{
			case 0:
				naipe = "Copas";
				break;
			case 1:
				naipe = "Paus";
				break;
			case 2:
				naipe = "Ouro";
				break;
			default:
				naipe = "Espada";
			}
			switch(nc)
			{
			case 1:
				numero = "As";
				break;
			case 11:
				numero = "Valete";
				break;
			case 12:
				numero = "Rainha";
				break;
			case 13:
				numero = "Rei";
				break;
			}


			if(mat[n][nc] != 0)
			{
				mat[n][nc] = 0;

				if(nc == 1 || nc == 11 || nc == 12 || nc == 13)
				{
					cout << "\n" << numero << " de " << naipe << " do baralho " << b << "\n";
				}
				else
				{
					cout << "\n" << nc << " de " << naipe << " do baralho " << b << "\n";
				}

				contador++;
			}
		}
		jogador++;
	}

	return 0;
}
