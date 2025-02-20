#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "User.h"
#include "client.h"
#include "Read.h"
#include "TransActions.h"
#include "clsFindClient.h"
#include "DeleteClient.h"
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
	static void UpdateClientScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Update Client screen\n";
		cout << "------------------------------\n\n";
		clsClient client = clsClient::CheckIfItExist();
		client.Print();
		cout << "\n--------- Update ---------\n";
		client.Update();
		cout << "\nClient Updated successfully :')\n";
		cout << "the new client Data is : \n\n";
		client.Print();
	}
	static void AddClientScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Add Client screen\n";
		cout << "------------------------------\n";
		clsClient client = clsClient::Add();
		cout << "\nClient Added Successfully :')\n";
	}
	static void DisplayClientListScreen() {
		clsClient::DisplayList();
	}
	static void ResetClientsScreen() {
		system("cls");
		HeaderName("Reset Client Screen");
		clsClient::Reset();
	}
	static void ShowMoneyListScreen() {
		system("cls");
		clsClient::ShowMoneyList();
	}
	static void TransScreen() {
		system("cls");
		cout << "\n ******************************************************************************* \n";
		cout << "			   Transactions Menue Screen		\n";
		cout << " ******************************************************************************* \n";

		cout << "\n			   (1) ==> Deposit.\n";
		cout << "			   (2) ==> WithDrow.\n";
		cout << "			   (3) ==> Show Money Lists.\n";
		cout << "			   (4) ==> Main Menue.\n";
		switch (clsRead::ReadTransChoice()) {
		case clsRead::_enTrans::Deposit:
			DepositScreen();
			GoBackToTrans();
			break;
		case clsRead::_enTrans::WithDrow:
			WithDrowScreen();

			GoBackToTrans();
			break;
		case clsRead::_enTrans::MainMenu:
			MainProgram();
			GoBackToTrans();
			break;
		case clsRead::_enTrans::ShowMoneyList:
			ShowMoneyListScreen();
			GoBackToTrans();
			break;
		}
	}
	static void MainProgram() {
		DisplayMain();
		switch (clsRead::ReadMainChoiceFromUser()) {
		case clsRead::_enMainChoice::ShowClientLIst:
			if (NowUser.IsAllowed(clsUser::enPermesion::ClientList)) DisplayClientListScreen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::adddNewClient:
			if (NowUser.IsAllowed(clsUser::enPermesion::AddClient)) AddClientScreen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::resetClients:
			if (NowUser.IsAllowed(clsUser::enPermesion::resetClients)) ResetClientsScreen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::deleteClient:
			if (NowUser.IsAllowed(clsUser::enPermesion::DeleteClient)) clsDeleteClient::Screen();
			else NotAvailible();
			GoBackToMainMenue();
			break;
		case clsRead::_enMainChoice::updateClient:
			if (NowUser.IsAllowed(clsUser::enPermesion::UpdateClient)) UpdateClientScreen();
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
			if (NowUser.IsAllowed(clsUser::enPermesion::TransActions)) TransScreen();
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
	static void DepositScreen() {
		system("cls");
		cout << "------------------------------\n";
		cout << "	Deposit Screen \n";
		cout << "------------------------------\n\n";
		int Deposit;
		clsClient client = clsClient::CheckIfItExist();
		clsTrans trans{ client };
		cout << "\nhow many you want to deposit : ";
		cin >> Deposit;
		trans.SetAdded(Deposit);
		trans.Deposit();
		if (Deposit > 0) printf("\n%d has been Added successfully to ", Deposit);
		else if (Deposit < 0) printf("\n%d has been WithDrown successfully from ", -Deposit);
		else printf("\nNothing has been Added to ");
		cout << client.AccountNumber() << " :')\n";
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
		clsTrans trans{ client };
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
	static void GoBackToTrans() {
		cout << "\n\npress any key to go to Trans menu...";
		TransScreen();
		system("pause>0");
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

