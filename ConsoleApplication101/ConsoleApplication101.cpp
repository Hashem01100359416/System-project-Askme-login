#include <iostream>
#include <vector> 
#include <map>
using namespace std;
struct user
{
    int ID;
    string password;
    string Email;
    string User_Name;
    user()
    {
        ID = 0;
        password = Email = User_Name = "";
    }
};
bool login_user(map<string, user>&);
void sign_up_user(map<string, user>&);
void Menu_Enter_to_project();
int Choose_Menue1();
void Project_Ask_me();
int main()
{
    Project_Ask_me();
}
void Project_Ask_me()
{
    map<string,user>User;
    int T=0,q=2;
    Menu_Enter_to_project();

    while (q--)
    {
        switch (Choose_Menue1())
        {
        case 1:
            T = login_user(User);
            break;
        case 2:
            sign_up_user(User);
            break;
        }
    }

    while (T > 0)             //This body of project 
    {
        cout<<"\n\n\nProgram open\n\n\n"<<endl;
        break;
    }

}
void Menu_Enter_to_project()
{
    cout << "Menu: \n";
    cout << "          1: Login\n";
    cout << "          2: Sign UP\n\n";
}
int Choose_Menue1()
{

    int x,c=0;
    while (c==0)
    {
        cout << "Enter number in range 1 - 2 : ";
        cin >> x;
        if (x > 2 || x < 1)
        {
            cout << "ERROR: invalid number.....Try again\n\n";
        }
        else
            c = 10;
    }
    return x;
}
bool login_user(map<string,user> &User)
{
    string s,st;
    int c = 0,T=0;
    while (c == 0)
    {
        cout << "\nPlease Enter User Name : ";
        cin >> s;
        if (User[s].ID == 0)
        {
            cout << "ERROR: This username does't exist.....Try agein\n\n";
        }
        else
        {
            cout << "Please Enter Password : ";
            cin >> st;
            if (st == User[s].password)
            {
                return 1;
            }
            else
            {
                cout << "\n\nERROR: This password is incorrect.....Try agein\n\n";
            }
        }
    }
}
void sign_up_user(map<string, user>& User)
{
    string s,sE,st,se="@gmail.com";
    int c = 0,ct=0,c2=0;
    while (c==0)
    {
        cout << "\nEnter User name Please : ";
        cin >> s;
        if (User[s].ID == 0 && User[s].password == "")
        {
            User[s].User_Name = s;
            cout << "Enter User ID Please : ";
            cin >> User[s].ID;
            while (c2 == 0)
            {
                ct = 0;
                cout << "Enter Email Please : ";
                cin >> sE;
                for (int i = 0; i < sE.size(); i++)
                {
                    if (sE[i] =='@')   ct = 10; 

                    if (ct > 0)  st.push_back(sE[i]);
                }

                if (st == se)
                {
                    User[s].Email = sE;
                    cout << "Enter User Password Please : ";
                    cin >> User[s].password;
                    c++;
                    c2++;
                    cout << "\n\n--------------------------------\n\n";
                }
                else
                {
                    cout << "\nERROR: Email must end with ""@gmail.com"".....Try agein\n\n";
                }
            }
            
        }
        else
        {
            cout << "ERROR: This name is already reserved.....Try agein\n\n";
        }
    }
}