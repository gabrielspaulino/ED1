#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define LIN 15
#define COL 40


int main()
{
    int acao;
    int i;
    int j;
    int k;
    int fileira;
    int poltrona;
    int faturamento = 0;
	    
    int **mat;
    
    mat = (int**)malloc(LIN * sizeof(int));
    
    for(i=0; i<LIN; ++i)
	{
		mat[i] = (int*)malloc(COL * sizeof(int));
	}

	for(i=0; i<LIN; ++i)
	{
		for(j = 0; j<COL; ++j)
		{
			mat[i][j] = j + 1;
		}
	}
	
	while(acao != 0)
	{
    cout << "\n\n 0.	Finalizar \n 1.	Reservar poltrona \n 2.	Mapa de ocupação \n 3.	Faturamento \n Digite o numero correspondente: ";
    cin >> acao;
    switch(acao){
		case 0:
			cout << "\nFinalizado.";
			break;
		
		case 1:
			cout << "Escolha a fileira (1 a 15): ";
			cin >> fileira;
			cout << "Escolha a poltorona (1 a 40): ";
			cin >> poltrona;
			if(fileira >= 1 && fileira < 16 && poltrona >= 1 && poltrona < 41)
			{
				if(mat[fileira - 1][poltrona - 1] != 0)
				{
					mat[fileira - 1][poltrona - 1] = 0;
					if(fileira < 6)
					{
						faturamento += 50;
					}
					else if(fileira > 10)
					{
						faturamento += 15;
					}
					else
					{
						faturamento += 30;
					}
					cout << "Lugar reservado";
				}
				else
				{
					cout << "Lugar ocupado";
				}
			}
			else
			{
				cout << "Lugar invalido";
			}
			break;
		
		case 2:
			cout << "\n# = ocupado \n. = livre\n";
			k = 1;
			for(i=0; i<LIN; ++i)
			{
				cout << "Fileira " <<  setw(2) << k; 
				for(j = 0; j<COL; ++j)
				{
					if(mat[i][j] != 0){
						cout << " | ." << setw(2) << mat[i][j];
					}
					else{
						cout << " |  #" << setw(5);
					}
				}
				k++;
				cout << endl;
			}
			break;
		
		case 3:
			cout << "\nFaturamento total: R$ ";
			cout << faturamento;
			break;
		
		default:
			cout << "Digitou um numero invalido.";
	}
	}
	return 0;
}