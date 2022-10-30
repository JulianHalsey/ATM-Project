#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void Register();
void Login();
void ViewPassword();


int main()
{
    int num;
    float total = 0;
    float moneyIn;
    float moneyOut;

    do{
        cout << "-------------------------" << endl;
        cout << "Please enter an option: " << endl;
        cout << "(1) Register" << endl;
        cout << "(2) Login" << endl;
        cout << "(3) View Balance" << endl;
        cout << "(4) Deposit Money" << endl;
        cout << "(5) Withdraw Money" << endl;
        cout << "(6) Forgot Password" << endl;
        cout << "(7) Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Option # ";
        cin >> num;

        switch (num) {
            case 1:
                Register();
                break;
            case 2:
                Login();
                break;
            case 3:
                cout << "********************************" << endl;
                cout << "Your current balance is $ " << total << endl;
                break;
            case 4:
                cout << "*****************************************************" << endl;
                cout << "Enter the amount of money you would like to deposit" << endl;
                cout << "$ ";
                cin >> moneyIn;
                total = total + moneyIn;
                cout << "*******************************" << endl;
                cout << "$ " << moneyIn << " successfully deposited" << endl;
                break;
            case 5:
                cout << "*****************************************************" << endl;
                cout << "Enter the amount of money you would like to withdraw" << endl;
                cout << "$ ";
                cin >> moneyOut;
                total = total - moneyOut;
                cout << "*******************************" << endl;
                if (moneyOut > total)
                {
                    cout << "You do not have enough funds to withdraw that amount" << endl;
                }
                else
                {
                    cout << "$ " << moneyOut << " successfully withdrawn" << endl;
                }
                break;
            case 6:
                ViewPassword();
                break;
            case 7:
                return 0;
            default:
                cout << "Error. Enter a valid number" << endl;
        }
    } while(num !=6);


    return 0;
}

void Register()
{
    string usrnm;
    string passwd;
    cout << "***********************************************" << endl;
    cout << "      Welcome to World Bank Registration!" << endl;
    cout << "***********************************************" << endl;
    cout << "    Please choose a username and password" << endl;
    cout <<"***********************************************" << endl;
    cout << "Username: ";
    cin >> usrnm;
    cout << "Password: ";
    cin >> passwd;
    cout <<"***********************************************" << endl;
    cout << "Username of " << usrnm << " created with passowrd of " << passwd << endl;
   

    ofstream users;
    users.open("C:\\Users\\julia\\Documents\\users.txt");
    users << usrnm << endl;
    users.close();
    ofstream passwds;
    passwds.open("C:\\Users\\julia\\Documents\\passwds.txt");
    passwds << passwd << endl;
    passwds.close();
}

void Login()
{
    string user;
    string usernm;
    string passwd;
    string password;
    ifstream users;
    ifstream passwds;
    passwds.open("C:\\Users\\julia\\Documents\\passwds.txt");
    users.open("C:\\Users\\julia\\Documents\\users.txt");
    
    if ((users) && (passwds))
    {
        cout << "*****************************************************" << endl;
        cout << "Please enter your username and password" << endl;
        cout << "Username: ";
        cin >> usernm;
        cout << "Password: ";
        cin >> password;
        cout << "********************************************************" << endl;

        if ((usernm == user) && (password == passwd))
        cout << "Login successful. Welcome " << usernm << endl;
        else if ((usernm == user) || (password == passwd))
        {
        cout << "Username and password do not match, try again" << endl;
        cout << "************************************************" << endl;
        Login();
        }
        else  
        {
        cout << "Incorrect credentials, please try again" << endl;
        cout << "******************************************" << endl;
        main();
        }
        users.close();
        passwds.close();
    }
    else
    {
        cout << "No username or password on file, please register" << endl;
        main();
    }
    
}

void ViewPassword()
{
    string usrnm;
    string passwd;
    string user;

    ifstream users;
    ifstream passwds;
    passwds.open("C:\\Users\\julia\\Documents\\passwds.txt");
    users.open("C:\\Users\\julia\\Documents\\users.txt");

    cout << "*****************************************************" << endl;
    cout << "Please enter your username for your forgotten password" << endl;
    cout << "Username: ";
    cin >> usrnm;

    users >> user;
    passwds >> passwd;

    if (usrnm == user)
    {
        cout << "***************************" << endl;
        cout << "Password: " << passwd << endl;
        main();

    }
    else
    {
        cout << "No matching passwords to that username" << endl;
        main();
    }

    passwds.close();
    users.close();

}