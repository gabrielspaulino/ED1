#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	
	int i;
	string invertida = "";
	string msg;
	string nospacemsg = "";
	char espaco = ' ';
	int size;
	int nospacesize;

	cout << "Digite uma mensagem: ";
	getline(cin, msg);
	
	for(i = 0; i <= msg.size() - 1; ++i) //refazendo a mensagem sem espaços
	{
		if(msg.at(i) != espaco)
		{
			nospacemsg += msg.at(i);
		}
	}
	
	for(i = nospacemsg.size() - 1; i >= 0; i--) //invertendo a mensagem
	{
		invertida += nospacemsg.at(i);
	}
	
	if(nospacemsg == invertida) //teste palíndromo
	{
		cout << "Essa mensagem é palíndromo";
	}
	else
	{
		cout << "Essa mensagem não é palíndromo";
	}
	cout << msg;
	return 0;
}
