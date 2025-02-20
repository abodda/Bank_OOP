#pragma once
#include "clsScreen.h"
#include "client.h"
class clsResetClass : protected clsScreen
{
public:
	static void Screen() {
		system("cls");
		HeaderName("Reset Client Screen");
		clsClient::Reset();
	}
};

