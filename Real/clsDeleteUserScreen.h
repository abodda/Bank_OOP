#pragma once
#include "clsScreen.h"
class clsDeleteUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Delete User screen");
		cout << "\nDelete User screen here \n";
	}
};

