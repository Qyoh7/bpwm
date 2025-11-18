#include "Manager.hpp"
using namespace std;
using json = nlohmann::json;

int main()
{
    Manager manager;
    manager.addLogin(const Login &newLogin)

    login test = {"bank", "testUserName", "testPassword", "bank.org"};
    logins.push_back(test);
    login test2 = {"bank", "testUserName", "testPassword", "bank.org"};
    logins.push_back(test2);
    login test3 = {"bank", "testUserName", "testPassword", "bank.org"};
    logins.push_back(test3);
    saveLogins(logins);

    for (auto &login : readLogins())
    {
        cout << login.name << endl;
    }

    // while (true)
    // {
      //  cout << "Choose one of the options below: " << endl << endl;
       // cout << "1. Create new login" << endl;
        //cout << "2. " << endl;
    //}
}
