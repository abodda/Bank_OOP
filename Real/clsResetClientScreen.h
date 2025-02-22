#pragma once
#include "clsScreen.h"
class clsResetClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Reset Clients Screen");
		char ans;
		cout << "\t\t\t Are you Sure ?? (y,n) ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			clsClient::Reset();
		}
		cout << "\n\t\t\t Clients Reseted Successfully :')\n";
	}

};

