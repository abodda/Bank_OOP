#pragma once
#include "clsScreen.h"
class clsFindUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Find User screen");
		clsUser user = clsUser::CheckUser();
		user.Print();
	}
};

