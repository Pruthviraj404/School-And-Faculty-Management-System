#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
char ret;
char zz = 220;
int inadminop;
int selec;
struct student
{

    char name[100];
    char fname[200];
    int cpp, dbs, mts, se, sum, os;
    int roll;
    char id[80];
    char stbr[80];
    float per, average;
} s;
struct cfacluty
{
    char hodname[100], payroll[15], institute[200], desig[30], facult[30], dept[40], experience[10];
    char address[300];
    char qualification[100];
    char mob[15];
} c;

struct User
{
    string username;
    string password;
};

struct Student
{
    string id;
    string name;
};

struct Admin
{
    string username;
    string password;
};

bool login(vector<User> &users, string &currentUser);
void studentSection(const vector<Student> &students);
void adminSection(vector<Student> &students);

void verify();
void intro();
void gotoxy();
void gotoXY(int x, int y);
void mainmenu();
void facmenu();
void faculty();
void set_cursor(int, int);
// void hodadmin();
void passadm();
void cpystd();
void stdrel();

void verify()
{ // system("color 19");
    int i;
    const string userdata = "admin";
    int passdata = 129612;
    char usr[20];
    int pass;
    system("cls");
start:
    system("color EA");
    for (i = 0; i < 110; i++)
    {
        cout << zz;
    }
    cout << "\nENTER USERNAME:-";
    cin >> usr;
    cout << "ENTER PASSWORD:-";
    cin >> pass;
    for (i = 0; i < 110; i++)
    {
        cout << zz;
    }
    system("cls");
    cout << "Loading";

    // Initialize char for printing
    // loading bar
    char a = 177, b = 219;

    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\tLoading...\n\n");
    printf("\t\t\t\t\t");

    // Print initial loading bar
    for (int i = 0; i < 26; i++)
        printf("%c", a);

    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");

    // Print loading bar progress
    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);

        // Sleep for 1 second
        Sleep(100);
    }
    // for (i = 0; i < 5; i++)
    //   {
    //       cout << ".";
    //     Sleep(300);
    // }

    system("cls");
    if (usr == userdata && pass == passdata)
    {

        cout << "LOGIN SUCESSFULL.....";
        Sleep(1000);
        system("cls");
    }
    else
    {

        SetConsoleTextAttribute(h, 12);
        {
            Beep(1545, 200);
            cout << "INVALID CREDENTIALS...." << endl;
        }
        Sleep(1000);
        system("cls");
        goto start;

        getchar();
    }
}

void faculty()
{
    cin >> inadminop;
    switch (inadminop)
    {
    case 1:

    {

        cfacluty c;
        ofstream outfile;
        outfile.open("Reporttest1.txt", ios::app | ios::binary);

        if (outfile.fail())
        {
            cout << "THE FILE COULD NOT BE OPEN...press enter key";
            cin.ignore();
            cin.get();
        }
        do
        {

            cout << "Enter Name                   : ";
            cin.ignore();
            cin.getline(c.hodname, 80);
            cout << "\nName of Faculty             : ";
            cin.getline(c.facult, 80);
            cout << "\nQualification               : ";
            cin.getline(c.qualification, 80);
            cout << "\nDesignation                 : ";
            cin.getline(c.desig, 80);
            cout << "\nInstitute:                  : ";
            cin.getline(c.institute, 80);
            cout << "\nName of Department          : ";
            cin.getline(c.dept, 80);
            cout << "\nExperience                  : ";
            cin.getline(c.experience, 80);
            cout << "\nBasic Payroll               : ";
            cin.getline(c.payroll, 80);

            // cin.ignore();

            cout << "ENTER ADDRESS:";

            cin.getline(c.address, 80);

            cout << "ENTER PHONE NUMBER: ";
            cin.getline(c.mob, 80);

            outfile.write(reinterpret_cast<char *>(&c), sizeof(cfacluty));

            outfile.close();
        } while (getch() != 27);

        cout << endl;
        cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
        system("cls");
        facmenu();
        faculty();
    }
    case 2:
    {
        stdrel();
        mainmenu();
    }
    case 3:
    {
        int i;
        system("cls");
        cfacluty c;
        ifstream infile;
        bool check = false;
        infile.open("Reporttest1.txt", ios::app | ios::binary);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED.....press enter key...";
            cin.ignore();
            cin.get();
        }
        cout << "\n\n";
        cout << "\t\t\t\tHEAD OF DEPARTEMENT LIST:" << endl;
        cout << "==================================================================================" << endl;
        cout << "\nHOD NAME:\n";
        do
        {
            while (infile.read(reinterpret_cast<char *>(&c), sizeof(cfacluty)))
            {

                cout << "______________________________________________" << endl
                     << c.hodname << endl;
                cout << c.qualification << endl;
                cout << c.mob << endl;
                cout << c.address << endl;
                cout << "\nName of Faculty             : " << c.facult;
                cout << "\nQualification               : " << c.qualification;
                cout << "\nDesignation                 : " << c.desig;
                cout << "\nInstitute:                  : " << c.institute;
                cout << "\nName of Department          : " << c.dept;
                cout << "\nExperience                  : " << c.experience;
                cout << "\nBasic Payroll               : " << c.payroll << " Rs./Month";
            }

            infile.close();

        } while (getch() != 27);
        cin.ignore();
        // cin.get();
        system("cls");
        facmenu();
        faculty();
    }
    case 4:
        char yesno;
        {
            set_cursor(5, 10);
        cs:
            cout << "DO YOU WANT TO EXIT ??[y/n]";
        }
        cin >> yesno;
        if (yesno == 'y')
        {
            exit(0);
        }
        else if (yesno == 'n')
        {
            system("cls");
            facmenu();
            faculty();
        }
        else
            system("cls");
        cout << "\ninvalid option:\n";
        goto cs;
    }
}

void intro()
{
    char r1 = 220, r2 = 220, r3 = 220, r5 = 220, r4 = 220, r6 = 220;
    int i;

    for (i = 0; i <= 100; i++)
    {
        Sleep(10);
        cout << zz;
    }
    system("color 4");
    // system("cls");
    cout << "\n\t" << r6 << "  ..........SANJAY GHODAWAT UNIVERSITY..........." << r6 << endl;
    cout << "\t" << r6 << "           Accredited with Grade A+ by UGC,      " << r6 << endl;
    cout << "\t" << r6 << "            Atigre, Kolhapur, Maharashtra        " << r6 << endl;
    //  cout << "\t" << r6 << "                                                                 " << r6 << endl;
    // cout << "\t" << r6 << "                                       " << r6 << endl;
    //  cout << "\t" << r6 << "                                                                 " << r6 << endl;

    for (i = 0; i <= 100; i++)
    {
        Sleep(10);
        cout << zz;
    }
}

void gotoxy()
{
    string rotating_string = "        ...WELCOME TO SANJAY GHODAWAT UNIVERSITY....      ";

    int len = rotating_string.length();
    char letter_holder;

    do
    {
        gotoXY(20, 4);
        cout << rotating_string << endl;
        Sleep(100);
        letter_holder = rotating_string[len];
        for (int x = len; x > 0; x--)
        {
            rotating_string[x] = rotating_string[x - 1];
        }
        rotating_string[0] = letter_holder;

    } while (true);
}
void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}
void stdrel()
{
    system("cls");

    int i;

    system("color B");
    cout << "\n\t\t\t\t=====================MAIN MENU=====================\n\n"
         << endl;
    Sleep(300);

    for (i = 0; i < 110; i++)
    {
        cout << zz;
    }
    cout << "\n1. CREATE STUDENT REPORT CARD\t\t\t\t\t";
    Sleep(300);
    cout << "2. VIEW ALL STUDENTs REPORT CARD\n"
         << endl;
    Sleep(300);
    cout << "3. VIEW A SINGLE STUDENT REPORT CARD\t\t\t\t";
    Sleep(300);
    cout << "4. MODIFY REPORT CARD\n"
         << endl;
    Sleep(300);
    cout << "5. RESULT\t\t\t\t\t";
    Sleep(300);
    cout << "\t\t6. DELETE RECORD\n\n"
         << endl;
    Sleep(300);
    cout << "7.EXIT\n";
    Sleep(300);

    cout << "_______________________________________________________________________________________________________________\n";
    cout << "ENTER CHOICE:\n";
    for (i = 0; i < 110; i++)
    {
        cout << zz;
    }
    cout << "";
}

void mainmenu()
{

    int choose;
    int nn;
    cout << "\nCHOOSE:-";
    cin >> choose;
    switch (choose)
    {
    case 1:
    {
        system("cls");
        student s;
        ofstream outfile;
        outfile.open("Report12.txt", ios::app | ios::binary);
        if (outfile.fail())
        {
            cout << "THE FILE COULD NOT BE OPEN...press enter key";
            cin.ignore();
            cin.get();
        }

        cout << "ENTER STUDENT NAME:";
        cin.ignore();
        cin.getline(s.name, 80);
        // getline(cin, s.name);
        cout << "ENTER STUDENT ROLL NO:";
        cin >> s.roll;
        cout << "ENTER YOUR ID NUMBER : GUE/";
        cin.ignore();
        cin.getline(s.id, 80);
        cout << "ENTER STUDENT BRANCH:";
        cin.getline(s.stbr, 80);
        cout << "SUBJECTS:\n";
        cout << "\tSOFTWARE ENGINEERING:";
        cin >> s.se;
        cout << "\tOPERATING SYSTEM:";
        cin >> s.os;
        cout << "\tOOP WITH C++:";
        cin >> s.cpp;
        cout << "\tDATABASE MANAGEMENT :";
        cin >> s.dbs;
        cout << "\tMATHS3:";
        cin >> s.mts;
        outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
        outfile.close();
        cout << endl;
        cout << "\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED" << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
        cpystd();
    }
        // while (choose != 0)

    case 2:
    {

        int response;
        system("cls");
        student s;
        ifstream infile;
        bool check = false;
        infile.open("Report12.txt", ios::app | ios::binary);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED.....press enter key...";
            cin.ignore();
            cin.get();
        }
        cout << "\n\n";
        cout << "\t\t\t\tALL STUDENTS REPORT CARDS" << endl;
        cout << "==================================================================================" << endl;
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            cout << "\nSTUDENT NAME:" << s.name << endl;
            cout << "\nSTUDENT ID:" << s.id << endl;
            cout << "STUDENT ROLL NO:" << s.roll << endl;
            cout << " STUDENT BRANCH:" << s.stbr << endl;
            cout << "SUBJECTS:\n";
            cout << "\tSOFTWARE ENGINEERING:" << s.se << endl;
            cout << "\tOPERATING SYSTEM:" << s.os << endl;
            cout << "\tOOP WITH C++:" << s.cpp << endl;
            cout << "\tDATABASE MANAGEMENT :" << s.dbs << endl;
            cout << "\tMATHS3:" << s.mts << endl;
        }
        infile.close();
        cout << "press any key to continue....";
        cin.ignore();
        cin.get();
        system("cls");
        cpystd();
    }
    case 3:
    {
        int n;
        cout << "ENTER YOUR ROLL NUMBER :";
        cin >> n;
        ifstream infile;

        infile.open("Report12.txt", ios::app | ios::binary);

        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED...";

            cin.ignore();
            cin.get();
        }
        // bool equality = false;
        cout << "\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.roll == n)
            {
                cout << "\nSTUDENT NAME:" << s.name << endl;
                cout << "\nSTUDENT ID:" << s.id << endl;
                cout << "STUDENT ROLL NO:" << s.roll << endl;
                cout << " STUDENT BRANCH:" << s.stbr << endl;
                cout << "SUBJECTS:\n";
                cout << "\tSOFTWARE ENGINEERING:" << s.se << endl;
                cout << "\tOPERATING SYSTEM:" << s.os << endl;
                cout << "\tOOP WITH C++:" << s.cpp << endl;
                cout << "\tDATABASE MANAGEMENT :" << s.dbs << endl;
                cout << "\tMATHS3:\n"
                     << s.mts << endl;
            }
            else
            {
                cout << "NO DATA FOUND..\n";
                //_sleep(300);
                // system("cls");
            }
        }

        infile.close();
        cout << "press any key to continue....";
        cin.ignore();
        cin.get();
        system("cls");
        cpystd();
    }

    case 4:
    {

        int no;
        cout << "ENTER YOUR ROLL NUMBER :";
        cin >> no;
        system("cls");
        student s;
        fstream infile;
        infile.open("Report12.txt", ios::binary | ios::in | ios::out);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED..." << endl;
            cin.ignore();
            cin.get();
        }
        bool checker = false;
        cout << "\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
        while (!infile.eof() && checker == false)
        {
            infile.read(reinterpret_cast<char *>(&s), sizeof(student));
            {
                if (s.roll == no)
                {
                    cout << "ENTER STUDENT NAME:";
                    cin.ignore();
                    cin.getline(s.name, 80);
                    // cin >> s.name;
                    cout << "ENTER STUDENT ROLL NO:";
                    cin >> s.roll;
                    cout << "ENTER YOUR ID NUMBER : GUE/";
                    cin.ignore();
                    cin.getline(s.id, 80);

                    cout << "ENTER STUDENT BRANCH:";
                    cin.getline(s.stbr, 80);
                    cout << "SUBJECTS:\n";
                    cout << "\tSOFTWARE ENGINEERING:";
                    cin >> s.se;
                    cout << "\tOPERATING SYSTEM:";
                    cin >> s.os;
                    cout << "\tOOP WITH C++:";
                    cin >> s.cpp;
                    cout << "\tDATABASE MANAGEMENT :";
                    cin >> s.dbs;
                    cout << "\tMATHS3:";
                    cin >> s.mts;

                    int pos = (-1) * static_cast<int>(sizeof(student));
                    infile.seekp(pos, ios::cur);
                    infile.write(reinterpret_cast<char *>(&s), sizeof(student));
                    cout << endl;
                    checker = true;
                }
            }
        }

        infile.close();
        if (checker == false)
            cout << "\t\t\t\tRECORD NOT FOUND" << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
        cpystd();
    }
    case 5:
    {
        int n;
        cout << "ENTER YOUR ROLL NUMBER :";
        cin >> n;
        system("cls");
        student s;
        ifstream infile;
        infile.open("Report12.txt", ios::app | ios::binary);
        if (infile.fail())
        {
            cout << "THE FILE COULD NOT BE OPENED..." << endl;
            cin.ignore();
            cin.get();
        }
        bool eq = false;
        cout << "\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.roll == n)
            {
                s.sum = s.se + s.os + s.cpp + s.dbs + s.mts;
                s.average = (s.sum / 5);
                cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl
                     << endl;
                cout << "\tSOFTWARE ENGINEERING:" << s.se << endl;
                cout << "\tOPERATING SYSTEM:" << s.os << endl;
                cout << "\tOOP WITH C++:" << s.cpp << endl;
                cout << "\tDATABASE MANAGEMENT :" << s.dbs << endl;
                cout << "\tMATHS3:" << s.mts << endl;
                cout << "TOTAL SUM:" << s.sum;
                cout << "TOTAL AVERAGE:" << s.average;

                //   cout << "\t\t\t\tSUM :" << s.sum << endl

                //    cout << "\t\t\t\tAVERAGE :" << s.average << endl

                cout << "\t\t\t\t==================================================" << endl;
                eq = true;
            }
        }
        infile.close();
        if (eq == false)
            cout << "\t\t\t\tRECORD NOT FOUND..." << endl;
        cout << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
        cpystd();
    }

    case 6:
    {
        system("cls");
        int n;
        cout << "Enter roll number to delete record:";
        cin >> n;
        student s;
        ifstream infile;
        infile.open("Report12.txt", ios::binary);
        if (!infile)
        {
            cout << "THE FILE COULD NOT BE OPENED..." << endl;
            cin.ignore();
            cin.get();
        }
        ofstream outfile;
        outfile.open("Record12.txt", ios::binary);
        infile.seekg(0, ios::beg);
        cout << "\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
        while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.roll != n)
            {
                outfile.write(reinterpret_cast<char *>(&s), sizeof(student));
            }
        }
        infile.close();
        outfile.close();
        remove("Report12.txt");
        // rename("Record12.txt", "Report11.txt");
        cout << endl;
        cout << "\t\t\t\tRECORD SUCCESSFULLY DELETED" << endl;
        cout << "press any key to continue...";
        cin.ignore();
        cin.get();
        cpystd();
    }

    case 7:
    {

        exit(0);

        break;
    }
    }
}

void cpystd()
{

    system("cls");
    int i;
    system("color B");
    cout << "\n\t\t\t\t=====================MAIN MENU=====================\n\n"
         << endl;
    Sleep(300);

    for (i = 0; i < 110; i++)
    {
        cout << zz;
    }
    cout << "\n1. CREATE STUDENT REPORT CARD\t\t\t\t\t";
    cout << "2. VIEW ALL STUDENTs REPORT CARD\n"
         << endl;
    cout << "3. VIEW A SINGLE STUDENT REPORT CARD\t\t\t\t";
    cout << "4. MODIFY REPORT CARD\n"
         << endl;
    cout << "5. RESULT\t\t\t\t\t";
    cout << "\t\t6. DELETE RECORD\n\n"
         << endl;
    cout << "7.EXIT\n";

    cout << "_______________________________________________________________________________________________________________\n";
    cout << "ENTER CHOICE:\n";
    for (i = 0; i < 110; i++)
    {
        cout << zz;
    }
    mainmenu();
}

void facmenu()
{
    system("cls");
    int i;
    set_cursor(0, 80);
    for (i = 0; i <= 80; i++)
    {
        cout << zz;
    }

    cout << "\n\n";
    cout << "1. ADD FACULTY DATA:\n";
    cout << "2.STUDENT SECTION:\n";
    cout << "3. LIST OF FACULTY IN PARTIICULAR DEPARTMENT:\n";
    cout << "4. EXIT TO PREVIOUS MENU:\n";
    cout << "\n\tYour choice: \n";
    set_cursor(0, 80);
    for (i = 0; i <= 80; i++)
    {
        cout << zz;
    }
    // cin >> inadminop;
}

void passadm()
{
    system("cls");
    int i;
    {
        int choose;
        string adminusr;
        string adminpass;
        string adminusrkey = "admin123";
        string adminpasskey = "4040";
        set_cursor(0, 80);
        for (i = 0; i <= 80; i++)
        {
            cout << zz;
        }

        cout << "\n\t1) Faculty Login.";
        cout << "\n\t2) Exit.\n";
        cout << "\n\tYour choice:\n";

        set_cursor(0, 80);
        for (i = 0; i <= 80; i++)
        {
            cout << zz;
        }
        cin >> choose;
        switch (choose)
        {
        case 1:
        faccred:
            cout << "Enter Username:";
            cin >> adminusr;
            if ((adminusr.compare(adminusrkey)) == (0))
            {
            }
            else
            {
                cout << "Invalid Username ";
                Sleep(1000);
                system("cls");
                goto faccred;
            }
        facpass:
            cout << "Enter passwrod";
            cin >> adminpass;
            if ((adminpass.compare(adminpasskey)) == (0))
            {
            }
            else
            {
                cout << "Invalid password ";
                Sleep(1000);
                system("cls");
                goto facpass;
            }
            system("cls");
        }
    }
}
void set_cursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/// cout<<"\n\t1) Finance department.";

int main()
{

    vector<User> users = {{"student", "pass"}, {"admin", "adminpass"}};
    vector<Student> students = {{"s1", "John"}, {"s2", "Jane"}};

    string currentUser;

    if (login(users, currentUser))
    {
        if (currentUser == "admin")
        {
            adminSection(students);
        }
        else
        {
            studentSection(students);
        }
    }
    else
    {
        cout << "Login failed. Exiting." << endl;
    }

    // verify();
    //     system("cls");
    //     int x = 0, y = 0;
    //     set_cursor(x, y);
    //     cout << "WELCOME..";
    //     set_cursor(99, 0);
    //     cout << "USER:\n";
    //     intro();
    //     set_cursor(5, 10);
    //     //   system("color 4");
    //     system("Color E");

    //     return 0;
    //     void cpystd();
    //     void stdrel();
    // }
}
bool login(vector<User> &users, string &currentUser)
{
    string enteredUsername, enteredPassword;

    cout << "Enter Username: ";
    cin >> enteredUsername;
    cout << "Enter Password: ";
    cin >> enteredPassword;

    for (const User &user : users)
    {
        if (user.username == enteredUsername && user.password == enteredPassword)
        {
            currentUser = user.username;
            return true;
        }
    }

    return false;
}

void studentSection(const vector<Student> &students)
{

    system("cls");
    system("cls");
    int x = 0, y = 0;
    set_cursor(x, y);
    cout << "WELCOME..";
    set_cursor(99, 0);
    cout << "USER:\n";
    intro();
    set_cursor(5, 10);
    //   system("color 4");
    system("Color E");
    {
        cout << "Welcome";
    }
    cout << "STUDENT LOGIN:\n";
    int n;
    cout << "\n1.CHECK RESULT:                                                   2.DETAILS:\n";
    cout << "\nENTER YOUR ROLL NUMBER :";
    cin >> n;
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report12.txt", ios::app | ios::binary);
    if (infile.fail())
    {
        cout << "THE FILE COULD NOT BE OPENED..." << endl;
        cin.ignore();
        cin.get();
    }
    bool eq = false;
    cout << "\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while (infile.read(reinterpret_cast<char *>(&s), sizeof(student)))
    {
        if (s.roll == n)
        {
            cout << "\t\t\t\tSTUDENT NAME :" << s.name << endl
                 << endl;
            cout << "\tSOFTWARE ENGINEERING:" << s.se << endl;
            cout << "\tOPERATING SYSTEM:" << s.os << endl;
            cout << "\tOOP WITH C++:" << s.cpp << endl;
            cout << "\tDATABASE MANAGEMENT :" << s.dbs << endl;
            cout << "\tMATHS3:" << s.mts << endl;
            cout << "TOTAL SUM:" << s.sum;
            s.sum = s.se + s.os + s.cpp + s.dbs + s.mts;
            //   cout << "\t\t\t\tSUM :" << s.sum << endl

            //    cout << "\t\t\t\tAVERAGE :" << s.average << endl

            cout << "\t\t\t\t==================================================" << endl;
            eq = true;
        }
    }
}
void adminSection(vector<Student> &students)
{

    // passadm();
    facmenu();
    faculty();
}

