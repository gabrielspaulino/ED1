#include <iostream>

using namespace std;

struct No
{
	float dado;
	struct No *prox;
};

struct senhasGeradas
{
	No *ini;
	No *fim;
};

senhasGeradas* init()
{
	senhasGeradas *s = new senhasGeradas;
	s->ini = NULL;
	s->fim = NULL;
	return s;
}

int isEmpty(senhasGeradas *s)
{
	return (s->ini == NULL);
}

int count(senhasGeradas *s)
{
	int qtde = 0;
	No *no;
	no = s->ini;
	while (no != NULL)
	{
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(senhasGeradas *s)
{
	No *no;
	no = s->ini;
	cout << "----------------------------------" << endl;
	while (no != NULL)
	{
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "----------------------------------" << endl;
}

int gerar(senhasGeradas *s, float v)
{
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(s))
	{
		s->ini = no;
	}
	else
	{
		s->fim->prox = no;
	}
	s->fim = no;
}

float atender(senhasGeradas *s)
{
	float ret;
	if (isEmpty(s))
	{
		ret = -1;
	}
	else
	{
		No *no = s->ini;
		ret = no->dado;
		s->ini = no->prox;
		if (s->ini == NULL)
		{
			s->fim = NULL;
		}
	}
	return ret;
}

int main()
{
	int acao = 3;
	int senha = 1;
	senhasGeradas *fila;
	fila = new senhasGeradas();
	fila = init();

	while(acao != 0)
	{
		cout << "Digite de acordo com o que quer fazer:\n0. Sair\n1. Gerar Senha\n2. Realizar Atendimento" << endl;
		cin >> acao;
		cout << "Senhas em espera: " << count(fila) << endl;
	}
	switch(acao)
	{
	case 0:
		cout << "Programa finalizado";
		break;
	case 1:
		gerar(fila, senha);
		print(fila);
		senha++;
		break;
	case 2:
		atender(fila);
		print(fila);
		break;
	default:
		cout << "Digite um número válido";
	}
		 return 0;
}
