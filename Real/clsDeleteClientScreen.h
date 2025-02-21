#pragma once
#include "clsScreen.h"
class clsDeleteClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Delete Client Screen");
		cout << "\nDelete Client here\n";
	}
};

