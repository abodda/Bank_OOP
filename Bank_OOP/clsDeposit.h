#pragma once
#include "clsScreen.h"
#include "client.h"
#include "TransActions.h"
class clsDeposit : protected clsScreen
{
public:
	static void DepositScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Deposit Screen \n";
		cout << "------------------------------\n\n";
		int Deposit;
		clsClient client = clsClient::CheckIfItExist();
		clsTTrans trans{ client };
		cout << "\nhow many you want to deposit : ";
		cin >> Deposit;
		trans.SetAdded(Deposit);
		trans.Deposit();
		if (Deposit > 0) printf("\n%d has been Added successfully to ", Deposit);
		else if (Deposit < 0) printf("\n%d has been WithDrown successfully from ", -Deposit);
		else printf("\nNothing has been Added to ");
		cout << client.AccountNumber() << " :')\n";
	}
};

