#pragma once
#include "clsDepositScreen.h"
#include "clsWithDrowScreen.h"
#include "clsMoneyListScreen.h"
#include "clsScreen.h"
#include <iostream>
#include "Misc.h"
class clsTransScreen : protected clsScreen
{
	static void _DisplayTransMenue() {
		system("cls");
		Header("\t TransActions Screen");
		cout << "\n						(1) ==> Deposit.\n";
		cout << "						(2) ==> WithDrow.\n";
		cout << "						(3) ==> Show Money Lists.\n";
		cout << "						(4) ==> Main Menue.\n";
	}
	static void _GoBackToTrans() {
		cout << "\n\npress any key to go to Trans menu...";
		system("pause>0");
		clsTransScreen::Print();
	}

public:
	static void Print() {
		_DisplayTransMenue();
		switch (_ReadTransChoice()) {
		case Deposit:
			clsDepositScreen::Print();
			_GoBackToTrans();
			break;
		case WithDrow:
			clsWithDrowScreen::Print();
			_GoBackToTrans();
			break;
		case MainMenu:
			break;
		case ShowMoneyList:
			clsMoneyListScreen::Print();
			_GoBackToTrans();
			break;
		}
	}
};