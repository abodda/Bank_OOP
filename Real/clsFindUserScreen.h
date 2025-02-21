#pragma once
#include "clsScreen.h"
class clsFindUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Find User screen");
		cout << "\nFind User screen here \n";
	}
};

