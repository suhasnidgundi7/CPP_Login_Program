#include <iostream>

using namespace std;

class LoginManager{
     public:
         string userNameAttempt;
         string passWordAttempt;

         LoginManager(){

            accessGranted = 0;
         }

         void login(){
             cout << "!!! PLEASE ENTER YOUR USERNAME AND PASSWORD !!!\n Username : ";
             cin >> userNameAttempt;
             if(userNameAttempt==userName){
                cout << " Password : ";
                cin >> passWordAttempt;

                if(passWordAttempt==passWord){

                    cout << "\n!!! *** LOGIN SUCCESSFULL *** !!!\n";
                }
            }
        }
    private:
        string passWord = "yourpassword";
        string userName = "yourusername";
        bool accessGranted;
};

int main()
{
    LoginManager loginManagerObj;
    loginManagerObj.login();
}