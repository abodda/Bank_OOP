#pragma once
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddClientScreen.h"
#include "clsResetClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDrowScreen.h"
#include "clsMoneyListScreen.h"
#include "clsAddUserScreen.h"
#include "clsFindUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsUserListScreen.h"
#include "clsTransScreen.h"
#include "clsManageUserScreen.h"
#include "Misc.h"
clsUser CurrentUser = clsUser::_EmptyObject();
class clsMainMenu : protected clsScreen
{
private:
	static void _DisplayMainScreen()
	{
		system("cls");
		Header("\t  Main Menue Screen");

		cout << "\n\t     			        (1)  ==> Display Client List.\n";
		cout << "\t     			        (2)  ==> Add New Client.\n";
		cout << "\t     			        (3)  ==> Delete Client.\n";
		cout << "\t     			        (4)  ==> Update Client.\n";
		cout << "\t     			        (5)  ==> Find Client.\n";
		cout << "\t     			        (6)  ==> reset Clients.\n";
		cout << "\t     			        (7)  ==> TransActions.\n";
		cout << "\t     			        (8)  ==> Manage Users.\n";
		cout << "\t     			        (9)  ==> Log out .\n";
		cout << "\t     			        (10) ==> Quit .\n";
		cout << "\t\t\t\t\t---------------------------------------\n";
	}
	static void _NotAvailible() {
		system("cls");
		cout << "\n\t\t\t\t\t   |  you can not access this :( |";
		cout << "\n\t\t\t\t\t   |   pls Contact your Admin    |";
	}
	static void _GoBackToMainMenue() {
		cout << "\n\n\t\t\t\t\t  press any key to go to main menu...";
		system("pause>0");
		_MainProgram();
	}
	static void _MainProgram() {
		_DisplayMainScreen();
		switch (_ReadMainChoiceFromUser()) {
			case ShowClientLIst:
				if (CurrentUser.IsAllowed(enPermesion::eClientList)) clsClientListScreen::Print();
				else _NotAvailible();
				_GoBackToMainMenue();
					break;
			case adddNewClient:
				if (CurrentUser.IsAllowed(enPermesion::eAddClient)) clsAddClientScreen::Print();
				else _NotAvailible();
				_GoBackToMainMenue();
				break;
			case resetClients:
				if (CurrentUser.IsAllowed(enPermesion::eresetClients)) clsResetClientScreen::Print();
				else _NotAvailible();
				_GoBackToMainMenue();
				break;
			case deleteClient:
				if (CurrentUser.IsAllowed(enPermesion::eDeleteClient)) clsDeleteClientScreen::Print();
				else _NotAvailible();
				_GoBackToMainMenue();
				break;
			case updateClient:
				if (CurrentUser.IsAllowed(enPermesion::eUpdateClient)) clsUpdateClientScreen::Print();
				else _NotAvailible();
				_GoBackToMainMenue();
				break;
			case findClient:
				if (CurrentUser.IsAllowed(enPermesion::eFindClient)) clsFindClientScreen::Print();
				else _NotAvailible();
				_GoBackToMainMenue();
				break;
			case LogOut:
				break;
			case TransActions:
				if (CurrentUser.IsAllowed(enPermesion::eTransActions)) 
				{
					clsTransScreen::Print();
					_MainProgram();
				}
				else 
				{
					_NotAvailible();
					_GoBackToMainMenue();
				}
				break;
			case MangeUsers:
				if (CurrentUser.IsAllowed(enPermesion::eManageUsers))
				{
					clsManageScreen::Print();
					_MainProgram();
				}
				else
				{
					_NotAvailible();
					_GoBackToMainMenue();
				}
				break;
			case Quit:
				exit(0);
			}

	}
public:
	static void LogIN() {
		system("cls");
		Header("\t Log in screen");
		string username;
		string password;
		for (int i = 1; i <= 3; i++) {
			cout << "\n\t\t\t enter username : ";
			getline(cin >> ws, username);
			cout << "\t\t\t enter Password : ";
			cin >> password;
			CurrentUser = clsUser::Find(username);
			if (!CurrentUser.IsEmbty() && CurrentUser.password() == password) break;
			cout << "\t\t\t Invalid User Name / Password remaining " << 3 - i << " time(s) to log in \n";
			if (i == 3) exit(0);
		}
		_MainProgram();
	}
	


};
