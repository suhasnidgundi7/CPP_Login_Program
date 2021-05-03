#include <iostream>
#include <fstream>

using namespace std;

class LoginManager
{
public:
    LoginManager()
    {

        accessGranted = 0;
    }

    void login()
    {
        cout << "!!! PLEASE ENTER YOUR USERNAME AND PASSWORD !!!.\n\n Username : ";
        cin >> userNameAttempt;

        userName = getFile("usernames.dat");
        if(userNameAttempt == userName)
        {
            cout << " Password : ";
            cin >> passWordAttempt;

            passWord = getFile("passwords.dat");

            if(passWordAttempt == passWord)
            {
                cout << "\n!!! *** LOGIN SUCCESSFULL *** !!!\n";
                cin.get();
            }
            else
            {
                cout << "\n!!! *** PLEASE ENTER VALID PASSWORD TO LOGIN *** !!!\n" << endl;
                login();
            }
        }
        else
        {
            cout << "\n!!! *** PLEASE ENTER VALID USERNAME TO LOGIN *** !!!\n" << endl;
            login();
        }
    }
    string getFile(const char* p_fileName)
    {
        string line;
        fstream file;

        file.open(p_fileName, ios::in);
        if(file.is_open())
        {
            getline(file, line);
        }
        file.close();

        return line;
    }
private:
    string passWord = "yourusername";
    string userName = "yourpassword";
    string userNameAttempt;
    string passWordAttempt;
    bool accessGranted;
};

int main()
{
    LoginManager loginManagerObj;
    loginManagerObj.login();
}