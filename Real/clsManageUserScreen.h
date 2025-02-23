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
	enum _enReadUserChoice {
		UserList = 1,
		Adduser = 2,
		deleteuser = 3,
		updateuser = 4,
		finduser = 5,
		MainMenue = 6
	};
	static _enReadUserChoice _ReadChoiceFromManageUserScreen() {
		short choice;
		cout << "\n\t\t\t\t\t(1 : 6) : ";
		cin >> choice;

		while (cin.fail() || choice > 6 || choice < 1) {
			cin.clear();
			cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
			cout << "\npls enter a valid choice (1 : 6) only \n";
			cin >> choice;
		}
		return _enReadUserChoice(choice);
	}

public:
	static void Print() {
		_DisplayManageUserScreen();
		switch (_ReadChoiceFromManageUserScreen()) {
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


