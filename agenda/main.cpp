#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	ifstream arq("agenda.txt");
	string nome;
	string sobrenome;
	int ultimo;

	if(arq.is_open())
	{
		string linha;
		while(getline(arq, linha))
		{
			ultimo = linha.size();
			int espaco = linha.find_last_of(' '); //ultimo espaco na string
			nome  = linha.substr(0, espaco);
			sobrenome  = linha.substr(espaco + 1 , ultimo); //ultimo nome
			cout << sobrenome << ", " << nome << endl;
		}
		arq.close();
	}
	else
	{
		cout << "Não foi possível abrir o arquivo";
	}

	return 0;
}
