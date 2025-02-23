#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsDeleteClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Delete Client Screen");
		clsClient FoundClient = clsClient::CheckIfItExist();
		FoundClient.Print();
		char ans;
		cout << "\n\t\t\t\t\t      CAre you sure you want to delete ??? (y,n) : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			FoundClient.Delete();
			cout << "\n\t\t\t\t\t      CClient Deleted successfully :')\n";
		}
	}
};

