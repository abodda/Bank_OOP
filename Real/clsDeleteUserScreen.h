#pragma once
#include "clsScreen.h"
class clsDeleteUserScreen : protected clsScreen
{
public:
	static void Print() {
		system("cls");
		Header("\t  Delete User screen");
		clsUser user = clsUser::CheckUser();
		if (user.Name() == "Admin") {
			cout << "\nyou cant delete Admin sorry :(\n";
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
};

