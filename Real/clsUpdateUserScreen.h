#pragma once
#include "clsScreen.h"
class clsUpdateUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Update User screen");
		cout << "\nUpdate User screen here \n";
	}
};

