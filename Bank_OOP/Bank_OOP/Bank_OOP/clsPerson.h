#pragma once
#include <iostream>
#include <string>
#include "Client.h"
using namespace std;
class clsPerson {
private:
	string _Name;
	string _Phone;
	string _Email;
public:
	clsPerson(string Name, string Phone, string Email) {
		_Name = Name;
		_Phone = Phone;
		_Email = Email;
	}
	void SetName(string FirstName) {
		_Name = FirstName;
	}
	void SetPhone(string Phone) {
		_Phone = Phone;
	}
	void SetEmail(string Email) {
		_Email = Email;
	}
	string Name() {
		return _Name;
	}
	string Phone() {
		return _Phone;
	}
	string Email() {
		return _Email;
	}
	friend class clsClient;
};