#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "string.h"
#include "Read.h"
#include "client.h"
#include "clsScreen.h"
#include "clsMainMenu.h"
class clsTTrans : protected clsScreen {
private:
	long long _Added = 0;
	long long _Withdrawen = 0;
	int _pos = 0;
	clsClient _client{0, "", "", "", "", "", ""};
	static void _GoBackToTrans() {
		cout << "\n\npress any key to go to Trans menu...";
		system("pause>0");
		Screen();
	}
public:
	clsTTrans(clsClient client) {
		_client = client;
	}
	clsClient client() {
		return _client;
	}
	void SetAdded(int Added) {
		_Added = Added;
	}
	void SetWithdrawen(int Withdrawen) {
		_Withdrawen = Withdrawen;
	}
	int Added() {
		return _Added;
	}
	int WithDrown() {
		return _Withdrawen;
	}
	int ClientPos() {
		return _pos;
	}
	void Deposit() {
		_client.SetBalance(to_string(stoi(_client.Balance()) + _Added));
		_pos = _client.ClientPos();
		SaveChanges();
	}
	void Withdrow() {
		_client.SetBalance(to_string(stoi(_client.Balance()) - _Withdrawen));
		_pos = _client.ClientPos();
		SaveChanges();
	}
	void SaveChanges() {
		vector <string> clients;
		vector <string> EditedClient;
		EditedClient.push_back(_client.Name());
		EditedClient.push_back(_client.Phone());
		EditedClient.push_back(_client.Email());
		EditedClient.push_back(_client.AccountNumber());
		EditedClient.push_back(_client.PinCode());
		EditedClient.push_back(_client.Balance());
		clients = _client._SaveFileContentToVector("clients.txt");
		clients[_pos] = clsClient::_ConvertClientObjectToLine(_client);
		clsClient::_SaveVecToFile(clients, "clients.txt");
	}
	static void Screen() {
		system("cls");
		HeaderName("");
		cout << "\n ******************************************************************************* \n";
		cout << "			   Transactions Menue Screen		\n";
		cout << " ******************************************************************************* \n";

		cout << "\n			   (1) ==> Deposit.\n";
		cout << "			   (2) ==> WithDrow.\n";
		cout << "			   (3) ==> Show Money Lists.\n";
		cout << "			   (4) ==> Main Menue.\n";
		switch (clsRead::ReadTransChoice()) {
		case clsRead::_enTrans::Deposit:
			//DepositScreen();
			_GoBackToTrans();
			break;
		case clsRead::_enTrans::WithDrow:
			//WithDrowScreen();
			_GoBackToTrans();
			break;
		case clsRead::_enTrans::MainMenu:
			clsMainMenu::MainProgram();
			break;
		case clsRead::_enTrans::ShowMoneyList:
			//clsMoneyList::Screen();
			_GoBackToTrans();
			break;
		}
	}

};