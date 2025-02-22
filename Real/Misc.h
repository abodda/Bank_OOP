#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsClient.h"
using namespace std;
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
 _enMainChoice _ReadMainChoiceFromUser() {

	short choice;
	cout << "\n\n\t\tWhich of these would you like to start with ? (1 : 10) : ";
	cin >> choice;

	while (cin.fail() || choice > 10 || choice < 1) {
		cin.clear();
		cin.ignore(std::numeric_limits< std::streamsize> ::max(), '\n');
		cout << "\n\n\t\tpls enter a valid choice (1 : 10) only \n";
		cin >> choice;
	}
	return _enMainChoice(choice);
}
enum _enTrans { Deposit = 1, WithDrow = 2, ShowMoneyList = 3, MainMenu = 4 };
 _enTrans _ReadTransChoice() {
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
enum _enReadUserChoice {
	UserList = 1,
	Adduser = 2,
	deleteuser = 3,
	updateuser = 4,
	finduser = 5,
	MainMenue = 6
};
_enReadUserChoice ReadChoiceFromManageUserScreen() {
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
string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}
vector<string> Split(string S1, string Delim)
	{

		vector<string> vString;

		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
		}

		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}

		return vString;

	}
string FromVector(vector <string> Words, string delim = " () ") {
		string Sentence = "";
		for (string& s : Words) {
			Sentence += s + delim;
		}
		return Sentence.substr(0, Sentence.length() - delim.length());
	}
void SaveStringToFile(string Line, string name) {
		fstream file;
		file.open(name, ios::out | ios::app);
		if (file.is_open()) {
			if (Line != "") file << "\n" << Line;
			file.close();
		}

	}
string ReadAccountNum() {
	string AccountName;
	cout << "\n\t\t\t Enter account number you want to : ";
	cin >> AccountName;
	return AccountName;
}
string ReadUserName() {
	string UserName;
	cout << "\nEnter User Name you want to : ";
	cin >> UserName;
	return UserName;
}
vector <string> _SaveFileContentToVector(string FileName) {
	vector <string> clients;
	fstream file;
	file.open(FileName, ios::in);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {

			if (line != "") {
				clients.push_back(line);
			}
		}
		file.close();
	}
	return clients;
}

