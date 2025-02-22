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
#include "Misc.h"
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
		cout << "|  you can not access this :( |\n";
		cout << "|   pls Contact your Admin    |\n";
	}
	static void _GoBackToMainMenue() {
		cout << "\n\n\t\t\t\t\t  press any key to go to main menu...";
		system("pause>0");
		MainProgram();
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
			_DisplayTransMenue();
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
			_DisplayManageUserScreen();
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
		_DisplayMainScreen();
		switch (_ReadMainChoiceFromUser()) {
			case ShowClientLIst:
				clsClientListScreen::Print();
				_GoBackToMainMenue();
					break;
			case adddNewClient:
				clsAddClientScreen::Print();
				_GoBackToMainMenue();
				break;
			case resetClients:
				clsResetClientScreen::Print();
				_GoBackToMainMenue();
				break;
			case deleteClient:
				clsDeleteClientScreen::Print();
				_GoBackToMainMenue();
				break;
			case updateClient:
				clsUpdateClientScreen::Print();
				_GoBackToMainMenue();
				break;
			case findClient:
				clsFindClientScreen::Print();
				_GoBackToMainMenue();
				break;
			case LogOut:
				break;
			case TransActions:
				_clsTransScreen::Print();
				break;
			case MangeUsers:
				_clsManageScreen::Print();
				_GoBackToMainMenue();
				break;
			case Quit:
				exit(0);
			}

	}
	
	
	


};
