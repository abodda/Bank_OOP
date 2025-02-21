#pragma once
#include "clsScreen.h"
class clsClientListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Client List screen");
		cout << "\nClient List screen here \n";
	}
};

