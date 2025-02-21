#pragma once
#include "clsScreen.h"
class clsMoneyListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t    Money List Screen");
		cout << "\nMoney List Screen\n";
	}
};

