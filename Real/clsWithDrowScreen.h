#pragma once
#include "clsScreen.h"
class clsWithDrowScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t    WithDrow Screen");
		cout << "\nWithDrow Screen\n";
	}
};

