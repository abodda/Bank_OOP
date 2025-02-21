#pragma once
#include "clsScreen.h"
class clsFindClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Find Client Screen");
		cout << "\nFindClient here\n";
	}
};

