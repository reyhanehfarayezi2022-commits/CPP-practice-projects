 #include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct Room
{
    int number;
    //bool available;
};

vector <Room> list_of_rooms;

int room_number()
{
    int RoomNumber;
    for( int f = 1 ; f <= 3 ; f ++ )// f = floor
    {
        for( int r = 0 ; r <= 5 ; r ++ )// r = room
        {
            RoomNumber = f * 100 + r;
            list_of_rooms.push_back({RoomNumber});
        }
    }
    return RoomNumber;
}

struct Customer
{
    // personal info :
    string fname;
    string lname;
    int phoneNumber;

    // general info :
    int get_roomNumber;

    // date of check in & check out :
    int month_in;
    int month_out;
    int day_in;
    int day_out;
    float time_in;
    float time_out;

}list_of_customers;



int menu ()
{
    system("cls");

    int ch;
    cout << "================= Welcome To Hotel Reyhan =================" << endl;
    cout << "1.\t Reserve a room " << endl;
    cout << "2.\t Edit Info " << endl;
    cout << "3.\t Cancel reservation " << endl;
    cout << "4.\t Show reservation info" << endl;
    cout << "5.\t Edit" << endl;
    cout << "===========================================================" << endl;
    cout << "===\tyour choice :\t";
    cin >> ch;
    return ch;
}


void reserve()
{
    system("cls");
    ofstream w("Customers.txt");
    cin.get();

    cout << "================= Welcome To Hotel Reyhan =================" << endl;

    int peopleCount;
    cout << "***\t Enter number of people :\t";
    cin >> peopleCount;

    w << "_________________________________________________________________________";
    for (int i = 0 ; i < peopleCount ; i ++)
    {
        cin.get();
        w << "*****************************" << endl;
        cout << "\n***\tEnter first name :\t";
        getline(cin , list_of_customers.fname);
        w << "First Name : " << list_of_customers.fname << endl;

        cout << "\n***\tEnter last name :\t";
        getline(cin , list_of_customers.lname);
        w << "Last Name : " << list_of_customers.lname << endl;

        cout << "\n***\tEnter phonr number:\t";
        cin >> list_of_customers.phoneNumber;
        w << "Phone Number : " << list_of_customers.phoneNumber << endl;

    }
    list_of_customers.get_roomNumber = room_number();
    w << "Room Number : " << list_of_customers.get_roomNumber << endl;

    cout << "\n================= Date Of Check In =================" << endl;
    w << "\n================= Date Of Check In =================" << endl;

    cout << "\n                  Month :\t";
    cin >> list_of_customers.month_in;
    w << "Month : " << list_of_customers.month_in << endl;

    cout << "\n                  Day :\t";
    cin >> list_of_customers.day_in;
    w << "Day : " << list_of_customers.day_in << endl;

    cout << "\n                  Time :\t";
    cin >> list_of_customers.time_in;
    w << "Time : " << list_of_customers.time_in << endl;

    cout << "\n=====================================================" << endl;
    w << "=====================================================" << endl;


    cout << "================= Date Of Check Out =================" << endl;
    w << "================= Date Of Check Out =================" << endl;

    cout << "                  Month :\t";
    cin >> list_of_customers.month_out;
    w << "Month : " << list_of_customers.month_out << endl;

    cout << "                  Day :\t";
    cin >> list_of_customers.day_in;
    w << "Day : " << list_of_customers.day_out << endl;

    cout << "                  Time :\t";
    cin >> list_of_customers.time_out;
    w << "Time : " << list_of_customers.time_out << endl;

    cout << "=====================================================" << endl;
    w << "=====================================================" << endl;
    w << "_________________________________________________________________________";
    system("pause");
    w.close();
}

void edit()
{
    system("cls");
    ifstream r("Customers.txt");

    string new_fn , new_ln;
    int new_phn;
    int new_m_in , new_d_in , new_t_in;
    int new_m_out , new_d_out , new_t_out;

    cout << "================= Edit Info =================" << endl ;

    while(true)
    {
        cout << "1. Edit Self Info \n2. Edit Date Of Check In\n3.Edit Date Of Check Out\n4. Exit" << endl;
        int ch;
        cout << "           Your choice :\t";
        cin >> ch;

        cout << "           Enter Room Number :\t";
        int r_num;
        cin >> r_num;

        r >> list_of_customers.get_roomNumber;
        if(list_of_customers.get_roomNumber == r_num)
        {
            switch(ch)
            {
                case 1:
                    while(!r.eof())
                    {
                        cout << "===\tEdit Personal Info\t===" << endl;

                        getline(r , list_of_customers.fname);
                        getline(r , list_of_customers.lname);
                        r >> list_of_customers.phoneNumber;

                        ofstream w("Customers.txt");
                        cin.get();

                        cout << "Edit first name :\t";
                        getline(cin , new_fn);
                        list_of_customers.fname = new_fn;
                        w << list_of_customers.fname;

                        cout << "Edit last name :\t";
                        getline(cin , new_ln);
                        list_of_customers.lname = new_ln;
                        w << list_of_customers.lname;

                        cout << "Edit phone number :\t";
                        cin >> new_phn;
                        list_of_customers.phoneNumber = new_phn;
                        w << list_of_customers.phoneNumber;

                        w.close();
                        r.close();
                        break;
                    }

                    case 2:
                        cout << "===\t Edit Date Of Check In \t===" << endl;
                        while(r.eof())
                        {
                            r >> list_of_customers.month_in;
                            r >> list_of_customers.day_in;
                            r >> list_of_customers.time_in;

                            ofstream w("Customers.txt");
                            cin.get();

                            cout << "Month :\t";
                            cin >> new_m_in;
                            list_of_customers.month_in = new_m_in;
                            w << list_of_customers.month_in;

                            cout << "Day :\t";
                            cin >> new_d_in;
                            list_of_customers.day_in = new_d_in;
                            w << list_of_customers.day_in;

                            cout << "Time :\t";
                            cin >> new_t_in;
                            list_of_customers.time_in = new_t_in;
                            w << list_of_customers.time_in;

                            r.close();
                            w.close();
                            break;
                        }

                        case 3:
                            {
                                cout << "===\t Edit Date Of Check Out \t===";
                                while(!r.eof())
                                {
                                    r >> list_of_customers.month_out;
                                    r >> list_of_customers.day_out;
                                    r >> list_of_customers.time_out;

                                    ofstream w("Customers.txt");
                                    cin.get();

                                    cout << "Month :\t";
                                    cin >> new_m_out;
                                    list_of_customers.month_out = new_m_out;
                                    w << list_of_customers.month_out;

                                    cout << "Day :\t";
                                    cin >> new_d_out;
                                    list_of_customers.day_out;
                                    w << list_of_customers.day_out;

                                    cout << "Time :\t";
                                    cin >> new_t_out;
                                    list_of_customers.time_out = new_t_out;

                                    w << list_of_customers.time_out;

                                    w.close();
                                    r.close();
                                    break;
                                }

                                    case 4:
                                        {
                                            false;
                                        }
                                }
                            }

            }
        }

    }


void cancel()
{
    system("cls");
    int r_num;
    string q;
    cout << "============\tCanecl Reservation\t============" << endl;
    cout << "\t***\tAre you sure to canecl reservation ? (Enter Yes/No)\t";
    cin >> q;
    if (q == "Yes")
    {
        cout << "***\t Enter room number :\t";
        cin >> r_num;

        ifstream r("Customers.txt");

        getline(r , list_of_customers.fname);
        getline(r , list_of_customers.lname);
        r >> list_of_customers.phoneNumber;

        r >> list_of_customers.get_roomNumber;

        r >> list_of_customers.month_in;
        r >> list_of_customers.month_out;

        r >> list_of_customers.day_in;
        r >> list_of_customers.day_out;

        r >> list_of_customers.time_in;
        r >> list_of_customers.time_out;

        ofstream w("Customers.txt");

        list_of_customers.fname = "";
        list_of_customers.lname = "";
        list_of_customers.phoneNumber = 0;

        list_of_customers.get_roomNumber = 0;

        list_of_customers.month_in = 0;
        list_of_customers.month_out = 0;

        list_of_customers.day_in = 0;
        list_of_customers.day_out = 0;

        list_of_customers.time_in = 0;
        list_of_customers.time_out = 0;



        w << list_of_customers.fname;
        w << list_of_customers.lname;
        w << list_of_customers.phoneNumber;

        for (int i = 0 ; i < list_of_rooms.size() ; i ++)
        {
            if(list_of_rooms[i].number == r_num)
            {
                list_of_rooms.erase(list_of_rooms.begin() + i);
                break;
            }
        }

        w << list_of_customers.month_in;
        w << list_of_customers.month_out;

        w << list_of_customers.day_in;
        w << list_of_customers.day_out;

        w << list_of_customers.time_in;
        w << list_of_customers.time_out;

        cout << "\t***\tReservation hase been cencelled\t***" << endl;
        w.close();
        r.close();
    }
    system("pause");
}

void show()
{
    system("cls");

    ifstream r("Customers.txt");

    cout << "================== Reservation Info ==================" << endl ;

    r >> list_of_customers.get_roomNumber;

    while(!r.eof())
    {
        r >> list_of_customers.month_in;
        r >> list_of_customers.day_in;
        r >> list_of_customers.time_in;

        r >> list_of_customers.month_out;
        r >> list_of_customers.day_out;
        r >> list_of_customers.time_out;

        if(r.eof())
            break;

        cout << left << "***\tRoom Number : " << list_of_customers.get_roomNumber << "\t***" << endl;
        cout <<"================= Date Of Check In =================" << endl;

        cout << "= Month :\t" << list_of_customers.month_in << endl;
        cout << "= Day :\t" << list_of_customers.day_in << endl;
        cout << "= Time :\t" << list_of_customers.time_in << endl;

        cout << "====================================================" << endl;

        cout << "================= Date Of Check Out =================" << endl;

        cout << "= Month :\t" << list_of_customers.month_out << endl;
        cout << "= Day :\t" << list_of_customers.day_out << endl;
        cout << "= Time :\t" << list_of_customers.time_out << endl;

        cout << "====================================================" << endl;

        r.get();
        break;
    }
    system("pause");
    r.close();
}



int main()
{
    system("cls");

    while(true)
    {
        int m = menu();
        menu();

        switch(m)
        {
            case 1:
                reserve();
                break;

            case 2:
                edit();
                break;

            case 3:
                cancel();
                break;

            case 4:
                show();
                break;

            case 5:
                exit(0);
                break;
        }
    }
    system("pause");
    return 0;
}
