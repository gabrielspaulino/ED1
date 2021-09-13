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
	
	for(i = 0; i <= msg.size() - 1; ++i) //refazendo a mensagem sem espa�os
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
	
	if(nospacemsg == invertida) //teste pal�ndromo
	{
		cout << "Essa mensagem � pal�ndromo";
	}
	else
	{
		cout << "Essa mensagem n�o � pal�ndromo";
	}
	cout << msg;
	return 0;
}
