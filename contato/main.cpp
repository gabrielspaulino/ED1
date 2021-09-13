#include <iostream>

using namespace std;

class Data
{
private:
	int dia;
	int mes;
	int ano;
	int idade;

public:
	Data(int dia, int mes, int ano)
	{
		this->mes = mes;
		this->dia = dia;
		this->ano = ano;
	}

	Data()
	{
		this->dia = 0;
		this->mes = 0;
		this->ano = 0;
	}

	void setDia(int dia)
	{
		this->dia = dia;
	}

	int getDia()
	{
		return this->dia;
	}

	void setMes(int mes)
	{
		this->mes = mes;
	}

	int getMes()
	{
		return this->mes;
	}

	void setAno(int ano)
	{
		this->ano = ano;
	}

	int getAno()
	{
		return this->ano;
	}
	string mostraIdade(int idade)
	{
		return to_string(idade);
	}
};

int main()
{
	string email[5] = {};
	string nome[5] = {};
	string telefone[5] = {};
	int idade[5] = {};
	int contador = 0;
	Data *dtnasc[5] ;
	Data *hoje;
	

	while(contador < 5)
	{
		cout << "Digite seu e-mail: ";
		cin >> email[contador];
		cout << "Digite seu nome: ";
		cin >> nome[contador];
		cout << "Digite seu telefone: ";
		cin >> telefone[contador];
		cout << "Digite o dia de nascimento" << endl;
		cin >> dtnasc[contador].dia = dia[contador];
		cout << "Digite o mês de nascimento" << endl;
		cin >> dtnasc[contador].mes = mes[contador];
		cout << "Digite o ano de nascimento" << endl;
		cin >> dtnasc[contador].ano = ano[contador];
		idade[contador] = 2021 - ano[contador];
		cout << mostraIdade(idade[contador]);
	}

	return 0;
}