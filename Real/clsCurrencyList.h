#pragma once
#include "clsScreen.h"
class clsCurrencyListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\tCurrency List Screen");
		cout << "Currency List here";
	}

};

