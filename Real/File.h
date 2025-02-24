#pragma once
#include <vector>
#include <string>
#include <fstream>
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
void SaveVectorToFile(vector <string> countries, string FileName) {
	fstream file;
	file.open(FileName, ios::out);
	if (file.is_open()) {
		for (string line : countries) {
			file << "\n" << line;
		}
		file.close();
	}
}