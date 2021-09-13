#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <windows.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	setlocale(LC_ALL, "");

	string msg;
	int i;
	int linha = 0;
	int contadorx = 30;
	int contadory;

	cout << "Digite uma mensagem: ";
	getline(cin, msg);
	gotoxy(30, 5);
	cout << msg << endl;

	for(i = 0; i < msg.size(); ++i)
	{
		contadory = 6;
		linha = 1;
		while(linha < 20)
		{
			gotoxy(contadorx, 5); //limpa o caractere na primeira linha
			cout << " ";
			gotoxy(contadorx, contadory); //mostra o caractere na linha de baixo
			cout << msg.at(i);
			Sleep(200);
			gotoxy(contadorx, contadory); //limpa o caractere
			cout << " ";
			linha++;
			contadory++;
		}
		if(linha = 20)
		{
			gotoxy(contadorx, 26);
			cout << msg.at(i);
			Sleep(200);
			linha++;
			contadory++;
		}
		contadorx++;
	}
	return 0;
}
