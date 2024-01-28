#include<conio.h>
#include<iostream>
#include<string>

using namespace std;

class atm 
{
    private:                       //private number vatiable
    long int account_no;
    string name;
    int pin;
    double balance;
    string mobile_no;

    public:                        //public number variable

    //setdata function is setting the data in private number variable
    void setData(long int account_no_a,string name_a, int pin_a, double balance_a,string mobile_no_a)
    {
        account_no=account_no_a;   //assiging the formal arguments to the private member var's
        name=name_a;
        pin=pin_a;
        balance=balance_a;
        mobile_no=mobile_no_a;
    }

    //getAccountNo function is returing the users account no.

    long int getAccountNO()
    {
        return account_no;
    }
    ////getAccountNo function is returning the user's account no.
    string getname()
    {
        return name;
    }
    //getPIN function is returning the user's PIN
	int getPIN()
	{
		return pin;
	}

	//getBalance is returning the user's Bank Balance
	double getBalance()
	{
		return balance;
	}

	//getMobileNo is returning the user's Mobile No.
	string getMobileNo()
	{
		return mobile_no;
	}
//setMobile function is updating the users mobile no.
    void setMobile(string mob_prev,string mob_new)
    {
        if(mob_prev==mobile_no)     // it will check old Mobile no
        {
            mobile_no = mob_new;    //if old mobile no. is correct then new no. is updated
            cout<<endl<<"Sucessfully Upadted Mobile Number.";
            _getch();            //getch() is used to hold the screen
        }
        else                //if old mobile no. is not matched then error message is displayed
        {
            cout<<endl<<"Incorrect Old Mobile Number Entered.";
            _getch();           ///getch is to hold the screen ( untill user press any key )
        }
    }
    //cashWithDraw function is used to withdraw money from ATM

    void cashWithDraw(int amount_a)
    {
        if(amount_a>0 && amount_a<balance)  //checking the amount is greater than 0 and less than balance
        {
          balance-=amount_a;
          cout<<endl<<"Please Collect the Cash";
          cout<<endl<<"Availabe Balance : "<< balance;
          _getch();             //getch() is used to hold the screen 
        }
        else
        {
            cout << endl << "Invalid Input or Insufficient Balance";
            cout<<endl<<"Your balance is : "<<balance;
			_getch();//getch is to hold the screen ( untill user press any key )
        }
    }

};



int main()
{
    int choice=0, enterPin;     //enterPIN and enterAccountNo. ---> user authentication
    long int enterAccountNO;

    system("cls");

    // created User{ object};
    atm user1;

    user1.setData(1234567,"Iftakher Alam", 1111, 500000.00, " 01700000000");

    do
    {
        system("cls");

        cout<<endl<<"*****Welcome to People's Banks ATM*****";
        cout<<endl<<"Enter Your Account No: ";          // asking user to enter account no
        cin>>enterAccountNO;

        cout<<endl<<"Enter PIN: ";
        cin>>enterPin;                               //asking user to enter pin for authentication


        if((enterAccountNO=user1.getAccountNO())&& (enterPin == user1.getPIN()))
        {
            do
            {
                int amount=0;
                string oldMobileNo, newMobileNo;

                system("cls");
                //user Interface

                cout<<endl<<"*****Welcome to People's Banks ATM*****"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1: Check Balance";
                cout << endl << "2: Cash withdraw";
				cout << endl << "3: Show User Details";
				cout << endl << "4: Update Mobile no.";
				cout << endl << "5: Exit" << endl;
                cin>>choice;        //taking user choice

                switch(choice)
                {
                    case 1:
                    cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                    _getch();
                    break;

                    case 2:
                    cout<<endl<<"Enter the amount : ";
                    cin >>amount ;
                    user1.cashWithDraw(amount);

                    break;


                    case 3:
                    cout<<endl<<"****User Details are :- ****"<<endl;
                    cout<<endl<<"Account No. : "<<user1.getAccountNO()<<endl;
                    cout<<endl<<"Name : "<<user1.getname()<<endl;
                    cout<<endl<<"Balance : "<<user1.getBalance()<<endl;
                    cout<<endl<<"Mobile No. : "<<user1.getMobileNo()<<endl;
                    _getch();
                    break;

                    case 4:
                    cout<<endl<<"Enter Old Mobile No. : ";
                    cin>>oldMobileNo;

                    cout<<endl<<"Enter New Mobile No. : ";
                    cin>>newMobileNo;

                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;


                    case 5:
                    exit(0);

                    default:
                    cout<<endl<<"Enter Valid Data"<<endl;
                }
            }while(1);
        
    } 

    else{
        cout<<endl<<"User Data not found"<<endl;
        _getch();
    }
}while(1);
return 0;
    

}