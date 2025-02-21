#pragma once
#include "clsScreen.h"
class clsAddUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Add User screen");
		cout << "\nAdd User screen here \n";
	}
};

