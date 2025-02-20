#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class clsString {
public:
    static string JoinString(vector<string> vString, string Delim)
    {

        string S1 = "";

        for (string& s : vString)
        {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());

    }
    static vector<string> Split(string S1, string Delim)
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
   static string FromVector(vector <string> Words, string delim = " () ") {
        string Sentence = "";
        for (string& s : Words) {
            Sentence += s + delim;
        }
        return Sentence.substr(0, Sentence.length() - delim.length());
    }
   static void SaveStringToFile(string Line, string name) {
       fstream file;
       file.open(name, ios::out | ios::app);
       if (file.is_open()) {
           if (Line != "") file << "\n" << Line;
           file.close();
       }

   }
};