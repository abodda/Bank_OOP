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
class clsTrans {
private:
	long long _Added = 0;
	long long _Withdrawen = 0;
	int _pos = 0;
	clsClient _client{0, "", "", "", "", "", ""};
public:
	clsTrans(clsClient client) {
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

};