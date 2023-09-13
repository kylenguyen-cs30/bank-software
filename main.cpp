// Name : Hoang Nguyen
// Email : Hnguyen1193@csu.fullerton.edu

#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
using namespace std;


class account
{
private:
    int acno;
    char name[50];
    int deposit;
    char type;

public:
    void create_account(); //function to get data from user
    void show_account()const ; //function to show data on screen
    void modify(); //function to add new data
    void dep(int); // function to accept amount and add to balance amount
    void draw(int); // function
    void report() const; // function to show data in tabular format
    int retacno() const; // fucntion to return balance account
    int redeposit() const; // function to retunr balance amount
    char rettype()const; //function to return type of account
};

void account::create_account(){
    cout << "\nEnter the account No. : ";
    cin >> acno;
    cout << "\n\nEnter the name of the account holder : ";
    cin.ignore();
    cin.getline(name,50);
    cout << "\nEnter the type of the account (C/S) :";
    cin>>type;
    type = toupper(type);
    cout<<"\nEnter the Initial amount(>=500 for saving and >=1000 for current) : ";
    cin >> deposit;
    cout << "\n\nAccount created";
}

void account::show_account()const{
    cout << "\nAccount No. :" << acno;
    cout << "\nAccount holder name : ";
    cout<<name;
    cout<<"\nType of Account : " << type;
    cout<<"\nBalance amount: " << deposit;
}

void account::modify(){
    cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}

void account::dep(int x){
    deposit +=x;

}

void account::draw(int x){
    deposit -= x;
}

void account::report() const{
    cout << acno << setw(10) << " " << name << setw(10) << " " << type << setw(6) << deposit << endl;
}

int account::retacno() const{
    return acno;
}

int account::redeposit() const{
    return deposit;
}   

char account::rettype()const{
    return type;
}

// FUNCTION DECLARATION
void write_account();   //function to write record in binary file
void display_sp(int);   //function to display account details given any user
void modify_account(int);   //function to modify record of the file
void delete_account(int);   //function to delete record of file 
void display_all();         //functon to display all account details
void deposit_withdraw(int, int);    //function to deposit/withdraw amount for given account
void intro();                   //intrc screen function


int main(){
    char ch;
    int num;
    intro();
    do
    {
        system("cls");
        cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. NEW ACCOUNT";
		cout<<"\n\n\t02. DEPOSIT AMOUNT";
		cout<<"\n\n\t03. WITHDRAW AMOUNT";
		cout<<"\n\n\t04. BALANCE ENQUIRY";
		cout<<"\n\n\t05. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t06. CLOSE AN ACCOUNT";
		cout<<"\n\n\t07. MODIFY AN ACCOUNT";
		cout<<"\n\n\t08. EXIT";
		cout<<"\n\n\tSelect Your Option (1-8) ";
		cin>>ch;
        system("cls");
        switch (ch)
        {
        case '1':
            write_account();
            break;
        case '2':
            cout << "\n\n\tEnter the account No. : ";
            cin >> num;
            deposit_withdraw(num, 1);
            break;
        case '3':
            cout<<"\n\n\tEnter the account No. : ";
            cin >> num;
            deposit_withdraw(num, 2);
            break;
        case '4':
            cout<<"\n\n\tEnter the account No. : "; cin >> num;
            display_sp(num);
            break;            
        case '5':
            display_all();
            break;
        case '6':
            cout<<"\n\n\tEnter the account No. : "; cin >> num;
            delete_account(num);
            break;
        case '7':
            cout<<"\n\n\tEnter the account No. :"; cin >> num;
            modify_account(num);
            break;
        case '8':
            cout << "\n\n\tThanks for using bank management system";
            break;
                       
        default: 
        cout << "\a";
            break;
        }
        cin.ignore();
        cin.get();
    } while (ch != '8');
    

    return 0;
}