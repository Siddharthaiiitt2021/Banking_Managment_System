#ifdef _WIN32
#include<Windows.h>
#else
#include<unistd.h>
#endif


#include<bits/stdc++.h>
#define MIN_BALANCE 2500
using namespace std;

class Accounts
{
   public:
























































   
    bool VerifyUser(string Username, string Pin)
    {
        fstream fr;
        string dbStr;
        fr.open("Accounts.csv",ios::in);
        
        while(getline(fr,dbStr))
        {
            string _usr;
            string _pin;
            string dataStr;
            stringstream str(dbStr);
            getline(str,dataStr,',');
            _usr = dataStr;
            getline(str,dataStr,',');
            _pin = dataStr;
            if(_usr == Username && _pin == Pin)
            {
                fr.close();
                return true;
            }
        }
        fr.close();
        return false;
    }

    vector<string> AccountDetails(string Username)
    {
        fstream fr;
        string dbStr;
        vector<string> db;
        fr.open("Accounts.csv",ios::in);
        
        while(getline(fr,dbStr))
        {
            string _usr;
            string dataStr;
            stringstream str(dbStr);
            getline(str,dataStr,',');
            _usr = dataStr;

            if(_usr == Username)
            {
                db.push_back(_usr);
                getline(str,dataStr,',');
                db.push_back(dataStr);
                getline(str,dataStr,',');
                db.push_back(dataStr);
                getline(str,dataStr,',');
                db.push_back(dataStr);
                fr.close();
                return db;
            }
        }
        fr.close();
        return db;
    } 
};

class Transactions
{
    public: 
    bool MoneyActions(string Username, float amount)
    {

        fstream fr,fw;
        string dbStr;

        fr.open("Accounts.csv",ios::in);
        fw.open("newAccounts.csv",ios::out);
        if(fr.is_open() && fw.is_open())
        {
            while(getline(fr,dbStr))
            {
                string _usr;
                string dbstring = "";
                stringstream str(dbStr);
                getline(str, _usr,',');
                dbstring += _usr+',';
                if(_usr == Username)
                {
                    cout<<"Found username"<<endl;
                    getline(str,_usr,',');
                    dbstring += _usr+',';
                    getline(str,_usr,',');
                    dbstring += _usr+',';
                    getline(str,_usr,',');
                    if(stof(_usr)+amount<MIN_BALANCE)
                    {
                        cout<<"Insufficient balance"<<endl;
                        fw<<dbStr+'\n';
                        continue;
                    }
                    _usr = to_string(stof(_usr)+amount);
                    dbstring += _usr+',';
                    fw<<dbstring+'\n';
                }
                else
                {
                    fw<<dbStr+'\n';
                }
            }
            fr.close();
            fw.close();
            rename("newAccounts.csv","Accounts.csv");
            return true;

        }
        else
        {
            cout<<"File open error"<<endl;
            return false;
        }
    }
    bool TransferMoney(string username, string Acc_No, float amount)
    {
        fstream fr,fw;
        string dbstr;
        bool acc_check = false;
        fr.open("Accounts.csv",ios::in);
        while(getline(fr,dbstr))
        {
            string _acc;
            string _balance;
            string _db;
            
            stringstream str(dbstr);
            getline(str,_db,',');
            getline(str,_db,',');
            getline(str,_db,',');
            _acc = _db;
            getline(str,_db,',');
            _balance = _db;

            if( _db == Acc_No && stof(_balance)-amount>=MIN_BALANCE);
            {
                acc_check = true;
            }
        }
        fr.close();
        if(acc_check == false)
        {
            return false;
        }
        fr.open("Accounts.csv",ios::in);
        fw.open("newAccounts.csv",ios::out);
        while(getline(fr,dbstr))
        {
            string _usr;
            string _acc;
            string db;
            string ret_str;
            stringstream str(dbstr);
            getline(str,db,',');
            ret_str += db+',';
            _usr = db;
            getline(str,db,',');
            ret_str += db+',';
            getline(str,db,',');
            ret_str += db+',';
            _acc = db;

            if(_usr == username && _acc == Acc_No)
            {
                fr.close();
                fw.close();
                remove("newAccounts.csv");
                return false;
            }

            if(_usr == username)
            {
                getline(str, db,',');
                db = to_string(stof(db)-amount);
                ret_str += db+',';
                fw<<ret_str+'\n';
            }
            else if(_acc == Acc_No)
            {
                getline(str, db,',');
                db = to_string(stof(db)+amount);
                ret_str += db+',';
                fw<<ret_str+'\n';
            }
            else
            {
                fw<<dbstr+'\n';
            }
        }
        fr.close();
        fw.close();
        rename("newAccounts.csv","Accounts.csv");
        return true;
    }

};

class
AccountActions
{
    string AccountNo()
    {
        char RandChar[15] = {'a','b','c','d','e','f','g','1','2','3','4','5','6','7','u'};
        bool duplicate = false;
        while(true)
        {
            srand(time(0));
            string mystr="";
            for(int i=0; i<6; i++)
            {
                mystr += RandChar[rand()%15];
            }
            fstream fr;
        string dbStr;
        fr.open("Accounts.csv",ios::in);
        
        while(getline(fr,dbStr))
        {
            string _usr;
            string dataStr;
            stringstream str(dbStr);
            getline(str,dataStr,',');
            _usr = dataStr;
            if(_usr == mystr)
            {
                fr.close();
                duplicate = true;
                break;
            }
        }
        fr.close();
        if(duplicate == true)
        {
            continue;
        }
        return mystr;
        }
    }   
    bool verifyCred(string usr, string pin)
    {
        fstream fr;
        string dbStr;
        fr.open("Accounts.csv",ios::in);
        
        while(getline(fr,dbStr))
        {
            string _usr;
            string _pin;
            string dataStr;
            stringstream str(dbStr);
            getline(str,dataStr,',');
            _usr = dataStr;
            getline(str,dataStr,',');
            _pin = dataStr;
            if(_usr == usr || _pin == pin)
            {
                fr.close();
                return true;
            }
        }
        fr.close();
        return false;
    }

    bool verifyusercharacter(string usr , string pin)
    {
        //cout<<endl<<"Into the verifystringverse"<<endl;
        for(int i=0; i<usr.size(); i++)
        {
            if(iswalnum(usr[i]))
            {
                continue;
            }
            else
            {
                return true;
            }
        }
        //cout<<"Passes the username verification"<<endl;
        for(int i=0; i<pin.size(); i++)
        {
            if(iswalnum(pin[i]))
            {
                continue;
            }
            else
            {
                return true;
            }
        }

        //cout<<"Passes the pin verification"<<endl;
        if(usr.size()<6)
        {
            return true;
        }
        
        //cout<<"Passes the pin verification"<<endl;
        if(pin.size()<6)
        {
            return true;
        }

        //cout<<"Passes all tests"<<endl;
        return false;

    }

  public:
    bool AddAccount(string username, string pin, float money)
    {
        cout<<"Add function"<<endl;
        if(verifyCred(username,pin))
        {
            //cout<<"Issue with username"<<endl;
            return false;
        }
        else if(verifyusercharacter(username,pin))
        {
            //cout<<"Issue with pin"<<endl;
            return false;
        }
        else if(money<2500)
        {
            return false;
        }
        else
        {
            fstream fapp;
            fapp.open("Accounts.csv",ios::app);
            string datastr = username+','+pin+','+AccountNo()+','+to_string(money);
            fapp<<datastr+'\n';
            fapp.close();
            return true;
        }
    }
    void DeleteAccount(string username)
    {
        fstream fr,fw;
        string db;

        fr.open("Accounts.csv",ios::in);
        fw.open("newAccounts.csv",ios::out);

        while(getline(fr,db))
        {
            string _db;
            stringstream str(db);
            getline(str,_db,',');
            if(_db == username)
            {
                continue;
            }
            else
            {
                fw<<db+'\n';
            }
        }

        fr.close();
        fw.close();
        rename("newAccounts.csv","Accounts.csv");
    }  
};

int main()
{
    class Accounts acc;
    class Transactions ts;
    class AccountActions aa;

    char response;
    int choice;
    cout<<"Welcome to the bank"<<endl;
    //  Sleep(4);  for Windows
    //  sleep(4);  for linux
    //  system("clear"); for linux
    //  system("cls"); for windows
    cout<<"Do you have a account?(y/n) :";
    //  Sleep(4);  for Windows
    //  sleep(4);  for linux
    //  system("clear"); for linux
    //  system("cls"); for windows

    string usr;
    while(response == 'y')
    {
        string pin;
        cout<<"Enter username :";
        cin>>usr;
        for(int i=0; i<usr.size(); i++)
        {
            if(iswalnum(usr[i]));
            else
            {
                cout<<"Improper input, No action performed"<<endl;
                break;
            }

        }
        cout<<"Enter pin :";
        cin>>pin;
        for(int i=0; i<pin.size(); i++)
        {
            if(iswalnum(pin[i]));
            else
            {
                cout<<"Improper input, No action performed"<<endl;
                break;
            }

        }
        if(acc.VerifyUser(usr,pin))
        {
            //  Sleep(4);  for Windows
            //  sleep(4);  for linux
            //  system("clear"); for linux
            //  system("cls"); for windows
            break;
        }
        else
        {
            cout<<"Looks like no such account exists"<<endl;
            cout<<"Do you want to try to login again?(y/n)";
            cin>>response;
            //  Sleep(4);  for Windows
            //  sleep(4);  for linux
            //  system("clear"); for linux
            //  system("cls"); for windows
        }
    }
    while(response == 'n')
    {
        char res;
        cout<<"Do you want to create a bank account?(y/n)"<<endl;
        cin>>res;
        if(res == 'y')
        {
            string n_pin; 
            cout<<"Enter new username :";
            cin>>usr;
            cout<<"Enter new pin :";
            cin>>n_pin;
            if(acc.VerifyUser(usr,n_pin))
            {
                cout<<"This account already exists"<<endl;
                cout<<"Logging in the account"<<endl;
                //  Sleep(4);  for Windows
                //  sleep(4);  for linux
                //  system("clear"); for linux
                //  system("cls"); for windows
                break;   
            }
            else
            {
                float amount;
                cout<<"Amount to deposit :";
                cin>>amount;
                if(aa.AddAccount(usr,n_pin,amount))
                {
                    cout<<"Account created"<<endl;
                    //  Sleep(4);  for Windows
                    //  sleep(4);  for linux
                    //  system("clear"); for linux
                    //  system("cls"); for windows
                    break;
                }
                else
                {
                    cout<<"Account not created, do follow rules given below"<<endl;
                    cout<<"1.Minimum length of use(rname and pin is 6 characters"<<endl;
                    cout<<"2.Username and pin must be alphanumeric"<<endl;
                    cout<<"3.Username and pin must not be repeated"<<endl;
                    cout<<"Try Again"<<endl;   
                    //  Sleep(4);  for Windows
                    //  sleep(4);  for linux
                    //  system("clear"); for linux
                    //  system("cls"); for windows
                }
            }
        }
        else
        {
            cout<<"Have a good day!"<<endl;
            return 0;
        }
        
    }
    bool status = true;
    while(status)
    {
        cout<<"Select actions :"<<endl;
        cout<<"1.Get account details :"<<endl;
        cout<<"2.Deposit Money :"<<endl;
        cout<<"3.Withdraw money :"<<endl;
        cout<<"4.Transfer money :"<<endl;
        cout<<"5.Delete account :"<<endl;
        cout<<"6.Logout :"<<endl;

        cout<<"Enter decided action :";
        cin>>choice;

        vector<string> Details;
        string acc_no;
        string amount;

        switch(choice)
        {
            case 1:
                Details = acc.AccountDetails(usr);
                cout<<"Username :"<<Details[0]<<endl;
                cout<<"Pin :"<<Details[1]<<endl;
                cout<<"Account Number :"<<Details[2]<<endl;
                cout<<"Balance :"<<Details[3]<<endl;
                break;
            case 2:
                cout<<"Enter amount to deposit :";
                cin>>amount;
                ts.MoneyActions(usr,stof(amount));
                break;
            case 3:
                cout<<"Enter amount to deposit :";
                cin>>amount;
                ts.MoneyActions(usr,-stof(amount));
            case 4:
                cout<<"Enter amount :";
                cin>>amount;
                cout<<"Enter Acc_No of reciever :";
                cin>>acc_no;
                ts.TransferMoney(usr,acc_no,stof(amount));
                break;
            case 5:
                aa.DeleteAccount(usr);
                cout<<"Account deleted"<<endl;
                status = false;
            case 6:
                cout<<"Have a nice day"<<endl;
                status = false;
                break;
            default:
                cout<<"Invalid command"<<endl;
                cout<<"have a nice day";
                status = false;
            }
            //  Sleep(4);  for Windows
            //  sleep(4);  for linux
            //  system("clear"); for linux
            //  system("cls"); for windows
        }
    }