#include <iostream>
#include<windows.h>
#include<string.h>
#include<conio.h>
using namespace std;

class bank
{
    public:
    string username="admin", password="admin",user,pass;
    char name[20];
    int cmp,cmp1,flag_auth,ch;
    int ybank_bal=10000;
    double acc_no,tran_amt,ch_final;
    int bank2=5000;


    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    void auth()
    {
        SetConsoleTextAttribute(h,9);
        cout<<"\n\n \t\tWELCOME TO LOTAK BANK\n\n \t\t"<<endl;

        cout<<"ENTER USERNAME : ";
        cin>>user;
        cout<<"ENTER PASSWORD: ";
        cin>>pass;
        cmp= user.compare(username);
        cmp1=pass.compare(password);
        if (cmp==0 && cmp1==0)
        {
            //line("Color 2");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
            cout<<"\n\n \t\tLOGIN SUCCESSFULL!!!!!!!\n\n"<<endl;
            flag_auth=1;
        }

        else
        {
            SetConsoleTextAttribute(h,4);
            cout<<"\n\n \t\tINVALID USERNAME OR PASS\n\n";
            flag_auth=0;
        }

    }


    void  check()
{
    char chk; 
    int j;
    SetConsoleTextAttribute(h,7);
    cout<<"\n\nPress any key to continue......\n\n\n";
    chk=getch();
    j=chk;
    for(int i=1;i<=256;i++)
    if(i==j) 
    break;

}

    void bank_1_info()
    {
    if (flag_auth == 1)
    {
        do {
            SetConsoleTextAttribute(h,7);
            cout << "1. CHECK BANK BALANCE" << endl;
            cout << "2. TRANSFER MONEY" << endl;
            cout << "3. CASH WITHDRAWAL" << endl;
            cout << "4. CASH DEPOSIT" << endl;
            cout << "5. EXIT" << endl;
            cin >> ch;

            switch (ch)
            {
            case 1:
                SetConsoleTextAttribute(h,2);
                cout << "\n\n\t\tRs." << ybank_bal <<"\n\n"<< endl;
                break;

            case 2:
                SetConsoleTextAttribute(h,7);
                //cout<<"ENTER BENEFICIARY NAME : ";
                //cin.getline(name,20);
                cout << "ENTER BENEFICIARY ACCOUNT NUMBER : ";
                cin >> acc_no;
                cout << "ENTER AMOUNT TO TRANSFER : ";
                cin >> tran_amt;
                cout << "\nARE YOU SURE TO TRANSFER Rs." << tran_amt;
                cout << "\nPRESS 1. YES    2. NO";
                cin >> ch_final;
                if (tran_amt < ybank_bal)
                {

                    if (ch_final == 1)
                    {
                        bank2 = bank2 + tran_amt;
                        ybank_bal = ybank_bal - tran_amt;
                        SetConsoleTextAttribute(h,2);
                        cout << "\n\n \t\tAMOUNT TRANSFERRED SUCCESSFULLY !!!!!!!!!!!\n\n" << endl;
                    }
                    else
                    {
                        cout << "\n\n \t\tTRANSFER CANCELLED SUCCESSFULL\n\n \t\t" << endl;

                    }
                }
                else
                {
                    SetConsoleTextAttribute(h,4);
                    cout << "\n\n \t\tNOT ENOUGH BALANCE\t\t\n\n" << endl;
                }
                break;

            case 3:
                cout << "ENTER AMOUNT TO WITHDRAW : ";
                cin >> tran_amt;
                if (tran_amt < ybank_bal)
                {
                    SetConsoleTextAttribute(h,2);
                    cout << "\n\n \t\tWITHDRAWAL SUCCESSFUL\n\n ";
                    ybank_bal = ybank_bal - tran_amt;
                }
                else
                {
                    SetConsoleTextAttribute(h,4);
                    cout << "\n\n \t\tNOT ENOUGH BALANCE !!\n\n \t\t" << endl;
                }
                break;

            case 4:
                cout<<"ENTER AMOUNT TO DEPOSIT : ";
                cin>>tran_amt;
                ybank_bal+=tran_amt;
                SetConsoleTextAttribute(h,2);
                cout<<"\n\n\t\tAMOUNT DEPOSITED SUCCESSFULLY\n\n";
                break;


            case 5:
                SetConsoleTextAttribute(h,2);
                cout << "\n\n \t\t!!!!THANKS FOR USING LOTAK BANK!!!!\n\n";
                SetConsoleTextAttribute(h,7);
                break;

            default:
                SetConsoleTextAttribute(h,4);
                cout << "\n\n \t\tENTER CORRECT CHOICE\n\n \t\t";

            }
        } while (ch != 5);
    }
    else
    {
        SetConsoleTextAttribute(h,4);
        cout << "\n\n \t\tERROR OCCURRED\n\n \t\t";
    }
}

};

int main()
{
    bank s1;

    s1.auth();
    if (s1.flag_auth==0)
    {

        return 0;
    }
    s1.check();
    s1.bank_1_info();
    return 0;
}

