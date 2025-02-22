#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "Misc.h"
#include <iomanip>
class clsClientListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Client List Screen");
		vector <string> clients = _SaveFileContentToVector("clients.txt");
		int clientsize = clients.size();
		if (clientsize == 0) 
		{
			cout << "\t\t\t\t\t   no clients have been added yet! \n";
			return;
		}
		printf("\n\n\t\t\t\t\t    Client List (%d) Client (s).\n", clientsize);
		cout << "\t  --------------------------------------------------------------------------------------------------\n";
		cout << "\t  | " << left << setw(20) << "Account Number" << "| " << setw(10) << "Pin Code" << "| " << setw(25) << "client Name" << "| " << setw(25) << "Phone" << "| " << setw(10) << "Balance" << "\n";
		cout << "\t  --------------------------------------------------------------------------------------------------\n\n";
		for (int i = 0; i < clients.size(); i++) {
			clsClient client = clsClient::_ConvertLineToClientObject(clients[i]);
			cout << "\t  | " << left << setw(20) << client.AccountNumber() << "| " << setw(10) << client.PinCode() << "| " << setw(25) << client.Name() << "| " << setw(25) << client.Phone() << "| " << client.Balance() << " $ \n";
		}
		cout << "\t  --------------------------------------------------------------------------------------------------\n\n";
	}
};

