#include <cstdlib>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
using json = nlohmann::json;

struct login
{
    string name;
    string username;
    string password;
    string website;
};

vector<login> readLogins()
{
    fstream loginFile("logins.json");
    json j = json::parse(loginFile);
    login tmp = {};
    vector<login> logins;

    for (const auto& item : j.items())
    {
        tmp.name = item.value();
        tmp.username = item.value()["username"].get<string>();
        tmp.password = item.value()["password"].get<string>();
        tmp.website = item.value()["website"].get<string>();
        logins.push_back(tmp);
    }
    return logins;
}

void saveLogins(vector<login> logins)
{
    ifstream inFile("logins.json");
    json j;

    if (inFile.is_open())
    {
        try 
        {
            inFile >> j;
        } 
        catch (...) 
        {
            j = json::array();
        }
    }
    else 
    {
        cerr << "Failed to open file" << endl;
        exit(EXIT_FAILURE);
    }

    cout << j << endl;

    for (const auto &login : logins)
    {
        j.push_back({
                    {"name", login.name},
                    {"username", login.username},
                    {"password", login.password},
                    {"website", login.website},
        });
    }
    ofstream outFile("logins.json", ios::trunc);
    outFile << setw(4) << j;
    cout << setw(4) << j << endl;
    outFile.close();
}

int main()
{
    vector<login> logins;
    login test = {"bank", "testUserName", "testPassword", "bank.org"};
    logins.push_back(test);
    login test2 = {"bank", "testUserName", "testPassword", "bank.org"};
    logins.push_back(test2);
    login test3 = {"bank", "testUserName", "testPassword", "bank.org"};
    logins.push_back(test3);
    saveLogins(logins);

    // while (true)
    // {
      //  cout << "Choose one of the options below: " << endl << endl;
       // cout << "1. Create new login" << endl;
        //cout << "2. " << endl;
    //}
}
