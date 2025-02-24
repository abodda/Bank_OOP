#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "string.h"
#include "clsClient.h"
#include "Misc.h"
using namespace std;
class clsUser : public clsPerson {
private:

	int _Permesion;
	string _Password;
	int _pos = 0;
	static clsUser _ConvertLineToUserObject(string line) {
		vector <string> data = Split(line, " () ");
		clsUser User(data[0], data[1], data[2], data[3], stoi(data[4]));
		return User;
	}
	static string _ConvertUserToLine(clsUser User) {
		vector <string> user;
		user.push_back(User.Name());
		user.push_back(User.Phone());
		user.push_back(User.Email());
		user.push_back(User.password());
		user.push_back(to_string(User.permesion()));
		return FromVector(user);
	}
public:
	static clsUser _EmptyObject() {
		return clsUser("", "", "", "", -2);
	}
	clsUser(string Name, string Phone, string Email, string password, int permesion) :
		clsPerson(Name, Phone, Email) {
		_Permesion = permesion;
		_Password = password;
	}
	//static void DisplayUsersList() {
	//	system("cls");
	//	vector <string> users = clsClient::_SaveFileContentToVector("users.txt");
	//	int num = users.size();	
	//	if (num == 0) {
	//		cout << left << setw(18) << "------------------------------\n";
	//		cout << left << setw(18) << "|    there are no Users !    |";
	//		cout << left << setw(18) << "\n------------------------------\n";
	//		return;
	//	}
	//	printf("\nUsers List (%d) user(s).\n", num);
	//	cout << "------------------------------------------------------------------\n";
	//	cout << "| " << left << setw(20) << "User Name" << "| " << setw(10) << "Password" << "| " << setw(25) << "Permeision" << "\n";
	//	cout << "------------------------------------------------------------------\n\n";
	//	for (int i = 0; i < num; i++) {
	//		clsUser User = _ConvertLineToUserObject(users[i]);
	//		cout << "| " << left << setw(20) << User.Name() << "| " << setw(10) << User.password() << "| " << setw(25) << User.permesion() << "\n";
	//	}
	//}
	bool IsEmbty() {
		return (_Password == "");
	}
	static clsUser Find(string Name) {
		fstream file;
		int pos = -1;
		file.open("users.txt", ios::in);
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				if (line != "") {
					pos += 1;
					clsUser User = _ConvertLineToUserObject(line);
					if (User.Name() == Name)
					{
						file.close();
						User.SetUserPos(pos);
						return User;
					}
				}
			}
			file.close();
		}
		return _EmptyObject();
	}
	static clsUser CheckUser() {
		string UserName;
		clsUser user = clsUser::_EmptyObject();
		while (true) {
			UserName = ReadUserName();
			user = clsUser::Find(UserName);
			if (!user.IsEmbty()) break;
			cout << "\nthe User Name does not exist try again... \n\n";
		}
		return user;
	}
	void SetPass(string password) {
		_Password = password;
	}
	void Setper(int permesion) {
		_Permesion = permesion;
	}
	string password() {
		return _Password;
	}
	int permesion() {
		return _Permesion;
	}
	void SetUserPos(int pos) {
		_pos = pos;
	}
	int pos() {
		return _pos;
	}
	static clsUser ReadUser() {
		string Name = "";
		string Phone;
		string Email;
		string Password;
		int permesion = 0;
		cout << "\t\t\tEnter Phone : ";
		getline(cin >> ws, Phone);
		cout << "\t\t\tEnter Email : ";
		getline(cin >> ws, Email);
		cout << "\t\t\tEnter Password : ";
		getline(cin >> ws, Password);
		char Ans;
		cout << "\n\t\t\tAre you want to make him an Admin ? : ";
		cin >> Ans;
		if (Ans == 'y' || Ans == 'Y') permesion = -1;
		else {
			cout << "\n\t\t\tAccess to Client List ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eClientList;
			cout << "\n\t\t\tAccess to Add New Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eAddClient;
			cout << "\n\t\t\tAccess to Delete Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eDeleteClient;
			cout << "\n\t\t\tAccess to Update Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eUpdateClient;
			cout << "\n\t\t\tAccess to Find Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eFindClient;
			cout << "\n\t\t\tAccess to Reset Clients ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eresetClients;
			cout << "\n\t\t\tAccess to TransActions Clients ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eTransActions;
			cout << "\n\t\t\tAccess to ManageUsers ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::eManageUsers;
		}
		return clsUser(Name, Phone, Email, Password, permesion);
	}
	void Print() {
		cout << "\n\t\t\t\t\t      ---------------------------\n";
		cout << "\t\t\t\t\t\t" << left << setw(18) << "User Name" << ": " << Name() << "\n";
		cout << "\t\t\t\t\t\t" << left << setw(18) << "Password" << ": " << _Password << "\n";
		cout << "\t\t\t\t\t\t" << left << setw(18) << "Email" << ": " << Email() << '\n';
		cout << "\t\t\t\t\t\t" << left << setw(18) << "phone number" << ": " << Phone();
		cout << "\n\t\t\t\t\t\t" << left << setw(18) << "permession" << ": " << _Permesion;
		cout << "\n\t\t\t\t\t      ---------------------------\n";
	}
	void Delete() {
		vector <string> users = _SaveFileContentToVector("users.txt");
		users.at(pos()).clear();
		clsClient::_SaveVecToFile(users, "users.txt");
		*this = _EmptyObject();
	}
	static void Add() {
		string UserName;
		clsUser user = clsUser::_EmptyObject();
		while (true) {
			UserName = ReadUserName();
			user = Find(UserName);
			if (user.IsEmbty()) break;
			cout << "\n\t\t\tthe User Name exist try again... \n\n";
		}
		user = ReadUser();
		user.SetName(UserName);
		clsClient::_SaveStringToFile(_ConvertUserToLine(user), "users.txt");
	}
	void Update() {
		string UserName = Name();
		vector <string> users = _SaveFileContentToVector("users.txt");
		clsUser user = ReadUser();
		user.SetName(UserName);
		users.at(pos()) = _ConvertUserToLine(user);
		*this = user;
		clsClient::_SaveVecToFile(users, "users.txt");
	}

	bool IsAllowed(int NumberOfWanted) {
		if (_Permesion == -1) return 1;
		return ((NumberOfWanted & _Permesion) == NumberOfWanted);
	}
	friend class clsMainScreeen;
	friend class clsUserListScreen;
};
