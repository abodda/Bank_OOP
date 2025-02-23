#pragma once
#include "clsScreen.h"
class clsFindCurrencyScreen : protected clsScreen
{public:
	static void Print() {
		system("cls");
		Header("\t Find Currency Screen");
		cout << "Find Currency here";
	}
};

