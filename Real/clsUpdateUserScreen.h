#pragma once
#include "clsScreen.h"
class clsUpdateUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Update User screen");
		clsUser user = clsUser::CheckUser();
		user.Print();
		char ans;
		cout << "\nAre you sure you want to Update ??? (y,n) : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			user.Update();
			cout << "\nUpdated Successfully :') ...";
		}
	}
};

