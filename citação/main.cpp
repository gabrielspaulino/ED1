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
			int espaco = linha.find_first_of(' '); //primeiro espaço
			int espaco2 = linha.find_last_of(' '); //último espaço
			nome  = linha.substr(0, espaco); //primeiro nome
			sobrenome  = linha.substr(espaco2 + 1 , ultimo); ; //ultimo nome
			cout << sobrenome << ", " << nome << " ";
			nome_meio = linha.substr(espaco + 1, ultimo); //todos os sobrenomes
			nome_meio.erase(linha.size() - sobrenome.size() - 1 - nome.size(), ultimo - nome.size()); //tira o último nome
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
		cout << "Não foi possível abrir o arquivo";
	}

	return 0;
}
