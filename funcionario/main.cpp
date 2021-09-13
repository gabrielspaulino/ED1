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
	cout << "Digite o prontuário do funcionário: ";
	cin >> x;
	y = 0;
	while(y <= i)
	{
		if(x == dados.prontuario[y])
		{
			cout << "Prontuário já registrado" << endl;
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
	cout << "Digite o nome do funcionário: ";
	cin >> dados.nome[i];
	cout << "Digite o salário do funcionário: ";
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
	cout << "Digite o número do prontuário do funcionário que deseja excluir: ";
	cin >> x;
	while(y <= i + 1)
	{
		if(i == 0)
		{
			cout << "Você ainda não registrou funcionários\n";
			y++;
		}
		if(dados.prontuario[y] == x)
		{
			dados.prontuario[y] = 0;
			dados.nome[y] = " ";
			soma -= dados.salario[y];
			dados.salario[y] = 0;
			cout << "Dados do funcionário excluídos\n";
			y = i + 2;
		}
		if(y == i + 1)
		{
			cout << "Não foi encontrado um funcionário com este prontuário\n";
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
	cout << "Digite o número do prontuário do funcionário que você deseja pesquisar: ";
	cin >> x;
	y = 0;
	while(y <= i)
	{
		if(i == 0)
		{
			cout << "Você ainda não registrou funcionários" << endl;
		}
		else if(dados.prontuario[y] == x)
		{
			cout << "\nProntuário do funcionário: " << dados.prontuario[y];
			cout << "\nNome do funcionário: " << dados.nome[y];
			cout << "\nSalário do funcionário: " << dados.salario[y] << "\n";
			y = i + 1;
		}
		else if(y == i)
		{
			cout << "Não foi encontrado um funcionário com este prontuário " << endl;
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
			cout << "Você ainda não registrou funcionários";
			y++;
		}
		else if(dados.prontuario[y] != 0)
		{
			cout << "\n\nProntuário do funcionário: " << dados.prontuario[y];
			cout << "\nNome do funcionário: " << dados.nome[y];
			cout << "\nSalário do funcionário: ";
			cout << dados.salario[y];
			y++;
		}
		else
		{
			y++;
		}
	}
	cout << "\nTotal dos salários: " << soma << "\n";
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
			cout << "Escolha uma opção válida" << endl;
		}
	}
	cout << "Programa finalizado";
}
