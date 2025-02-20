#pragma once
#include "clsScreen.h"
#include "client.h"
class clsAddClient : protected clsScreen
{
public:
	static void Screen() {
		HeaderName("Add Client screen");
		clsClient client = clsClient::Add();
		cout << "\nClient Added Successfully :')\n";
	}
};

