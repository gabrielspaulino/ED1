#include <iostream>
#include <locale.h>

using namespace std;

struct senhasGeradas
{
	int ini;
	int fim;
	float nos[];
};

struct senhasAtendidas
{
	int ini;
	int fim;
	float nos[];
};

senhasGeradas* init()
{
	senhasGeradas *s = new senhasGeradas;
	s->ini = NULL;
	s->fim = NULL;
	return s;
}

senhasAtendidas* initsa()
{
	senhasAtendidas *sa = new senhasAtendidas;
	sa->ini = NULL;
	sa->fim = NULL;
	return sa;
}

int isEmpty(senhasGeradas *s)
{
	return (s->ini == s->fim);
}

int incrementa(int i)
{
	int ret;
	ret = i + 1;
	return ret;
}

int count(senhasGeradas *s)
{
	int qtde = 0;
	int i = s->ini;
	while (i != s->fim)
	{
		qtde++;
		i = incrementa(i);
	}
	return qtde;
}

void print(senhasGeradas *s)
{
	int i = s->ini;
	cout << "Senhas a serem atendidas" << endl << "----------------------------------" << endl;
	while (i != s->fim)
	{
		cout << s->nos[i] << endl;
		i = incrementa(i);
	}
	cout << "----------------------------------\n" << endl;
}

void printAtendidas(senhasAtendidas *sa)
{
	int i = sa->ini;
	cout << "Senhas atendidas" << endl << "----------------------------------" << endl;
	while (i < sa->fim - 1)
	{
		cout << sa->nos[i] - 1 << endl;
		i = incrementa(i);
	}
}

int gerar(senhasGeradas *s, float v)
{
	s->nos[s->fim] = v;
	s->fim = incrementa(s->fim);
}

float atender(senhasGeradas *s, senhasAtendidas *sa)
{
	float ret;
	if (isEmpty(s))
	{
		cout << "Nenhuma senha a ser atendida" << endl;
		ret = -1;
	}
	else
	{
		cout << "Senha atendida: " << s->nos[s->ini] << endl;
		ret = s->nos[s->ini];
		s->ini = incrementa(s->ini);
		sa->nos[sa->fim] = s->nos[s->ini];
		sa->fim = incrementa(sa->fim);
	}
	return ret;
}

int main()
{
	setlocale(LC_ALL, "");
	int acao = 3;
	int senha = 1;
	int contador = 0;

	senhasGeradas *fila;
	fila = new senhasGeradas();
	fila = init();

	senhasAtendidas *atendidas;
	atendidas = new senhasAtendidas();
	atendidas = initsa();

	do
	{
		print(fila);
		printAtendidas(atendidas);
		cout << contador << endl << "----------------------------------\n" << endl;
		cout << "\nSenhas em espera: " << count(fila) << endl;
		cout << "0. Sair\n1. Gerar Senha\n2. Realizar Atendimento\nDigite de acordo com o que deseja fazer: ";
		cin >> acao;
		switch(acao)
		{
		case 0:
			cout << "Programa finalizado";
			break;
		case 1:
			cout << "\nGerou: " << (gerar(fila, senha) ? "SIM" : "NÃO") << endl << "Sua senha é " << senha << endl;
			senha++;
			break;
		case 2:
			atender(fila, atendidas);
			contador++;
			break;
		default:
			cout << "Digite um número válido";
		}
	}
	while(acao != 0 && count(fila) != 0);

	if(count(fila) == 0)
	{
		cout << "Todas as senhas foram atendidas" << endl;
	}
	return 0;
}
