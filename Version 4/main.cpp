#include <iostream>
#include <fstream>
#include <math.h>

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
        cout << "!!! PLEASE ENTER YOUR USERNAME AND PASSWORD !!! \n Username : ";
        cin >> userNameAttempt;


        if(checkFile(userNameAttempt, "usernames.dat"))
        {
            cout << " Password : ";
            cin >> passwordAttempt;

            if(checkFile(passwordAttempt, "passwords.dat"))
            {
                cout << "\n!!! *** LOGIN SUCCESSFULL *** !!! \n" << endl;;
                login();

            }
            else
            {
                cout << "!!! ERROR 404 !!! PLEASE ENTER VAILD PASSWORD !!!" << endl;
                login();
            }
        }
        else
        {
            cout << "!!! ERROR 404 !!! PLEASE ENTER VAILD USERNAME !!!" << endl;
            login();
        }
    }
    bool checkFile(string attempt, const char* p_fileName)
    {
        string line;
        fstream file;

        long long eChar;

        file.open(p_fileName, ios::in);
        
        while(1)
        {
            file >> eChar;
            if(eChar == 0)
            {
                if(attempt == line)
                {
                    file.close();
                    return true;
                }
                else
                {
                    line.erase(line.begin(), line.end());
                }
            }
            else
            {
                line += (char)decrypt(eChar);
            }

            if(file.peek() == EOF)
            {
                file.close();
                return false;
            }
        }
    }

    void saveFile(string p_line, const char* p_fileName)
    {
        fstream file;
        file.open(p_fileName, ios::app);

        for(int i = 0; i < p_line.length(); i++)
        {
            file << encrypt(p_line[i]);
            file << "\n";
        }

        file << "0 \n";
        file.close();
    }

    long long encrypt(int p_letter)
    {
        return powf(p_letter, 5) * 4 - 14;
    }
    int decrypt(long long p_letter)
    {
        return powf((p_letter + 14) / 4, 1/5.f);
    }

private:
    string userNameAttempt;
    string passwordAttempt;
    bool accessGranted;
};

int main()
{
    LoginManager app;
    app.login();
    cin.get();
}