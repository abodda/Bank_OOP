#pragma once
#include "clsScreen.h"
#include "Misc.h"
#include "clsAddUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsUserListScreen.h"
class clsManageScreen : protected clsScreen
{
	static void _DisplayManageUserScreen() {
		system("cls");
		Header("\t Manage Users Screen");
		cout << "\n\t\t\t\t\t(1) ==> Users List\n";
		cout << "\t\t\t\t\t(2) ==> Add new User\n";
		cout << "\t\t\t\t\t(3) ==> delete User\n";
		cout << "\t\t\t\t\t(4) ==> update User\n";
		cout << "\t\t\t\t\t(5) ==> find User\n";
		cout << "\t\t\t\t\t(6) ==> Main Menue\n";
		cout << "\t\t\t\t\t---------------------------------------\n";
	}
	static void _BackToManageScreen() {
		cout << "\n\npress any key to go to Manage User menu...";
		system("pause>0");
		clsManageScreen::Print();
	}

public:
	static void Print() {
		_DisplayManageUserScreen();
		switch (ReadChoiceFromManageUserScreen()) {
		case Adduser:
			clsAddUserScreen::Print();
			_BackToManageScreen();
			break;
		case finduser:
			clsFindUserScreen::Print();
			_BackToManageScreen();
			break;
		case deleteuser:
			clsDeleteUserScreen::Print();
			_BackToManageScreen();
			break;
		case updateuser:
			clsUpdateUserScreen::Print();
			_BackToManageScreen();
			break;
		case MainMenue:
			break;
		case UserList:
			clsUserListScreen::Print();
			_BackToManageScreen();
			break;
		}

	}
};


