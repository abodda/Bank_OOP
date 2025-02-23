#pragma once
#include "clsScreen.h"
class clsCurrencyCalcScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\tCurrency Calculator Screen");
		cout << "Currency Calculator here";
	}
};

