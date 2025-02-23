#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class clsAddUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Add User screen");
		clsUser::Add();
		cout << "\nAdded Successfully :') ...";
	}
};

