#include <iostream>
#include <locale.h>
using namespace std;

#define MAX 30

struct Pilha
{
	int qtde;
	float elementos[MAX];
};

struct Pares
{
	int qtde;
	float elementos[MAX];
};

struct Impares
{
	int qtde;
	float elementos[MAX];
};

Pilha* init()
{
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

Pares* initPar()
{
	Pares *par = new Pares;
	par->qtde = 0;
	return par;
}

Impares* initImpar()
{
	Impares *imp = new Impares;
	imp->qtde = 0;
	return imp;
}

int push(Pilha *p, float v)
{
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar)
	{
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p)
{
	int podeDesempilhar = (p->qtde > 0);
	float v;
	if (podeDesempilhar)
	{
		v = p->elementos[p->qtde - 1];
		p->qtde--;
	}
	else
	{
		v = -1;
	}
	return v;
}

int pushPar(Pares *par, float v)
{
	int podeEmpilhar = (par->qtde < MAX);
	if (podeEmpilhar)
	{
		par->elementos[par->qtde++] = v;
	}
	return podeEmpilhar;
}

float popPar(Pares *par)
{
	int podeDesempilhar = (par->qtde > 0);
	float v;
	if (podeDesempilhar)
	{
		v = par->elementos[par->qtde - 1];
		par->qtde--;
	}
	else
	{
		v = -1;
	}
	return v;
}

int pushImpar(Impares *imp, float v)
{
	int podeEmpilhar = (imp->qtde < MAX);
	if (podeEmpilhar)
	{
		imp->elementos[imp->qtde++] = v;
	}
	return podeEmpilhar;
}

float popImpar(Impares *imp)
{
	int podeDesempilhar = (imp->qtde > 0);
	float v;
	if (podeDesempilhar)
	{
		v = imp->elementos[imp->qtde - 1];
		imp->qtde--;
	}
	else
	{
		v = -1;
	}
	return v;
}

int isEmpty(Pilha *p)
{
	return (p->qtde == 0);
}

int count(Pilha *p)
{
	return (p->qtde);
}

void print(Pilha *p)
{
	for(int i = p->qtde - 1; i >= 0; --i)
	{
		cout << p->elementos[i] << endl;
	}
	cout << "--------------" << endl;
}

void printPares(Pares *par)
{
	for(int i = par->qtde - 1; i >= 0; --i)
	{
		cout << par->elementos[i] << endl;
	}
	cout << "--------------" << endl;
}

void printImpares(Impares *imp)
{
	for(int i = imp->qtde - 1; i >= 0; --i)
	{
		cout << imp->elementos[i] << endl;
	}
	cout << "--------------" << endl;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	
	Pilha *pilhaFloat;
	pilhaFloat = new Pilha;
	pilhaFloat = init();

	Pares *pilhaPares;
	pilhaPares = new Pares;
	pilhaPares = initPar();
	
	Impares *pilhaImpares;
	pilhaImpares = new Impares;
	pilhaImpares = initImpar();
	
	int numero;
	int anterior;
	int contador = 0;
	int contapar = 0;
	int contaimpar = 0;

	cout << "Pilha vazia: " << (isEmpty(pilhaFloat) ? "SIM" : "NAO") << endl;



	while(contador < 30)
	{
		cout << "Digite um número maior que o anterior (se houver): ";
		cin >> numero;
		if(contador == 0){
			anterior = numero - 1;
		}
		if(anterior < numero)
		{
			cout << "Empilhado valor: " << (push(pilhaFloat, numero) ? "SIM" : "NAO") << endl;
			contador++;
			anterior = numero;
			if(numero % 2 == 0)
			{
				pushPar(pilhaPares, numero);
				cout << "Valor par" << endl;
				contapar++;
			}
			else
			{
				pushImpar(pilhaImpares, numero);
				cout << "Valor ímpar" << endl;
				contaimpar++;
			}
		}
		else
		{
			cout << "Empilhado valor: NAO" << endl;
		}
	}

	cout << "Pilha vazia: " << (isEmpty(pilhaFloat) ? "SIM" : "NAO") << endl;
	
	cout << "--------------" << endl;
	cout << "Valores em ordem decrescente" << endl;
	contador = 0;
	while(contador < 30)
	{
		cout << pop(pilhaFloat) << endl;
		contador++;
	}
	print(pilhaFloat);
	
	contador = 0;
	cout << "Valores pares" << endl;
	while(contador < contapar)
	{
		cout << popPar(pilhaPares) << endl;
		contador++;
	}
	printPares(pilhaPares);
	
	contador = 0;
	cout << "Valores ímpares" << endl;
	while(contador < contaimpar)
	{
		cout << popImpar(pilhaImpares) << endl;
		contador++;
	}
	printImpares(pilhaImpares);
	
	return 0;
}