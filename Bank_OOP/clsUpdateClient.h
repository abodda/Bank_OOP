#pragma once
#include "clsScreen.h"
#include "Client.h"
class clsUpdateClient :protected clsScreen
{
public:
	static void Screen() {
		system("cls");
		HeaderName("Update Client screen");
		clsClient client = clsClient::CheckIfItExist();
		client.Print();
		cout << "\n--------- Update ---------\n";
		client.Update();
		cout << "\nClient Updated successfully :')\n";
		cout << "the new client Data is : \n\n";
		client.Print();
	}
};

