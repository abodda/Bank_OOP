#pragma once
#include "Client.h"
#include "clsScreen.h"

class clsFindClient : protected clsScreen
{
public:
	static void Screen(){
		system("cls");
		HeaderName("Find Client Screen");
		clsClient FoundClient = clsClient::CheckIfItExist();
		FoundClient.Print();
	}
};

