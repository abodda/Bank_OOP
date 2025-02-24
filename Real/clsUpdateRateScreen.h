#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "String.h"
class clsUpdateRateScreen : protected clsScreen
{
	static string _ConvertCurrencyObjToLine(clsCurrency Currency) {
		vector <string> parts;
		parts.push_back(Currency.CountryName());
		parts.push_back(Currency.Code());
		parts.push_back(Currency.CurrencyName());
		parts.push_back(Currency.Equal_1_Dollar());
		return JoinString(parts, "#//#");
	}
public:
	static void Print() {
		system("cls");
		Header("\t Update Rate Screen");
		vector <string> Countries = _SaveFileContentToVector("Currencies.txt");
		clsCurrency Currency = clsCurrency::EmbtyObj();
		string equal_1_dollar;
		while (true) {
			string CountryNameOrAbbr;
			cout << "\t\t\t\t\tEnter Country name or code : ";
			getline(cin >> ws, CountryNameOrAbbr);
			Currency = clsCurrency::Find(CountryNameOrAbbr);
			if (!Currency.IsEmbty()) {
				break;
			}
			cout << "\n\t\t\t\t\tEnter valid Country..\n\n";
		}
		cout << "\n\t\t\t\t\t" << left << setw(12) << "Currency Card :\n";
		cout << "\t\t\t\t\t" << "----------------------------------\n";
		cout << "\t\t\t\t\t" << left << setw(15) << "country name" << ": " << Currency.CountryName() << '\n';
		cout << "\t\t\t\t\t" << left << setw(15) << "Code" << ": " << Currency.Code() << '\n';
		cout << "\t\t\t\t\t" << left << setw(15) << "Currency name" << ": " << Currency.CurrencyName() << '\n';
		cout << "\t\t\t\t\t" << left << setw(15) << "1 dollar" << ": " << Currency.Equal_1_Dollar() << " " << Currency.CurrencyName() + "(s)\n";
		cout << "\t\t\t\t\t" << "----------------------------------\n";
		cout << "\n\t\t\t\t\tEnter the new 1_dollar_equal : ";
		cin >> equal_1_dollar;
		Currency.SetEqual_1_Dollar(equal_1_dollar);
		Countries[Currency.pos()] = _ConvertCurrencyObjToLine(Currency);
		SaveVectorToFile(Countries, "Currencies.txt");
		cout << "\n\t\t\t\t\tUpdated Succesfully:')\n";
	}
};

