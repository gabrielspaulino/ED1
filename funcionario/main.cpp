#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

struct Funcionario
{
	int prontuario[100];
	string nome[100];
	double salario[100];
} dados;

void incluir(int x, int &i, int y, double &soma)
{
	cout << "Digite o prontu�rio do funcion�rio: ";
	cin >> x;
	y = 0;
	while(y <= i)
	{
		if(x == dados.prontuario[y])
		{
			cout << "Prontu�rio j� registrado" << endl;
			y = i + 1;
		}
		if(y == i)
		{
			dados.prontuario[i] = x;
			y++;
		}
		else
		{
			y++;
		}
	}
	cout << "Digite o nome do funcion�rio: ";
	cin >> dados.nome[i];
	cout << "Digite o sal�rio do funcion�rio: ";
	cin >> dados.salario[i];
	if(dados.prontuario[i] != 0)
	{
		soma += dados.salario[i];
	}
	i++;
}

void excluir(int x, int &i, int y, double &soma)
{
	y = 0;
	cout << "Digite o n�mero do prontu�rio do funcion�rio que deseja excluir: ";
	cin >> x;
	while(y <= i + 1)
	{
		if(i == 0)
		{
			cout << "Voc� ainda n�o registrou funcion�rios\n";
			y++;
		}
		if(dados.prontuario[y] == x)
		{
			dados.prontuario[y] = 0;
			dados.nome[y] = " ";
			soma -= dados.salario[y];
			dados.salario[y] = 0;
			cout << "Dados do funcion�rio exclu�dos\n";
			y = i + 2;
		}
		if(y == i + 1)
		{
			cout << "N�o foi encontrado um funcion�rio com este prontu�rio\n";
			y++;
		}
		else
		{
			y++;
		}
	}
}

void pesquisar(int x, int &i, int y)
{
	cout << "Digite o n�mero do prontu�rio do funcion�rio que voc� deseja pesquisar: ";
	cin >> x;
	y = 0;
	while(y <= i)
	{
		if(i == 0)
		{
			cout << "Voc� ainda n�o registrou funcion�rios" << endl;
		}
		else if(dados.prontuario[y] == x)
		{
			cout << "\nProntu�rio do funcion�rio: " << dados.prontuario[y];
			cout << "\nNome do funcion�rio: " << dados.nome[y];
			cout << "\nSal�rio do funcion�rio: " << dados.salario[y] << "\n";
			y = i + 1;
		}
		else if(y == i)
		{
			cout << "N�o foi encontrado um funcion�rio com este prontu�rio " << endl;
		}
		y++;
	}
}

void listar(int x, int &i, int y, double &soma)
{
	y = 0;
	while(y < i)
	{

		if(i == 0)
		{
			cout << "Voc� ainda n�o registrou funcion�rios";
			y++;
		}
		else if(dados.prontuario[y] != 0)
		{
			cout << "\n\nProntu�rio do funcion�rio: " << dados.prontuario[y];
			cout << "\nNome do funcion�rio: " << dados.nome[y];
			cout << "\nSal�rio do funcion�rio: ";
			cout << dados.salario[y];
			y++;
		}
		else
		{
			y++;
		}
	}
	cout << "\nTotal dos sal�rios: " << soma << "\n";
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	int opcao;
	int contador = 0;
	int percorrer;
	int func;
	double folha = 0;

	while(opcao != 10)
	{
		cout << "\n0. Sair \n1. Incluir \n2. Excluir \n3. Pesquisar \n4. Listar \nEscolha de acordo com o numero: ";
		cin >> opcao;
		switch(opcao)
		{
		case 0:
			opcao = 10;
			break;
		case 1:
			incluir(func, contador, percorrer, folha);
			break;
		case 2:
			excluir(func, contador, percorrer, folha);
			break;
		case 3:
			pesquisar(func, contador, percorrer);
			break;
		case 4:
			listar(func, contador, percorrer, folha);
			break;
		default:
			cout << "Escolha uma op��o v�lida" << endl;
		}
	}
	cout << "Programa finalizado";
}
