#include <cstdlib>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using string = std::string;
using json = nlohmann::json;

class Manager
{

    private:
        struct Login
        {
            string name;
            string username;
            string password;
            string website;
        };

        std::vector<Login> m_logins;

    public:
        manager()
        {
            m_logins = readLogins();
        }


        std::vector<Login> readLogins()
        {
            std::fstream LoginFile("logins.json");
            json j;
            LoginFile >> j;
            if (LoginFile.is_open())
            {
                try
                {
                    LoginFile >> j;
                }
                catch (...)
                {
                    j = json::array();
                }
            }
            Login tmp = {};
            std::vector<Login> logins;

            for (const auto& item : j.items())
            {
                tmp.name = item.value()["name"].get<string>();
                tmp.username = item.value()["username"].get<string>();
                tmp.password = item.value()["password"].get<string>();
                tmp.website = item.value()["website"].get<string>();
                Logins.push_back(tmp);
            }
            return Logins;
        }

        void saveLogins(std::vector<Login> logins)
        {
            std::ifstream inFile("Logins.json");
            json j;

            if (!inFile.is_open())
            {
                std::cerr << "Failed to open file\n";
            }

            for (const auto &Login : logins)
            {
                j.push_back({
                        {"name", Login.name},
                        {"username", Login.username},
                        {"password", Login.password},
                        {"website", Login.website},
                        });
            }
            std::ofstream outFile("Logins.json", std::ios::trunc);
            outFile << std::setw(4) << j;
            std::cout << std::setw(4) << j << std::endl;
            outFile.close();
        }

        const std::vector<Login>& getLogins() { return m_logins; }

        void addLogin(const Login& newLogin)
        {
            m_logins.push_back(newLogin);
        }

        
};
