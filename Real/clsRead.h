#pragma once
#include <iostream>
#include <string>
#include "clsClient.h"
class clsRead
{
public:

	static string AccountNum() {
		string AccountName;
		cout << "\n\t\t\t\t      Enter account number you want to : ";
		cin >> AccountName;
		return AccountName;
	}
	static string UserName() {
		string UserName;
		cout << "\n\t\t\tEnter User Name you want to : ";
		cin >> UserName;
		return UserName;
	}
};

