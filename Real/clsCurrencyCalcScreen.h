#pragma once
#include "clsScreen.h"
#include <string>
#include "clsCurrency.h"
class clsCurrencyCalcScreen : protected clsScreen
{
	static string _ReadString(string message) {
		string String;
		cout << message;
		cin >> String;
		return String;
	}
public:
	static void Print() {
		int Amount;
		system("cls");
		Header("\tCurrency Calculator Screen");
		string From = _ReadString("Enter Country Currency to Connvert : ");
		string To = _ReadString("Convert To ? : ");
		cout << "Enter Amount to Exchange : ";
		cin >> Amount;
		clsCurrency Currency1 = clsCurrency::Find(From);
		clsCurrency Currency2 = clsCurrency::Find(To);
		cout << Amount << " " << Currency1.Code() << " = " << clsCurrency::Convert(Currency1, Currency2) * Amount << " " << Currency2.Code();
	}
};

