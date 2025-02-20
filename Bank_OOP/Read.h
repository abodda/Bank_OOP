#pragma once
#include "clsMainMenu.h"
#include "TransActions.h"

using namespace std;

class clsRead {
	static enum _enMainChoice {
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
	enum _enTrans { Deposit = 1, WithDrow = 2, ShowMoneyList = 3, MainMenu = 4 };
	enum _enReadUserChoice {
		UserList = 1,
		Adduser = 2,
		deleteuser = 3,
		updateuser = 4,
		finduser = 5,
		MainMenue = 6
	};
public:
	static _enReadUserChoice ReadChoiceFromManageUserScreen() {
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
    static string AccountNum() {
        string AccountName;
        cout << "\nEnter account number you want to : ";
        cin >> AccountName;
        return AccountName;
    }
    static string UserName() {
        string UserName;
        cout << "\nEnter User Name you want to : ";
        cin >> UserName;
        return UserName;
    }
	static _enMainChoice ReadMainChoiceFromUser() {
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
	static _enTrans ReadTransChoice() {
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
	friend class clsMainMenu;
	friend class clsTTrans;

};