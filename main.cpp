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

void saveLogins(vector<login> logins)
{
    fstream loginFile("logins.json");
    json j;

    if (loginFile.is_open())
    {
        try 
        {
            loginFile >> j;
        } 
        catch (...) 
        {
            j = json::array();
        }
        loginFile.close();
    }
    else 
    {
        j = json::array();
    }

    cout << j << endl;

    for (const auto &login : logins)
    {
        j.push_back({
                login.name, {
                    {"username", login.username},
                    {"password", login.password},
                    {"website", login.website},
                }
        });
    }
    loginFile << j << endl;
    cout << setw(4) << j << endl;
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
