#include <iostream>
#include <conio.h>
using namespace std;

void garis();
void login();
void regis();
void bank();
void menu();

int pilih,limit;

string uname[1000];
string pass[1000];
int a = 0;
int d;
string log = "false";
int main(){
	cout<<"Welcome to HoshiBank!!\n";
	garis();
	cout<<"1.Register your account!!\n"
	<<"2.Login to use our services!!\n"
	<<"3.Quit\n"
	<<"Pick your option! (input 1/2)"<<endl;
	cin>>pilih;
	switch(pilih){ //choose your option between register,login, or quit the session
		case 1:
			system("cls"); //this is for closing the current cmd and starting the new one
			regis();
			break;
		case 2:
			system("cls");
			login();
			break;
		case 3:
			cout<<"Thank you for using our services!!"<<endl;
			return 0;
			
	}
	
}

void garis(){
	cout<<"==================================="<<endl;
}
void regis(){
	int cont;
	string user,password;
	regist:
	cout<<"Register Yourself to Use our Services!!\n";
	garis();
	cout<<"Insert your Username : ";
	cin>>uname[a];
	cout<<"Insert your Password : ";
	cin>>pass[a];
	cout<<"You've entered "<<uname[a]<<" as Username and "<<pass[a]<<" as your Password\n";
	cout<<"Do you want to continue\n"
	<<"1.Yes			2.No\n";
	cin>>cont;
		for (int c=0; c<a; c++){ //to find if your username has been used or not
			if(uname[a] == uname[c]){
				cout<<"Username Has Been Used\n";
				getch();
				goto regist;
			}
		}
		a = a+1; //to add a new array for the next registration
		cout<<"\nYour account has been Registered!!";
		getch();
		system("CLS");
		login();
}

void login(){
	string user,password;
	int chance = 2;
	system("CLS");
	relog:
	if (a<1){ //if there is no username and password registered first, you will get this notification
		cout<<"Uhh ohh,Looks like we don't have any account to proceed'\n"
		<<"Please create an account first!!"<<endl;
		getch();
		system("CLS");
		regis();
	}
	do {
		garis();
		cout<<"Please Login First to Experience our Services!!"<<endl;
		garis();
		cout<<"Enter your username : "; //input your username
		cin>>user;
		cout<<"Enter your password : "; //input your pass
		cin>>password;
		for (int b=0; b<a; b++){
			if (user == uname[b] && password == pass[b]){
				log = "true"; //to access menu,you should have this on "true"
				d = b; 
			}
		}
		if (log == "true"){
		cout<<"\nLogin Success!! Hello, "<<uname[d]<<endl;
		log = "false"; //to prevent the next login would be an error
		getch();
		system("cls");
		menu();
		} else {		
			if(chance != 0){ //if the chance still not on 0, program will loop
				cout<<"You have "<<chance--<<" more chance left\n\n"<<endl;
				goto relog;
			} else { //if the chance has been run out
				cout<<"You're being blocked out from our system!!"<<endl;
				break;
			}
		}
	}while (true);
}

void menu(){
	//Local variable declarations
	int command = 0;
	int money = 0;
	int balance = 100;
	// Print cmd
	transaction:
	garis();
	cout<<"Welcome, "<<uname[d]<<"!!\n"
	<<"=============================\n";
	balance = balance;
	cout<<"Balance on your account : "<<balance<<endl;
	cout<<"Enter command number:\n"
	<<" 0 - Quit\n"
	<<" 1 - Deposit Money\n"
	<<" 2 - Withdraw Money\n"
	<<" 3 - Print Balance\n";

	//Read and handle banking command
	cin >> command;
	switch(command){
		case 0: //Quit
			cout << "See you later!" <<endl;
			break;
		case 1: //Deposit
			cout<<"Enter deposit amount: ";
			cin>>money;
			if(money<=60){ //you can't deposit above 60 balance at once
				balance = balance + money;
				break;
			}else{
				cout<<"Sorry you reached your Deposit Limit(max 60 for each transaction)\n";
				break;
			}
		case 2: //Withdraw
			retry_withdraw:
			cout <<"Enter withdraw amount: ";
			cin>>money;
			limit=balance - money < 10;
			if(balance>10){ //if you don't have enough balance to withdraw
				if(money>=balance){
					cout<<"Your balance are not enough to do this"<<endl;
					goto retry_withdraw;
				} else if (limit) {
					cout<<"Your balance are not enough to do this"<<endl;
					goto retry_withdraw;
				} else {
					balance = balance - money;
					break;
				}
			} else {
				cout<<"Your balance are not enough to do this"<<endl;
				break;
			}

		case 3: //Print Balance
			cout << "Your current balance = " << balance <<endl;
			break;
		default: //Handle other values
			cout << "Oops! your value are invalid!!"<<endl;
			break;
	}
	//print final balance
	int cont;
	string password;
	cout<<"=============================\n";
	cout<<"Your final balance are : "<<balance<<endl;
	cout<<"=============================\n";
	cout<<"Do you want to continue the transaction?\n"
	<<"1.Yes			2.No\n";
	cin>>cont;
	if (cont == 1){
		cout<<"=============================\n\n";
		cout<<"Input Password :"; //input your last password if you want to continue your transaction
		cin>>password;
		if (password == pass[d]){
			system("CLS");
			goto transaction;
		} 
	} else {
		cout<<"Thank you,Please come back later!!"<<endl;
		cout<<"Press Any Button To Log Out";
		getch();
		system("CLS");
		main();
	}
}
