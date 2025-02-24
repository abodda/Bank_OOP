#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "File.h"
class clsMoneyListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t    Money List Screen");
		vector <string> clients = _SaveFileContentToVector("clients.txt");
		int clientsize = clients.size();
		printf("\n\n\t\t\t\t\t     Client List (%d) Client (s).\n", clientsize);
		cout << "\t\t\t  ----------------------------------------------------------------\n";
		cout << "\t\t\t  | " << left << setw(20) << "Account Number" << "| " << setw(25) << "client Name" << "| " << "Balance" << "\n";
		cout << "\t\t\t  ----------------------------------------------------------------\n\n";
		for (int i = 0; i < clients.size(); i++) {
			clsClient client =clsClient::_ConvertLineToClientObject(clients[i]);
			cout << "\t\t\t  | " << left << setw(20) << client.AccountNumber() << "| " << setw(25) << client.Name() << "| " << client.Balance() << " $ \n";
		}
	}
};

