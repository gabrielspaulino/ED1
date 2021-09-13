#include <iostream>

using namespace std;

int ordenar(int n[10])
{
	int aux;
	int i;
	int x;
	for(i = 0; i < 10; i++)
	{
		if(n[i] > n[i + 1])
		{
			aux = n[i];
			n[i] = n[i + 1];
			n[i + 1] = aux;
		}
		x = i;
		while(n[x] < n[x - 1] && x >= 1)
		{
			aux = n[x];
			n[x] = n[x - 1];
			n[x - 1] = aux;
			x--;
		}
	}
}

void mostraVetor(int n[10])
{
	int i;
	cout << "Vetor em ordem crescente: ";
	for(i = 0; i < 9; i++)
	{
		cout << n[i] << ", ";
	}
	cout << n[9] << endl;
}

int main()
{
	//Insertion Sort
	int contador;
	
	int v[10] = {3, 0, 1, 8, 7, 2, 5, 4, 9, 6};
	cout << "Insertion Sort\nVetor sem ordem: ";
	for(contador = 0; contador < 9; contador++)
	{
		cout << v[contador] << ", ";
	}
	cout << v[9] << endl;
	
	ordenar(v);
	mostraVetor(v);
	return 0;
}
