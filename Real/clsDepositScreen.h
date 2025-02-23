#pragma once
#include "clsScreen.h"
#include "clsTrans.h"
class clsDepositScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t    Deposit Screen");
		int Deposit;
		clsClient client = clsClient::CheckIfItExist();
		clsTrans trans{ client };
		cout << "\n\t\t\t\t\thow many you want to deposit : ";
		cin >> Deposit;
		trans.SetAdded(Deposit);
		trans.Deposit();
		if (Deposit > 0) printf("\n\t\t\t\t\t%d has been Added successfully to ", Deposit);
		else if (Deposit < 0) printf("\n\t\t\t%d has been WithDrown successfully from ", -Deposit);
		else printf("\n\t\t\t\t\tNothing has been Added to ");
		cout << client.AccountNumber() << " :')\n";
	}
};

