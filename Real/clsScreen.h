#pragma warning(disable : 4996)
#pragma once
#include <string>
#include <iostream>
using namespace std;
class clsScreen
{
	static void DateTime() {
		time_t t = time(0);
		tm* now = localtime(&t);
		printf("%d/%d/%d", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	}
protected:
	//\t\t\t\t\t\t      Aboda
	static void Header(string title, string subtitle = "") {
		cout << "\n\t\t\t\t\t---------------------------------------\n";
		cout << "\t\t\t\t\t" << title << "\n";
		cout << "\n\t\t\t\t\t";
		cout << "Today Is "; DateTime();
		cout << "\tUser : " /*<< NowUser.Name()*/;
		cout << "\n\t\t\t\t\t---------------------------------------\n";
	}
};

