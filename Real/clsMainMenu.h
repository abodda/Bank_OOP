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
class clsMainMenu : protected clsScreen
{
private:

	enum _enReadUserChoice {
		UserList = 1,
		Adduser = 2,
		deleteuser = 3,
		updateuser = 4,
		finduser = 5,
		MainMenue = 6
	};
	static _enReadUserChoice ReadChoiceFromManageUserScreen() {
		_DisplayManageUserScreen();
		short choice;
		cout << "\n (1 : 6) : ";
		cin >> choice;

		while (cin.fail() || choice > 6 || choice < 1) {
			cin.clear();
			cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
			cout << "\npls enter a valid choice (1 : 6) only \n";
			cin >> choice;
		}
		return _enReadUserChoice(choice);
	}
	enum _enTrans { Deposit = 1, WithDrow = 2, ShowMoneyList = 3, MainMenu = 4 };
	enum _enMainChoice {
		ShowClientLIst = 1,
		adddNewClient = 2,
		deleteClient = 3,
		updateClient = 4,
		findClient = 5,
		resetClients = 6,
		TransActions = 7,
		MangeUsers = 8,
		LogOut = 9,
		Quit = 10
	};
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
		cout << "|  you can not access this :( |\n";
		cout << "|   pls Contact your Admin    |\n";
	}
	static void _GoBackToMainMenue() {
		cout << "\n\npress any key to go to main menu...";
		system("pause>0");
		MainProgram();
	}
	static _enMainChoice _ReadMainChoiceFromUser() {
		_DisplayMainScreen();
		short choice;
		cout << "\n\nWhich of these would you like to start with ? (1 : 10) : ";
		cin >> choice;

		while (cin.fail() || choice > 10 || choice < 1) {
			cin.clear();
			cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
			cout << "\npls enter a valid choice (1 : 10) only \n";
			cin >> choice;
		}
		return _enMainChoice(choice);
	}
	static _enTrans _ReadTransChoice() {
		_DisplayTransMenue();
		short choice;
		cout << "\n\n(1 : 4) : ";
		cin >> choice;
		while (cin.fail() || choice > 4 || choice < 1) {
			cin.clear();
			cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
			cout << "\npls enter a valid choice (1 : 4) only \n";
			cin >> choice;
		}
		return _enTrans(choice);
	}
	static void _DisplayTransMenue() {
		system("cls");
		Header("\t TransActions Screen");
		cout << "\n			   (1) ==> Deposit.\n";
		cout << "			   (2) ==> WithDrow.\n";
		cout << "			   (3) ==> Show Money Lists.\n";
		cout << "			   (4) ==> Main Menue.\n";
	}
	static void _GoBackToTrans() {
		cout << "\n\npress any key to go to Trans menu...";
		system("pause>0");
		_clsTransScreen::Print();
	}
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
		_clsManageScreen::Print();
	}
	class _clsTransScreen
	{
	public:
		static void Print() {	
			switch (_ReadTransChoice()) {
			case Deposit:
				clsDepositScreen::Print();
				_GoBackToTrans();
				break;
			case WithDrow:
				clsWithDrowScreen::Print();
				_GoBackToTrans();
				break;
			case MainMenu:
				clsMainMenu::MainProgram();
				break;
			case ShowMoneyList:
				clsMoneyListScreen::Print();
				_GoBackToTrans();
				break;
			}
		}
		

	};
	class _clsManageScreen : protected clsScreen
	{
	public:
		static void Print() {
			system("cls");
			Header("       Manage Users Client Screen");
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
				MainProgram();
				break;
			case UserList:
				clsUserListScreen::Print();
				_BackToManageScreen();
				break;
			}

		}
	};


public:
	static void MainProgram() {
		
		switch (_ReadMainChoiceFromUser()) {
		case ShowClientLIst:
			//if (NowUser.IsAllowed(clsUser::enPermesion::ClientList))
			clsClientListScreen::Print();
				_GoBackToMainMenue();
				break;
		case adddNewClient:
			//if (NowUser.IsAllowed(clsUser::enPermesion::AddClient)) cout << "Scren";
			//else _NotAvailible();
			clsAddClientScreen::Print();
			_GoBackToMainMenue();
			break;
		case resetClients:
			//if (NowUser.IsAllowed(clsUser::enPermesion::resetClients)) cout << "Scren";
			//else _NotAvailible();
			clsResetClientScreen::Print();
			_GoBackToMainMenue();
			break;
		case deleteClient:
			//if (NowUser.IsAllowed(clsUser::enPermesion::DeleteClient)) 
			clsDeleteClientScreen::Print();
			//else _NotAvailible();
			_GoBackToMainMenue();
			break;
		case updateClient:
			//if (NowUser.IsAllowed(clsUser::enPermesion::UpdateClient)) 
			clsUpdateClientScreen::Print();
			//else _NotAvailible();
			_GoBackToMainMenue();
			break;
		case findClient:
			//if (NowUser.IsAllowed(clsUser::enPermesion::FindClient))
			clsFindClientScreen::Print();
			//else _NotAvailible();
			_GoBackToMainMenue();
			break;
		case LogOut:
			//Process();
			break;
		case TransActions:
			//if (NowUser.IsAllowed(clsUser::enPermesion::TransActions)) 
			_clsTransScreen::Print();
			//else
			//{
			//	_NotAvailible();
			//	_GoBackToMainMenue();
			//}
			break;
		case MangeUsers:
			//if (NowUser.IsAllowed(clsUser::enPermesion::ManageUsers))
			_clsManageScreen::Print();
			//else _NotAvailible();
			_GoBackToMainMenue();
			break;
		case Quit:
			exit(0);
		}
		
		
		
		
		
	}
	
	
	


};

