#pragma once
#include "clsScreen.h"
class clsUpdateRateScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t Update Rate Screen");
		cout << "Update Rate here";
	}
};

