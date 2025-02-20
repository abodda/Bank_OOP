#pragma once
#include "clsScreen.h"
#include "Client.h"
class clsDeleteClient : clsScreen
{
public:
	static void Screen() {
		system("cls");
		HeaderName("Delete Client Screen");
		clsClient FoundClient = clsClient::CheckIfItExist();
		FoundClient.Print();
		char ans;
		cout << "\nAre you sure you want to delete ??? (y,n) : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			FoundClient.Delete();
			cout << "\nClient Deleted successfully :')\n";
		}
	}
};

