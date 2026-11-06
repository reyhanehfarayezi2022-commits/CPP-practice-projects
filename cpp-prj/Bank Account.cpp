#include <iostream>
#include <string>
#include <fstream>
#define fileName "BankInfo.txt"
using namespace std;

void writeFile_forWithdraw(int blnc , int w_a)
{
    ofstream w(fileName , ios :: app);
    if(!w.is_open())
    {
        cout << "\t\t*** Cannot Open file...";
        system("pause");
        return;
    }
    w << "______________________________________________________________________________________________________" << endl;
    w << left << string(45 , ' ') << "Balance : " << blnc << endl;
    w << left << string(45 , ' ') << "Withdraw Amount : " << w_a << endl;
    w << "______________________________________________________________________________________________________" << endl;
    w.close();
    cout << endl << left << string(45 , ' ') << " * History Updated *";
}


void writeFile_forDeposit(int blnc , int d_a)
{
    ofstream w(fileName , ios :: app);
    if(!w.is_open())
    {
        cout << "\t\t*** Cannot Open file...";
        system("pause");
        return;
    }
    w << "_______________________________________________________________________________________________________" << endl;
    w << left << string(45 , ' ') << "Balance : " << blnc << endl;
    w << left << string(45 , ' ') << "Withdraw Amount : " << d_a << endl;
    w << "_______________________________________________________________________________________________________" << endl;
    cout << endl << left << string(45 , ' ') << "* History Updated *";
    w.close();
}

class BankAccount
{
    private :
        int balance = 0;
        string username;
        int password;

    public :
        int getBalance()
        {
            return balance;
        }
        void getUsernamePassword();
        bool checkUsernamePassword();

        BankAccount()// Constructor Method
        {
            int x;
            cout << left << string(45 , ' ') << "=====================" << endl ;
            cout << left << string(45 , ' ') << "  Enter amount :\t";
            cin >> x;
            if (x < 0)
            {
                cout << left << string(45 , ' ') << "Invalid amount";
                system("pause");
            }
            else
            {
                balance = x;
                cout << "Balance : " << balance;
            }
        }
        void credit()// Method 1
        {
            system("cls");
            int amount;
            cout << left << string(45 , ' ') << "Enter Amount :\t";
            cin >> amount;
            if (amount < 0)
            {
            cout << left << string(45 , ' ') << "Invalid Amount";
            system("pause");
            return;
            }
            else
            {
                balance += amount;
                cout << "_________________________________________" << endl;
                cout << "credit : " << amount << endl;
                cout << "balance : " << balance << endl;
                cout << "_________________________________________" << endl;
            }
            writeFile_forDeposit(balance , amount);
        }

    void debit()//Method 2
        {
            system("cls");
            int amount;
            cout << left << string(45 , ' ') << "Enter amount :\t";
            cin >> amount;

            if (amount < 0)
            {
            cout << left << string(45 , ' ') << "Invalid Amount";
            system("pause");
            //return;
            }
            else
            {
                balance -= amount;
                cout << "_________________________________________" << endl;
                cout << "debit : " << amount << endl;
                cout << "balance : " << balance << endl;
                cout << "_________________________________________" << endl;
            }
            writeFile_forWithdraw(balance , amount);
        }


};
void BankAccount :: getUsernamePassword()
{
    system("cls");
    string usn;
    int psw;

    cin.get();
    cout << left << string( 45 , ' ' ) << "| Enter username :\t";
    getline (cin , usn);

    cout << endl <<left << string (45 , ' ' ) << "_______________________" << endl;
    cout << left << string( 45 , ' ' ) << "| Enter password :\t";
    cin >> psw;

    username = usn;
    password = psw;
}
bool BankAccount :: checkUsernamePassword()// Method 4
{
    system("cls");
    string usn;
    int psw;
    bool result = false;

    cin.get();
    cout << left << string (45 , ' ') << "| Enter Username :\t";
    getline(cin , usn);

    cout << endl << left << string (45 , ' ') << "_______________________" << endl ;

    cout << left << string (45 , ' ') << "| Enter Password:\t";
    cin >> psw;

    if (usn == username && psw == password)
    {
        result = true;
        return result;
    }
}
int menu()
{
    system("cls");
    int ch;
    cout << left << string (45 , ' ') << " _________________________________" << endl;
    cout << left << string (45 , ' ') << "| 1. Get Balance" << endl;
    cout << left << string (45 , ' ') << "| 2. Deposit" << endl;
    cout << left << string (45 , ' ') << "| 3. Withdraw" << endl;
    cout << left << string (45 , ' ') << "| 4. Exit" << endl;
    cout << left << string (45 , ' ') << " _________________________________" << endl;
    cout << left << string (45 , ' ') << " |||===|||=== YOUR CHOICE :\t";
    cin >> ch;
    return ch;
}

int main()
{
    BankAccount accountObj;
    accountObj.getUsernamePassword();
    while(true)
    {
        int m = menu();
        switch(m)
        {
            case 1:
            {
                bool check_usernamePassword = accountObj.checkUsernamePassword();
                if( check_usernamePassword == true)
                {
                    int show_balance = accountObj.getBalance();
                    cout << left << string(45 , ' ') << "=========================" << endl;
                    cout << left << string(45 , ' ') << "=== Balance : " << show_balance << endl;
                    cout << left << string(45 , ' ') << "=========================" << endl;
                    system("pause");
                }
                else if (check_usernamePassword == false)
                    {cout << left << string (45 , ' ') << "Incorrect Info." << endl;}
                break;
            }
            case 2:
                {
                    bool check_usernamePassword = accountObj.checkUsernamePassword();
                    if( check_usernamePassword == true)
                    {
                        accountObj.credit();
                        system("pause");
                    }
                    else if (check_usernamePassword == false)
                        {cout << left << string(45 , ' ') << "Incorrect Info." << endl;}
                    break;
                }
            case 3:
                {
                    bool check_usernamePassword = accountObj.checkUsernamePassword();
                    if( check_usernamePassword == true)
                    {
                        accountObj.debit();
                        system("pause");
                    }
                    else if (check_usernamePassword == false)
                        {cout << left << string(45 , ' ') << "Incorrect Info." << endl;}
                    break;
                }
            case 4:
                {
                    exit(0);
                }
        }
    }
    return 0;
}
