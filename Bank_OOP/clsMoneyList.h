#pragma once
#include "clsScreen.h"
#include "client.h"
#include <vector>
class clsMoneyList : protected clsScreen
{
public:
	static void Screen() {
		system("cls");
		vector <string> clients = clsClient::_SaveFileContentToVector("clients.txt");
		int clientsize = clients.size();
		if (clientsize == 0) {
			HeaderName("|   there are no Clients !    |");
			return;
		}
		 HeaderName("Client List Screen"); printf("(%d) Client (s).\n", clientsize);
		cout << "----------------------------------------------------------------\n";
		cout << "| " << left << setw(20) << "Account Number" << "| " << setw(25) << "client Name" << "| " << "Balance" << "\n";
		cout << "----------------------------------------------------------------\n\n";
		for (int i = 0; i < clients.size(); i++) {
			clsClient client = clsClient::_ConvertLineToClientObject(clients[i]);
			cout << "| " << left << setw(20) << client.AccountNumber() << "| " << setw(25) << client.Name() << "| " << client.Balance() << " $ \n";
		}
	}
};

