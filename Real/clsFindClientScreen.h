#pragma once
#include "clsScreen.h"
#include "clsClient.h"
class clsFindClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Find Client Screen");
		clsClient FoundClient = clsClient::CheckIfItExist();
		FoundClient.Print();
	}
};

