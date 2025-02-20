#pragma once
#include "clsScreen.h"
#include "Client.h"
#include <vector>
class clsClientList : protected clsScreen
{
public:
	static void Screen() {
		system("cls");
		vector <string> clients = clsClient ::_SaveFileContentToVector("clients.txt");
		int clientsize = clients.size();
		if (clientsize == 0) {
			HeaderName("|   there are no Clients !    |");
			return;
		}
		printf("\n\nClient List (%d) Client (s).\n", clientsize);
		cout << "--------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(20) << "Account Number" << "| " << setw(10) << "Pin Code" << "| " << setw(25) << "client Name" << "| " << setw(25) << "Phone" << "| " << setw(10) << "Balance" << "\n";
		cout << "--------------------------------------------------------------------------------------------------\n\n";
		for (int i = 0; i < clients.size(); i++) {
			clsClient client = clsClient::_ConvertLineToClientObject(clients[i]);
			cout << "| " << left << setw(20) << client.AccountNumber() << "| " << setw(10) << client.PinCode() << "| " << setw(25) << client.Name() << "| " << setw(25) << client.Phone() << "| " << client.Balance() << " $ \n";
		}
		cout << "\n--------------------------------------------------------------------------------------------------\n\n";
	}
};

