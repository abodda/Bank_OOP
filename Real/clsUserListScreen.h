#pragma once
#include "clsScreen.h"
#include "clsClient.h"
#include "Misc.h"
class clsUserListScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  User List screen");
			vector <string> users = _SaveFileContentToVector("users.txt");
			int num = users.size();
			if (num == 0) {
				cout << left << setw(18) << "\t\t\t\t\t    ------------------------------\n";
				cout << left << setw(18) << "\t\t\t\t\t    |    there are no Users !    |";
				cout << left << setw(18) << "\n\t\t\t\t\t    ------------------------------\n";
				return;
			}
			printf("\n\n\t\t\t\t\t    Users List (%d) user(s).\n", num);
			cout << "\t\t       ------------------------------------------------------------------\n";
			cout << "\t\t       | " << left << setw(20) << "User Name" << "| " << setw(10) << "Password" << "| " << setw(25) << "Permeision" << "\n";
			cout << "\t\t       ------------------------------------------------------------------\n\n";
			for (int i = 0;  i < num; i++) {
				clsUser User = clsUser::_ConvertLineToUserObject(users[i]);
				cout << "\t\t       | " << left << setw(20) << User.Name() << "| " << setw(10) << User.password() << "| " << setw(25) << User.permesion() << "\n";
			}
	}
};

