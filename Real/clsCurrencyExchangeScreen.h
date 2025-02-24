#pragma once
#include "clsScreen.h"
#include "clsCurrencyList.h"
#include "clsCurrencyCalcScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
class clsCurrencyExchangeScreen : protected clsScreen
{
	static void _Display() {
		system("cls");
		Header("    Currency Exchange Menue Screen");
		cout << "\n\t     			        (1)  ==> List Currencies.\n";
		cout << "\t     			        (2)  ==> Find Currency.\n";
		cout << "\t     			        (3)  ==> Update Currency.\n";
		cout << "\t     			        (4)  ==> Currency Calculator.\n";
		cout << "\t     			        (5)  ==> Main Menue.\n";
	}
	enum _enCurrency {
		CurrencyList = 1,
		FindCurrency = 2,
		UpdateRate = 3,
		CurrencyCalculator = 4,
		MainMenu = 5,
	};
	static _enCurrency _ReadChoice() {
		short choice;
		cout << "\n\n\t\t (1 : 5) : ";
		cin >> choice;

		while (cin.fail() || choice > 5 || choice < 1) {
			cin.clear();
			cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
			cout << "\n\n\t\tpls enter a valid choice (1 : 5) only \n";
			cin >> choice;
		}
		return _enCurrency(choice);
	}
	static void _GoBackToCurrencyScreen() {
		cout << "\n\t\t\tpress any key to back to CurrencyScreen ....";
		system("pause>0");
		Print();
	}
public:
	static void Print() {
		_Display();
		switch (_ReadChoice()) {
		case CurrencyCalculator:
			clsCurrencyCalcScreen::Print();
			_GoBackToCurrencyScreen();
			break;
		case CurrencyList:
			clsCurrencyListScreen::Print();
			_GoBackToCurrencyScreen();
			break;
		case FindCurrency:
			clsFindCurrencyScreen::Print();
			_GoBackToCurrencyScreen();
			break;
		case MainMenu:
			break;
		case UpdateRate:
			clsUpdateRateScreen::Print();
			_GoBackToCurrencyScreen();
			break;
		}
	}
};

