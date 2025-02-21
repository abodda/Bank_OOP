#pragma once
#include "clsScreen.h"
class clsResetClientScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Reset Client Screen");
		cout << "\nReset Client here\n";
	}

};

