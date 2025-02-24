#pragma warning(disable : 4996)
#pragma once
#include <string>
#include <iostream>
#include "CurrentUser.h"
using namespace std;
class clsScreen
{
	static void DateTime() {
		time_t t = time(0);
		tm* now = localtime(&t);
		printf("%d/%d/%d", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	}
protected:
	static void Header(string title, string subtitle = "") {
		cout << "\n\t\t\t\t\t---------------------------------------\n";
		cout << "\t\t\t\t\t" << title << "\n";
		cout << "\n\t\t\t\t\t";
		cout << "Today Is "; DateTime();
		cout << "\tUser : " << CurrentUser.Name();
		cout << "\n\t\t\t\t\t---------------------------------------\n";
	}
};

