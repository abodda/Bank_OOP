#pragma once
#include "clsScreen.h"
class clsUpdateClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Update Client Screen");
		clsClient client = clsClient::CheckIfItExist();
		client.Print();
		cout << "\n\t\t\t\t\t      --------- Update ---------\n";
		client.Update();
		cout << "\n\t\t\t\t\t      Client Updated successfully :')\n";
		cout << "\t\t\t\t\t      the new client Data is : \n\n";
		client.Print();
	}
};

