#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "string.h"
#include "Read.h"
using namespace std;
class clsUser : public clsPerson {
private:
	enum enPermesion {
		ClientList = 1,
		AddClient = 2,
		DeleteClient = 4,
		UpdateClient = 8,
		FindClient = 16,
		resetClients = 32,
		TransActions = 64,
		ManageUsers = 128,
	};
	int _Permesion;
	string _Password;
	int _pos = 0;
	static clsUser _ConvertLineToUserObject(string line) {
		vector <string> data = clsString::Split(line, " () ");
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
		return clsString::FromVector(user);
	}
	static clsUser _EmptyObject() {
		return clsUser("", "", "", "", -2);
	}
public:
	clsUser(string Name, string Phone, string Email, string password, int permesion) : 
		clsPerson(Name, Phone, Email) {
		_Permesion = permesion;
		_Password = password;
	}
	static void DisplayUsersList() {
		system("cls");
		vector <string> users = clsClient::_SaveFileContentToVector("users.txt");
		int num = users.size();	
		if (num == 0) {
			cout << left << setw(18) << "------------------------------\n";
			cout << left << setw(18) << "|    there are no Users !    |";
			cout << left << setw(18) << "\n------------------------------\n";
			return;
		}
		printf("\nUsers List (%d) user(s).\n", num);
		cout << "------------------------------------------------------------------\n";
		cout << "| " << left << setw(20) << "User Name" << "| " << setw(10) << "Password" << "| " << setw(25) << "Permeision" << "\n";
		cout << "------------------------------------------------------------------\n\n";
		for (int i = 0; i < num; i++) {
			clsUser User = _ConvertLineToUserObject(users[i]);
			cout << "| " << left << setw(20) << User.Name() << "| " << setw(10) << User.password() << "| " << setw(25) << User.permesion() << "\n";
		}
	}
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
			UserName = clsRead::UserName();
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
		cout << "Enter Phone : ";
		getline(cin >> ws, Phone);
		cout << "Enter Email : ";
		getline(cin >> ws, Email);
		cout << "Enter Password : ";
		getline(cin >> ws, Password);
		char Ans;
		cout << "\nAre you want to make him an Admin ? : ";
		cin >> Ans;
		if (Ans == 'y' || Ans == 'Y') permesion = -1;
		else {
			cout << "\nAccess to Client List ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::ClientList;
			cout << "\nAccess to Add New Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::AddClient;
			cout << "\nAccess to Delete Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::DeleteClient;
			cout << "\nAccess to Update Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::UpdateClient;
			cout << "\nAccess to Find Client ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::FindClient;
			cout << "\nAccess to Reset Clients ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::resetClients;
			cout << "\nAccess to TransActions Clients ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::TransActions;
			cout << "\nAccess to ManageUsers ? : ";
			cin >> Ans;
			if (Ans == 'y' || Ans == 'Y')  permesion += enPermesion::ManageUsers;
		}
		return clsUser(Name, Phone, Email, Password, permesion);
	}
	void Print() {
		cout << "\n---------------------------\n";
		cout << left << setw(18) << "User Name" << ": " << Name() << "\n";
		cout << left << setw(18) << "Password" << ": " << _Password << "\n";
		cout << left << setw(18) << "Email" << ": " << Email() << '\n';
		cout << left << setw(18) << "phone number" << ": " << Phone();
		cout << left << setw(18) << "\npermession" << " : " << _Permesion;
		cout << "\n---------------------------\n";
	}
	void Delete() {
		vector <string> users = clsClient::_SaveFileContentToVector("users.txt");
		users.at(pos()).clear();
		clsClient::_SaveVecToFile(users, "users.txt");
		*this = _EmptyObject();
	}
	static void Add() {
		string UserName;
		clsUser user = clsUser::_EmptyObject();
		while (true) {
			UserName = clsRead::UserName();
			user = Find(UserName);
			if (user.IsEmbty()) break;
			cout << "\nthe User Name exist try again... \n\n";
		}
		user = ReadUser();
		user.SetName(UserName);
		clsClient::_SaveStringToFile(_ConvertUserToLine(user), "users.txt");
	}
	void Update() {
		string UserName = Name();
		vector <string> users = clsClient::_SaveFileContentToVector("users.txt");
		clsUser user = ReadUser();
		user.SetName(UserName);
		users.at(pos()) = _ConvertUserToLine(user);
		*this = user;
		clsClient::_SaveVecToFile(users, "users.txt");
	}
	clsUser LogINScreen() {
		system("cls");
		string username;
		string password;
		cout << "------------------------------\n";
		cout << "	Log in screen\n";
		cout << "------------------------------\n";
		
		while(1){
			cout << "\nenter username : ";
			getline(cin >> ws, username);
			SetName(username);
			cout << "enter Password : ";
			cin >> password;
			*this = Find(Name());
			if (!this->IsEmbty() && this->password() == password) break;
			cout << "Invalid User Name / Password";
		}
		return *this;
	}
	bool IsAllowed(int NumberOfWanted) {
		if (_Permesion == -1) return 1;
		return ((NumberOfWanted & _Permesion) == NumberOfWanted);
	}
	friend class clsMainMenu;
};