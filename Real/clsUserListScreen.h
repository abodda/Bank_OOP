#pragma once
#include "clsScreen.h"
class clsUserListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  User List screen");
		cout << "\nUser List User screen here \n";
	}
};

