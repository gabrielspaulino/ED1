#include <iostream>
#include <fstream>
#include <locale.h>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	ifstream arq("nomes.txt");
	int ultimo;
	string nome;
	string nome_meio;
	string sobrenome;
	int i = 0;
	int contador = 0;
	string abreviado[] = {};

	if(arq.is_open())
	{
		string linha;
		while(getline(arq, linha))
		{
			ultimo = linha.size();
			int espaco = linha.find_first_of(' '); //primeiro espa�o
			int espaco2 = linha.find_last_of(' '); //�ltimo espa�o
			nome  = linha.substr(0, espaco); //primeiro nome
			sobrenome  = linha.substr(espaco2 + 1 , ultimo); ; //ultimo nome
			cout << sobrenome << ", " << nome << " ";
			nome_meio = linha.substr(espaco + 1, ultimo); //todos os sobrenomes
			nome_meio.erase(linha.size() - sobrenome.size() - 1 - nome.size(), ultimo - nome.size()); //tira o �ltimo nome
			for(i = 0; i < nome_meio.size() - 1; ++ i)
			{
				if(isupper(nome_meio.at(i)))
				{
					abreviado[contador] = nome_meio.at(i);
					cout << abreviado[contador] << ". ";
					contador++;
				}
			}
			cout << endl;
		}
		arq.close();
	}
	else
	{
		cout << "N�o foi poss�vel abrir o arquivo";
	}

	return 0;
}
