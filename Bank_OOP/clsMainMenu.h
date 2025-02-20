#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "User.h"
#include "client.h"
#include "Read.h"
#include "clsFindClient.h"
#include "DeleteClient.h"
#include "clsUpdateClient.h"
#include "clsAddClient.h"
#include "clsClientList.h"
#include "clsResetClass.h"
#include "clsMoneyList.h"
#include "TransActions.h"
using namespace std;
clsUser NowUser("", "", "", "", 0);
class clsMainMenu : protected clsScreen {
private:

public:
	static void DisplayMain()
	{
		system("cls");
		PrintDateAndUserName();
		cout << "\n ******************************************************************************* \n";
		cout << "				Main Menue Screen		\n";
		cout << " ******************************************************************************* \n";

		cout << "\n			   (1)  ==> Display Client List.\n";
		cout << "			   (2)  ==> Add New Client.\n";
		cout << "			   (3)  ==> Delete Client.\n";
		cout << "			   (4)  ==> Update Client.\n";
		cout << "			   (5)  ==> Find Client.\n";
		cout << "			   (6)  ==> reset Clients.\n";
		cout << "			   (7)  ==> TransActions.\n";
		cout << "			   (8)  ==> Manage Users.\n";
		cout << "			   (9)  ==> Log out .\n";
		cout << "			   (10) ==> Quit .\n";
	}



	static void MainProgram() {
		DisplayMain();
		switch (clsRead::ReadMainChoiceFromUser()) {
		case clsRead::_enMainChoice::ShowClientLIst:
			if (NowUser.IsAllowed(clsUser::enPermesion::ClientList)) clsClientList::Screen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::adddNewClient:
			if (NowUser.IsAllowed(clsUser::enPermesion::AddClient)) clsAddClient::Screen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::resetClients:
			if (NowUser.IsAllowed(clsUser::enPermesion::resetClients)) clsResetClass::Screen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::deleteClient:
			if (NowUser.IsAllowed(clsUser::enPermesion::DeleteClient)) clsDeleteClient::Screen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::updateClient:
			if (NowUser.IsAllowed(clsUser::enPermesion::UpdateClient)) clsUpdateClient::Screen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::findClient:
			if (NowUser.IsAllowed(clsUser::enPermesion::FindClient)) clsFindClient::Screen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::LogOut:
			Process();
			break;
		case clsRead::_enMainChoice::TransActions:
			if (NowUser.IsAllowed(clsUser::enPermesion::TransActions)) clsTTrans::Screen();
			else
			{
				NotAvailible();
				GoBackToMainMenue();
			}
			break;
		case clsRead::_enMainChoice::MangeUsers:
			if (NowUser.IsAllowed(clsUser::enPermesion::ManageUsers)) ManageUserScreen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::Quit:
			exit(0);
		}
	}
	static void AddUserScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Add User screen\n";
		cout << "------------------------------\n\n";
		clsUser::Add();
		cout << "\nAdded Successfully :') ...";

	}
	static void UpdateUserScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Update User screen\n";
		cout << "------------------------------\n\n";
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
	static void FindUserScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Find Client screen\n";
		cout << "------------------------------\n\n";
		clsUser user = clsUser::CheckUser();
		user.Print();
	}
	static void DeleteUserScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Delete User screen\n";
		cout << "------------------------------\n\n";
		clsUser user = clsUser::CheckUser();
		if (user.Name() == "Admin") {
			cout << "\nyou cant delete Amin sorry :(\n";
			return;
		}
		user.Print();
		char ans;
		cout << "\nAre you sure you want to delete ??? (y,n) : ";
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			user.Delete();
			cout << "\nClient Deleted successfully :')\n";
		}
	}
	static void ManageUserScreen() {
		system("cls");
		cout << "********************************************\n";
		cout << "	Manage Users screen\n";
		cout << "********************************************\n\n";
		cout << "(1) ==> Users List\n";
		cout << "(2) ==> Add new User\n";
		cout << "(3) ==> delete User\n";
		cout << "(4) ==> update User\n";
		cout << "(5) ==> find User\n";
		cout << "(6) ==> Main Menue\n";
		cout << "------------------------------";		
		switch (clsRead::ReadChoiceFromManageUserScreen()) {
		case clsRead::_enReadUserChoice::Adduser:
			AddUserScreen();
			BackToManageScreen();
			break;
		case clsRead::_enReadUserChoice::finduser:
			FindUserScreen();
			BackToManageScreen();
			break;
		case clsRead::_enReadUserChoice::deleteuser:
			DeleteUserScreen();
			BackToManageScreen();
			break;
		case clsRead::_enReadUserChoice::updateuser:
			UpdateUserScreen();
			BackToManageScreen();
			break;
		case clsRead::_enReadUserChoice::MainMenue:
			MainProgram();
			break;
		case clsRead::_enReadUserChoice::UserList:
			clsUser::DisplayUsersList();
			BackToManageScreen();
			break;
		}
	}
	static void Process() {
		while (1) {
			NowUser.LogINScreen();
			MainProgram();
		}
	}

	static void WithDrowScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	WithDrow Screen \n";
		cout << "------------------------------\n\n";
		int withdrow;
		clsClient client = clsClient::CheckIfItExist();
		while (true) {
			cout << "\nhow many you want to Withdrow : ";
			cin >> withdrow;
			if (withdrow < stoi(client.Balance())) break;
			if (client.Balance() != "0") cout << "you can withdrow up to " << client.Balance() << " only ..\n";
			else
			{
				cout << "account has no money :(\n\n";
				return;
			}
		}
		clsTTrans trans{ client };
		trans.SetWithdrawen(withdrow);
		trans.Withdrow();
		printf("\n%d has been WithDrowen successfully from ", withdrow);
		cout << client.AccountNumber() << " :')\n";

	}
	static void GoBackToMainMenue() {
		cout << "\n\npress any key to go to main menu...";
		system("pause>0");
		MainProgram();
	}

	static void NotAvailible() {
		system("cls");
		cout << "|  you can not access this :( |\n";
		cout << "|   pls Contact your Admin    |\n";
	}
	static void BackToManageScreen() {
		cout << "\n\npress any key to go to Manage User menu...";
		system("pause>0");
		clsMainMenu::ManageUserScreen();
	}
};

