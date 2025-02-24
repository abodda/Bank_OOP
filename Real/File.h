#pragma once
#include <vector>
#include <string>
#include "clsClient.h"
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