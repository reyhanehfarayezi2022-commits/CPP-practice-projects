#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct customer
{
    string fname;
    string lname;
    int tableNum;
    vector <customer> list_of_orders;
}c;

int menu1()
{
    int ch;
    system("cls");
    cout << "===================== Menu =====================" << endl;
    cout << "1) ==========      Fast Food       ==========" << endl;
    cout << "2) ==========   Traditional Food   ==========" << endl;
    cout << "3) ==========        Drinks        ==========" << endl;
    cout << "4) ==========         Exit         ==========" << endl;
    cout << "================================================" << endl;
    cout << "= YOUR CHOICE :\t";
    cin >> ch;
    return ch;
}

int fastFood()
{
    int ch;
    cout << "===================== Fast Food =====================" << endl;
    cout << "                   1) Pizza" << endl;
    cout << "                   2) Hamburger" << endl;
    cout << "                   3) Cheese burger" << endl;
    cout << "                   4) Double burger" << endl;
    cout << "                   5) Hot dog" << endl;
    cout << "                   6) Fries" << endl;
    cout << "                   7) French fries" << endl;
    cout << "=====================================================" << endl;
    cout << "= YOUR CHOICE :\t";
    cin >> ch;
    return ch;
}

int traditionalFood()
{
    int ch;
    cout << "===================== Traditional Food =====================" << endl;
    cout << "                    1) Gheimeh" << endl;
    cout << "                    2) Sabzi Ghormeh" << endl;
    cout << "                    3) Koofte Tabrizi" << endl;
    cout << "                    4) Jouje Kabab" << endl;
    cout << "                    4) Kabab Tabei" << endl;
    cout << "                    5) Abgousht" << endl;
    cout << "===========================================================" << endl;
    cout << "= YOUR CHOICE :\t";
    cin >> ch;
    return ch;
}

int drinks()
{
    int ch;
    cout << "===================== Drinks =====================" << endl;
    cout << "                   1) Cola" << endl;
    cout << "                   2) Doogh Abali" << endl;
    cout << "                   3) Fanta" << endl;
    cout << "                   4) Water" << endl;
    cout << "==================================================" << endl;
    cout << "= YOUR CHOICE :\t";
    cin >> ch;
    return ch;
}

void EnterInfo()
{
    ofstream w("OrderFile.txt" , ios::app);
    cin.get();
    if(!w.is_open())
    {
        cout << "Cannot open file";
        system("pause");
    }
    cout << "*\t Enter First Name :\t";
    getline(cin , c.fname);
    w << "First Name : " << c.fname << endl;

    cout << "*\t Enter Last Name :\t";
    getline(cin , c.lname);
    w << "Last Name : " << c.lname << endl;

    cout << "*\t Enter Table Number :\t";
    cin >> c.tableNum;
    w << "Table Number : " << c.tableNum << endl;

    system("pause");
    w.close();
}


int order()
{

    ofstream w("OrderFile.txt" , ios::app);
    cin.get();
    if (!w.is_open())
    {
        cout << "Cannot open file.";
        system("pause");
    }

    w << "================= Orders =================" << endl;

    while( true )
    {
    int mn = menu1();
    switch(mn)
    {
        case 1:
            {
                int ch = fastFood();
                switch(ch)
                {
                    case 1:
                        c.list_of_orders.push_back({"Pizza"});
                        w << "= Pizza =" << endl;
                        break;
                    case 2:
                        c.list_of_orders.push_back({"Hamburger"});
                        w << "= Hamburger =" << endl;
                        break;
                    case 3:
                        c.list_of_orders.push_back({"Cheese burger"});
                        w << "= Cheese burger =" << endl;
                        break;
                    case 4:
                        c.list_of_orders.push_back({"Double burger"});
                        w << "= Double burger =" << endl;
                        break;
                    case 5:
                        c.list_of_orders.push_back({"Hot dog"});
                        w << "= Hot dog =" << endl;
                        break;
                    case 6:
                        c.list_of_orders.push_back({"Fries"});
                        w << "= Fries =" << endl;
                        break;
                    case 7:
                        c.list_of_orders.push_back({"French fries"});
                        w << "= French fries =" << endl;
                        break;
                }
            }
            break;

        case 2:
            {
                int ch = traditionalFood();
                switch(ch)
                {
                    case 1:
                        c.list_of_orders.push_back({"Gheimeh"});
                        w << "= Gheimeh =" << endl;
                        break;
                    case 2:
                        w << "= Sabzi ghorme =" << endl;
                        c.list_of_orders.push_back({"Sabzi ghorme"});
                        break;
                    case 3:
                        c.list_of_orders.push_back({"Koofte Tabrizi"});
                        w << "= Koofte Tabrizi =" << endl;
                        break;
                    case 4:
                        w << "= Jouje Kabab =" << endl;
                        break;
                    case 5:
                        c.list_of_orders.push_back({"Kabab Tabei"});
                        w << "= Kabab tabei =" << endl;
                        break;
                    case 6:
                        c.list_of_orders.push_back({"Abghousht"});
                        w << "= Aboghousht =" << endl;
                        break;
                }

            }
            break;

        case 3:
            {
                int ch = drinks();
                switch(ch)
                {
                    case 1:
                        c.list_of_orders.push_back({"Cola"});
                        w << "= Cola =" << endl;
                        break;
                    case 2:
                        c.list_of_orders.push_back({"Doogh Abali"});
                        w << "= Doogh Abali =" << endl;
                        break;
                    case 3:
                        c.list_of_orders.push_back({"Fanta"});
                        w << "= Fanta =" << endl;
                        break;
                    case 4:
                        c.list_of_orders.push_back({"Water"});
                        w << "= Water =" << endl;
                        break;
                }
            }
            break;

        case 4:
            return false;
    }
    }
    w.close();
    return 0;
}

void showOrder()
{
    system("cls");
    ifstream r("OrderFile.txt");
    r.get();

    getline(r , c.fname);
    getline(r , c.lname);
    r >> c.tableNum;


    cout << c.fname << "\t" << c.lname << "\t" << c.tableNum << endl;

    cout << "=================== orders ===================" << endl;

    for (int i = 0 ; i < c.list_of_orders.size() ; i ++)
    {
        //cout << c.list_of_orders[i] << endl;
    }

    system("pause");
    r.close();

}

int main()
{
    EnterInfo();
    order();
    showOrder();

    return 0;
}
