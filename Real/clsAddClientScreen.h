#pragma once
#include "clsScreen.h"
class clsAddClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Add Client Screen");
		cout << "\nAdd Client here\n";
	}
};

