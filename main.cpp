#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct login
{
    string name;
    string username;
    string password;
    string website;
};

void saveLogins(vector<login> logins)
{
    fstream loginFile("logins.json");
    string loginFileString;
    while (getline(loginFile, loginFileString)) {}
    cout << loginFileString << endl;

    nlohmann::json j = loginFileString;
    for (login login : logins)
    {
        j += {
                login.name, {
                    {"username", login.username},
                    {"password", login.password},
                    {"website", login.website},
                }
        };
    }
    cout << setw(4) << j << endl;
}

int main()
{
    vector<login> logins;
    login test = {"bank", "testUserName", "testPassword", "bank.org"};
    logins.push_back(test);
    saveLogins(logins);

    // while (true)
    // {
      //  cout << "Choose one of the options below: " << endl << endl;
       // cout << "1. Create new login" << endl;
        //cout << "2. " << endl;
    //}
}
