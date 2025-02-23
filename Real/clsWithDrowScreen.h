#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "clsTrans.h"
class clsWithDrowScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t    WithDrow Screen");
		int withdrow;
		clsClient client = clsClient::CheckIfItExist();
		while (true) {
			cout << "\n\t\t\t\t\thow many you want to Withdrow : ";
			cin >> withdrow;
			if (withdrow <= stoi(client.Balance())) break;
			if (client.Balance() != "0") cout << "\t\t\t\t\tyou can withdrow up to " << client.Balance() << " only ..\n";
			else
			{
				cout << "\t\t\t\t\taccount has no money :(\n\n";
				return;
			}
		}
		clsTrans trans{ client };
		trans.SetWithdrawen(withdrow);
		trans.Withdrow();
		printf("\n\t\t\t\t\t%d has been WithDrowen successfully from ", withdrow);
		cout << client.AccountNumber() << " :')\n";
	}
};

