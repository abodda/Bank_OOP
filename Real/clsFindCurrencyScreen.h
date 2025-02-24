#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include <string>
#include <iomanip>
class clsFindCurrencyScreen : protected clsScreen
{

public:
	static void Print() {
		system("cls");
		clsCurrency Currency = clsCurrency::EmbtyObj();
		Header("\t Find Currency Screen");
		while (true) {
		string CountryNameOrAbbr;
		cout << "\t\t\t\t\tEnter Country name or code : ";
		getline(cin >> ws, CountryNameOrAbbr);
		Currency = clsCurrency::Find(CountryNameOrAbbr);
			if(!Currency.IsEmbty()){
				break;
			}
		cout << "\n\t\t\t\t\tEnter valid Country..\n\n";
		}
		cout <<"\n\t\t\t\t\t"<< left << setw(12) << "Currency Card :\n";
		cout <<"\t\t\t\t\t"<< "----------------------------------\n";
		cout <<"\t\t\t\t\t"<< left << setw(15) << "country name" << ": " << Currency.CountryName() << '\n';
		cout <<"\t\t\t\t\t"<< left << setw(15) << "Code" << ": " << Currency.Code() << '\n';
		cout <<"\t\t\t\t\t"<< left << setw(15) << "Currency name" << ": " << Currency.CurrencyName() << '\n';
		cout <<"\t\t\t\t\t"<< left << setw(15) << "1 dollar" << ": " << Currency.Equal_1_Dollar() << " " << Currency.CurrencyName() + "(s)\n";
		cout <<"\t\t\t\t\t"<< "----------------------------------\n";
	}
};

