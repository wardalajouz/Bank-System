#pragma once

#pragma warning(disable:4996)
#include<iostream>
#include<ctime>
#include <vector>
using namespace std;

namespace MyLibrary
{
    void test()
    {
        cout << "this is my first funct in the librtary" << endl;
    }

    int Sum2Numbers(int n1, int n2)
    {
        return n1 + n2;
    }

    // ios::out to open a file and will delete everything 
    // ios::out | ios::app to make a file if it's not exist and append on it 
    // ios::in for read
    // fstream MyFile;
    // MyFile.open(filename, ios::out | ios::app);

    void PrintLocalTime()
    {
        time_t t = time(0);
        char* dt = ctime(&t);
        cout << "The local date and time is : " << dt << endl;
    }

    int RandomNumber(int from, int to)
    {
        // srand(time(0)) or srand((unsigned)time(NULL));
        int rannum = rand() % (to - from + 1) + from;
        return rannum;
    }

    // printf("%0*d",2(length),x)
    // short hand if : (condition) ? (expression_if_true) : (expression_if_false);

    void PrintFirstLetter(string name)
    {
        bool isfirst = true;
        for (short i = 0; i < name.length(); i++) {
            if (name[i] != ' ' && isfirst)
                cout << name[i] << endl;
            isfirst = (name[i] == ' ') ? true : false;
        }
    }

    void UpperAll(string name)
    {
        for (int i = 0; i < name.length(); i++) {
            name[i] = toupper(name[i]);
        }
        cout << name << endl;
    }

    void LowerAll(string name)
    {
        for (int i = 0; i < name.length(); i++) {
            name[i] = tolower(name[i]);
        }
        cout << name << endl;
    }

    char Invert(char x)
    {
        return isupper(x) ? tolower(x) : toupper(x);
    }

    void PrintEachWordInString(string name)
    {
        string sword = "";
        string delim = " ";
        int pos = 0;
        while ((pos = name.find(delim)) != std::string::npos) {
            sword = name.substr(0, pos);
            if (sword != "")
                cout << sword << endl;
            name.erase(0, pos + delim.length());
        }
        if (name != "")
            cout << name << endl;
    }

    vector<string> SplitString(string S1, string Delim)
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

            S1.erase(0, pos + Delim.length());  /* erase() until position and move to next word. */
        }

        if (S1 != "")
        {
            vString.push_back(S1); // it adds last word of the string.
        }

        return vString;
    }

    string Reverse(string s1)
    {
        vector<string> vString;
        string s2 = "";
        vString = SplitString(s1, " ");
        vector<string>::iterator iter = vString.end(); // iter is like a pointer
        while (iter != vString.begin()) {
            iter--;
            s2 += *iter + " "; // * represents the key
        }
        s2 = s2.substr(0, s2.length() - 1);
        return s2;
    }

    // system("cls"), system("pause>0")
}
