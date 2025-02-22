#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsAddClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Add Client Screen");
		clsClient client = clsClient::Add();
		cout << "\n\t\t\t Client Added Successfully :')\n";
	}
};

