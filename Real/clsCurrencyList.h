#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "clsScreen.h"
#include "File.h"
#include "clsCurrency.h"
class clsCurrencyListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\tCurrency List Screen");
		vector <string> Countries = _SaveFileContentToVector("Currencies.txt");
		int CountriesSize = Countries.size();
		printf("\n\n\t\t\t\t\t    Currency List (%d) Client (s).\n", CountriesSize);
		cout << "------------------------------------------------------------------------------------------------------------------------\n";
		cout << "| " << left << setw(30) << "Country Name" << "| " << setw(20) << "Code" << "| " << setw(40) << "Currency Name" << "| " << setw(15) << " Equal 1 Dollar" << "\n";
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
		for (int i = 0; i < CountriesSize; i++) {
			clsCurrency Currency = clsCurrency::_ConvertLineToCurrencyObject(Countries[i]);
			cout << "| " << left << setw(30) << Currency.CountryName() << "| " << setw(20) << Currency.Code() << "| " << setw(40) << Currency.CurrencyName() << "| " << setw(15) << Currency.Equal_1_Dollar() << "\n";
		}
		cout << "------------------------------------------------------------------------------------------------------------------------\n\n";

	}

};

