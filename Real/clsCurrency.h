#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "File.h"
#include "String.h"
using namespace std;
class clsCurrency
{
	string _CountryName;
	string _Code;
	string _CurrencyName;
	string _Equal_1_Dollar;
	int _pos = -1;
	static clsCurrency _ConvertLineToCurrencyObject(string line) {
		vector <string> words = Split(line, "#//#");
		return clsCurrency(words[0], words[1], words[2], words[3]);
	}
public:
	static clsCurrency EmbtyObj() {
		return clsCurrency("", "", "", "");
	}
	clsCurrency(string CountryName, string Code, string CurrencyName, string Equal_1_Dollar) {
		_CountryName = CountryName;
		_Code = Code;
		_CurrencyName = CurrencyName;
		_Equal_1_Dollar = Equal_1_Dollar;
	}
	void SetPos(int pos) {
		_pos = pos;
	}
	int pos() {
		return _pos;
	}
	static clsCurrency Find(string CountryName_Or_Abbriviation) {
		int pos = -1;
		vector <string> Countries = _SaveFileContentToVector("Currencies.txt");
		for (string line : Countries) {
			pos += 1;
			clsCurrency CurrencyObj = _ConvertLineToCurrencyObject(line);
			if ((CurrencyObj.Code() == CountryName_Or_Abbriviation)) {
				CurrencyObj.SetPos(pos);
				return CurrencyObj;
			}
			if (CurrencyObj.CountryName() == CountryName_Or_Abbriviation) {
				CurrencyObj.SetPos(pos);
				return CurrencyObj;
			}
		}
		return EmbtyObj();
	}	
	void SetEqual_1_Dollar(string Equal_1_Dollar) {
		_Equal_1_Dollar = Equal_1_Dollar;

	}
	string Equal_1_Dollar() {
		return _Equal_1_Dollar;
	}
	string Code() {
		return _Code;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	string CountryName() {
		return _CountryName;
	}
	bool IsEmbty() {
		return (_CurrencyName == "");
	}
	static double Convert(clsCurrency Currency1, clsCurrency Currency2) {
		return ((stod(Currency2.Equal_1_Dollar()))) / stod(Currency1.Equal_1_Dollar());
	}
	friend class clsCurrencyListScreen;

};

