#pragma once
#include "clsScreen.h"
class clsDepositScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t    Deposit Screen");
		cout << "\nDeposit Screen\n";
	}
};

