#pragma once
#include "clsScreen.h"
class clsUpdateClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Update Client Screen");
		cout << "\nUpdate Client here\n";
	}
};

